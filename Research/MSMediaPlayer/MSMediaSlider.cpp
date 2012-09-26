/*******************************************************
 *
 *	@author	: Turgut Mehdiyev
 *	@date	: 8/1/2012
 *	
 *	Copyright (c) Idrak Technology Transfer 2012
 *
 ******************************************************/

#include <MSMediaSlider.h>

#define MINIMUM 0
#define MAXIMUM 1000

#define FADEDURATION 300
#define FADEOUTDELAY 2000

MSMediaSlider::MSMediaSlider( Qt::Orientation q, QWidget *_parent, bool _static )
          : QSlider( q, _parent ), b_classic( _static ) {

    this->isSliding = false;
    this->f_buffering = 1.0;
    this->mHandleOpacity = 1.0;

    // timer used to fire intermediate updatePos() when sliding
    this->seekLimitTimer = new QTimer( this );
    this->seekLimitTimer->setSingleShot( true );

    // tooltip bubble
    this->mTimeTooltip = new MSSliderTimeTooltip( this );
    this->mTimeTooltip->setMouseTracking( true );

    // properties
    this->setSingleStep( 2 );
    this->setPageStep( 10 );
    this->setMouseTracking( true );
    this->setTracking( true );
    this->setFocusPolicy( Qt::NoFocus );

    // init to 0
    this->setPosition( -1.0, 0, 0 );
    secstotimestr( this->psz_length, 0 );

    this->animHandle = new QPropertyAnimation( this, "handleOpacity", this );
    this->animHandle->setDuration( FADEDURATION );
    this->animHandle->setStartValue( 0.0 );
    this->animHandle->setEndValue( 1.0 );

    this->hideHandleTimer = new QTimer( this );
    this->hideHandleTimer->setSingleShot( true );
    this->hideHandleTimer->setInterval( FADEOUTDELAY );

    connect( this, SIGNAL(sliderMoved(int)), this, SLOT(startSeekTimer()) );
    connect( this->seekLimitTimer, SIGNAL(timeout()), this, SLOT(updatePos()) );
    connect( this->hideHandleTimer, SIGNAL(timeout()), this, SLOT(hideHandle()) );
    this->mTimeTooltip->installEventFilter( this );

}


MSMediaSlider::~MSMediaSlider() {

}


void MSMediaSlider::setPosition( float pos, int64_t time, int length ) {

    if( pos == -1.0 ) {
        this->setEnabled( false );
        this->isSliding = false;
    }
    else {
        this->setEnabled( true );
    }

    if( !this->isSliding )
        this->setValue( (int)( pos ) );

    this->inputLength = length;
}


void MSMediaSlider::startSeekTimer() {

    // Only fire one update, when sliding, every 150ms
    if( this->isSliding && !this->seekLimitTimer->isActive() ) {
        this->seekLimitTimer->start( 150 );
    }

}


void MSMediaSlider::updatePos() {

    float f_pos = (float)( this->value()*1000 );

    // Send new position to VLC's core
    emit this->sliderDragged( f_pos );
}


void MSMediaSlider::updateBuffering( float buf ) {
    this->f_buffering = buf;
    this->repaint();
}


void MSMediaSlider::mouseReleaseEvent( QMouseEvent *event ) {

    // right click
    if( event->button() != Qt::LeftButton &&
        event->button() != Qt::MidButton ) {
        return;
    }

    this->isSliding = false;
    // We're not sliding anymore: only last seek on release
    this->seekLimitTimer->stop();

    this->updatePos();

    event->accept();
}


void MSMediaSlider::mousePressEvent( QMouseEvent* event ) {

    // right click
    if( event->button() != Qt::LeftButton &&
        event->button() != Qt::MidButton ) {
        QSlider::mousePressEvent( event );
        return;
    }

    this->isSliding = true;

    this->setValue( QStyle::sliderValueFromPosition( 0, this->inputLength, event->x(), width(), false ) );

    event->accept();
}


void MSMediaSlider::mouseMoveEvent( QMouseEvent *event ) {


    if( this->isSliding )  {
        this->setValue( QStyle::sliderValueFromPosition( 0, this->inputLength, event->x(), width(), false) );
        emit sliderMoved( this->value() );
    }

    // tooltip
    if ( this->inputLength > 0 ) {
        int posX = qMax( rect().left(), qMin( rect().right(), event->x() ) );

        QString tooltipText;

        secstotimestr( psz_length, ( posX * (this->inputLength) ) / size().width() );
        this->mTimeTooltip->setText( this->psz_length, tooltipText );

        QPoint p( event->globalX() - ( event->x() - posX ) - ( this->mTimeTooltip->width() / 2 ),
                  QWidget::mapToGlobal( QPoint( 0, 0 ) ).y() - ( this->mTimeTooltip->height() - 2 ) );
        this->mTimeTooltip->move( p );
    }

    event->accept();
}


void MSMediaSlider::wheelEvent( QWheelEvent *event ) {

    // Don't do anything if we are for somehow reason sliding
    if( !this->isSliding ) {
        this->setValue( this->value() + event->delta()/10  ); // 12 = 8 * 15 / 10

        // Since delta is in 1/8 of ° and mouse have steps of 15 °
        // and that our slider is in 0.1% and we want one step to be a 1%
        // increment of position
        emit this->sliderDragged( this->value()*1000 );
    }
    event->accept();
}


void MSMediaSlider::enterEvent( QEvent * ) {

    // Cancel the fade-out timer
    this->hideHandleTimer->stop();

    // Only start the fade-in if needed
    if( this->animHandle->direction() != QAbstractAnimation::Forward ) {
        // If pause is called while not running Qt will complain
        if( this->animHandle->state() == QAbstractAnimation::Running ) {
            this->animHandle->pause();
        }
        this->animHandle->setDirection( QAbstractAnimation::Forward );
        this->animHandle->start();
    }

    // Don't show the tooltip if the slider is disabled or a menu is open
    if( this->isEnabled() && this->inputLength > 0 && !qApp->activePopupWidget() ) {
        this->mTimeTooltip->show();
    }

}


void MSMediaSlider::leaveEvent( QEvent * ) {

    this->hideHandleTimer->start();

    /* Hide the tooltip
       - if the mouse leave the slider rect (Note: it can still be
         over the tooltip!)
       - if another window is on the way of the cursor */
    if( !this->rect().contains( this->mapFromGlobal( QCursor::pos() ) ) ||
      ( !this->isActiveWindow() && !this->mTimeTooltip->isActiveWindow() ) ) {
        this->mTimeTooltip->hide();
    }
}


void MSMediaSlider::hideEvent( QHideEvent * ) {
    this->mTimeTooltip->hide();
}


bool MSMediaSlider::eventFilter( QObject *obj, QEvent *event ) {
    if( obj == this->mTimeTooltip )
    {
        if( event->type() == QEvent::Leave ||
            event->type() == QEvent::MouseMove )
        {
            QMouseEvent *e = static_cast<QMouseEvent*>( event );
            if( !this->rect().contains( this->mapFromGlobal( e->globalPos() ) ) )
                this->mTimeTooltip->hide();
        }
        return false;
    }
    else {
        return QSlider::eventFilter( obj, event );
    }
}


QSize MSMediaSlider::sizeHint() const {
    return ( orientation() == Qt::Horizontal ) ? QSize( 100, 18 )
                                               : QSize( 18, 100 );
}


QSize MSMediaSlider::handleSize() const {
    const int size = ( orientation() == Qt::Horizontal ? height() : width() );
    return QSize( size, size );
}


void MSMediaSlider::paintEvent( QPaintEvent *event ) {

    if( this->b_classic ) {
        return QSlider::paintEvent( event );
    }

    QStyleOptionSlider option;
    this->initStyleOption( &option );

    QPainter painter( this );
    painter.setRenderHints( QPainter::Antialiasing );

    // draw bar
    const int barCorner = 3;
    qreal sliderPos     = -1;
    int range           = this->inputLength;
    QRect barRect       = rect();

    // adjust positions based on the current orientation
    if ( option.sliderPosition != 0 ) {
        switch ( orientation() ) {
            case Qt::Horizontal:
                sliderPos = ( ( (qreal)width() ) / (qreal)range )
                        * (qreal)option.sliderPosition;
                break;
            case Qt::Vertical:
                sliderPos = ( ( (qreal)height() ) / (qreal)range )
                        * (qreal)option.sliderPosition;
                break;
        }
    }

    switch ( orientation() ) {
        case Qt::Horizontal:
            barRect.setHeight( height() /2 );
            break;
        case Qt::Vertical:
            barRect.setWidth( width() /2 );
            break;
    }

    barRect.moveCenter( rect().center() );

    // set the background color and gradient
    QColor backgroundBase( palette().window().color() );
    QLinearGradient backgroundGradient( 0, 0, 0, height() );
    backgroundGradient.setColorAt( 0.0, backgroundBase.darker( 140 ) );
    backgroundGradient.setColorAt( 1.0, backgroundBase );

    // set the foreground color and gradient
    QColor foregroundBase( 50, 156, 255 );
    QLinearGradient foregroundGradient( 0, 0, 0, height() );
    foregroundGradient.setColorAt( 0.0,  foregroundBase );
    foregroundGradient.setColorAt( 1.0,  foregroundBase.darker( 140 ) );

    // draw a slight 3d effect on the bottom
    painter.setPen( QColor( 230, 230, 230 ) );
    painter.setBrush( Qt::NoBrush );
    painter.drawRoundedRect( barRect.adjusted( 0, 2, 0, 0 ), barCorner, barCorner );

    // draw background
    painter.setPen( Qt::NoPen );
    painter.setBrush( backgroundGradient );
    painter.drawRoundedRect( barRect, barCorner, barCorner );

    // adjusted foreground rectangle
    QRect valueRect = barRect.adjusted( 1, 1, -1, 0 );

    switch ( orientation() ) {
        case Qt::Horizontal:
            valueRect.setWidth( qMin( width(), int( sliderPos ) ) );
            break;
        case Qt::Vertical:
            valueRect.setHeight( qMin( height(), int( sliderPos ) ) );
            valueRect.moveBottom( rect().bottom() );
            break;
    }

    if ( option.sliderPosition > minimum() && option.sliderPosition <= maximum() ) {
        // draw foreground
        painter.setPen( Qt::NoPen );
        painter.setBrush( foregroundGradient );
        painter.drawRoundedRect( valueRect, barCorner, barCorner );
    }

    // draw buffering overlay
    if ( f_buffering < 1.0 ) {
        QRect innerRect = barRect.adjusted( 1, 1,
                            barRect.width() * ( -1.0 + f_buffering ) - 1, 0 );
        QColor overlayColor = QColor( "Orange" );
        overlayColor.setAlpha( 128 );
        painter.setBrush( overlayColor );
        painter.drawRoundedRect( innerRect, barCorner, barCorner );
    }

    if ( option.state & QStyle::State_MouseOver || isAnimationRunning() ) {

        // draw handle
        if ( sliderPos != -1 ) {
            const int margin = 0;
            QSize hSize = handleSize() - QSize( 6, 6 );
            QPoint pos;

            switch ( orientation() )
            {
                case Qt::Horizontal:
                    pos = QPoint( sliderPos - ( hSize.width() / 2 ), 2 );
                    pos.rx() = qMax( margin, pos.x() );
                    pos.rx() = qMin( width() - hSize.width() - margin, pos.x() );
                    break;
                case Qt::Vertical:
                    pos = QPoint( 2, height() - ( sliderPos + ( hSize.height() / 2 ) ) );
                    pos.ry() = qMax( margin, pos.y() );
                    pos.ry() = qMin( height() - hSize.height() - margin, pos.y() );
                    break;
            }

            QPalette p;
            QPoint shadowPos( pos - QPoint( 2, 2 ) );
            QSize sSize( handleSize() - QSize( 2, 2 ) );

            // prepare the handle's gradient
            QLinearGradient handleGradient( 0, 0, 0, hSize.height() );
            handleGradient.setColorAt( 0.0, p.window().color().lighter( 120 ) );
            handleGradient.setColorAt( 0.9, p.window().color().darker( 120 ) );

            // prepare the handle's shadow gradient
            QColor shadowBase = p.shadow().color();
            if( shadowBase.lightness() > 100 )
                shadowBase = QColor( 60, 60, 60 ); // Palette's shadow is too bright
            QColor shadowDark( shadowBase.darker( 150 ) );
            QColor shadowLight( shadowBase.lighter( 180 ) );
            shadowLight.setAlpha( 50 );

            QRadialGradient shadowGradient( shadowPos.x() + ( sSize.width() / 2 ),
                                            shadowPos.y() + ( sSize.height() / 2 ),
                                            qMax( sSize.width(), sSize.height() ) / 2 );
            shadowGradient.setColorAt( 0.4, shadowDark );
            shadowGradient.setColorAt( 1.0, shadowLight );

            painter.setPen( Qt::NoPen );
            painter.setOpacity( mHandleOpacity );

            // draw the handle's shadow
            painter.setBrush( shadowGradient );
            painter.drawEllipse( shadowPos.x(), shadowPos.y() + 1, sSize.width(), sSize.height() );

            // finally draw the handle
            painter.setBrush( handleGradient );
            painter.drawEllipse( pos.x(), pos.y(), hSize.width(), hSize.height() );
        }
    }
}


qreal MSMediaSlider::handleOpacity() const {
    return this->mHandleOpacity;
}


void MSMediaSlider::setHandleOpacity(qreal opacity) {
    this->mHandleOpacity = opacity;
    // Request a new paintevent
    this->update();
}


void MSMediaSlider::hideHandle() {

    // If pause is called while not running Qt will complain
    if( this->animHandle->state() == QAbstractAnimation::Running )
        this->animHandle->pause();

    // Play the animation backward
    this->animHandle->setDirection( QAbstractAnimation::Backward );
    this->animHandle->start();
}


bool MSMediaSlider::isAnimationRunning() const {
    return (this->animHandle->state() == QAbstractAnimation::Running) ||
           this->hideHandleTimer->isActive();
}

/*******************************************************
 *
 *	@author	: Turgut Mehdiyev
 *	@date	: 8/2/2012
 *	
 *	Copyright (c) Idrak Technology Transfer 2012
 *
 ******************************************************/

#include <MSMediaVolumeSlider.h>

#define WLENGTH   80 // px
#define WHEIGHT   22  // px
#define SOUNDMIN  0   // %
#define SOUNDMAX  100 // % OR 400 ?


MSMediaVolumeSlider::MSMediaVolumeSlider( QWidget *parent, int incStep, bool b_hard )
                        : QSlider( parent ) {

    this->setOrientation( Qt::Horizontal );

    this->sliderGradient = "153;210;153;153;210;153;153;210;153;20;210;20";

    this->_fStep = ( incStep * 100 ) / AOUT_VOLUME_MAX ;
    this->setRange( SOUNDMIN, b_hard ? (2 * SOUNDMAX) : SOUNDMAX  );
    this->setMouseTracking( true );

    this->_isSliding = false;
    this->_isMouseOutside = true;
    this->_isMuted = false;

    this->pixOutside = QPixmap( ":/resources/toolbar/volume-slider-outside.png" );

    const QPixmap temp( ":/resources/toolbar/volume-slider-inside.png" );
    const QBitmap mask( temp.createHeuristicMask() );

    this->setFixedSize( this->pixOutside.size() );

    this->pixGradient = QPixmap( mask.size() );
    this->pixGradient2 = QPixmap( mask.size() );

    // Gradient building from the preferences
    QLinearGradient gradient( this->paddingL, 2, WLENGTH + this->paddingL , 2 );
    QLinearGradient gradient2( this->paddingL, 2, WLENGTH + this->paddingL , 2 );

    QStringList colorList = QString::fromUtf8( this->sliderGradient.c_str() ).split( ";" );

    // Fill with 255 if the list is too short
    if( colorList.count() < 12 ) {
        for( int i = colorList.count(); i < 12; i++) {
            colorList.append( "255" );
        }
    }

    // Regular colors
#define c(i) colorList.at(i).toInt()
#define add_color(gradient, range, c1, c2, c3) \
    gradient.setColorAt( range, QColor( c(c1), c(c2), c(c3) ) );

    // Desaturated colors
#define desaturate(c) c->setHsvF( c->hueF(), 0.2 , 0.5, 1.0 )
#define add_desaturated_color(gradient, range, c1, c2, c3) \
    foo = new QColor( c(c1), c(c2), c(c3) );\
    desaturate( foo ); gradient.setColorAt( range, *foo );\
    delete foo;

    // combine the two helpers
#define add_colors( gradient1, gradient2, range, c1, c2, c3 )\
    add_color( gradient1, range, c1, c2, c3 ); \
    add_desaturated_color( gradient2, range, c1, c2, c3 );

    QColor * foo;
    add_colors( gradient, gradient2, 0.0, 0, 1, 2 );
    add_colors( gradient, gradient2, 0.45, 3, 4, 5 );
    add_colors( gradient, gradient2, 0.55, 6, 7, 8 );
    add_colors( gradient, gradient2, 1.0, 9, 10, 11 );

    QPainter painter( &this->pixGradient );
    painter.setPen( Qt::NoPen );
    painter.setBrush( gradient );
    painter.drawRect( this->pixGradient.rect() );
    painter.end();

    painter.begin( &this->pixGradient2 );
    painter.setPen( Qt::NoPen );
    painter.setBrush( gradient2 );
    painter.drawRect( this->pixGradient2.rect() );
    painter.end();

    this->pixGradient.setMask( mask );
    this->pixGradient2.setMask( mask );
}


void MSMediaVolumeSlider::wheelEvent( QWheelEvent *event ) {
    int newvalue = value() + event->delta() / ( 8 * 15 ) * this->_fStep;
    this->setValue( __MIN( __MAX( minimum(), newvalue ), maximum() ) );

    emit sliderReleased();
    emit sliderMoved( this->value() );
}


void MSMediaVolumeSlider::mousePressEvent( QMouseEvent *event ) {

    if( event->button() != Qt::RightButton ) {
        // enter the sliding mode
        this->_isSliding = true;
        this->_oldValue = this->value();
        emit sliderPressed();
        this->changeValue( event->x() - this->paddingL );
        emit sliderMoved( this->value() );
    }
}


void MSMediaVolumeSlider::mouseReleaseEvent( QMouseEvent *event ) {

    if( event->button() != Qt::RightButton ) {

        if( !_isMouseOutside && value() != _oldValue ) {
            emit this->sliderReleased();
            this->setValue( this->value() );
            emit this->sliderMoved( this->value() );
        }

        this->_isSliding = false;
        this->_isMouseOutside = false;
    }

}


void MSMediaVolumeSlider::mouseMoveEvent( QMouseEvent *event ) {
    if( this->_isSliding ) {

        QRect rect( paddingL - 15,    -1,
                    WLENGTH + 15 * 2 , WHEIGHT + 5 );
        if( !rect.contains( event->pos() ) ) {

            // outside
            if ( !this->_isMouseOutside ) {
                this->setValue( this->_oldValue );
            }
            this->_isMouseOutside = true;
        }
        else {
            // inside
            this->_isMouseOutside = false;
            this->changeValue( event->x() - this->paddingL );
            emit this->sliderMoved( this->value() );
        }
    }
    else {
        int i = ( ( event->x() - this->paddingL ) * maximum() + 40 ) / WLENGTH;
        i = __MIN( __MAX( 0, i ), maximum() );
        this->setToolTip( QString("%1  \%" ).arg( i ) );
    }
}


void MSMediaVolumeSlider::changeValue( int x ) {
    this->setValue( (x * this->maximum() + 40 ) / WLENGTH );
}


void MSMediaVolumeSlider::setMuted( bool m ) {
    this->_isMuted = m;
    this->update();
}


bool MSMediaVolumeSlider::getMuted() const {
    return this->_isMuted;
}


void MSMediaVolumeSlider::setVolume(int vol) {
    this->setValue( vol );
    emit sliderMoved( this->value() );
//    this->update();
}


int MSMediaVolumeSlider::getVolume() const {
    return this->value();
}


void MSMediaVolumeSlider::paintEvent( QPaintEvent *e ) {

    QPainter painter( this );
    QPixmap *pixGradient;

    if ( this->_isMuted ) {
        pixGradient = &this->pixGradient2;
    }
    else {
        pixGradient = &this->pixGradient;
    }

    const int offset = int( ( WLENGTH * this->value() + 100 ) / this->maximum() ) + this->paddingL;

    const QRectF boundsG( 0, 0, offset , pixGradient->height() );
    painter.drawPixmap( boundsG, *pixGradient, boundsG );

    const QRectF boundsO( 0, 0, this->pixOutside.width(), this->pixOutside.height() );
    painter.drawPixmap( boundsO, this->pixOutside, boundsO );

    QColor background = palette().color( QPalette::Active, QPalette::Background );
    QColor foreground = palette().color( QPalette::Active, QPalette::WindowText );
    foreground.setHsv( foreground.hue(),
                    ( background.saturation() + foreground.saturation() ) / 2,
                    ( background.value() + foreground.value() ) / 2 );
    painter.setPen( foreground );
    QFont font; font.setPixelSize( 9 );
    painter.setFont( font );
    const QRect rect( 0, 0, 34, 15 );
    painter.drawText( rect, Qt::AlignRight | Qt::AlignVCenter,
                      QString::number( value() ) + '%' );

    painter.end();

    e->accept();
}

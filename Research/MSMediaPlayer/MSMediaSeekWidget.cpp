/*******************************************************
 *
 *	@author	: Turgut Mehdiyev
 *	@date	: 8/1/2012
 *	
 *	Copyright (c) Idrak Technology Transfer 2012
 *
 ******************************************************/

#include "MSMediaSeekWidget.h"

MSMediaSeekWidget::MSMediaSeekWidget( MSMediaPlayer *player, QWidget *parent )
    : QWidget(parent),
      _player(player) {

    assert( player != NULL );

    this->initSeekWidget();
}


MSMediaSeekWidget::MSMediaSeekWidget( QWidget *parent )
    : QWidget(parent),
      _player(0) {
    this->initSeekWidget();
}


MSMediaSeekWidget::~MSMediaSeekWidget() {
    delete this->_wdgtSeek;
    delete this->_lblTimeElapsed;
    delete this->_lblTimeFull;
    delete this->_timer;
}


void MSMediaSeekWidget::initSeekWidget() {

    this->_autoHide = false;

    this->_wdgtSeek = new MSMediaSlider( Qt::Horizontal, this );
//    this->_wdgtSeek->setOrientation( Qt::Horizontal );
//    this->_wdgtSeek->setMaximum( 0 );
//    this->_wdgtSeek->setPageStep( 10 );
//    this->_wdgtSeek->setSingleStep( 2 );
//    this->_wdgtSeek->setPageStep( 10 );
//    this->_wdgtSeek->setMouseTracking( true );
//    this->_wdgtSeek->setTracking( true );
//    this->_wdgtSeek->setFocusPolicy( Qt::NoFocus );

    this->_lblTimeElapsed = new QLabel( this );
    this->_lblTimeElapsed->setText( "00:00:00" );

    this->_lblTimeFull = new QLabel( this );
    this->_lblTimeFull->setText( "00:00:00" );

    QHBoxLayout *layout = new QHBoxLayout;
    layout->addWidget( this->_lblTimeElapsed );
    layout->addWidget( this->_wdgtSeek );
    layout->addWidget( this->_lblTimeFull );
    this->setLayout( layout );

    this->_timer = new QTimer( this );

    connect( _timer, SIGNAL(timeout()), this, SLOT(updateTime()) );
    connect( this->_wdgtSeek, SIGNAL(sliderDragged(float)), this, SLOT(changeTime(float)) );


    this->_timer->start( 150 );
}


void MSMediaSeekWidget::setMediaPlayer( MSMediaPlayer *player ) {

    assert( !this->_player );

    this->_player = player;

//    this->_timer->start( 400 );
}


void MSMediaSeekWidget::updateTime() {

    if ( this->_player->getState() == Vlc::Buffering ||
       this->_player->getState() == Vlc::Playing ||
       this->_player->getState() == Vlc::Paused) {
        int fullTime = _player->getMediaLenght();
        int currentTime = _player->getMediaTime();

//        printf( "Current time :%d\n", currentTime );
//        printf( "FullTime: %d\n", fullTime );

        this->_wdgtSeek->setPosition( currentTime/1000, 0, fullTime/1000 );

        this->_lblTimeFull->setText( QTime(0,0,0,0).addMSecs( fullTime ).toString( "hh:mm:ss" ) );
        this->_wdgtSeek->setMaximum( fullTime );

        this->_lblTimeElapsed->setText( QTime(0,0,0,0).addMSecs( currentTime ).toString( "hh:mm:ss" ) );

        if ( this->_autoHide && !fullTime ) {
            this->setVisible( false );
        } else {
            this->setVisible( true );
        }


    } else {
        this->_lblTimeFull->setText( "00:00:00" );
        this->_wdgtSeek->setMaximum( 0 );

        this->_lblTimeElapsed->setText( "00:00:00" );
        this->_wdgtSeek->setValue( 0 );

        if ( this->_autoHide ) {
            this->setVisible( false );
        }
    }

}


void MSMediaSeekWidget::changeTime() {

    if ( !this->_player )
        return;

    this->_lblTimeElapsed->setText( QTime(0,0,0,0).addMSecs( this->_wdgtSeek->value()).toString( "hh:mm:ss" ) );

    this->_player->setTime( this->_wdgtSeek->value() );

}

void MSMediaSeekWidget::changeTime( float time ) {

    if ( !this->_player ) {
        return;
    }

    this->_lblTimeElapsed->setText( QTime(0,0,0,0).addMSecs( (int)time ).toString( "hh:mm:ss" ) );

    this->_player->setTime( (int)time );
}


void MSMediaSeekWidget::decorateWidgets() {

}


void MSMediaSeekWidget::mouseMoveEvent( QMouseEvent *e ) {
    QWidget::mouseMoveEvent( e );
}


void MSMediaSeekWidget::mousePressEvent( QMouseEvent* e ) {
    QWidget::mousePressEvent( e );
}


void MSMediaSeekWidget::mouseReleaseEvent( QMouseEvent *e ) {
    QWidget::mouseReleaseEvent( e );
}

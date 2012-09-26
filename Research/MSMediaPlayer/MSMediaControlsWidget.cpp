/*******************************************************
 *
 *	@author	: Turgut Mehdiyev
 *	@date	: 7/31/2012
 *	
 *	Copyright (c) Idrak Technology Transfer 2012
 *
 ******************************************************/

#include "MSMediaControlsWidget.h"

MSMediaControlsWidget::MSMediaControlsWidget( MSMediaPlayer *player, QWidget *parent )
    : QWidget( parent ) {

    assert( player != NULL );

    this->setMediaPlayer( player );

    this->setupUI();
}


void MSMediaControlsWidget::setupUI() {

    this->_btnsLayout = new QHBoxLayout();
    this->setLayout( this->_btnsLayout );

    this->_btnPlayPause = new QPushButton( this );
    connect( this->_btnPlayPause, SIGNAL( clicked() ), this, SLOT(togglePlay()) );

    this->_btnSeekToBegin = new QPushButton( this );
    connect( this->_btnSeekToBegin, SIGNAL(clicked()), this, SLOT(seekToBegin()) );

    this->_btnSeekToEnd = new QPushButton( this );
    connect( this->_btnSeekToEnd, SIGNAL(clicked()), this, SLOT(seekToEnd()) );

    this->_btnStop = new QPushButton( this );
    connect( this->_btnStop, SIGNAL(clicked()), this, SLOT(stop()) );

    this->layout()->addWidget( this->_btnPlayPause );
    this->layout()->addWidget( this->_btnSeekToBegin );
    this->layout()->addWidget( this->_btnSeekToEnd );
    this->layout()->addWidget( this->_btnStop );

    this->decorateControlButtons();
}


void MSMediaControlsWidget::setMediaPlayer( MSMediaPlayer *player ) {

    assert( this->_mediaPlayer != NULL );

    this->_mediaPlayer = player;

    connect( this->_mediaPlayer->getVlcMediaPlayer(), SIGNAL(currentState(Vlc::State)),
             this, SLOT(updateWidgetState(Vlc::State)) );

}


MSMediaPlayer* MSMediaControlsWidget::getMediaPlayer() const {
    return this->_mediaPlayer;
}


MSMediaControlsWidget::~MSMediaControlsWidget() {
    delete this->_btnPlayPause;
    delete this->_btnSeekToBegin;
    delete this->_btnSeekToEnd;
    delete this->_btnStop;
    delete this->_btnsLayout;
}



void MSMediaControlsWidget::decorateControlButtons() {
    this->_btnPlayPause->setText( tr("Play") );
    this->_btnSeekToBegin->setText( tr("SeekToBegin") );
    this->_btnSeekToEnd->setText( tr("SeekToEnd") );
    this->_btnStop->setText( tr("stop") );
}


void MSMediaControlsWidget::togglePlay() {

    assert( this->_mediaPlayer->getMedia() != NULL );


    if ( this->_mediaPlayer->getState() == Vlc::Playing ) {
        this->_mediaPlayer->pause();
    }
    else {
        if ( this->_mediaPlayer->getState() == Vlc::Ended ) {
            this->_mediaPlayer->open( this->_mediaPlayer->getMedia() );
        }
        this->_mediaPlayer->play();
    }

    emit this->togglePlayTriggered();
}


void MSMediaControlsWidget::stop() {
    if ( this->_mediaPlayer->getState() != Vlc::Stopped ) {
        this->_mediaPlayer->stop();
    }
    emit this->stopTriggered();
}


void MSMediaControlsWidget::seekToBegin() {

    emit this->seekToBeginTriggered();
}


void MSMediaControlsWidget::seekToEnd() {

    emit this->seekToEndTriggered();
}

void MSMediaControlsWidget::updateWidgetState( const Vlc::State &st ) {

    assert( this->_mediaPlayer != NULL );

    if ( st == Vlc::Playing || st == Vlc::Buffering || st == Vlc::Idle ) {
        this->_btnPlayPause->setText( tr("Pause") );
    }
    else {
        this->_btnPlayPause->setText( tr("Play") );
    }

}

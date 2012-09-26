/*******************************************************
 *
 *	@author	: Turgut Mehdiyev
 *	@date	: 8/3/2012
 *	
 *	Copyright (c) Idrak Technology Transfer 2012
 *
 ******************************************************/

#include "MSMediaVolumeContolWidget.h"


MSMediaVolumeContolWidget::MSMediaVolumeContolWidget( QWidget *parent )
    : QWidget( parent ),
      _player(0) {

    this->InitWidgets();
}


MSMediaVolumeContolWidget::MSMediaVolumeContolWidget(MSMediaPlayer *player, QWidget *parent )
    : QWidget( parent ) {

    assert( player != NULL );

    this->_player = player;

    // init widgets
    this->InitWidgets();

    // initialize connection
    connect( this->_btnMute, SIGNAL(toggled(bool)), this, SLOT(setMuted(bool)) );


    this->setVolume( 54 );
    this->setMuted( true );

}

void MSMediaVolumeContolWidget::InitWidgets() {

    QHBoxLayout *hbox = new QHBoxLayout();
    this->setLayout( hbox );

    // init volume slider
    this->_volumeSlider = new MSMediaVolumeSlider( this, 1, false );

    // init mute button
    this->_btnMute = new QPushButton();
    this->_btnMute->setText( "Mute" );
    this->_btnMute->setCheckable( true );

    this->layout()->addItem( new QSpacerItem( -1, -1, QSizePolicy::Expanding, QSizePolicy::Fixed));
    this->layout()->addWidget( this->_btnMute );
    this->layout()->addWidget( this->_volumeSlider );

}


void MSMediaVolumeContolWidget::setVolume( int vol ) {
    this->_volumeSlider->setValue( vol );
}


int MSMediaVolumeContolWidget::getVolume() const {
    return this->_volumeSlider->value();
}


void MSMediaVolumeContolWidget::setMuted( bool mute ) {
    printf("setMuted\n");
    this->_volumeSlider->setMuted( mute );
}


bool MSMediaVolumeContolWidget::getMuted() const {
    return this->_volumeSlider->getMuted();
}


void MSMediaVolumeContolWidget::setMediaPlayer( MSMediaPlayer *player ) {

    assert( player != NULL );

    this->_player = player;
}

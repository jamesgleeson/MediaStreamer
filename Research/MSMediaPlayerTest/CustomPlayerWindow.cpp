#include "CustomPlayerWindow.h"

CustomMediaPlayer::CustomMediaPlayer()
    : _player(0) {

    this->_player = new MSMediaPlayer( true, this );

    this->setupUI();

    this->_player->open( "data/audio.mp3", true );

    this->_player->setTime( 20000 );
}

CustomMediaPlayer::~CustomMediaPlayer(){
//    delete this->_mediaControlsWidget;
//    delete this->_player;
}


void CustomMediaPlayer::setupUI() {

    this->setWindowTitle( tr("Main Window Name") );

    QVBoxLayout *vbox = new QVBoxLayout( this );

    this->setLayout( vbox );

    this->setupVideoWidget();

    this->setupControlPanel();

}

void CustomMediaPlayer::setupVideoWidget(){

    this->_player->getVideoWidget()->setSizePolicy( QSizePolicy::Expanding, QSizePolicy::Expanding );

    this->layout()->addWidget( this->_player->getVideoWidget() );

}

void CustomMediaPlayer::setupControlPanel() {

    QHBoxLayout *hbox = new QHBoxLayout();
    QWidget *wdgt = new QWidget();
    wdgt->setLayout( hbox );

    this->_mediaSeekWidget = new MSMediaSeekWidget( this->_player, this );
    this->_mediaControlsWidget = new MSMediaControlsWidget( this->_player, this );
    this->_mediaVolumeControlWidget = new MSMediaVolumeContolWidget( this->_player, this );

    wdgt->layout()->addWidget( this->_mediaControlsWidget );
    wdgt->layout()->addItem( new QSpacerItem( -1, -1, QSizePolicy::Expanding, QSizePolicy::Fixed));
    wdgt->layout()->addWidget( this->_mediaVolumeControlWidget );

    this->layout()->addWidget( this->_mediaSeekWidget );
    this->layout()->addWidget( wdgt );

}

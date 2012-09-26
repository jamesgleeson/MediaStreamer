/*****************************************************
 *
 *  @author      Turgut Mehdiyev
 *  @date        24/07/2012
 *
 *  Copyright (c) Idrak Technology Transfer LLC 2012
 *
 *****************************************************/

#include "MSMediaPlayer.h"

MSMediaPlayer::MSMediaPlayer( bool createWidget, QWidget *parent )
    : _vlc_instance(0),
      _vlc_media_player(0),
      _video_widget(0),
      _media(0) {


    // init vlc instance
    this->_vlc_instance = new VlcInstance( VlcCommon::args(), parent );

    // init media player
    this->_vlc_media_player = new VlcMediaPlayer( this->_vlc_instance );

    if ( createWidget ) {
        // init video widget
        this->_video_widget = new MSVideoWidget( parent );

        // create connection
        this->_video_widget->setMediaPlayer( this->_vlc_media_player );
        this->_vlc_media_player->setVideoWidget( this->_video_widget );
    }
}


MSMediaPlayer::~MSMediaPlayer() {
    delete this->_vlc_instance;
    delete this->_vlc_media_player;
    delete this->_video_widget;
    delete this->_media;
}

void MSMediaPlayer::setVideoWidget( MSVideoWidget *widget ) {
    this->_video_widget = widget;
}

MSVideoWidget *MSMediaPlayer::getVideoWidget() const {
    return this->_video_widget;
}


VlcInstance *MSMediaPlayer::getVlcInstance() const {
    return this->_vlc_instance;
}


VlcMediaPlayer *MSMediaPlayer::getVlcMediaPlayer() const {
    return this->_vlc_media_player;
}


Vlc::State MSMediaPlayer::getState() const {
    return this->_vlc_media_player->state();
}


VlcAudio *MSMediaPlayer::getAudio() const {
    return this->_vlc_media_player->audio();
}


VlcVideo *MSMediaPlayer::getVideo() const {
    return this->_vlc_media_player->video();
}


int MSMediaPlayer::getMediaLenght() const {
    return this->_vlc_media_player->lenght();
}


int MSMediaPlayer::getMediaTime() const {
    return this->_vlc_media_player->time();
}


void MSMediaPlayer::open( const std::string &file, bool isLocal ) {
    VlcMedia *media = new VlcMedia( QString(file.c_str()), isLocal, this->_vlc_instance );
    this->_vlc_media_player->open( media );
    this->_media = media;
}

void MSMediaPlayer::open( VlcMedia *media ) {
    this->_vlc_media_player->open( media );
    this->_media = media;
}


void MSMediaPlayer::play() {
    this->_vlc_media_player->play();
}


void MSMediaPlayer::pause() {
    this->_vlc_media_player->pause();
}


void MSMediaPlayer::stop() {
    this->_vlc_media_player->stop();
}


void MSMediaPlayer::setTime( const int &time ) {
    this->_vlc_media_player->setTime( time );
}


bool MSMediaPlayer::getMute() const {
    return this->_vlc_media_player->audio()->getMute();
}


void MSMediaPlayer::toggleMute() {
    this->_vlc_media_player->audio()->toggleMute();
}


void MSMediaPlayer::setVolume( const int &volume ) {
    this->_vlc_media_player->audio()->setVolume( volume );
}


int MSMediaPlayer::getVolume() const {
    return this->_vlc_media_player->audio()->volume();
}


void MSMediaPlayer::volumeControl( const bool &up ) {
    int currVol = this->_vlc_media_player->audio()->volume();

    if (up) {
        if ( currVol != 200 ) {
            this->setVolume( ++currVol );
        }
    } else {
        if ( currVol != 0 ) {
            this->setVolume( --currVol );
        }
    }
}


void MSMediaPlayer::volumeDown() {
    this->volumeControl( false );
}


void MSMediaPlayer::volumeUp() {
    this->volumeControl(true);
}


VlcMedia* MSMediaPlayer::getMedia() const {
    return this->_media;
}

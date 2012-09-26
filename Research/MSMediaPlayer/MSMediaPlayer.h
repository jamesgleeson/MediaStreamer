/*****************************************************
 *
 *  @author      Turgut Mehdiyev
 *  @date        24/07/2012
 *
 *  Copyright (c) Idrak Technology Transfer LLC 2012
 *
 *****************************************************/

#ifndef IDRAK_MS_MEDIA_PLAYER_H
#define IDRAK_MS_MEDIA_PLAYER_H

#include <MSMediaPlayer_global.h>
#include <MSVideoWidget.h>

#include <core/Common.h>
#include <core/Instance.h>
#include <core/MediaPlayer.h>
#include <core/Media.h>
#include <core/Audio.h>
#include <gui/VideoWidget.h>


namespace Idrak {
    namespace MediaStreamer {
        namespace MediaPlayer {
            class MSMediaPlayer;
        }
    }
}

/*!
 *  Media Player class
 *
 *  \brief This class provides wrapper funcionality over VlcMediaPlayer and VlcVideoWidget classes
 *         TODO: write in more detail
 */
class MS_MEDIA_PLAYER_EXPORT MSMediaPlayer : public QObject {

    Q_OBJECT

public:


    /*!
     *  Object constructor
     *
     *  \brief     Initializes object
     */
    MSMediaPlayer( bool createWidget = false, QWidget *parent = 0 );


    /*!
     *  Class destructor
     *
     *  \brief     Cleans up all garbage related to object
     */
    virtual ~MSMediaPlayer();


    /*!
     *  \brief Set video widget.
     *  Set video widget to be able to play video inside Qt interface.
     *
     *  \param widget video widget (MSVideoWidget *)
     */
    void setVideoWidget( MSVideoWidget *widget );


    /*!
     *  \brief Get VlcVideoWidget object.
     *         Developer should use this widget for integrating video widget into GUI.
     *  \return VlcVideoWidget
     */
    MSVideoWidget *getVideoWidget() const;


    /*!
     *  \brief Get VlcInstance object
     *  \return VlcInstance
     */
    VlcInstance *getVlcInstance() const;


    /*!
     *  Get VlcMediaPlayer object
     *
     *  \brief Gets VlcMedia Player object.
     *         This object controls all player related functionalities.
     *  \return VlcMediaPlayer object
     */
    VlcMediaPlayer *getVlcMediaPlayer() const;


    /*!
     *  \brief Get current player state.
     *  \return current player state (const Vlc::State)
     */
    Vlc::State getState() const;


    /*!
     *   \brief Get audio manager object.
     *   \return audio manager (VlcAudio *)
     */
    VlcAudio *getAudio() const;


    /*!
        \brief Returns video manager object.
        \return video manager (VlcVideo *)
    */
    VlcVideo *getVideo() const;


    /*!
        \brief Get the current media lenght (in ms).
        \return the media lenght (in ms), or -1 if there is no media (const int)
    */
    int getMediaLenght() const;


    /*!
        \brief Get the current movie time (in ms).
        \return the movie time (in ms), or -1 if there is no media (const int)
    */
    int getMediaTime() const;


    /*!
     *  \brief Open specified file and starts playing
     *
     *  \param file filename to open
     *  \param isLocal
     *
     *  \exception UnableToPlay
     */
    void open( const std::string &file, bool isLocal );


    /*!
     * \brief Open media
     * \param media Media to open (*VlcMedia)
     */
    void open( VlcMedia *media );


    /*!
     *  \brief Starts playing current media if possible
     */
    void play();


    /*!
     *  \brief Pauses the playback of current media if possible
     */
    void pause();


    /*!
     *  \brief Stops playing current media
     */
    void stop();


    /*!
     *  \brief Set the movie time (in ms).
     *         This has no effect if no media is being played. Not all formats and protocols support this.
     *  \param time the movie time (in ms) (int)
     */
    void setTime(const int &time);


    /*!
     *  \brief Get mute status
     */
    bool getMute() const;


    /*!
     *  \brief Toggle mute status.
     *  \return new mute status (const bool)
     */
    void toggleMute();


    /*!
     *  \brief Set volume for current media
     *  \param volume number from 0 to 200 (int)
     */
    void setVolume(const int &volume);


    /*!
     *  \brief Get volume for current media
     *  \return volume number from 0 to 200 (const int)
     */
    int getVolume() const;


    /*!
     *  \brief Decreases or increases volume for 1, depending on the parameter.
     *         Limits from 0 to 200 apply to this function.
     *  \param up if true increases the volume (bool)
     */
    void volumeControl(const bool &up);


    /*!
     *  \brief Decreases volume for 1.
     *         This function is provided for convenience.
     *  \see volumeControl()
     */
    void volumeDown();


    /*!
     *  \brief Increases volume for 1.
     *         This function is provided for convenience.
     *  \sa volumeControl()
     */
    void volumeUp();


    /*!
     *  \brief Get current media
     *  \return VlcMedia object
     */
    VlcMedia* getMedia() const;

private:
    VlcInstance *_vlc_instance;
    VlcMediaPlayer *_vlc_media_player;
    MSVideoWidget *_video_widget;

    VlcMedia *_media;

}; // class MSMediaPlayer



#endif // IDRAK_MS_MEDIA_PLAYER_H

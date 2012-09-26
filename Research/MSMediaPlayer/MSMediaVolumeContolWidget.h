/*******************************************************
 *
 *	@author	: Turgut Mehdiyev
 *	@date	: 8/3/2012
 *	
 *	Copyright (c) Idrak Technology Transfer 2012
 *
 ******************************************************/

#ifndef MS_MEDIA_VOLUME_CONTOL_WIDGET_H
#define MS_MEDIA_VOLUME_CONTOL_WIDGET_H

#include <MSMediaPlayer_global.h>
#include <MSMediaPlayer.h>
#include <MSMediaVolumeSlider.h>


#include <assert.h>


namespace Idrak {
    namespace MediaStreamer {
        namespace MediaPlayer {
            class MSMediaVolumeContolWidget;
        }
    }
}

/*!
 *  The MSMediaVolumeContolWidget class
 *
 *  \brief Provides user interface with Mute Button and Volume Slider controls
 */
class MS_MEDIA_PLAYER_EXPORT MSMediaVolumeContolWidget : public QWidget {

    Q_OBJECT

public:

    /*!
     * \brief MSMediaVolumeContolWidget contructor
     * \param parent Parent widget
     */
    MSMediaVolumeContolWidget( MSMediaPlayer *player, QWidget *parent = 0 );

    /*!
     * \brief MSMediaVolumeContolWidget contructor
     * \param parent Parent widget
     */
    MSMediaVolumeContolWidget( QWidget *parent = 0 );

    /*!
     * \brief Set media player
     * \param player MSMediaPlayer object
     */
    void setMediaPlayer( MSMediaPlayer *player );

    /*!
     * \brief Get volume
     * \return Current volume
     */
    int getVolume() const;

    /*!
     * \brief Get mute
     * \return Whether volume is muted or not
     */
    bool getMuted() const;



public slots:

    /*!
     * \brief Set volume
     * \param vol
     */
    void setVolume( int vol );

    /*!
     * \brief Set mute
     * \param mute
     */
    void setMuted( bool mute );


signals:

    /*!
     * \brief Fires when volume changed
     * \param vol New volume
     */
    void volumeChanged( int vol );

    /*!
     * \brief Fires when mute state changed
     * \param mute New mute state
     */
    void muteChanged( bool mute );


private:

    /*!
     * \brief Initialize mute button and volume slider
     */
    void InitWidgets();

    /*!
     * \brief Mute Button
     */
    QPushButton * _btnMute;

    /*!
     * \brief Volume Slider Widget
     */
    MSMediaVolumeSlider *_volumeSlider;

    /*!
     *  \brief Media player
     *  \see MSMediaPlayer
     */
    MSMediaPlayer *_player;



}; // class MSMediaVolumeControlWidget


#endif // MS_MEDIA_VOLUME_CONTOL_WIDGET_H

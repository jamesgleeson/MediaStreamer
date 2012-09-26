/*******************************************************
 *
 *	@author	: Turgut Mehdiyev
 *	@date	: 7/31/2012
 *	
 *	Copyright (c) Idrak Technology Transfer 2012
 *
 ******************************************************/

#ifndef MS_MEDIA_CONTROLS_WIDGET_H
#define MS_MEDIA_CONTROLS_WIDGET_H


#include <MSMediaPlayer_global.h>
#include <QtGui>
#include <MSMediaPlayer.h>
#include <assert.h>


namespace Idrak {
    namespace MediaStreamer {
        namespace MediaPlayer {
            class MSMediaControlsWidget;
        }
    }
}


/*!
 *  \brief The MSMediaControlsWidget class
 */
class MS_MEDIA_PLAYER_EXPORT MSMediaControlsWidget : public QWidget {

    Q_OBJECT

public:


    /*!
     * \brief The ControlButton enum
     */
    enum ControlButton {
        PlayPause,
        Stop,
        SeekToBegin,
        SeekToEnd
    };


    /*!
     *  \brief Class constructor
     *  \param player MSMediaPlayer object to manage
     *  \param parent widget's parent GUI widget (QWidget)
     */
    MSMediaControlsWidget( MSMediaPlayer *player, QWidget *parent = 0 );


    /*!
     * \brief setMediaPlayer
     * \param player
     */
    void setMediaPlayer( MSMediaPlayer *player );


    /*!
     *  \brief Get associated media player
     *  \return media player MSMediaPlayer
     *  \see MSMediaPlayer
     */
    MSMediaPlayer* getMediaPlayer() const;


    /*!
     *  \brief Class destructor
     */
    ~MSMediaControlsWidget();




protected:


    /*!
     *  Creates GUI of Widget.
     *  \brief Initizing Buttons and Decorate
     */
    virtual void setupUI();


    /*!
     *  Decorate buttons
     *  \brief Set button text, icon, style etc.
     *  \note For Developers: if you want to modify button interface
     *        you should extend class and override this method
     */
    virtual void decorateControlButtons();


    QPushButton *_btnPlayPause;
    QPushButton *_btnStop;
    QPushButton *_btnSeekToBegin;
    QPushButton *_btnSeekToEnd;

    QHBoxLayout *_btnsLayout;


public slots:

    /*!
     * \brief Handle Play/Pause button click event
     */
    void togglePlay();

    /*!
     * \brief Handle Stop button click event
     */
    void stop();

    /*!
     * \brief Handle SeekToBegin button click event
     */
    void seekToBegin();

    /*!
     * \brief Handle SeekToEnd button click event
     */
    void seekToEnd();

    /*!
     *  \brief Update widgets according to media players state
     *  \note Should call this method if media player's state changes outside
     */
    virtual void updateWidgetState( const Vlc::State &st );


signals:
    void togglePlayTriggered();
    void stopTriggered();
    void seekToBeginTriggered();
    void seekToEndTriggered();


private:
    MSMediaPlayer *_mediaPlayer;

};

#endif // MS_MEDIA_CONTROLS_WIDGET_H

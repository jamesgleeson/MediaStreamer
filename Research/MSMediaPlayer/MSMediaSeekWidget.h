/*******************************************************
 *
 *	@author	: Turgut Mehdiyev
 *	@date	: 8/1/2012
 *	
 *	Copyright (c) Idrak Technology Transfer 2012
 *
 ******************************************************/

#ifndef MS_MEDIA_SEEK_WIDGET_H
#define MS_MEDIA_SEEK_WIDGET_H

#include <assert.h>
#include <MSMediaPlayer_global.h>
#include <MSMediaPlayer.h>
#include <MSMediaSlider.h>
#include <QtGui>

namespace Idrak {
    namespace MediaStreamer {
        namespace MediaPlayer {
            class MSMediaSeekWidget;
        }
    }
}


/*!
 *  The MSMediaSeekWidget class
 *
 *  \brief The MSMediaSeekWidget class provides GUI for managing with media time
 *         It provides display of elapsed time and full time of the media.
 *
 *  \see MSMediaPlayer
 *  \see VlcMedia
 */
class MS_MEDIA_PLAYER_EXPORT MSMediaSeekWidget : public QWidget {

    Q_OBJECT

public:

    /*!
     *  \brief MSMediaSeekWidget constructor
     *  \param player media player (MSMediaPlayer *)
     *  \param parent seek widget's parent GUI widget (QWidget *)
     */
    MSMediaSeekWidget( MSMediaPlayer *player, QWidget *parent = 0 );


    /*!
     *  \brief MSMediaSeekWidget constructor
     *  \param parent seek widget's parent GUI widget (QWidget *)
     */
    explicit MSMediaSeekWidget( QWidget *parent = 0 );

    /*!
     *  \brief MSMediaSeekWidget destructor
     */
    ~MSMediaSeekWidget();

    /*!
     *  \brief Get auto-hide option.
     *  \return auto-hide option status, true if enabled (bool)
     */
    bool getAutoHide() const { return _autoHide; }

    /*!
     *  \brief Set auto-hide option.
     *         This option will automatically hide seek widget, if enabled.
     *
     *  \param autoHide new auto-hide option (bool)
     */
    void setAutoHide(const bool &autoHide) { _autoHide = autoHide; }

    /*!
     *  \brief Set media player if initialised without it
     *  \param player media player ( MSMediaPlayer * )
     */
    void setMediaPlayer( MSMediaPlayer *player );


protected:

    virtual void mouseMoveEvent( QMouseEvent *event );
    virtual void mousePressEvent( QMouseEvent* event );
    virtual void mouseReleaseEvent( QMouseEvent *event );


    /*!
     *  \brief Configures styles of widgets (styles etc)
     *  \note For developers: override this method for modifing Widgets style
     */
    virtual void decorateWidgets();

    MSMediaSlider *_wdgtSeek;
    QLabel *_lblTimeElapsed;
    QLabel *_lblTimeFull;
    QTimer *_timer;

public slots:

//    void setPosition( float, int64_t, int );

private slots:

    void changeTime();
    void changeTime(float time );
    void updateTime();

private:

    void initSeekWidget();

    MSMediaPlayer *_player;

    bool _autoHide;
};

#endif // MS_MEDIA_SEEK_WIDGET_H

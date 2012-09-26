/*******************************************************
 *
 *	@author	: Turgut Mehdiyev
 *	@date	: 8/2/2012
 *	
 *	Copyright (c) Idrak Technology Transfer 2012
 *
 ******************************************************/

#ifndef MS_MEDIA_VOLUME_SLIDER_H
#define MS_MEDIA_VOLUME_SLIDER_H

#include <MSMediaPlayer_global.h>
#include <assert.h>
#include <QtGui>
#include <vlc_common.h>
#include <vlc_aout_intf.h>

namespace Idrak {
    namespace MediaStream {
        namespace MediaPlayer  {
            class MSMediaVolumeSlider;
        }
    }
}


class MS_MEDIA_PLAYER_EXPORT MSMediaVolumeSlider : public QSlider {

    Q_OBJECT

public:


    /*!
     * \brief Class contructor
     * \param parent Parent widget
     * \param _i_step Increment value
     * \param b_softamp
     */
    MSMediaVolumeSlider(QWidget *_parent, int _i_step, bool b_softamp);



    /*!
     * \brief Get whether slider is muted
     * \return mute state
     */
    bool getMuted() const;

    /*!
     * \brief Get current volume
     * \return current volume
     */
    int getVolume() const;


public slots:

    /*!
     * \brief Set mute status
     */
    void setMuted( bool mute );

    /*!
     * \brief Set current volume
     * \param vol volume
     */
    void setVolume( int vol );

protected:

    const static int paddingL = 3;
    const static int paddingR = 2;

    virtual void paintEvent( QPaintEvent *);
    virtual void wheelEvent( QWheelEvent *event );
    virtual void mousePressEvent( QMouseEvent * );
    virtual void mouseMoveEvent( QMouseEvent * );
    virtual void mouseReleaseEvent( QMouseEvent * );

private:


    /*!
     *  \brief Whether we are currently sliding by user action
     */
    bool _isSliding;


    /*!
     *  \brief Whether the mouse is outside or inside the Widget
     */
    bool _isMouseOutside;


    /*!
     *  \brief Store the old Value before changing
     */
    int _oldValue;


    /*!
     *  How much do we increase each time we wheel
     */
    float _fStep;


    /*!
     * \brief Determines whether sound is muted
     */
    bool _isMuted;


    /*!
     * \brief Gradient pix storage
     */
    QPixmap pixGradient;


    /*!
     * \brief Muted Gradient pix storage
     */
    QPixmap pixGradient2;


    /*!
     * \brief OutLine pix storage
     */
    QPixmap pixOutside;

    std::string sliderGradient;

    /*!
     * \brief Function to modify the value from pixel x()
     * \param x
     */
    void changeValue( int x );


}; // class MSMediaVolumeSlider


#endif // MS_MEDIA_VOLUME_SLIDER_H

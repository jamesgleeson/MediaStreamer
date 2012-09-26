/*******************************************************
 *
 *	@author	: Turgut Mehdiyev
 *	@date	: 8/1/2012
 *	
 *	Copyright (c) Idrak Technology Transfer 2012
 *
 ******************************************************/

#ifndef MS_MEDIA_SLIDER_H
#define MS_MEDIA_SLIDER_H

#include <QtGui>
#include <MSSliderTimeTooltip.h>
#include <vlc_common.h>


namespace Idrak {
    namespace MediaStreamer {
        namespace MediaPlayer {
            class MSMediaSlider;
        }
    }
}


#define MSTRTIME_MAX_SIZE 22


class MSMediaSlider : public QSlider {

    Q_OBJECT
    Q_PROPERTY(qreal handleOpacity READ handleOpacity WRITE setHandleOpacity)

public:

    MSMediaSlider( Qt::Orientation q, QWidget *_parent = 0, bool _classic = false );
    ~MSMediaSlider();

protected:
    virtual void mouseMoveEvent( QMouseEvent *event );
    virtual void mousePressEvent( QMouseEvent* event );
    virtual void mouseReleaseEvent( QMouseEvent *event );
    virtual void wheelEvent( QWheelEvent *event );
    virtual void enterEvent( QEvent * );
    virtual void leaveEvent( QEvent * );
    virtual void hideEvent( QHideEvent * );

    virtual void paintEvent( QPaintEvent* event );
    virtual bool eventFilter( QObject *obj, QEvent *event );

    QSize handleSize() const;
    virtual QSize sizeHint() const;

    bool isAnimationRunning() const;
    qreal handleOpacity() const;
    void setHandleOpacity( qreal opacity );

private:

    /*!
     *  \brief Whether we are currently sliding by user action
     */
    bool isSliding;

    /*!
     *  \brief InputLength that can change
     */
    int inputLength;

    /*!
     *  \brief Used for the ToolTip
     */
    char psz_length[MSTRTIME_MAX_SIZE];

    QTimer *seekLimitTimer;

    MSSliderTimeTooltip *mTimeTooltip;

    float f_buffering;

    bool b_classic;


    /*!
     *  \brief Handle animation
     */
    qreal mHandleOpacity;
    QPropertyAnimation *animHandle;
    QTimer *hideHandleTimer;


public slots:

    /*!
     *  \brief Main public method, superseeding setValue. Disabling the slider when neeeded
     *
     *  \param pos Position, between 0 and 1. -1 disables the slider
     *  \param time Elapsed time. Unused
     *  \param legnth Duration time.
     */
    void setPosition( float, int64_t, int  );
    void updateBuffering( float buf );
    void hideHandle();

private slots:
    void startSeekTimer();
    void updatePos();

signals:
    void sliderDragged( float );
};

#endif // MS_MEDIA_SLIDER_H

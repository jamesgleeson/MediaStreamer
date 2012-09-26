#ifndef CUSTOMPLAYERWINDOW_H
#define CUSTOMPLAYERWINDOW_H

#include <assert.h>

#include <QWidget>
#include <QtGui>
#include <MSMediaPlayer.h>
#include <MSVideoWidget.h>
#include <MSMediaControlsWidget.h>
#include <MSMediaSeekWidget.h>
#include <MSMediaVolumeSlider.h>
#include <MSMediaVolumeContolWidget.h>

#include <QKeyEvent>

namespace Idrak {
    namespace MediaStreamer {
        namespace MediaPlayer {
            class MSMediaPlayer;
            class MSVideoWidget;
            class MSMediaControlsWidget;
            class MSMediaSeekWidget;
            class MSMediaVolumeSlider;
            class MSMediaVolumeContolWidget;
        }
    }
}


class CustomMediaPlayer : public QWidget {

    Q_OBJECT

public:
    CustomMediaPlayer();

    ~CustomMediaPlayer();

private:

    void setupUI();
    void setupVideoWidget();
    void setupControlPanel();

    MSMediaPlayer *_player;

    MSMediaControlsWidget *_mediaControlsWidget;
    MSMediaSeekWidget *_mediaSeekWidget;
    MSMediaVolumeSlider *_mediaVolumeSliderWidget;
    MSMediaVolumeContolWidget *_mediaVolumeControlWidget;


public slots:

};


#endif // CUSTOMPLAYERWINDOW_H

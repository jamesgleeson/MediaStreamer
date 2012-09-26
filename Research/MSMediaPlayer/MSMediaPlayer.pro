#=====================================================
#
#   @author      Turgut Mehdiyev
#   @date        24/07/2012
#
#   Copyright (c) Idrak Technology Transfer LLC 2012
#
#=====================================================

TARGET = MSMediaPlayer

TEMPLATE = lib shared

DEFINES += MS_MEDIA_PLAYER_LIBRARY

SOURCES += \
    MSMediaPlayer.cpp \
    MSVideoWidget.cpp \
    MSMediaControlsWidget.cpp \
    MSMediaSeekWidget.cpp \
    MSMediaSlider.cpp \
    MSSliderTimeTooltip.cpp \
    MSMediaVolumeSlider.cpp \
    MSMediaVolumeContolWidget.cpp \
    MSMediaPlayerException.cpp

HEADERS += \
    MSMediaPlayer_global.h \
    MSMediaPlayer.h \
    MSVideoWidget.h \
    MSMediaControlsWidget.h \
    MSMediaSeekWidget.h \
    MSMediaSlider.h \
    MSSliderTimeTooltip.h \
    MSMediaVolumeSlider.h \
    MSMediaVolumeContolWidget.h \
    MSMediaPlayerException.h

win32 {
    win32-g++ {

        INCLUDEPATH +=  . \
                        "..//..//3rdparty//vlc-qt-0.6.1//src" \
                        "..//..//3rdparty//vlc-qt-0.6.1//src//core" \
                        "..//..//3rdparty//vlc-2.0.0//sdk//include" \
                        "..//..//3rdparty//vlc-2.0.0//sdk//include//vlc//plugins"

        LIBS        +=  -L"..//..//3rdparty//vlc-qt-0.6.1//lib" \
                        -L"..//..//3rdparty//vlc-2.0.0//sdk//lib" \
                        -lvlc \
                        -lvlccore \
                        -lvlc-qt

        OBJECTS_DIR =   "build/win32/gcc/temp/objs"
        MOC_DIR     =   "build/win32/gcc/temp/mocs"
        DESTDIR     =   "../build/win32/gcc"

        CONFIG ( debug, debug|release ) {
            TARGET  =   MSMediaPlayerd

        }

        CONFIG ( release, debug|release ) {
            TARGET  =   MSMediaPlayer
        }
    }
}

unix {
    linux-g++ | linux-g++-64 {
        # TODO : Linux platform configuration
    }
}

RESOURCES += \
    toolbar.qrc

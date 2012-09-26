#=====================================================
#
#   @author      Turgut Mehdiyev
#   @date        24/07/2012
#
#   Copyright (c) Idrak Technology Transfer LLC 2012
#
#=====================================================

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

DEFINES += Qt4 DEBUG

TEMPLATE = app

CONFIG += console

TRANSLATIONS = \
    ms_ru.ts \
    ms_az.ts \
    ms_en.ts

SOURCES += \
    main.cpp \
    CustomPlayerWindow.cpp \
    dialog.cpp

HEADERS  += \
    CustomPlayerWindow.h \
    dialog.h

FORMS    += \
    dialog.ui


win32 {
    win32-g++ {

        INCLUDEPATH +=  . \
                        "..//..//3rdparty//vlc-qt-0.6.1//src" \
                        "..//..//3rdparty//vlc-qt-0.6.1//src//core" \
                        "..//..//3rdparty//vlc-2.0.0//sdk//include" \
                        "..//..//3rdparty//vlc-2.0.0//sdk//include//vlc//plugins" \
                        "..//MSMediaPlayer"

        LIBS        +=  -L"..//..//3rdparty//vlc-qt-0.6.1//lib" \
                        -L"..//..//3rdparty//vlc-2.0.0//sdk//lib" \
                        -L"..//build//win32//gcc" \
                        -lvlc \
                        -lvlccore \
                        -lvlc-qt \
                        -lMSMediaPlayer

        OBJECTS_DIR =   "build/win32/gcc/temp/objs"
        MOC_DIR     =   "build/win32/gcc/temp/mocs"
        DESTDIR     =   "../build/win32/gcc"

        CONFIG ( debug, debug|release ) {
            TARGET  =   MSMediaPlayerTestd

        }

        CONFIG ( release, debug|release ) {
            TARGET  =   MSMediaPlayerTest
        }
    }
}

unix {
    linux-g++ | linux-g++-64 {
        # TODO : Linux platform configuration
    }
}


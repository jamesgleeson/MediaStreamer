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

TEMPLATE = app

SOURCES += \
    main.cpp

HEADERS +=

FORMS   +=


win32 {
    win32-g++ {
        OBJECTS_DIR = "build/win32/gcc/temp/objs"
        MOC_DIR = "build/win32/gcc/temp/mocs"
        DESTDIR = "../build/win32/gcc"

        CONFIG ( debug, debug|release ) {
            TARGET = MSBroadcasterd
        }

        CONFIG ( release, debug|release ) {
            TARGET = MSBroadcaster
        }
    }
}

unix {
    linux-g++ | linux-g++-64 {
        # TODO : Linux platform configuration
    }
}

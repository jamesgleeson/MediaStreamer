#-------------------------------------------------
#
# Project created by QtCreator 2012-07-17T22:11:13
#
#-------------------------------------------------

QT       -= gui

TEMPLATE = lib

DEFINES += LIBCOMMON_LIBRARY

SOURCES += \
    painting.cpp

HEADERS += \
    LibCommon_global.h \
    painting.h

INCLUDEPATH += .

win32 {
    win32-g++ {

        OBJECTS_DIR =   "build/win32/gcc/temp/objs"
        MOC_DIR     =   "build/win32/gcc/temp/mocs"
        DESTDIR     =   "../build/win32/gcc"

        CONFIG ( debug, debug|release ) {
            TARGET = LibCommond
        }

        CONFIG ( release, debug|release ) {
            TARGET = LibCommon
        }
    }
}

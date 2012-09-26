#-------------------------------------------------
#
# Project created by QtCreator 2012-09-25T10:45:26
#
#-------------------------------------------------

QT       += core sql

QT       -= gui

TARGET = dbclass
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    DBManager.cpp

HEADERS += \
    DBManager.h

INCLUDEPATH += \
    ../../MSCommon \
    . \

LIBS += -L"../../build/win32/gcc/"
LIBS += -lMSCommon

win32 {
    win32-g++ {

        OBJECTS_DIR =   "build/win32/gcc/temp/objs"
        MOC_DIR     =   "build/win32/gcc/temp/mocs"
        DESTDIR     =   "../build/win32/gcc"

        CONFIG ( debug, debug|release ) {
            TARGET =  dbclass_d
        }

        CONFIG ( release, debug|release ) {

            TARGET =  dbclass
        }

    }
}

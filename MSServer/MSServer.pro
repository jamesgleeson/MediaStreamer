#=====================================================
#
#   @author      Turgut Mehdiyev
#   @date        24/07/2012
#
#   Copyright (c) Idrak Technology Transfer LLC 2012
#
#=====================================================

QT       += core gui network

CONFIG   += console

TEMPLATE = app

HEADERS += \
    network/MSTcpRequestHandler.h \
    network/MSTcpListener.h \
    network/MSTcpRequestHandlerTask.h \
    app/AppSettings.h

SOURCES += \
    main.cpp \
    network/MSTcpRequestHandlerTask.cpp \
    network/MSTcpRequestHandler.cpp \
    network/MSTcpListener.cpp \
    app/AppSettings.cpp


# Project's root path
PROJECT_PATH = D:/GitHub/MediaStreamer

INCLUDEPATH += \
    . \
    "$${PROJECT_PATH}/MSCommon"

win32 {
    win32-g++ {

        LIBS += -L"$${PROJECT_PATH}/build/win32/gcc"

        OBJECTS_DIR = "$${PROJECT_PATH}/build/win32/gcc/temp/objs"
        MOC_DIR = "$${PROJECT_PATH}/build/win32/gcc/temp/mocs"
        DESTDIR = "$${PROJECT_PATH}/build/win32/gcc"
        RCC_DIR = "$${PROJECT_PATH}/MSServer"

        CONFIG ( debug, debug|release ) {
            TARGET = MSServer_d
            LIBS += -lMSCommon_d
        }

        CONFIG ( release, debug|release ) {
            TARGET = MSServer
            LIBS += -lMSCommon
        }
    }
}

unix {
    linux-g++ | linux-g++-64 {
        # TODO : Linux platform configuration
    }
}



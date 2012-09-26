#=====================================================
#
#   @author      Turgut Mehdiyev
#   @date        24/07/2012
#
#   Copyright (c) Idrak Technology Transfer LLC 2012
#
#=====================================================

QT += core network sql

TEMPLATE = lib shared

DEFINES += MSCOMMON_LIBRARY

HEADERS += \
    export.h \
    network/TcpRequest.h \
    network/TcpResponse.h \
    network/TcpListener.h \
    network/TcpRequestHandler.h \
    network/TcpRequestSender.h \
    network/TcpRequestHandlerTask.h \
    utils/SleepSimulator.h \
    utils/Settings.h \
    Exception.hpp \
    network/Common.h \
    MSUser.h

SOURCES += \
    network/TcpRequest.cpp \
    network/TcpResponse.cpp \
    network/TcpListener.cpp \
    network/TcpRequestHandler.cpp \
    network/TcpRequestSender.cpp \
    network/TcpRequestHandlerTask.cpp \
    utils/SleepSimulator.cpp \
    utils/Settings.cpp \
    network/Common.cpp \
    MSUser.cpp



INCLUDEPATH += \
    . \

win32 {
    win32-g++ {

        OBJECTS_DIR = "build/win32/gcc/temp/objs"
        MOC_DIR = "build/win32/gcc/temp/mocs"
        DESTDIR = "../build/win32/gcc"

        CONFIG ( debug, debug|release ) {
            TARGET = MSCommon_d
        }

        CONFIG ( release, debug|release ) {
            TARGET = MSCommon
        }

    }
}

unix {
    linux-g++ | linux-g++-64 {
        # TODO : Linux platform configuration
    }
}


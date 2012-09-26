#=====================================================
#
#   @author      Turgut Mehdiyev
#   @date        24/07/2012
#
#   Copyright (c) Idrak Technology Transfer LLC 2012
#
#=====================================================

QT       += core gui network sql

TEMPLATE = app

TRANSLATIONS = translations/msadministrator_ru.ts

SOURCES += \
    main.cpp \
    network/MSTcpRequestSender.cpp \
    app/MSSettings.cpp \
    gui/MSUserLogin.cpp \
    gui/MSTabWidget.cpp \
    gui/MSRightWidget.cpp \
    gui/MSMainWindow.cpp \
    gui/MSLeftWidget.cpp \
    gui/users/MSUserWidget.cpp \
    gui/users/MSUserForm.cpp

HEADERS  += \
    network/MSTcpRequestSender.h \
    app/MSSettings.h \
    gui/MSUserLogin.h \
    gui/MSTabWidget.h \
    gui/MSRightWidget.h \
    gui/MSMainWindow.h \
    gui/MSLeftWidget.h \
    gui/users/MSUserWidget.h \
    gui/users/MSUserForm.h

RESOURCES += \
    resources.qrc

CONFIG += console

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
        RCC_DIR = "$${PROJECT_PATH}/MSAdministrator"

        CONFIG ( debug, debug|release ) {
            TARGET = MSAdministrator_d
            LIBS += -lMSCommon_d
        }

        CONFIG ( release, debug|release ) {
            TARGET = MSAdministrator
            LIBS += -lMSCommon
        }
    }
}

unix {
    linux-g++ | linux-g++-64 {
        # TODO : Linux platform configuration
    }
}

RESOURCES += \
    resources.qrc

FORMS +=

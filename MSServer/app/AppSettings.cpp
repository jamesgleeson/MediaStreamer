/*******************************************************
 *
 *	@author	: Turgut Mehdiyev
 *	@date	: 9/10/2012
 *	
 *	Copyright (c) Idrak Technology Transfer 2012
 *
 ******************************************************/

#include <app/AppSettings.h>

#include <QApplication>
#include <QDebug>

using namespace MSServer;


// predeclare singleton instance as NULL
AppSettings* AppSettings::_settings( NULL );


void AppSettings::init( void ) {
    QApplication::setOrganizationName( "Idrak Technology Transfer" );
    QApplication::setOrganizationDomain( "www.idrak.az" );
    QApplication::setApplicationName( "MSServer" );
    QApplication::setApplicationVersion( "1.0.0" );

    this->setValue( "SERVER_IP", "127.0.0.1" );
    this->setValue( "SERVER_PORT", quint16(4321) );
}


AppSettings *AppSettings::getInstance( void ) {
    if ( !_settings ) {
        _settings = new AppSettings();
    }
    return _settings;
}


AppSettings::~AppSettings( void ) {
    delete _settings;
}

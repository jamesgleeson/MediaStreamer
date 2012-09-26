/*******************************************************
 *
 *	@author	: Turgut Mehdiyev
 *	@date	: 9/10/2012
 *	
 *	Copyright (c) Idrak Technology Transfer 2012
 *
 ******************************************************/

#include <app/MSSettings.h>
#include <network/Common.h>

#include <QApplication>


using namespace MSAdministrator;


// predeclare singleton instance as NULL
MSSettings* MSSettings::_instance( NULL );


void MSSettings::init( void ) {

    QApplication::setOrganizationName( "Idrak Technology Transfer" );
    QApplication::setOrganizationDomain( "www.idrak.az" );
    QApplication::setApplicationName( "MSAdministrator" );
    QApplication::setApplicationVersion( "1.0.0" );

    // its temporary, should get from user input
    this->setValue( "SERVER_IP", "127.0.0.1" );
    this->setValue( "SERVER_PORT", quint16(4321) );

    this->setValue( "LOCAL_COMPUTER_IP", NetworkCommon::getIpAddress() );
}


MSSettings *MSSettings::getInstance( void ) {
    if ( !_instance ) {
        _instance = new MSSettings();
    }
    return _instance;
}


MSSettings::~MSSettings( void ) {
    delete _instance;
}

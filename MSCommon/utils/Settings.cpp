/*******************************************************
 *
 *	@author	: Turgut Mehdiyev
 *	@date	: 9/12/2012
 *	
 *	Copyright (c) Idrak Technology Transfer 2012
 *
 ******************************************************/

#include <utils/Settings.h>
#include <QSettings>

using namespace MSCommon;

QVariant Settings::getValue( const QString &key ) const {
    QSettings settings;
    return settings.value( key );
}


void Settings::setValue( const QString &key, const QVariant &value ) {
    QSettings settings;
    settings.setValue( key, value );
}

Settings::~Settings( void ) { }


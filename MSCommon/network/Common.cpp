/*******************************************************
 *
 *	@author	: Turgut Mehdiyev
 *	@date	: 9/24/2012
 *
 *	Copyright (c) Idrak Technology Transfer 2012
 *
 ******************************************************/

#include <network/Common.h>
#include <QNetworkInterface>

using namespace MSCommon;


NetworkCommon::NetworkCommon() {
}

QString NetworkCommon::getIpAddress() {

    QString ipAddress;

    QList<QHostAddress> ipAddressesList = QNetworkInterface::allAddresses();

    // use the first non-localhost IPv4 address
    for (int i = 0; i < ipAddressesList.size(); ++i) {
        if ( ipAddressesList.at(i) != QHostAddress::LocalHost &&
             ipAddressesList.at(i).toIPv4Address() ) {
             ipAddress = ipAddressesList.at(i).toString();
             break;
        }
    }

    // if we did not find one, use IPv4 localhost
    if ( ipAddress.isEmpty()) {
         ipAddress = QHostAddress(QHostAddress::LocalHost).toString();
    }

    return ipAddress;
}

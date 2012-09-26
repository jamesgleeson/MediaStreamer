/*******************************************************
 *
 *	@author	: Turgut Mehdiyev
 *	@date	: 9/10/2012
 *
 *	Copyright (c) Idrak Technology Transfer 2012
 *
 ******************************************************/

#include <network/TcpListener.h>
#include <network/TcpRequestHandler.h>
#include <Exception.hpp>

#include <QThreadPool>
#include <QDebug>

using namespace MSCommon;

TcpListener::~TcpListener( void ) {
}

void TcpListener::start(const QHostAddress &ip, quint16 port ) {
    if ( listen( ip, port ) ) {
        qDebug() << "Listening for incoming requests";
    }
    else {
        throw UnableToListenToNetworkConnections();
    }
}

/*******************************************************
 *
 *	@author	: Turgut Mehdiyev
 *	@date	: 9/10/2012
 *	
 *	Copyright (c) Idrak Technology Transfer 2012
 *
 ******************************************************/

#include <network/TcpRequestHandler.h>
#include <Exception.hpp>

#include <QThreadPool>
#include <QTcpSocket>

using namespace MSCommon;
using namespace std;

TcpRequestHandler::TcpRequestHandler( QObject *parent, int descriptor )
    : QObject( parent ) {

    // initialize socket
    if ( descriptor > 0 ) {
        _socket = new QTcpSocket();

        _socket->setSocketDescriptor( descriptor );

        _descriptor = descriptor;

    }
    else {
        throw InvalidSocketDescriptor();
    }
}

TcpRequestHandler::~TcpRequestHandler( void ) {
}

int TcpRequestHandler::getSocketDescriptor( void ) {
    return _descriptor;
}

/*******************************************************
 *
 *	@author	: Turgut Mehdiyev
 *	@date	: 9/12/2012
 *	
 *	Copyright (c) Idrak Technology Transfer 2012
 *
 ******************************************************/

#include <network/MSTcpRequestHandler.h>
#include <network/MSTcpRequestHandlerTask.h>
#include <network/TcpResponse.h>
#include <network/TcpRequest.h>
#include <Exception.hpp>

#include <QThreadPool>
#include <QTcpSocket>
#include <QDataStream>

using namespace MSServer;
using namespace MSCommon;

MSTcpRequestHandler::MSTcpRequestHandler( QObject *parent, int descriptor )
    : TcpRequestHandler( parent, descriptor ),
      _pkgSize( 0 ) {

    connect( _socket, SIGNAL(destroyed()), this, SLOT(socketDestroyed()) );
    connect( _socket, SIGNAL(disconnected()), this, SLOT(disconnected()) );
    connect( _socket, SIGNAL(readyRead()), this, SLOT(readyRead()) );

    isSocketConnected = true;
}


MSTcpRequestHandler::~MSTcpRequestHandler() {
}


void MSTcpRequestHandler::socketDestroyed(void) {
    emit connectionClosed( getSocketDescriptor() );
}


void MSTcpRequestHandler::disconnected( void ) {
    isSocketConnected = false;

    // queue socket for deletion
    _socket->deleteLater();
}


void MSTcpRequestHandler::readyRead( void ) {
    try {

        // read incoming request package
        if ( _socket->bytesAvailable() < (int)sizeof(quint32)) {
            return;
        }

        QDataStream in( _socket );
        in.setVersion(QDataStream::Qt_4_8);

        // get package size
        if ( _pkgSize == 0 ) {
            in >> _pkgSize;
        }

        // wait for full package
        if ( _socket->bytesAvailable() < _pkgSize ) {
            return;
        }

        // task handler should care about deleting this pointer
        TcpRequest *request = new TcpRequest();
        in >> *request;

        // reset package size
        _pkgSize = 0;

        MSTcpRequestHandlerTask *task = new MSTcpRequestHandlerTask( request );
        task->setAutoDelete( true );
        connect( task, SIGNAL( sendResponse(TcpResponse*) ), this, SLOT( sendResponse(TcpResponse*)), Qt::QueuedConnection );
        QThreadPool::globalInstance()->start( task );

    }
    catch (...) {
        throw UnableToReadNetworkRequest();
    }
}


void MSTcpRequestHandler::sendResponse( TcpResponse *response ) {
    try {
        QByteArray block;
        QDataStream out( &block, QIODevice::WriteOnly );
        out.setVersion( QDataStream::Qt_4_8 );

        out << (quint32)0;
        out << *response;
        out.device()->seek(0);
        out << (quint32)( block.size() - sizeof(quint32) );

        if (  isSocketConnected ) {
            _socket->write( block );
        }

        delete response;
    }
    catch ( ... ) {
        throw UnableToSendNetworkResponse();
    }
}

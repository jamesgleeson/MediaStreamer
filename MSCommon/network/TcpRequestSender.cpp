/*******************************************************
 *
 *	@author	: Turgut Mehdiyev
 *	@date	: 9/13/2012
 *	
 *	Copyright (c) Idrak Technology Transfer 2012
 *
 ******************************************************/

#include <network/TcpRequestSender.h>
#include <network/TcpRequest.h>
#include <network/TcpResponse.h>
#include <Exception.hpp>

#include <QThreadPool>
#include <QHostAddress>


using namespace MSCommon;


TcpRequestSender::TcpRequestSender( const QString &hostName, quint16 port,
                                    bool connectImmediately, int timeout, QObject *parent )
    : QObject( parent ) {

    // TODO: validate ip and port

    _isConnected = false;

    _hostName = hostName;
    _port = port;

    _socket = new QTcpSocket( this );

    connect( _socket, SIGNAL( connected() ), this, SLOT( connected() ) );
    connect( _socket, SIGNAL( disconnected() ), this, SLOT( disconnected() ) );

    connect( _socket, SIGNAL( error( QAbstractSocket::SocketError ) ),
             this, SLOT( handleError( QAbstractSocket::SocketError ) ) );

    if ( connectImmediately ) {
        connectToHost( hostName, port );
    }
}


TcpRequestSender::~TcpRequestSender() {
    _socket->close();
    _socket->deleteLater();
    qDebug()<< "TcpRequestSender destructed";
}


void TcpRequestSender::connectToHost( const QString &hostName, quint16 port, int timeout ) {

    try {
        if (_isConnected) {
            disconnectFromHost( timeout );

            if ( !_socket->waitForDisconnected(timeout) ) {
                throw NetworkConnectionTimedOut();
            }
        }

        if ( hostName.isEmpty() || port < 1 ) {
            throw new InvalidHostInformation();
        }

        _socket->connectToHost( hostName, port );

        if ( !_socket->waitForConnected(timeout) ) {
            throw NetworkConnectionTimedOut();
        }
        qDebug() << "Network connection established: IP = " << _socket->localAddress().toString();
    }
    catch (Exception &exc) {
        throw exc;
    }

}


void TcpRequestSender::disconnectFromHost( int timeout ) {
    _socket->disconnectFromHost();

    if ( !_socket->waitForDisconnected(timeout) ) {
        throw NetworkConnectionTimedOut();
    }
}


void TcpRequestSender::sendRequest( TcpRequest &request, TcpResponse &response, int timeout ) {
    try {
        if ( _isConnected ) {
            // Send request to receiver
            QByteArray block;
            QDataStream out( &block, QIODevice::WriteOnly );
            out.setVersion( QDataStream::Qt_4_8 );

            out << (quint32)0;
            out << request;
            out.device()->seek(0);
            out << (quint32)( block.size() - sizeof(quint32) ) ;

            qDebug() << "Request sent";
            _socket->write( block );

            readResponse( response, timeout );
        }
    }
    catch ( Exception &exc ) {
        qDebug() << "Exception thrown while writing";
        throw exc;
    }
}


void TcpRequestSender::readResponse( TcpResponse &response, int timeout ) {
    try {
        while ( _socket->bytesAvailable() < (int)sizeof(quint32) ) {
            if ( !_socket->waitForReadyRead( timeout ) ) {
                response.setSuccess(false);
                response.setErrMsg( _socket->errorString() );
                return;
            }
        }

        quint32 blockSize = 0;
        QDataStream in( _socket );
        in.setVersion( QDataStream::Qt_4_8 );

        in >> blockSize;

        while ( _socket->bytesAvailable() < blockSize ) {
            if ( !_socket->waitForReadyRead( timeout ) ) {
                response.setSuccess(false);
                response.setErrMsg( _socket->errorString() );
                return;
            }
        }

        in >> response;
    }
    catch (...) {
        qDebug() << "Exception thrown while reading";
        response.setSuccess(false);
        response.setErrMsg( UnknownNetworkError().errMsg() );
    }
}


void TcpRequestSender::handleError( QAbstractSocket::SocketError socketError ) {
    _isConnected = false;

    switch ( socketError ) {
        case QAbstractSocket::RemoteHostClosedError:
            throw RemoteHostClosedConnection();
        case QAbstractSocket::HostNotFoundError:
            throw HostNotFound();
        case QAbstractSocket::ConnectionRefusedError:
            throw NetworkConnectionRefused();
        default:
            throw Exception( _socket->errorString() );
    }
}


void TcpRequestSender::connected( void ) {
    _isConnected = true;
}


void TcpRequestSender::disconnected( void ) {
    _isConnected = false;
}


bool TcpRequestSender::isConnected( void ) {
    return _isConnected;
}


void TcpRequestSender::setHostName( const QString &hostName ) {
    _hostName = hostName;
}


QString TcpRequestSender::getHostName( void ) const {
    return _hostName;
}


void TcpRequestSender::setPort( quint16 port ) {
    _port = port;
}


quint16 TcpRequestSender::getPort( void ) const {
    return _port;
}



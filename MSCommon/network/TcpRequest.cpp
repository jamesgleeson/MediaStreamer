/*******************************************************
 *
 *	@author	: Turgut Mehdiyev
 *	@date	: 9/14/2012
 *	
 *	Copyright (c) Idrak Technology Transfer 2012
 *
 ******************************************************/

#include <network/TcpRequest.h>
#include <QDataStream>
#include <QDebug>

using namespace MSCommon;

TcpRequest::TcpRequest(void) {
}

TcpRequest::TcpRequest(
        quint32 userID, QString command, QByteArray data,
        QString senderIPAddress, QString receiverIPAddress,
        quint16 receiverPort)
    : _userID( userID ),
      _command( command ), _data( data ),
      _senderIpAddress( senderIPAddress ),
      _receiverIpAddress( receiverIPAddress ),
      _receiverPort( receiverPort ) {
}

TcpRequest::~TcpRequest(void) { }

QDataStream & operator << ( QDataStream &stream, const TcpRequest &request ) {
    stream.setVersion( QDataStream::Qt_4_8 );

    stream << request.getUserID()
           << request.getCommand()
           << request.getSenderIpAddress()
           << request.getReceiverIpAddress()
           << request.getReceiverPort()
           << request.getData();

    return stream;
}

QDataStream & operator >> ( QDataStream &stream, TcpRequest &request ) {

    stream.setVersion( QDataStream::Qt_4_8 );

    quint32 userID;
    QString command;
    QString senderIpAddress;
    QString receiverIpAddress;
    quint16 receiverPort;
    QByteArray data;

    stream >> userID
           >> command
           >> senderIpAddress
           >> receiverIpAddress
           >> receiverPort
           >> data;

    request = TcpRequest( userID, command, data, senderIpAddress, receiverIpAddress, receiverPort );

    return stream;
}

TcpRequest::TcpRequest( const TcpRequest &request ) {
    _userID = request.getUserID();
    _command = request.getCommand();
    _senderIpAddress = request.getSenderIpAddress();
    _receiverIpAddress = request.getReceiverIpAddress();
    _receiverPort = request.getReceiverPort();
    _data = request.getData();
}

TcpRequest & TcpRequest::operator = ( const TcpRequest &request ) {
    _userID = request.getUserID();
    _command = request.getCommand();
    _senderIpAddress = request.getSenderIpAddress();
    _receiverIpAddress = request.getReceiverIpAddress();
    _receiverPort = request.getReceiverPort();
    _data = request.getData();

    return *this;
}

bool TcpRequest::isValid( void ) {
    return
        !_command.isEmpty() &&
        !_senderIpAddress.isEmpty() &&
        !_receiverIpAddress.isEmpty() &&
        ( _receiverPort > 0 );
}

quint32 TcpRequest::getUserID( void ) const {
    return _userID;
}

void TcpRequest::setUserID( quint32 id ) {
    _userID = id;
}

QString TcpRequest::getCommand( void ) const {
    return _command;
}

void TcpRequest::setCommand( QString command ) {
    _command = command;
}

QByteArray TcpRequest::getData( void ) const{
    return _data;
}

void TcpRequest::setData(QByteArray data ) {
    _data = data;
}

QString TcpRequest::getSenderIpAddress( void ) const {
    return _senderIpAddress;
}

void TcpRequest::setSenderIpAddress( QString ip ) {
    _senderIpAddress = ip;
}

QString TcpRequest::getReceiverIpAddress( void ) const {
    return _receiverIpAddress;
}

void TcpRequest::setReceiverIpAddress( QString ip ) {
    _receiverIpAddress = ip;
}

quint16 TcpRequest::getReceiverPort( void ) const {
    return _receiverPort;
}

void TcpRequest::setReceiverPort( quint16 port ) {
    _receiverIpAddress = port;
}

/*******************************************************
 *
 *	@author	: Turgut Mehdiyev
 *	@date	: 9/14/2012
 *	
 *	Copyright (c) Idrak Technology Transfer 2012
 *
 ******************************************************/

#include <network/TcpResponse.h>
#include <QDataStream>
#include <QDebug>

using namespace MSCommon;

TcpResponse::TcpResponse(
        bool success, QString errMsg,
        quint16 errCode, quint32 userID,
        QString senderIPAddress, QString receiverIPAddress,
        quint16 receiverPort,
        QByteArray data,
        QObject *parent )
    : QObject( parent ),
      _success( success ), _errMsg( errMsg ), _errCode( errCode ),
      _userID( userID ),
      _senderIpAddress( senderIPAddress ),
      _receiverIpAddress( receiverIPAddress ),
      _receiverPort( receiverPort ), _data( data ) { }

TcpResponse::TcpResponse( const TcpResponse &response ) {
    _success = response.getSuccess();
    _errMsg = response.getErrMsg();
    _errCode = response.getErrCode();
    _userID = response.getUserID();
    _senderIpAddress = response.getSenderIpAddress();
    _receiverIpAddress = response.getReceiverIpAddress();
    _receiverPort = response.getReceiverPort();
    _data = response.getData();
}

TcpResponse::~TcpResponse(void) { }

QDataStream & operator << ( QDataStream &stream, const TcpResponse &response ) {
    stream.setVersion( QDataStream::Qt_4_8 );

    stream << response.getSuccess()
           << response.getErrMsg()
           << response.getErrCode()
           << response.getUserID()
           << response.getSenderIpAddress()
           << response.getReceiverIpAddress()
           << response.getReceiverPort()
           << response.getData();

    return stream;
}
QDataStream & operator >> ( QDataStream &stream, TcpResponse &response ) {
    stream.setVersion( QDataStream::Qt_4_8 );

    bool success;
    QString errMsg;
    quint16 errCode;
    quint32 userID;
    QString senderIpAddress;
    QString receiverIpAddress;
    quint16 receiverPort;
    QByteArray data;

    stream >> success
           >> errMsg
           >> errCode
           >> userID
           >> senderIpAddress
           >> receiverIpAddress
           >> receiverPort
           >> data;

    response = TcpResponse( success, errMsg, errCode,  userID, senderIpAddress, receiverIpAddress, receiverPort, data );

    return stream;
}

TcpResponse& TcpResponse::operator = ( const TcpResponse &response ) {
    _success = response.getSuccess();
    _errMsg = response.getErrMsg();
    _errCode = response.getErrCode();
    _userID = response.getUserID();
    _senderIpAddress = response.getSenderIpAddress();
    _receiverIpAddress = response.getReceiverIpAddress();
    _receiverPort = response.getReceiverPort();
    _data = response.getData();
    return *this;
}

bool TcpResponse::isValid( void ) {
    return
        !_senderIpAddress.isEmpty() &&
        !_receiverIpAddress.isEmpty() &&
        ( _receiverPort > 0 );
}

bool TcpResponse::getSuccess( void ) const {
    return _success;
}

void TcpResponse::setSuccess( bool success ) {
    _success = success;
}

QString TcpResponse::getErrMsg( void ) const {
    return _errMsg;
}

void TcpResponse::setErrMsg( QString errMsg ) {
    _errMsg = errMsg;
}

quint16 TcpResponse::getErrCode( void ) const {
    return _errCode;
}

void TcpResponse::setErrCode( quint16 errCode ) {
    _errCode = errCode;
}

quint32 TcpResponse::getUserID( void ) const {
    return _userID;
}

void TcpResponse::setUserID( quint32 id ) {
    _userID = id;
}

QByteArray TcpResponse::getData( void ) const{
    return _data;
}

void TcpResponse::setData( QByteArray data ) {
    _data = data;
}

QString TcpResponse::getSenderIpAddress( void ) const {
    return _senderIpAddress;
}

void TcpResponse::setSenderIpAddress( QString ip ) {
    _senderIpAddress = ip;
}

QString TcpResponse::getReceiverIpAddress( void ) const {
    return _receiverIpAddress;
}

void TcpResponse::setReceiverIpAddress( QString ip ) {
    _receiverIpAddress = ip;
}

quint16 TcpResponse::getReceiverPort( void ) const {
    return _receiverPort;
}

void TcpResponse::setReceiverPort( quint16 port ) {
    _receiverIpAddress = port;
}


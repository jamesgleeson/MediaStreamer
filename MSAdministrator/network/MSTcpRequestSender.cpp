#include <network/MSTcpRequestSender.h>
#include <app/MSSettings.h>
#include <Exception.hpp>
#include <network/TcpRequest.h>
#include <network/TcpResponse.h>

using namespace MSAdministrator;


// predeclare singleton instance as NULL
MSTcpRequestSender* MSTcpRequestSender::_instance( NULL );



MSTcpRequestSender::MSTcpRequestSender(
        const QString &hostName, quint16 port,
        bool connectImmediately, int timeout, QObject *parent)
    : TcpRequestSender( hostName, port, connectImmediately, timeout, parent ){
}

void MSTcpRequestSender::init() {
    try {
        QString hostIP = MSSettings::getInstance()->getValue("SERVER_IP").toString();
        int hostPort = MSSettings::getInstance()->getValue("SERVER_PORT").toInt();
        MSTcpRequestSender::getInstance()->connectToHost( hostIP, hostPort );
    }
    catch ( Exception &exc ) {
        qDebug() << exc.errMsg();
    }
}

void MSTcpRequestSender::sendRequest( TcpRequest &request, TcpResponse &response, int timeout) {

    // append sender and receiver details
    QString receiverIP = MSSettings::getInstance()->getValue("SERVER_IP").toString();
    int receiverPort = MSSettings::getInstance()->getValue("SERVER_IP").toInt();
    QString senderIP = MSSettings::getInstance()->getValue( "LOCAL_COMPUTER_IP" ).toString();

    request.setReceiverIpAddress( receiverIP );
    request.setReceiverPort( (quint16)receiverPort );
    request.setSenderIpAddress( senderIP );

    TcpRequestSender::sendRequest( request, response, timeout );
}


MSTcpRequestSender* MSTcpRequestSender::getInstance( void ) {
    if ( !_instance ) {
        _instance = new MSTcpRequestSender();
    }
    return _instance;
}


MSTcpRequestSender::~MSTcpRequestSender( void ) {
    delete _instance;
}

#include <network/MSTcpRequestSender.h>

using namespace MSServer;

MSTcpRequestSender::MSTcpRequestSender(
        const QString &hostName, quint16 port, bool connectImmediately, QObject *parent )
    : TcpRequestSender( hostName, port, connectImmediately, parent ){
}

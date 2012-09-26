/*******************************************************
 *
 *	@author	: Turgut Mehdiyev
 *	@date	: 9/15/2012
 *	
 *	Copyright (c) Idrak Technology Transfer 2012
 *
 ******************************************************/

#include <network/TcpRequestSenderTask.h>
#include <QTcpSocket>

#include <QDebug>

using namespace MSCommon;

TcpRequestSenderTask::TcpRequestSenderTask( QTcpSocket *socket, QObject *parent )
    : QObject( parent ) {
    _socket = socket;
}

void TcpRequestSenderTask::run( void ) {
    qDebug() << "New request handled";

    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_4_0);

    out << 10; // request

    _socket->write(block);

//    emit result( 10 );

}

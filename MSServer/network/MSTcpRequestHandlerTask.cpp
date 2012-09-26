/*******************************************************
 *
 *	@author	: Turgut Mehdiyev
 *	@date	: 9/13/2012
 *	
 *	Copyright (c) Idrak Technology Transfer 2012
 *
 ******************************************************/

#include <network/MSTcpRequestHandlerTask.h>
#include <network/TcpResponse.h>
#include <network/TcpRequest.h>

#include <utils/SleepSimulator.h>
#include <QDebug>

using namespace MSServer;

MSTcpRequestHandlerTask::MSTcpRequestHandlerTask( TcpRequest *request, QObject *parent)
    : TcpRequestHandlerTask( request, parent ) {
}

MSTcpRequestHandlerTask::~MSTcpRequestHandlerTask() {
}

void MSTcpRequestHandlerTask::run( void ) {
    SleepSimulator ss;
    ss.sleep(400);

    QByteArray data;
    data.resize( 1000000 ); // 1Mb

    TcpResponse *response = new TcpResponse();
    response->setSuccess( true );

    emit sendResponse( response );
}

/*******************************************************
 *
 *	@author	: Turgut Mehdiyev
 *	@date	: 9/12/2012
 *	
 *	Copyright (c) Idrak Technology Transfer 2012
 *
 ******************************************************/

#include <network/TcpRequestHandlerTask.h>
#include <network/TcpRequest.h>

#include <assert.h>

using namespace MSCommon;

TcpRequestHandlerTask::TcpRequestHandlerTask( TcpRequest* request, QObject *parent )
    : QObject( parent ) {
    _request = request;
}

TcpRequestHandlerTask::~TcpRequestHandlerTask() {
    delete _request;
}

/*******************************************************
 *
 *	@author	: Turgut Mehdiyev
 *	@date	: 9/12/2012
 *	
 *	Copyright (c) Idrak Technology Transfer 2012
 *
 ******************************************************/

#include <QApplication>
#include <network/MSTcpListener.h>
#include <network/MSTcpRequestHandler.h>

#include <QThreadPool>
#include <QDebug>

using namespace MSServer;
using namespace std;

MSTcpListener::MSTcpListener( quint16 maxThreadCount ) {
//  QThreadPool::globalInstance()->setMaxThreadCount( maxThreadCount );
    qDebug() << "Established working threads: " << QThreadPool::globalInstance()->maxThreadCount();
}

void MSTcpListener::incomingConnection( int descriptor ) {
    qDebug() << "New connection";
    MSTcpRequestHandler *handler = new MSTcpRequestHandler( 0, descriptor );

    QObject::connect( handler, SIGNAL( connectionClosed(int) ), this, SLOT( connectionClosed(int) ) );

    _handlers.push_back( handler );
}

void MSTcpListener::connectionClosed( int descriptor ) {

    // remove connection handler
    // object for specified descriptor
    vector<MSTcpRequestHandler*>::iterator it;
    for( it = _handlers.begin(); it != _handlers.end(); ) {
        if ( (*it)->getSocketDescriptor() == descriptor ) {
            (*it)->deleteLater();
            _handlers.erase(it);
        }
        else {
            ++it;
        }
    }
}

MSTcpListener::~MSTcpListener() {
    vector<MSTcpRequestHandler*>::const_iterator it;
    for( it = _handlers.begin(); it != _handlers.end(); it++ ) {
        (*it)->deleteLater();
    }
    _handlers.clear();
}

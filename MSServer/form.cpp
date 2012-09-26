/*******************************************************
 *
 *	@author	: Turgut Mehdiyev
 *	@date	: 9/15/2012
 *	
 *	Copyright (c) Idrak Technology Transfer 2012
 *
 ******************************************************/

#include "form.h"
#include "ui_form.h"

#include <network/TcpRequest.h>
#include <network/MSTcpRequestSender.h>

using namespace MSCommon;
using namespace MSServer;

Form::Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);

    connect( this->ui->pushButton, SIGNAL(clicked()), this, SLOT(btnClicked()));

    sender = new MSTcpRequestSender( "172.16.1.117" , 4321 );
}

Form::~Form()
{
    delete ui;
}

void Form::btnClicked()
{

    quint32 userID = 1;
    QString cmd = "cmd";
    QByteArray data;
    QString senderIP = "172.16.1.117";
    QString recIP = "172.16.1.117";
    quint16 port = 4321 ;

    TcpRequest request( userID, cmd, data, senderIP, recIP, port );


    QByteArray block;
    QDataStream out( &block, QIODevice::ReadWrite );
    out.setVersion( QDataStream::Qt_4_8 );

    out << request;

    qDebug() << request.getCommand();


    sender->sendRequest( request );

    sender->sendRequest( request );
}

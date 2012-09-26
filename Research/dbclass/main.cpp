/*******************************************************
 *
 *	@author	: Turgut Mehdiyev
 *	@date	: 9/25/2012
 *	
 *	Copyright (c) Idrak Technology Transfer 2012
 *
 ******************************************************/

#include <QCoreApplication>
#include <QSqlQuery>
#include <QDebug>

#include <Exception.hpp>

#include <db.h>

using namespace MSCommon;

int main(int argc, char *argv[]) {

    try {
        DBManager::getInstance()->init( "172.16.1.194", 3306, "MediaStreamer", "mssoft", "mssoftpwd!", true );

        bool res;

        QSqlQuery q1("SELECT * FROM Terminals");
        res = q1.exec();

        qDebug() << ( res ? "OK": "ERROR" );

        QSqlQuery q2("SELECT * FROM Terminals");
        res = q2.exec();

        qDebug() << ( res ? "OK": "ERROR" );

    }
    catch ( Exception &exc ) {
        qDebug() << exc.errMsg();
    }

    system("pause");
    return 0;
}

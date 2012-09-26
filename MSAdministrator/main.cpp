#include <QApplication>
#include <QTranslator>

#include <app/MSSettings.h>
#include <Exception.hpp>

#include <gui/MSMainWindow.h>

#include <network/MSTcpRequestSender.h>
#include <network/TcpRequest.h>
#include <network/TcpResponse.h>


#include <QDebug>

using namespace MSCommon;
using namespace MSAdministrator;

int main( int argc, char *argv[] ) {

    try {

        QApplication app(argc, argv);

//        MSSettings::getInstance()->init();

//        MSTcpRequestSender::getInstance()->init();

//        TcpRequest request( 10, QString("string"), QString("127.0.0.1"), QString("127.0.0.1"), 4321 );

//        TcpResponse response;
//        MSTcpRequestSender::getInstance()->sendRequest( request, response );

//        qDebug() << response.getSuccess() << "\t" << response.getErrMsg();

        // set application style
//        app.setStyle( new QCleanlooksStyle );

//        // configure language
//        QTranslator mst;
//        mst.load("msadministrator_ru.qm", ".");
//        app.installTranslator( &mst );

        MSMainWindow mw;
        mw.show();

        app.exec();
    }
    catch( Exception &exc ) {
        qDebug() << exc.errMsg();
    }

    system("pause");
    return 0;
}

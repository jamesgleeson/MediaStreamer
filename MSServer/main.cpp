#include <QApplication>
#include <app/AppSettings.h>
#include <network/MSTcpListener.h>

using namespace MSServer;
using namespace MSCommon;

int main(int argc, char *argv[]) {

    QApplication app(argc, argv);

    // initialize global settings
    AppSettings::getInstance()->init();

    // start listening to incoming requests
    MSTcpListener listener( 20 );
    listener.start(
        QHostAddress( AppSettings::getInstance()->getValue("SERVER_IP").toString()),
        AppSettings::getInstance()->getValue("SERVER_PORT").toInt()
    );

    return app.exec();
}

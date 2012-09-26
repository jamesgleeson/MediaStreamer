/**
 *
 **/

#include <QtCore/QCoreApplication>

#if defined(Qt5)
    #include <QtWidgets/QApplication>
#elif defined(Qt4)
    #include <QtGui/QApplication>
#endif

#include <QTranslator>
#include <CustomPlayerWindow.h>
#include <QString>

int main(int argc, char *argv[]) {

    QApplication app(argc, argv);

    QTranslator translator;
    translator.load( "ms_en" );

    app.installTranslator( &translator );

    CustomMediaPlayer win;
    win.showMaximized();


    return app.exec();
}

#ifndef MSMAINWINDOW_H
#define MSMAINWINDOW_H

#include <QCleanlooksStyle>
#include <QFile>
#include <QHBoxLayout>
#include <QMainWindow>
#include <QMenu>
#include <QMenuBar>
#include <QPushButton>

#include <gui/MSLeftWidget.h>
#include <gui/MSRightWidget.h>
#include <MSUser.h>

using namespace MSCommon;

namespace MSAdministrator {

    class MSMainWindow : public QMainWindow
    {
        Q_OBJECT

    public:
        explicit MSMainWindow(QWidget *parent = 0);
        ~MSMainWindow();
        MSLeftWidget *msLW;
        MSRightWidget *msRW;
        MSUser *msUSER;

    private:
        void setupMainView();
        void setupMainMenu();
        void setupLeftView();
        void setupRightView();
        void setupUI();

        QMenu *menuFile;
        QMenu *menuAbout;

        QMenuBar *menubar;

    };

}

#endif // MSMAINWINDOW_H

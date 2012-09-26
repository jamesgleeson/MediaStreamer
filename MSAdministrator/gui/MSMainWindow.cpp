#include <gui/MSMainWindow.h>

#include <QDebug>

using namespace MSAdministrator;

MSMainWindow::MSMainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    msUSER = new MSUser();
    msUSER->createConnection();

    msLW = new MSLeftWidget();
    msRW = new MSRightWidget();

    setupUI();

    QObject::connect(msLW->widgetLeftMenu, SIGNAL(currentRowChanged(int)), msRW->widgetRightTab, SLOT(setCurrentIndex(int)));
    QObject::connect(msLW->widgetLeftMenu, SIGNAL(currentRowChanged(int)), msRW, SLOT(activateWidget(int)));
}

MSMainWindow::~MSMainWindow() {

}

void MSMainWindow::setupMainMenu()
{
    menubar = new QMenuBar();

    menuFile = new QMenu();
    menuFile = menubar->addMenu(tr("File"));
    menuFile->addAction(QIcon(":/resources/icons/exit.png"), tr("Exit"));

    menuAbout = new QMenu();
    menuAbout = menubar->addMenu(tr("About"));
    menuAbout->addAction(QIcon(":/resources/icons/help.png"), tr("Help"));
    menuAbout->addAction(QIcon(":/resources/icons/about.png"), tr("About"));

    this->setMenuBar(menubar);
}

void MSMainWindow::setupMainView()
{
    QHBoxLayout *mainLayout = new QHBoxLayout();
    mainLayout->setMargin(0);

    QWidget *centralwidget = new QWidget();
    centralwidget->setLayout(mainLayout);

    setCentralWidget(centralwidget);
}

void MSMainWindow::setupLeftView()
{
    msLW->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Expanding);
    msLW->setFixedWidth(270);

    centralWidget()->layout()->addWidget(msLW);
}

void MSMainWindow::setupRightView()
{
    msRW->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    centralWidget()->layout()->addWidget(msRW);
}

void MSMainWindow::setupUI()
{
    setWindowTitle("Media Streamer");
    //showMaximized();
    setupMainMenu();
    setupMainView();
    setupLeftView();
    setupRightView();
}

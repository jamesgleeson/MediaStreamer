#include <gui/MSLeftWidget.h>

using namespace MSAdministrator;

MSLeftWidget::MSLeftWidget(QWidget *parent) :
    QWidget(parent)
{
    setupUI();
}

void MSLeftWidget::setupUI()
{
    QFile styleFile(":/resources/styles/leftwidget.qss" );
    styleFile.open(QFile::ReadOnly );
    QString style(styleFile.readAll());
    QHBoxLayout *layoutLeftMenu = new QHBoxLayout();

    widgetLeftMenu = new QListWidget();

    widgetLeftMenu->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    widgetLeftMenu->addItem(tr("Users"));
    widgetLeftMenu->addItem(tr("Broadcast points"));
    widgetLeftMenu->addItem(tr("Media files"));
    widgetLeftMenu->addItem(tr("Schedules"));
    widgetLeftMenu->addItem(tr("Extraordinary broadcasting"));
    widgetLeftMenu->addItem(tr("Speaker"));
    widgetLeftMenu->addItem(tr("Reports"));
    widgetLeftMenu->setStyleSheet(style);

    setLayout(layoutLeftMenu);
    layout()->addWidget(widgetLeftMenu);

}

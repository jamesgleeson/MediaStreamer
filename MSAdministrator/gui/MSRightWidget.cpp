#include <gui/MSRightWidget.h>

using namespace MSAdministrator;

MSRightWidget::MSRightWidget(QWidget *parent) :
    QWidget(parent)
{
    setupUI();
}

void MSRightWidget::setupUI()
{
    msUW = new MSUsersWidget();

    QHBoxLayout *layoutRightTab = new QHBoxLayout();

    widgetRightTab = new MSTabWidget();
    widgetRightTab->addTab(msUW, tr("0"));
    widgetRightTab->addTab(new QLabel("asd"), tr("1"));
    widgetRightTab->addTab(new QLabel("asd"), tr("2"));
    widgetRightTab->addTab(new QLabel("asd"), tr("3"));
    widgetRightTab->addTab(new QLabel("aassd"), tr("4"));
    widgetRightTab->addTab(new QLabel("asdasd"), tr("5"));
    widgetRightTab->addTab(new QLabel("asd"), tr("6"));
    widgetRightTab->addTab(new QLabel(""), tr("7"));
    widgetRightTab->setCurrentIndex(7);
    widgetRightTab->hideTabBar();

    setLayout(layoutRightTab);
    layout()->addWidget(widgetRightTab);
}

void MSRightWidget::activateWidget(int i)
{
    if(i == 0)
        msUW->activateUserWidget();
}

#include <gui/MSTabWidget.h>

using namespace MSAdministrator;

MSTabWidget::MSTabWidget(QTabWidget *parent) :
    QTabWidget(parent)
{

}

void MSTabWidget::hideTabBar()
{
    tabBar()->hide();
}

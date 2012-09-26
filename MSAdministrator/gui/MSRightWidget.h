#ifndef MSRIGHTWIDGET_H
#define MSRIGHTWIDGET_H

#include <QHBoxLayout>
#include <QLabel>
#include <QTabWidget>
#include <QTabBar>
#include <QWidget>

#include <gui/users/MSUserWidget.h>
#include <gui/MSTabWidget.h>

namespace MSAdministrator {

    class MSRightWidget : public QWidget
    {
        Q_OBJECT
    public:
        explicit MSRightWidget(QWidget *parent = 0);
        MSUsersWidget *msUW;
        MSTabWidget *widgetRightTab;

    private:
        void setupUI();

    signals:

    public slots:
        void activateWidget(int);
    };

}

#endif // MSRIGHTWIDGET_H

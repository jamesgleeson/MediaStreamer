#ifndef MSTABWIDGET_H
#define MSTABWIDGET_H

#include <QTabBar>
#include <QTabWidget>

namespace MSAdministrator {

    class MSTabWidget : public QTabWidget
    {
        Q_OBJECT
    public:
        explicit MSTabWidget(QTabWidget *parent = 0);
        void hideTabBar();

    signals:

    public slots:

    };

}

#endif // MSTABWIDGET_H

#ifndef MSLEFTWIDGET_H
#define MSLEFTWIDGET_H

#include <QFile>
#include <QHBoxLayout>
#include <QListWidget>
#include <QWidget>

namespace MSAdministrator {

    class MSLeftWidget : public QWidget
    {
        Q_OBJECT
    public:
        explicit MSLeftWidget(QWidget *parent = 0);
        QListWidget *widgetLeftMenu;
    
    private:
        void setupUI();

    signals:
    
    public slots:

    };

}

#endif // MSLEFTWIDGET_H

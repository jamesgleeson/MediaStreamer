#ifndef MSUSERLOGIN_H
#define MSUSERLOGIN_H

#include <QWidget>


class QWidget;
class QLineEdit;
class QPushButton;

namespace MSAdministrator {

    class MSUserLogin : public QWidget
    {
        Q_OBJECT
    public:
        explicit MSUserLogin(QWidget *parent = 0);

    private:
        void setupUI();

        QPushButton *btnDoLogin;
        QPushButton *btnStatus;

    signals:

    public slots:

    };

}

#endif // MSUSERLOGIN_H

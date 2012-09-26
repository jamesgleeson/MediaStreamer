#ifndef MSUSERFORM_H
#define MSUSERFORM_H

#include <QCheckBox>
#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>
#include <QMessageBox>
#include <QPushButton>
#include <QTextEdit>
#include <QWidget>
#include <QStringList>

#include <MSUser.h>

using namespace MSCommon;

namespace MSAdministrator {

    class MSUserForm : public QWidget
    {
        Q_OBJECT

    public:
        explicit MSUserForm(QWidget *parent = 0);
        ~MSUserForm();
        MSUser *msUSER;

    private:
        QLabel *lblUserName;
        QLabel *lblUserPass;
        QLabel *lblUserPassRepeat;
        QLabel *lblUserDescription;
        QLabel *lblUserPermission;

        QLineEdit *editUserName;
        QLineEdit *editUserPass;
        QLineEdit *editUserPassRepeat;
        QTextEdit *editUserDescription;

        QCheckBox *chkPermUsers;
        QCheckBox *chkPermTerminals;
        QCheckBox *chkPermMedia;
        QCheckBox *chkPermSchedules;
        QCheckBox *chkPermReports;

        QPushButton *btnUserSave;

        QStringList permissionList;

        bool validateUserForm();
        bool validatePermissionList(QStringList, QString);

    signals:
        void windowClosed(bool);

    public slots:
        void createPermissionList();
        void saveUser();
        void savePermission();

    private:

        /*!
         * \brief Setup UI controls
         */
        void setupUI();
    };

}

#endif // MSUSERFORM_H

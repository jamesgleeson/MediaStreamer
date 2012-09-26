#ifndef MSUSERSWIDGET_H
#define MSUSERSWIDGET_H

#include <QDebug>
#include <QHBoxLayout>
#include <QPushButton>
#include <QTreeView>
#include <QVBoxLayout>
#include <QWidget>

#include <MSUser.h>
#include <gui/users/MSUserForm.h>

using namespace MSCommon;

namespace MSAdministrator {

    class MSUsersWidget : public QWidget
    {
        Q_OBJECT
    public:
        explicit MSUsersWidget(QWidget *parent = 0);
        MSUserForm *msUF;
        MSUser *msUSER;

    private:
        QPushButton *btnUserAdd;
        QPushButton *btnUserEdit;
        QPushButton *btnUserRemove;
        QPushButton *btnUserRefresh;

        QTreeView *viewUserList;
        QWidget *widgetUserButton;

        bool isActive;
        int usrId;

        void setupUI();

    public slots:
        void btnUserAddClicked();
        void btnUserEditClicked();
        void btnUserRemoveClicked();
        void btnUserRefreshClicked();
        void activateUserWidget();
        void itemClicked(QModelIndex);
        void refreshUserList(bool);
        void refreshButtons(bool);
    };

}

#endif // MSUSERSWIDGET_H

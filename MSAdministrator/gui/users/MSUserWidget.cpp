#include <gui/users/MSUserWidget.h>

using namespace MSAdministrator;

MSUsersWidget::MSUsersWidget(QWidget *parent) :
    QWidget(parent)
{
    isActive = false;
}

void MSUsersWidget::setupUI()
{
//    QVBoxLayout *layoutUserMain = new QVBoxLayout();
//    QHBoxLayout *layoutUserButton = new QHBoxLayout();

//    /* Creating buttons for controlling users  */
//    widgetUserButton = new QWidget();
//    widgetUserButton->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
//    widgetUserButton->setFixedHeight(40);
//    widgetUserButton->setLayout(layoutUserButton);

//    btnUserAdd = new QPushButton(QIcon(":/resources/icons/user_add.png"), tr("New"));
//    btnUserAdd->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
//    btnUserAdd->setFixedHeight(30);
//    btnUserEdit = new QPushButton(QIcon(":/resources/icons/user_edit.png"), tr("Edit"));
//    btnUserEdit->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
//    btnUserEdit->setFixedHeight(30);
//    btnUserEdit->setEnabled(false);
//    btnUserRemove = new QPushButton(QIcon(":/resources/icons/user_remove.png"), tr("Remove"));
//    btnUserRemove->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
//    btnUserRemove->setFixedHeight(30);
//    btnUserRemove->setEnabled(false);
//    btnUserRefresh = new QPushButton(QIcon(":/resources/icons/user_refresh.png"), tr("Refresh"));
//    btnUserRefresh->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
//    btnUserRefresh->setFixedHeight(30);

//    layoutUserButton->addWidget(btnUserAdd, 0, Qt::AlignLeft);
//    layoutUserButton->addWidget(btnUserEdit, 0, Qt::AlignLeft);
//    layoutUserButton->addWidget(btnUserRemove, 0, Qt::AlignLeft);
//    layoutUserButton->addWidget(btnUserRefresh, 1, Qt::AlignRight);

//    /* Creating users list widget */
////    msUSER->getUserList();

////    viewUserList = new QTreeView();
////    viewUserList->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
////    viewUserList->setModel(msUSER->modelUserList);
////    viewUserList->setColumnHidden(0, true);

//    setLayout(layoutUserMain);
//    layout()->addWidget(widgetUserButton);
//    layout()->addWidget(viewUserList);

//    isActive = true;
}

void MSUsersWidget::activateUserWidget()
{
//    if(!isActive)
//    {
//        msUSER = new MSUser;
//        setupUI();

//        connect(btnUserAdd, SIGNAL(clicked()), this, SLOT(btnUserAddClicked()));
//        connect(btnUserRefresh, SIGNAL(clicked()), this, SLOT(btnUserRefreshClicked()));
//        connect(btnUserRemove, SIGNAL(clicked()), this, SLOT(btnUserRemoveClicked()));
//        connect(viewUserList, SIGNAL(clicked(QModelIndex)), this, SLOT(itemClicked(QModelIndex)));
//    }
}

void MSUsersWidget::btnUserAddClicked()
{
    msUF = new MSUserForm();
    msUF->setWindowModality(Qt::ApplicationModal);
    msUF->show();
    connect(msUF, SIGNAL(windowClosed(bool)), this, SLOT(refreshUserList(bool)));
    msUSER->cmdText = "save";
    qDebug(msUSER->cmdText.toLocal8Bit());
}

void MSUsersWidget::btnUserEditClicked()
{

}

void MSUsersWidget::btnUserRemoveClicked()
{
    msUSER->removeUser(usrId);
    msUSER->removeUserPremission(usrId);
    refreshButtons(false);
    refreshUserList(true);
}

void MSUsersWidget::btnUserRefreshClicked()
{
    viewUserList->clearSelection();
    refreshButtons(false);
    refreshUserList(true);
}

void MSUsersWidget::refreshButtons(bool b)
{
    btnUserEdit->setEnabled(b);
    btnUserRemove->setEnabled(b);
}

void MSUsersWidget::itemClicked(QModelIndex mi)
{
    usrId = viewUserList->model()->data(mi.model()->index(mi.row(), 0)).toInt();
    refreshButtons(true);
}

void MSUsersWidget::refreshUserList(bool b)
{
//    if(b)
//    {
//        msUSER->getUserList();
//        viewUserList->setModel(msUSER->modelUserList);
//    }
}

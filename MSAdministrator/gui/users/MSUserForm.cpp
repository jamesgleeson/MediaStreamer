#include <gui/users/MSUserForm.h>

using namespace MSAdministrator;

MSUserForm::MSUserForm(QWidget *parent) : QWidget(parent)
{
    setupUI();

    setWindowTitle(tr("User"));
    setWindowIcon(QIcon(":/resources/icons/users.png"));
}

MSUserForm::~MSUserForm()
{

}

void MSUserForm::setupUI()
{

    QGridLayout *userFormLayout = new QGridLayout();

    lblUserName = new QLabel(tr("Username:"));
    lblUserPass = new QLabel(tr("Password:"));
    lblUserPassRepeat = new QLabel(tr("Repeat password:"));
    lblUserDescription = new QLabel(tr("Description:"));
    lblUserPermission = new QLabel(tr("Permissions:"));

    editUserName = new QLineEdit();
    editUserPass = new QLineEdit();
    editUserPassRepeat = new QLineEdit();
    editUserDescription = new QTextEdit();

    userFormLayout->addWidget(lblUserName, 0, 0);
    userFormLayout->addWidget(lblUserPass, 1, 0);
    userFormLayout->addWidget(lblUserPassRepeat, 2, 0);
    userFormLayout->addWidget(lblUserDescription, 3, 0);
    userFormLayout->addWidget(lblUserPermission, 4, 0);

    userFormLayout->addWidget(editUserName, 0, 1);
    userFormLayout->addWidget(editUserPass, 1, 1);
    userFormLayout->addWidget(editUserPassRepeat, 2, 1);
    userFormLayout->addWidget(editUserDescription, 3, 1);

    chkPermUsers = new QCheckBox(tr("User management"));
    chkPermUsers->setProperty("value", 1);
    chkPermTerminals = new QCheckBox(tr("Terminal management"));
    chkPermTerminals->setProperty("value", 2);
    chkPermMedia = new QCheckBox(tr("Media management"));
    chkPermMedia->setProperty("value", 3);
    chkPermSchedules = new QCheckBox(tr("Schedule management"));
    chkPermSchedules->setProperty("value", 4);
    chkPermReports = new QCheckBox(tr("Report management"));
    chkPermReports->setProperty("value", 5);

    userFormLayout->addWidget(chkPermUsers, 4, 1);
    userFormLayout->addWidget(chkPermTerminals, 5, 1);
    userFormLayout->addWidget(chkPermMedia, 6, 1);
    userFormLayout->addWidget(chkPermSchedules, 7, 1);
    userFormLayout->addWidget(chkPermReports, 8, 1);

    btnUserSave = new QPushButton(QIcon(":/resources/icons/save.png"), tr("Save"));
    btnUserSave->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    btnUserSave->setFixedSize(100,30);

    userFormLayout->addWidget(btnUserSave, 9, 1, Qt::AlignRight);

    setLayout(userFormLayout);

    QObject::connect(btnUserSave, SIGNAL(clicked()), this, SLOT(saveUser()));
    QObject::connect(btnUserSave, SIGNAL(clicked()), this, SLOT(savePermission()));

    QObject::connect(chkPermUsers, SIGNAL(clicked()), this, SLOT(createPermissionList()));
    QObject::connect(chkPermTerminals, SIGNAL(clicked()), this, SLOT(createPermissionList()));
    QObject::connect(chkPermMedia, SIGNAL(clicked()), this, SLOT(createPermissionList()));
    QObject::connect(chkPermSchedules, SIGNAL(clicked()), this, SLOT(createPermissionList()));
    QObject::connect(chkPermReports, SIGNAL(clicked()), this, SLOT(createPermissionList()));
}

bool MSUserForm::validateUserForm()
{
    if(editUserName->text().isEmpty() || editUserPass->text().isEmpty() || editUserPassRepeat->text().isEmpty())
    {
        QMessageBox::critical(0, tr("Error"), tr("Form is empty"), QMessageBox::Cancel);
        return false;
    }

    if(editUserPass->text() != editUserPassRepeat->text())
    {
        QMessageBox::critical(0, tr("Error"), tr("Passwords does not matches"), QMessageBox::Cancel);
        return false;
    }

    if(msUSER->checkUserName(editUserName->text()))
    {
        QMessageBox::critical(0, tr("Error"), tr("The user already exists"), QMessageBox::Cancel);
        return false;
    }

    return true;
}

bool MSUserForm::validatePermissionList(QStringList sl, QString s)
{
    for (QStringList::iterator it = sl.begin(); it != sl.end(); it++)
    {
        if(*it == s)
            return false;
    }

    return true;
}

void MSUserForm::saveUser()
{
    if(this->validateUserForm())
    {
        msUSER->saveUser(editUserName->text(), editUserPass->text(), QDateTime::currentDateTime(), editUserDescription->toPlainText());
        close();
        emit windowClosed(true);
    }
}

void MSUserForm::savePermission()
{
    msUSER->saveUserPermissions();
    int usrId = msUSER->getLastUserId();
    for (QStringList::iterator it = permissionList.begin(); it != permissionList.end(); ++it)
    {
        QString usrPrmId = *it;
        msUSER->updateUserPermission(usrId, usrPrmId.toInt());
    }
}

void MSUserForm::createPermissionList()
{
    if(chkPermUsers->isChecked() && this->validatePermissionList(permissionList, chkPermUsers->property("value").toString()))
        permissionList.append(chkPermUsers->property("value").toString().toLocal8Bit());
    else if(!chkPermUsers->isChecked())
        permissionList.removeAt(permissionList.indexOf(chkPermUsers->property("value").toString().toLocal8Bit()));

    if(chkPermTerminals->isChecked() && this->validatePermissionList(permissionList, chkPermTerminals->property("value").toString()))
        permissionList.append(chkPermTerminals->property("value").toString().toLocal8Bit());
    else if(!chkPermTerminals->isChecked())
        permissionList.removeAt(permissionList.indexOf(chkPermTerminals->property("value").toString().toLocal8Bit()));

    if(chkPermMedia->isChecked() && this->validatePermissionList(permissionList, chkPermMedia->property("value").toString()))
        permissionList.append(chkPermMedia->property("value").toString().toLocal8Bit());
    else if(!chkPermMedia->isChecked())
        permissionList.removeAt(permissionList.indexOf(chkPermMedia->property("value").toString().toLocal8Bit()));

    if(chkPermSchedules->isChecked() && this->validatePermissionList(permissionList, chkPermSchedules->property("value").toString()))
        permissionList.append(chkPermSchedules->property("value").toString().toLocal8Bit());
    else if(!chkPermSchedules->isChecked())
        permissionList.removeAt(permissionList.indexOf(chkPermSchedules->property("value").toString().toLocal8Bit()));

    if(chkPermReports->isChecked() && this->validatePermissionList(permissionList, chkPermReports->property("value").toString()))
        permissionList.append(chkPermReports->property("value").toString().toLocal8Bit());
    else if(!chkPermReports->isChecked())
        permissionList.removeAt(permissionList.indexOf(chkPermReports->property("value").toString().toLocal8Bit()));
}



#include <QCryptographicHash>
#include <QDebug>
#include <QMessageBox>
#include <QtSql>
#include <MSUser.h>

using namespace MSCommon;

MSUser::MSUser()
{

}

bool MSUser::createConnection()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");

    db.setHostName("172.16.1.194");
    db.setPort(3306);
    db.setDatabaseName("MediaStreamer");
    db.setUserName("mssoft");
    db.setPassword("mssoftpwd!");

    qDebug() << db.lastError().text();

    if (!db.open())
    {
        QMessageBox::critical(0, qApp->tr("Error"), qApp->tr("Cannot open database"), QMessageBox::Cancel);
        return false;
    }

    return true;
}

bool MSUser::checkUserName(QString usrName)
{
    QSqlQuery cuQuery;
    cuQuery.prepare(" SELECT * FROM Users WHERE USR_NAME = ? ");
    cuQuery.addBindValue(usrName);
    cuQuery.exec();

    if(cuQuery.size() > 0)
        return true;

    return false;
}

void MSUser::saveUser(QString usrName, QString usrPass, QDateTime usrRegDate, QString usrDesc)
{
    QSqlQuery suQuery;
    suQuery.prepare(" INSERT INTO Users(USR_NAME, USR_PWD, USR_REG_DT, USR_DESC) VALUES(?, ?, ?, ?) ");
    suQuery.addBindValue(usrName);
    suQuery.addBindValue(QString(QCryptographicHash::hash(usrPass.toLocal8Bit(), QCryptographicHash::Md5).toHex()));
    suQuery.addBindValue(usrRegDate);
    suQuery.addBindValue(usrDesc);
    suQuery.exec();
    suQuery.finish();
}

void MSUser::updateUser(QString usrName, QString usrPass, QString usrDesc, int usrId)
{
    QSqlQuery uuQuery;
    uuQuery.prepare(" UPDATE Users SET USR_NAME = ?, USR_PWD = ?, USR_DESC = ? WHERE USR_ID = ? ");
    uuQuery.addBindValue(usrName);
    uuQuery.addBindValue(QString(QCryptographicHash::hash(usrPass.toLocal8Bit(), QCryptographicHash::Md5).toHex()));
    uuQuery.addBindValue(usrDesc);
    uuQuery.addBindValue(usrId);
    uuQuery.exec();
    uuQuery.finish();
}

void MSUser::saveUserPermissions()
{
    int usrId = getLastUserId();
    QSqlQuery gpQuery;
    gpQuery.exec(" SELECT PRM_ID FROM Permissions ORDER BY PRM_ID ASC ");

    QSqlRecord gpRecord = gpQuery.record();
    while(gpQuery.next())
    {
        QSqlQuery ipQuery;
        ipQuery.prepare(" INSERT INTO UserPermissions(USR_PRM_VALUE, USR_ID, PRM_ID) VALUES('0', ?, ?) ");
        ipQuery.addBindValue(usrId);
        ipQuery.addBindValue(gpQuery.value(gpRecord.indexOf("PRM_ID")).toInt());
        ipQuery.exec();
        ipQuery.finish();
    }
    gpQuery.finish();
}

void MSUser::updateUserPermission(int usrId, int usrPrmId)
{
    QSqlQuery spQuery;
    spQuery.prepare(" UPDATE UserPermissions SET USR_PRM_VALUE = '1' WHERE USR_ID = ? AND PRM_ID = ? ");
    spQuery.addBindValue(usrId);
    spQuery.addBindValue(usrPrmId);
    spQuery.exec();
    spQuery.finish();
}

void MSUser::getUserList()
{
    modelUserList = new QSqlQueryModel();
    modelUserList->setQuery(" SELECT USR_ID, USR_NAME, USR_LAST_LOGIN_DT, USR_LAST_LOGOUT_DT, USR_DESC FROM Users ORDER BY USR_ID ASC ");
    modelUserList->setHeaderData(0, Qt::Horizontal, tr("ID"));
    modelUserList->setHeaderData(1, Qt::Horizontal, tr("User name"));
    modelUserList->setHeaderData(2, Qt::Horizontal, tr("Last login date"));
    modelUserList->setHeaderData(3, Qt::Horizontal, tr("Last logout date"));
    modelUserList->setHeaderData(4, Qt::Horizontal, tr("Description"));

    if(modelUserList->lastError().isValid())
        qDebug() << modelUserList->lastError();
}

void MSUser::getUserById(int usrId)
{
    QSqlQuery guQuery;
    guQuery.prepare(" SELECT USR_NAME, USR_DESC FROM Users WHERE USR_ID = ? ");
    guQuery.addBindValue(usrId);
    guQuery.exec();
    guQuery.finish();
}

void MSUser::getUserPermissionById(int usrId)
{
    QSqlQuery gpQuery;
    gpQuery.prepare(" SELECT PRM_ID FROM UserPermissions WHERE USR_ID = ? ");
    gpQuery.addBindValue(usrId);
    gpQuery.exec();
    gpQuery.finish();
}

void MSUser::removeUser(int usrId)
{
    QSqlQuery ruQuery;
    ruQuery.prepare(" DELETE FROM Users WHERE USR_ID = ? ");
    ruQuery.addBindValue(usrId);
    ruQuery.exec();
    ruQuery.finish();
}

void MSUser::removeUserPremission(int usrId)
{
    QSqlQuery rpQuery;
    rpQuery.prepare(" DELETE FROM UserPermissions WHERE USR_ID = ? ");
    rpQuery.addBindValue(usrId);
    rpQuery.exec();
    rpQuery.finish();
}

int MSUser::getLastUserId()
{
    int i;
    QSqlQuery uQuery;
    uQuery.exec(" SELECT USR_ID FROM Users ORDER BY USR_ID DESC LIMIT 0,1 ");

    QSqlRecord record = uQuery.record();
    while (uQuery.next())
    {
        i = uQuery.value(record.indexOf("USR_ID")).toInt();
    }

    uQuery.finish();

    return i;
}


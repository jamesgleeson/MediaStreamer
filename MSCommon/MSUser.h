#ifndef MSUSER_H
#define MSUSER_H

#include <export.h>
#include <QObject>
#include <QSqlQueryModel>
#include <QDateTime>

class QString;

namespace MSCommon {

    /*!
     * \brief MSUser class provides functionality for
     *        controlling users
     */
    class MSCOMMONSHARED_EXPORT MSUser : public QObject
    {
        Q_OBJECT
    public:
        MSUser();
        QSqlQueryModel *modelUserList;

        bool createConnection();
        int getLastUserId();
        QString cmdText;

        /*!
         * \brief Save user's informations
         * \param usrName User's name
         * \param usrPass User's password
         * \param usrRegDate User's registration date
         * \param usrDesc Other information about user
         *
         */
        void saveUser(QString usrName, QString usrPass, QDateTime usrRegDate, QString usrDesc);

        /*!
         * \brief Save user permissions
         *
         */
        void saveUserPermissions();

        /*!
         * \brief Update user informations
         * \param usrName User's name
         * \param usrPass User's password
         * \param usrDesc Other information about user
         *
         */
        void updateUser(QString usrName, QString usrPass, QString usrDesc, int usrId);

        /*!
         * \brief Update user premissions
         * \param usrId User id
         * \param usrPermId Permission id
         *
         */
        void updateUserPermission(int usrId, int usrPermId);

        /*!
         * \brief Remove user
         * \param usrId User id
         *
         */
        void removeUser(int usrId);

        /*!
         * \brief Remove user permission
         * \param usrId User id
         *
         */
        void removeUserPremission(int usrId);

        /*!
         * \brief Get user's information by id
         * \param usrId User id
         *
         */
        void getUserById(int usrId);

        /*!
         * \brief Get user's permissions by id
         * \param usrId User id
         *
         */
        void getUserPermissionById(int usrId);

        /*!
         * \brief Get users' list
         *
         */
        void getUserList();

        /*!
         * \brief Check if user exists
         * \param usrName User name
         *
         */
        bool checkUserName(QString usrName);

    public slots:

    };

}

#endif // MSUSER_H

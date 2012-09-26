/*******************************************************
 *
 *	@author	: Turgut Mehdiyev
 *	@date	: 9/14/2012
 *	
 *	Copyright (c) Idrak Technology Transfer 2012
 *
 ******************************************************/

#ifndef MS_COMMON_TCP_RESPONCE_H
#define MS_COMMON_TCP_RESPONCE_H

#include <export.h>
#include <QObject>

class QDataStream;
class QString;

namespace MSCommon {

    /*!
     * \brief The TcpResponse class
     */
    class MSCOMMONSHARED_EXPORT TcpResponse : public QObject {

    public:

        /*!
         * \brief Class constructor
         * \param userID user identificator
         * \param data
         * \param senderIPAddress
         * \param receiverIPAddress
         * \param recieverPort
         * \param parent
         */
        TcpResponse(
            bool success = false,
            QString errMsg = "",
            quint16 errCode = 0,
            quint32 userID = 0,
            QString senderIPAddress = "",
            QString receiverIPAddress = "",
            quint16 recieverPort = 0,
            QByteArray data = QByteArray(),
            QObject *parent = 0
        );

        /*!
         * \brief Copy constructor
         */
        TcpResponse( const TcpResponse& response );

        /*!
         * \brief Destructor
         */
        virtual ~TcpResponse(void);

        /*!
         * \brief Assignment operator overloading
         * \param response
         * \return
         */
        TcpResponse & operator = ( const TcpResponse& response );

        quint32 getUserID( void ) const;
        void setUserID( quint32 id );

        QByteArray getData( void ) const;
        void setData( QByteArray data );

        QString getSenderIpAddress( void ) const;
        void setSenderIpAddress( QString ip );

        QString getReceiverIpAddress( void ) const;
        void setReceiverIpAddress( QString ip );

        quint16 getSenderPort( void ) const;
        void setSenderPort( quint16 port );

        quint16 getReceiverPort( void ) const;
        void setReceiverPort( quint16 port );

        bool getSuccess( void ) const;
        void setSuccess( bool success );

        QString getErrMsg( void ) const;
        void setErrMsg(QString errMsg );

        quint16 getErrCode( void ) const;
        void setErrCode( quint16 code );

        /*!
         * \brief Determines whether response object is valid
         * \return true -> if all input is valid
         *         false -> if any input is not valid
         */
        bool isValid( void );

    protected:
        bool _success;
        QString _errMsg;
        quint16 _errCode;
        quint32 _userID;
        QString _senderIpAddress;
        QString _receiverIpAddress;
        quint16 _receiverPort;
        QByteArray _data;

    private:
        bool _isValid;

    }; // class TcpResponse

} // namespace MSCommon


/*!
 * \brief Implementation of TcpResponse object serialization
 */
MSCOMMONSHARED_EXPORT QDataStream & operator << ( QDataStream &stream, const MSCommon::TcpResponse &response );
MSCOMMONSHARED_EXPORT QDataStream & operator >> ( QDataStream &stream, MSCommon::TcpResponse &response );

#endif // MS_COMMON_TCP_RESPONCE_H

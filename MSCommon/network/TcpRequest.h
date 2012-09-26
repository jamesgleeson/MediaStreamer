/*******************************************************
 *
 *	@author	: Turgut Mehdiyev
 *	@date	: 9/14/2012
 *	
 *	Copyright (c) Idrak Technology Transfer 2012
 *
 ******************************************************/

#ifndef MS_COMMON_TCP_REQUEST_H
#define MS_COMMON_TCP_REQUEST_H

#include <export.h>
#include <QObject>

class QDataStream;
class QString;

namespace MSCommon {

    /*!
     * \brief The TcpRequest class
     */
    class MSCOMMONSHARED_EXPORT TcpRequest : public QObject {

    public:

        /*!
         * \brief TcpRequest default constructor
         */
        TcpRequest(void);

        /*!
         * \brief Class constructor
         * \param userID user identificator
         * \param command
         * \param senderIPAddress
         * \param receiverIPAddress
         * \param recieverPort
         * \param data
         */
        TcpRequest(
            quint32 userID,
            QString command,
            QByteArray data = QByteArray(),
            QString senderIPAddress = "",
            QString receiverIPAddress = "",
            quint16 recieverPort = 0
        );

        /*!
         * \brief class destructor
         */
        virtual ~TcpRequest(void);

        /*!
         * \brief Copy contructor
         */
        TcpRequest( const TcpRequest& request );

        /*!
         * \brief Assignment operator overloading
         * \param request request object
         * \return Copy of request object
         */
        TcpRequest & operator = ( const TcpRequest& request);

        quint32 getUserID( void ) const;
        void setUserID( quint32 id );

        QString getCommand( void ) const;
        void setCommand( QString command );

        QByteArray getData( void ) const;
        void setData( QByteArray data );

        QString getSenderIpAddress( void ) const;
        void setSenderIpAddress( QString ip );

        QString getReceiverIpAddress( void ) const;
        void setReceiverIpAddress( QString ip );

        quint16 getReceiverPort( void ) const;
        void setReceiverPort( quint16 port );

        /*!
         * \brief Determines whether request content is valid
         * \return true -> if all input is valid
         *         false -> if any input is not valid
         */
        bool isValid( void );

    protected:
        quint64 _size;
        quint32 _userID;
        QString _command;
        QByteArray _data;
        QString _senderIpAddress;
        QString _receiverIpAddress;
        quint16 _receiverPort;

    private:
        bool _isValid;

    }; // class TcpRequest

} // namespace MSCommon


/*!
 * \brief Implementation of TcpRequest object serialization
 */
MSCOMMONSHARED_EXPORT QDataStream & operator << ( QDataStream &stream, const MSCommon::TcpRequest &request );
MSCOMMONSHARED_EXPORT QDataStream & operator >> ( QDataStream &stream, MSCommon::TcpRequest &request );

#endif // MS_COMMON_TCP_REQUEST_H

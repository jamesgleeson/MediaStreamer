/*******************************************************
 *
 *	@author	: Turgut Mehdiyev
 *	@date	: 9/13/2012
 *	
 *	Copyright (c) Idrak Technology Transfer 2012
 *
 ******************************************************/

#ifndef MS_COMMON_TCP_REQUEST_SENDER_H
#define MS_COMMON_TCP_REQUEST_SENDER_H

#include <export.h>
#include <QObject>
#include <QTcpSocket>

namespace MSCommon {

    class TcpRequest;
    class TcpResponse;

    /*!
     * \brief TcpRequestSender class provides functionality
     *        for sending network messages and handling response
     */
    class MSCOMMONSHARED_EXPORT TcpRequestSender : public QObject {

        Q_OBJECT

    public:

        /*!
         * \brief Class constructor
         * \param hostName Host IP address
         * \param port Host port number
         * \param connectImmediately Flag for connecting to server immediately
         * \param parent Parent object
         */
        TcpRequestSender( const QString &hostName = "", quint16 port = 0,
                          bool connectImmediately = false, int timeout = 6000, QObject *parent = 0 );

        /*!
         * \brief The TcpRequestSender destructor
         */
        virtual ~TcpRequestSender();


        /*!
         * \brief Send request to host
         */
        virtual void sendRequest( TcpRequest &request, TcpResponse &response, int timeout = 5000 );


        /*!
         * \brief Get host IP address
         * \return IP address
         */
        QString getHostName( void ) const;


        /*!
         * \brief Get host port number
         * \return Port number
         */
        quint16 getPort( void ) const;


        /*!
         * \brief Set host IP address
         * \param hostName Host IP address
         */
        void setHostName( const QString &hostName );


        /*!
         * \brief Set host port number
         * \param port Port number
         */
        void setPort( quint16 port );


        /*!
         * \brief Get socket's connection state
         * \return true -> socket connected to host
         *         false -> not connected
         */
        bool isConnected( void );


        /*!
         * \brief Connect to host
         * \param hostName Host IP address
         * \param port Host port number
         */
        void connectToHost( const QString &hostName, quint16 port, int timeout = 6000 );


        /*!
         * \brief Disconnect from host
         */
        void disconnectFromHost( int timeout );


    public slots:

        /*!
         * \brief handleError
         * \param socketError
         */
        virtual void handleError( QAbstractSocket::SocketError socketError );

        /*!
         * \brief Fires when connection to host successfully established
         */
        virtual void connected( void );

        /*!
         * \brief Fires when socket disconnected from host
         */
        virtual void disconnected( void );

        /*!
         * \brief Fires when socket is ready to read
         */
        virtual void readResponse(TcpResponse &response , int timeout = 5000 );


    protected:
        QTcpSocket *_socket;
        bool _isConnected;

    private:
        QString _hostName;
        quint16 _port;

    };  // class TcpRequestSender

} // namespace MSCommon


#endif // MS_COMMON_TCP_REQUEST_SENDER_H

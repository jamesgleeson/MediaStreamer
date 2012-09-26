/*******************************************************
 *
 *	@author	: Turgut Mehdiyev
 *	@date	: 9/10/2012
 *	
 *	Copyright (c) Idrak Technology Transfer 2012
 *
 ******************************************************/

#ifndef MS_COMMON_TCP_REQUEST_HANDLER_H
#define MS_COMMON_TCP_REQUEST_HANDLER_H

#include <export.h>

#include <QObject>
#include <QRunnable>

class QTcpSocket;

namespace  MSCommon {

    class TcpResponse;

    /*!
     * \brief Provides interface for handling incoming TCP connections
     */
    class MSCOMMONSHARED_EXPORT TcpRequestHandler : public QObject {

        Q_OBJECT

    public:

        /*!
         * \brief Class contructor
         * \param parent Parent object
         * \param socket Socket descriptor
         */
        TcpRequestHandler( QObject *parent = 0, int descriptor = 0 );

        /*!
         * \brief Class destructor
         */
        virtual ~TcpRequestHandler( void );

        /*!
         * \brief Get associated socket descriptor
         * \return socket descriptor
         */
        int getSocketDescriptor( void );

    public slots:
        virtual void disconnected( void ) = 0;
        virtual void readyRead( void ) = 0;
        virtual void sendResponse( TcpResponse *response ) = 0;

    protected:

        /*!
         * \brief _socket
         * \note For developers: DO NOT delete this pointrer in derived classes.
         *       TcpRequestHandler class destructor will delete it.
         */
        QTcpSocket *_socket;
        int _descriptor;

    signals:
        void connectionClosed( int descriptor );

    }; // class TcpRequestHandler


} // namespace MSCommon


#endif // MS_COMMON_TCP_REQUEST_HANDLER_H

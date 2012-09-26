/*******************************************************
 *
 *	@author	: Turgut Mehdiyev
 *	@date	: 9/10/2012
 *
 *	Copyright (c) Idrak Technology Transfer 2012
 *
 ******************************************************/

#ifndef MS_COMMON_TCP_LISTENER_H
#define MS_COMMON_TCP_LISTENER_H

#include <export.h>
#include <network/TcpRequestHandler.h>

#include <QTcpServer>

namespace MSCommon {

    /*!
     * \brief TCPListener abstract class provides functionality for
     *        listening and handing incoming TCP connections
     */
    class MSCOMMONSHARED_EXPORT TcpListener : public QTcpServer {

        Q_OBJECT

    public:

        /*!
         * \brief Start listening to incoming connections
         * \param ip
         * \param port
         */
        virtual void start( const QHostAddress &ip, quint16 port = 0 );

        /*!
         * \brief Class desctructor
         */
        virtual ~TcpListener( void );

    public slots:

        /*!
         * \brief Fires when connection disconnects
         * \param descriptor SOcket descriptor
         */
        virtual void connectionClosed( int descriptor ) = 0;

    protected:

        /*!
         * \brief Handle incoming connections
         * \param descriptor Socket descriptor
         */
        virtual void incomingConnection( int descriptor ) = 0;

    }; // class TcpListener

} // namespace MSCommon

#endif // MS_COMMON_TCP_LISTENER_H

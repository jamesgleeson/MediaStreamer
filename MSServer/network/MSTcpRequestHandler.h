/*******************************************************
 *
 *	@author	: Turgut Mehdiyev
 *	@date	: 9/12/2012
 *	
 *	Copyright (c) Idrak Technology Transfer 2012
 *
 ******************************************************/

#ifndef MS_SERVER_TCP_HANDLER_H
#define MS_SERVER_TCP_HANDLER_H

#include <network/TcpRequestHandler.h>

namespace MSCommon {
    class TcpResponse;
}

using namespace MSCommon;

namespace MSServer {


    /*!
     * \brief The MSTcpRequestHandler class
     */
    class MSTcpRequestHandler : public TcpRequestHandler {

        Q_OBJECT

    public:

        /*!
         * \brief Class contructor
         * \param parent Parent object
         * \param socket Socket descriptor
         */
        MSTcpRequestHandler( QObject *parent = 0, int descriptor = 0 );


        /*!
         * \brief Class destructor
         */
        ~MSTcpRequestHandler( void );


    public slots:


        /*!
         * \brief Handle sockets' disconnected signal
         */
        void disconnected( void );


        /*!
         * \brief Handle sockets' ready read state
         */
        void readyRead( void );


        /*!
         * \brief Send response to sender
         * \param response TcpResponse object
         */
        void sendResponse( TcpResponse *response );


        /*!
         * \brief Emits connectionClosed signal
         */
        void socketDestroyed( void );

    private:
        quint32 _pkgSize;

        bool isSocketConnected;

    }; // class MSTcpRequestHandler

} // namespace MSServer

#endif // MS_SERVER_TCP_HANDLER_H

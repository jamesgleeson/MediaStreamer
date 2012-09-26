/*******************************************************
 *
 *	@author	: Turgut Mehdiyev
 *	@date	: 9/12/2012
 *	
 *	Copyright (c) Idrak Technology Transfer 2012
 *
 ******************************************************/

#ifndef MS_ADM_TCP_LISTENER_H
#define MS_ADM_TCP_LISTENER_H

#include <network/TcpListener.h>

using namespace MSCommon;

namespace MSServer {

    class MSTcpRequestHandler;

    /*!
     * \brief MSTcpListener class provides functionality for
     *        listening and handing incoming TCP connections
     */
    class MSTcpListener : public TcpListener {

    public:

        /*!
         * \brief Class contructor
         * \param maxThreadCount Maximum concurrent thread count
         */
        MSTcpListener( quint16 maxThreadCount = 25 );


        /*!
         * \brief Handle incoming connections
         * \param descriptor Socket descriptor
         */
        void incomingConnection( int descriptor );


        /*!
         * \brief Class destructor
         */
        ~MSTcpListener( void );

    public slots:

        /*!
         * \brief Fires when connection gets closed
         * \param descriptor Socket descriptor
         */
        void connectionClosed( int descriptor );

    private:

        /*!
         * \brief _handlers Keeps all active MSTcpRequestHandler instances
         */
        std::vector<MSTcpRequestHandler*> _handlers;

    }; // class MSTcpListener

} // namespace MSServer

#endif // MS_ADM_TCP_LISTENER_H

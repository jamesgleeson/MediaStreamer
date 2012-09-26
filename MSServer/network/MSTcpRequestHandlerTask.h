/*******************************************************
 *
 *	@author	: Turgut Mehdiyev
 *	@date	: 9/13/2012
 *	
 *	Copyright (c) Idrak Technology Transfer 2012
 *
 ******************************************************/

#ifndef MS_SERVER_TCP_REQUEST_TASK_H
#define MS_SERVER_TCP_REQUEST_TASK_H

#include <network/TcpRequestHandlerTask.h>

namespace MSCommon {
    class TcpRequest;
    class TcpResponse;
}

using namespace MSCommon;

namespace MSServer {

    /*!
     * \brief The MSTcpRequestTask class provides functionality for
     *        processing network thread in separate thread
     *
     */
    class MSTcpRequestHandlerTask : public TcpRequestHandlerTask {

        Q_OBJECT

    public:

        /*!
         * \brief MSTcpRequestHandlerTask constructor
         * \param request Request object
         * \param parent Parent object
         */
        MSTcpRequestHandlerTask( TcpRequest *request, QObject *parent = 0 );

        /*!
         * \brief Task implementation
         */
        void run();

        /*!
         * \brief MSTcpRequestHandlerTask destructor
         */
        virtual ~MSTcpRequestHandlerTask();

    signals:

        /*!
         * \brief Send response
         * \param response TcpResponse object
         */
        void sendResponse( TcpResponse *response );

    }; // class MSTcpRequestHandlerTask

} // namespace MSServer

#endif // MS_SERVER_TCP_REQUEST_TASK_H

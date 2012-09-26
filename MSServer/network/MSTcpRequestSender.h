/*******************************************************
 *
 *	@author	: Turgut Mehdiyev
 *	@date	: 9/13/2012
 *
 *	Copyright (c) Idrak Technology Transfer 2012
 *
 ******************************************************/

#ifndef MS_SERVER_TCP_REQUEST_SENDER_H
#define MS_SERVER_TCP_REQUEST_SENDER_H

#include <network/TcpRequestSender.h>

using namespace MSCommon;

namespace MSServer {

    /*!
     * \brief The MSTcpRequestSender class
     */
    class MSTcpRequestSender : public TcpRequestSender {

    public:
        /*!
         * \brief TcpRequestSender
         * \param parent
         */
        MSTcpRequestSender( const QString &hostName, quint16 port, bool connectImmediately = true, QObject *parent = 0 );



    }; // class MSTcpRequestSender

} // namespace MSServer


#endif // MS_ADM_TCP_REQUEST_SENDER_H

/*******************************************************
 *
 *	@author	: Turgut Mehdiyev
 *	@date	: 9/15/2012
 *	
 *	Copyright (c) Idrak Technology Transfer 2012
 *
 ******************************************************/

#ifndef MS_COMMON_TCP_REQUEST_SENDER_TASK_H
#define MS_COMMON_TCP_REQUEST_SENDER_TASK_H

#include <export.h>
#include <QObject>
#include <QRunnable>

class QTcpSocket;

namespace MSCommon {

    class MSCOMMONSHARED_EXPORT TcpRequestSenderTask : public QObject, public QRunnable {

        Q_OBJECT

    public:

        /*!
         * \brief TcpRequestHandlerTask
         * \param parent
         * \param socket
         */
        TcpRequestSenderTask( QTcpSocket *socket, QObject *parent = 0 );

        /*!
         * \brief Code implementation
         */
        virtual void run( void );

    signals:

        /*!
         * \brief result
         * \param ds
         */
        void result( int ds );

    protected:

        /*!
         * \brief _socket
         * \note For developer: DO NOT implicitly delete this pointer.
         *       TCPRequestHandler class owns it
         */
        QTcpSocket *_socket;

    };

}


#endif // MS_COMMON_TCP_REQUEST_SENDER_TASK_H

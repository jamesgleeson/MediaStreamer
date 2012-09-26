/*******************************************************
 *
 *	@author	: Turgut Mehdiyev
 *	@date	: 9/12/2012
 *	
 *	Copyright (c) Idrak Technology Transfer 2012
 *
 ******************************************************/

#ifndef MS_COMMON_TCP_REQUEST_TASK_H
#define MS_COMMON_TCP_REQUEST_TASK_H

#include <export.h>
#include <QObject>
#include <QRunnable>

class QTcpSocket;
class QDataStream;

namespace MSCommon {

    class TcpRequest;

    /*!
     * \brief The TcpRequestHandlerTask class
     */
    class MSCOMMONSHARED_EXPORT TcpRequestHandlerTask : public QObject, public QRunnable {

        Q_OBJECT

    public:

        /*!
         * \brief Class constructor
         * \param parent
         * \param socket
         */
        TcpRequestHandlerTask( TcpRequest *request, QObject* parent = 0 );

        /*!
         * \brief Class destructor
         */
        virtual ~TcpRequestHandlerTask( void );

    protected:

        /*!
         * \brief Request object
         */
        TcpRequest *_request;

    }; // class TcpRequestHandlerTask

} // namespace MSCommon

#endif // MS_COMMON_TCP_REQUEST_TASK_H

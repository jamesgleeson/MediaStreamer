/*******************************************************
 *
 *	@author	: Turgut Mehdiyev
 *	@date	: 9/13/2012
 *	
 *	Copyright (c) Idrak Technology Transfer 2012
 *
 ******************************************************/

#ifndef MS_COMMON_EXCEPTION_H
#define MS_COMMON_EXCEPTION_H

#include <export.h>
#include <exception>
#include <QObject>

using namespace std;

namespace MSCommon {


    class MSCOMMONSHARED_EXPORT Exception {
    public:
        Exception( void ) {}
        Exception( QString errMsg = "", int errCode = 0 ) : _errMsg(errMsg), _errCode(errCode) {}
        virtual QString errMsg(void) {
            return _errMsg.isEmpty()
                    ? QObject::tr( "Generic error occured." )
                    : _errMsg;
        }
        virtual int errCode(void) { return _errCode; }

        QString _errMsg;
        int _errCode;
    };

    class MSCOMMONSHARED_EXPORT UnknownException : public Exception {
    public:
        UnknownException(void)
            : Exception( QObject::tr("An unknown error occured."), 1 ) {}
    };

    class MSCOMMONSHARED_EXPORT UnableToListenToNetworkConnections : public Exception {
    public:
        UnableToListenToNetworkConnections(void)
            : Exception( QObject::tr( "Unable to listen for incoming connections." ), 2 ) { }
    };

    class MSCOMMONSHARED_EXPORT InvalidSocketDescriptor : public Exception {
    public:
        InvalidSocketDescriptor(void)
           : Exception( QObject::tr( "Invalid socket descriptor specfied." ) , 3 ) { }
    };

    class MSCOMMONSHARED_EXPORT UnableToSendNetworkResponse : public Exception {
    public:
        UnableToSendNetworkResponse(void)
            : Exception( QObject::tr( "Unable to send network response." ), 4 ) {}
    };

    class MSCOMMONSHARED_EXPORT UnableToReadNetworkRequest : public Exception {
    public:
        UnableToReadNetworkRequest(void)
            : Exception( QObject::tr( "Unable to read network request." ), 5 ) {}
    };

    class MSCOMMONSHARED_EXPORT HostNotFound : public Exception {
    public:
        HostNotFound(void)
            : Exception( QObject::tr( "The host was not found. Please check the host name and port settings." ), 6 ) {}
    };

    class MSCOMMONSHARED_EXPORT RemoteHostClosedConnection : public Exception {
    public:
        RemoteHostClosedConnection(void)
            : Exception( QObject::tr( "Remote host closed network connection." ), 7 ) {}
    };

    class MSCOMMONSHARED_EXPORT NetworkConnectionRefused : public Exception {
    public:
        NetworkConnectionRefused(void)
            : Exception( QObject::tr( "Network connection refused by host machine." ),  8 ) {}
    };

    class MSCOMMONSHARED_EXPORT UnknownNetworkError : public Exception {
    public:
        UnknownNetworkError(void)
            : Exception( QObject::tr( "An unknown network error occured." ), 9 ) {}
    };

    class MSCOMMONSHARED_EXPORT NetworkConnectionTimedOut : public Exception {
    public:
        NetworkConnectionTimedOut(void)
            : Exception( QObject::tr("Network connection timed out."), 10 ) {}
    };

    class MSCOMMONSHARED_EXPORT InvalidHostInformation : public Exception {
    public:
        InvalidHostInformation()
            : Exception( QObject::tr( "Invalid host information specified." ), 11 ) {}
    };

    class MSCOMMONSHARED_EXPORT InvalidDBServerInformation : public Exception {
    public:
        InvalidDBServerInformation()
            : Exception( QObject::tr( "Invalid database server information specified." ), 12 ) {}
    };

    class MSCOMMONSHARED_EXPORT UnableToConnectToDatabase : public Exception {
    public:
        UnableToConnectToDatabase()
            : Exception( QObject::tr("Unable to connect to database server"), 13 ) {}
    };


} // namespace MSCommon

#endif // MS_COMMON_EXCEPTION_H

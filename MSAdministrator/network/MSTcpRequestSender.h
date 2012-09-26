#ifndef MS_ADM_TCP_REQUEST_SENDER
#define MS_ADM_TCP_REQUEST_SENDER

#include <network/TcpRequestSender.h>

using namespace MSCommon;

namespace MSAdministrator {

    /*!
     * \brief MSTcpRequestSender class provides functionality
     *        for sending network messages and handling response
     *        Also provides singleton access pattern
     */
    class MSTcpRequestSender : public TcpRequestSender {

    public:

        /*!
         * \brief Class constructor
         * \param hostName Host IP address
         * \param port Host port number
         * \param connectImmediately Flag for connecting to server immediately
         * \param parent Parent object
         */
        MSTcpRequestSender( const QString &hostName = "", quint16 port = 0,
                          bool connectImmediately = false, int timeout = 6000, QObject *parent = 0 );


        /*!
         * \brief Class destructor
         */
        ~MSTcpRequestSender( void );


        /*!
         * \brief Initialize application related settings
         */
        void init();


        /*!
         * \brief Send request to remote host
         * \param request Requet object
         * \param response Response object
         * \param timeout sending and reading timeout
         */
        void sendRequest( TcpRequest &request, TcpResponse &response, int timeout = 5000 );


        /*!
         * \brief Get singleton instance
         * \return
         */
        static MSTcpRequestSender* getInstance( void );

    private:

        /*!
         * \brief Holds singleton instance
         */
        static MSTcpRequestSender* _instance;

    };


} // namespace MSAdministrator



#endif // MS_ADM_TCP_REQUEST_SENDER

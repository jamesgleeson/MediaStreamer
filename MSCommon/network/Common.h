#ifndef MS_COMMON_NETWORK_COMMON_H
#define MS_COMMON_NETWORK_COMMON_H

#include <export.h>

class QString;

namespace MSCommon {

    class MSCOMMONSHARED_EXPORT NetworkCommon {
    public:

        /*!
         * \brief Contructor
         */
        NetworkCommon();

        /*!
         * \brief Get current machine network IP address
         * \return IP address
         */
        static QString getIpAddress(void);

    }; // class NetworkCommon

} // namespace MSCommon



#endif // MS_COMMON_NETWORK_COMMON_H

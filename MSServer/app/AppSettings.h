/*******************************************************
 *
 *	@author	: Turgut Mehdiyev
 *	@date	: 9/10/2012
 *	
 *	Copyright (c) Idrak Technology Transfer 2012
 *
 ******************************************************/

#ifndef MS_ADM_SETTINGS_H
#define MS_ADM_SETTINGS_H

#include <utils/Settings.h>

using namespace MSCommon;

namespace MSServer {

    /*!
     * \brief A Singleton instance to store application related settings
     * \todo Should work on singleton instance destructor.
     *       For now we rely on OS to delete it.
     */
    class AppSettings : public Settings {

    public:

        /*!
         * \brief Class destructor
         */
        ~AppSettings( void );

        /*!
         * \brief Initialize application related settings
         */
        void init( void );

        /*!
         * \brief Get singleton instance
         * \return
         */
        static AppSettings* getInstance( void );

    private:

        /*!
         * \brief Holds singleton instance
         */
        static AppSettings* _settings;

    };

}


#endif // MS_ADM_SETTINGS_H

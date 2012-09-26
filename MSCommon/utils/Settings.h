/*******************************************************
 *
 *	@author	: Turgut Mehdiyev
 *	@date	: 9/10/2012
 *
 *	Copyright (c) Idrak Technology Transfer 2012
 *
 ******************************************************/

#ifndef MS_COMMON_SETTINGS_H
#define MS_COMMON_SETTINGS_H

#include <export.h>
#include <QSettings>

namespace MSCommon {

    /*!
     * \brief Abstract class
     *        Stores application specific settings
     */
    class MSCOMMONSHARED_EXPORT Settings {

    public:

        /*!
         * \brief Initialize default Application settings
         * \example
         *          QApplication::setOrganizationName( "Idrak Technology Transfer" );
         *          QApplication::setOrganizationDomain( "www.idrak.az" );
         *          QApplication::setApplicationName( "MSCommon Library" );
         *          QApplication::setApplicationVersion( "1.0.0" );
         * \see QApplication
         */
        virtual void init( void ) = 0;

        /*!
         * \brief Get setting by key
         * \param key
         * \return setting object
         */
        virtual QVariant getValue( const QString &key ) const;

        /*!
         * \brief Set setting value by key
         * \param key
         * \param value
         */
        virtual void setValue( const QString &key, const QVariant &value );

        virtual ~Settings( void );
    };

}


#endif // MS_COMMON_SETTINGS_H

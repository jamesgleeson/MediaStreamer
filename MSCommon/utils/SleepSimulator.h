/*******************************************************
 *
 *	@author	: Turgut Mehdiyev
 *	@date	: 9/12/2012
 *	
 *	Copyright (c) Idrak Technology Transfer 2012
 *
 ******************************************************/

#ifndef MS_COMMON_SLEEP_SIMULATOR_H
#define MS_COMMON_SLEEP_SIMULATOR_H

#include <export.h>
#include <QMutex>
#include <QWaitCondition>


namespace MSCommon {

    /*!
     * \brief SleepSimulator class provides corss-browser sleep functionality
     */
    class MSCOMMONSHARED_EXPORT SleepSimulator {

    public:

        /*!
         * \brief Class constructor
         */
        SleepSimulator( void );

        /*!
         * \brief sleep
         * \param ms How long to sleep ( in milliseconds )
         */
        void sleep( unsigned long ms );

        /*!
         * \brief cancel sleep
         */
        void cancelSleep( void );

    private:

        QMutex localMutex;
        QWaitCondition sleepSimulator;

    }; //  class SleepSimulator

} // namespace MSCommon


#endif // MS_COMMON_SLEEP_SIMULATOR_H

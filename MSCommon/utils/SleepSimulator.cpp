/*******************************************************
 *
 *	@author	: Turgut Mehdiyev
 *	@date	: 9/12/2012
 *	
 *	Copyright (c) Idrak Technology Transfer 2012
 *
 ******************************************************/

#include <utils/SleepSimulator.h>

using namespace MSCommon;

SleepSimulator::SleepSimulator( void ) {
    localMutex.lock();
}

void SleepSimulator::sleep( unsigned long ms ) {
    sleepSimulator.wait( &localMutex, ms );
}

void SleepSimulator::cancelSleep( void ) {
    sleepSimulator.wakeAll();
}

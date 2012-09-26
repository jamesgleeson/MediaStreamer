/*****************************************************
 *
 *  @author      Turgut Mehdiyev
 *  @date        24/07/2012
 *
 *  Copyright (c) Idrak Technology Transfer LLC 2012
 *
 *****************************************************/

#ifndef MS_MEDIA_PLAYER_GLOBAL_H
#define MS_MEDIA_PLAYER_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(MS_MEDIA_PLAYER_LIBRARY)
#  define MS_MEDIA_PLAYER_EXPORT Q_DECL_EXPORT
#else
#  define MS_MEDIA_PLAYER_EXPORT Q_DECL_IMPORT
#endif

#endif // MS_MEDIA_PLAYER_GLOBAL_H

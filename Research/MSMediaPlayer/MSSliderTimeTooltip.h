/*****************************************************************************
 * Copyright © 2011 VideoLAN
 * $Id: 4e74286037d358bf6769c9ccb49689b1c6d33cca $
 *
 * Authors: Ludovic Fauvet <etix@l0cal.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin Street, Fifth Floor, Boston MA 02110-1301, USA.
 *****************************************************************************/

#ifndef MS_SLIDER_TIME_TOOLTIP_H
#define MS_SLIDER_TIME_TOOLTIP_H

#include <MSMediaPlayer_global.h>
#include <QtGui>


namespace Idrak {
    namespace MediaStreamer {
        namespace MediaPlayer {
            class MSSliderTimeTooltip;
        }
    }
}


class MS_MEDIA_PLAYER_EXPORT MSSliderTimeTooltip : public QWidget {

    Q_OBJECT

public:
    explicit MSSliderTimeTooltip( QWidget *parent = 0 );

    void setText( const QString& time, const QString& text );

    virtual void show();

protected:
    virtual void paintEvent( QPaintEvent * );

private:
    void buildPath();
    QString mTime;
    QString mText;
    QString mDisplayedText;
    QFont mFont;
    QRect mBox;
    QPainterPath mPainterPath;
    QBitmap mMask;
    int mPreviousMetricsWidth;
    bool mInitialized;
};

#endif // MS_SLIDER_TIME_TOOLTIP_H

/*****************************************************************************
 * Copyright © 2011-2012 VideoLAN
 * $Id: d031e79dbe28596daa3dede31fdecf85b0397994 $
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

#include "MSSliderTimeTooltip.h"

#define TIP_HEIGHT 5

MSSliderTimeTooltip::MSSliderTimeTooltip( QWidget *parent ) :
    QWidget( parent ) {

    this->setWindowFlags( Qt::Window                  |
                          Qt::WindowStaysOnTopHint    |
                          Qt::FramelessWindowHint     |
                          Qt::X11BypassWindowManagerHint );

    // Tell Qt that it doesn't need to erase the background before
    // a paintEvent occurs. This should save some CPU cycles.
    this->setAttribute( Qt::WA_OpaquePaintEvent );

#ifdef Q_WS_WIN

    /*
    - This attribute is required on Windows to avoid focus stealing of other windows.
    - When set on Linux the MSSliderTimeTooltip appears behind the FSController in fullscreen.
    */
    this->setAttribute( Qt::WA_ShowWithoutActivating );
#endif

    // Inherit from the system default font size -5
    this->mFont = QFont( "Tahoma", qMax( qApp->font().pointSize() - 5, 7 ) );
    this->mPreviousMetricsWidth = 0;

    // Set default text
    this->setText( "00:00:00", "" );

    this->mInitialized = false;
}


void MSSliderTimeTooltip::buildPath() {
    QFontMetrics metrics( this->mFont );

    // Get the bounding box required to print the text and add some padding
    QRect textbox = metrics.boundingRect( this->mDisplayedText ).adjusted( -2, -2, 2, 2 );

    if ( this->mPreviousMetricsWidth == textbox.width() )
        return; //same width == same path
    else
        this->mPreviousMetricsWidth = textbox.width();

    this->mBox = QRect( 0, 0, textbox.width(), textbox.height() );

    // Resize the widget to fit our needs
    this->resize( this->mBox.width() + 1, this->mBox.height() + TIP_HEIGHT + 1 );

    // Prepare the painter path for future use so
    // we only have to generate the text at runtime.

    // Draw the text box
    this->mPainterPath = QPainterPath();
    this->mPainterPath.addRect( this->mBox );

    // Draw the tip
    int center = this->mBox.width() / 2;
    QPolygon polygon;
    polygon << QPoint( center - 3,   this->mBox.height() )
            << QPoint( center,       this->mBox.height() + TIP_HEIGHT )
            << QPoint( center + 3,   this->mBox.height() );

    this->mPainterPath.addPolygon( polygon );

    // Store the simplified version of the path
    this->mPainterPath = this->mPainterPath.simplified();

    // Create the mask used to erase the background
    // Note: this is a binary bitmap (black & white)
    this->mMask = QBitmap( size() );
    QPainter painter( &this->mMask );
    painter.fillRect( this->mMask.rect(), Qt::white );
    painter.setPen( QColor( 0, 0, 0 ) );
    painter.setBrush( QColor( 0, 0, 0 ) );
    painter.drawPath( this->mPainterPath );
    painter.end();

    this->setMask( this->mMask );
}


void MSSliderTimeTooltip::setText( const QString& time, const QString& text ) {
    this->mInitialized = true;
    this->mDisplayedText = time;
    if ( !text.isEmpty() )
        this->mDisplayedText.append( " - " ).append( text );

    if ( time.length() != this->mTime.length() || this->mText != text )
        buildPath();

    this->mTime = time;
    this->mText = text;
    update();
}


void MSSliderTimeTooltip::show() {
    QWidget::setVisible( this->mInitialized );
}


void MSSliderTimeTooltip::paintEvent( QPaintEvent * ) {
    QPainter p( this );
    p.setRenderHints( QPainter::HighQualityAntialiasing | QPainter::TextAntialiasing );

    p.setPen( Qt::black );
    p.setBrush( qApp->palette().base() );
    p.drawPath( this->mPainterPath );

    p.setFont( this->mFont );
    p.setPen( QPen( qApp->palette().text(), 1 ) );
    p.drawText( this->mBox, Qt::AlignCenter, this->mDisplayedText );
}

#undef TIP_HEIGHT

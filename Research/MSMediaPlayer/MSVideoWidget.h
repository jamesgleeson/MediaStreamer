/*****************************************************
 *
 *  @author      Turgut Mehdiyev
 *  @date        24/07/2012
 *
 *  Copyright (c) Idrak Technology Transfer LLC 2012
 *
 *****************************************************/

#ifndef MS_VIDEO_WIDGET_H
#define MS_VIDEO_WIDGET_H

#include <MSMediaPlayer_global.h>
#include <gui/VideoWidget.h>

namespace Idrak {
    namespace MediaStreamer {
        namespace MediaPlayer {
            class MSVideoWidget;
        }
    }
}


/*!
 * \brief The MSVideoWidget class is a wrapper for VLCVideWidget class
 *        and provides additional functionality for displayig Running Text and Image
 */
class MS_MEDIA_PLAYER_EXPORT MSVideoWidget : public VlcVideoWidget {

public:

    /*!
     *  \brief MSVideoWidget constructor
     */
    MSVideoWidget();

    /*!
     *  \brief MSVideoWidget constructor
     *  \param player media player (VlcMediaPlayer *)
     *  \param parent video widget's parent GUI widget (QWidget)
     */
    MSVideoWidget(VlcMediaPlayer *player, QWidget *parent = 0);

    /*!
     *  \brief MSVideoWidget constructor
     *  \param parent video widget's parent GUI widget (QWidget)
     */
    explicit MSVideoWidget(QWidget *parent = 0);


    /*!
     *  \brief MSVideoWidget destructor
     */
    virtual ~MSVideoWidget();


}; // class MSVideoWidget


#endif // MS_VIDEO_WIDGET_H

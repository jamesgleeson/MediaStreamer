/*****************************************************
 *
 *  @author      Turgut Mehdiyev
 *  @date        24/07/2012
 *
 *  Copyright (c) Idrak Technology Transfer LLC 2012
 *
 *****************************************************/

#include "MSVideoWidget.h"


MSVideoWidget::MSVideoWidget()
    : VlcVideoWidget(){

}


MSVideoWidget::MSVideoWidget( VlcMediaPlayer *player, QWidget *parent )
    : VlcVideoWidget( player, parent ){

}


MSVideoWidget::MSVideoWidget( QWidget *parent )
    : VlcVideoWidget( parent ) {

}


MSVideoWidget::~MSVideoWidget() {

}

/*******************************************************
 *
 *	@author	: Turgut Mehdiyev
 *	@date	: 9/15/2012
 *	
 *	Copyright (c) Idrak Technology Transfer 2012
 *
 ******************************************************/

#ifndef FORM_H
#define FORM_H

#include <QWidget>

namespace Ui {
class Form;
}

namespace MSServer {
    class MSTcpRequestSender;
}

class Form : public QWidget
{
    Q_OBJECT
    
public:
    explicit Form(QWidget *parent = 0);
    ~Form();

public slots:
    void btnClicked();
    
private:
    Ui::Form *ui;
    MSServer::MSTcpRequestSender *sender;
};

#endif // FORM_H

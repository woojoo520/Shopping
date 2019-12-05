#include "msgbutton.h"

msgButton::msgButton(QWidget *parent, int Id, bool isread)
 : QPushButton(parent)
{
    this->Id = Id;
    if(isread) {
        this->setIcon(QIcon("E:\\Qt\\Shopping\\Game\\pic\\otherpic\\read.png"));
    } else {
        this->setIcon(QIcon("E:\\Qt\\Shopping\\Game\\pic\\otherpic\\msg.png"));
    }
    this->setIconSize(QSize(20, 20));
    connect(this, SIGNAL(clicked(bool)), this, SLOT(changeIcon()));
}

void msgButton::changeIcon() {
    this->setIcon(QIcon("E:\\Qt\\Shopping\\Game\\pic\\otherpic\\read.png"));
    emit readXmsg(this->Id);
}

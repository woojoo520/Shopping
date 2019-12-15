#include "msgbutton.h"

/**
 * @brief heritage the QPushButton class, and add an slot function clicked
 * @param Id     the message id in the database
 * @param isread to identify that the message has been read or not
 * heritage the QPushButton class and has the attribute of If and isRead, mainly used for changing the message to read or unread
 */
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

/**
 * @brief change teh unread icon
 * when the user cope with the order message, then he or she can click the button, and the the button's icon will be changed to "read" to show that the message has been done 
 */
void msgButton::changeIcon() {
    this->setIcon(QIcon("E:\\Qt\\Shopping\\Game\\pic\\otherpic\\read.png"));
    emit readXmsg(this->Id);
}

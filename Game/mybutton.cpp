#include "mybutton.h"

myButton::myButton(QWidget *parent, int id, int labelId, int seq, QString productId)
    : QPushButton(parent)
{
    this->id = id;
    this->productId = productId;
    this->labelId = labelId;
    this->seq = seq;
    this->setIcon(QIcon("E:\\Qt\\Shopping\\Game\\pic\\otherpic\\unpraise.png"));
    this->setIconSize(QSize(20, 20));
    isclicked = false;
}

void myButton::mousePressEvent(QMouseEvent *event) {
    isclicked = !isclicked;
    if(isclicked) {
        this->setIcon(QIcon("E:\\Qt\\Shopping\\Game\\pic\\otherpic\\praise.png"));
        emit click(this->id, this->labelId, this->seq, this->productId, true);
    } else {
        this->setIcon(QIcon("E:\\Qt\\Shopping\\Game\\pic\\otherpic\\unpraise.png"));
        emit click(this->id, this->labelId, this->seq, this->productId, false);
    }

}

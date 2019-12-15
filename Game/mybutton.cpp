#include "mybutton.h"

/**
 * @brief init the praise button with id, labelid, seq, productId
 * @param id        it means the 
 * @param labelId   it means the  
 * @param seq       it means the seq is the order in the layout
 * @param productId it means the comment is of this product(id = productid)
 */
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


/**
 * @brief praise one of the comment
 * @param event a clicked signal 
 * When the user clicks the icon, it indicates the like operation, and when the user clicks again, it indicates that the like operation is cancelled
 */
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

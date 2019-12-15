#include<QLabel>
#include"MYLABEL.h"
#include"mainwindow.h"

/**
 * @brief   Initialize and connect the click signal to the corresponding slot function
 * @param   text        the text that should be shown in the QLabel
 * @param   parent      the parent object
 * @param   productId   the productId that the QLabel will be shown
 */
Mylabel::Mylabel(const QString & text,QWidget* parent, QString productId)
    :QLabel(parent)
{
    this->productId = productId;
    this->setText(text);
    connect(&lineEdit, SIGNAL(textChanged(QString)), this, SLOT(showComment()));
    lineEdit.setText("true");
}

/**
 * @brief emit signal to request the product information
 */
void Mylabel::showComment() {
    emit showC(this->commentInfo);
}

/**
 * @brief emit the click signal, and implement the corresponding function -- show the detailed information of the product.
 */
void Mylabel::mousePressEvent(QMouseEvent* event)
{
    emit clicked(tag, productId);
}


#include<QLabel>
#include"MYLABEL.h"
#include"mainwindow.h"

Mylabel::Mylabel(const QString & text,QWidget* parent, QString productId)
    :QLabel(parent)
{
    this->productId = productId;
    this->setText(text);
    connect(&lineEdit, SIGNAL(textChanged(QString)), this, SLOT(showComment()));
    lineEdit.setText("true");
}


void Mylabel::showComment() {
    emit showC(this->commentInfo);
}

void Mylabel::mousePressEvent(QMouseEvent* event)
{
    emit clicked(tag, productId);
}


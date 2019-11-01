#include<QLabel>
#include"MYLABEL.h"
#include"mainwindow.h"

Mylabel::Mylabel(const QString & text,QWidget* parent)
    :QLabel(parent)
{
     this->setText(text);
     connect(this, SIGNAL(clicked()), this, SLOT(showDetail()));
}

void Mylabel::showDetail()
{
    productShow *productshow = new productShow();
    productshow->show();
}
void Mylabel::mousePressEvent(QMouseEvent* event)
{
    emit clicked();
}

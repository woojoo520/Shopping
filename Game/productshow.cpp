#include "productshow.h"
#include "ui_productshow.h"
#include "qlabel.h"
#include "qstring.h"
#include <QDebug>
#include<QSqlError>
#include<QSqlDatabase>
#include<QSqlQuery>
productShow::productShow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::productShow)
{
    ui->setupUi(this);
    QImage *img = new QImage;
    img->load(":/new/prefix1/BUPT.png");
    ui->label1->setPixmap(QPixmap::fromImage(*img));



}

productShow::search()
{
    QString str = QString("select *from Product where product_id = 1");
    QSqlQuery query;
    query.exec(str);
    QString name;
    QString seller;
    QString description;
    int state;
    int number;
    double price;
    while(query.next())
    {
        number = query.value(0).toInt();
        seller = query.value(1).toString();
        state = query.value(2).toInt();
        price = query.value(3).toDouble();
        description = query.value(4).toString();
        name = query.value(5).toString();
    }
    qDebug()<<name;
    qDebug()<<seller;
    qDebug()<<state;
    qDebug()<<price;
    qDebug()<<description;


   // pornPropLabel->setText(QString::number(intResult, 10, 4));
    ui->name->setText(name);
    ui->price->setText(QString::number(price, 10, 4));
    ui->seller->setText(seller);
    ui->description->setText(description);
    ui->state->setText(QString::number(state, 10, 4));


}

productShow::~productShow()
{
    delete ui;
}


void productShow::on_addBtn_clicked()
{

}

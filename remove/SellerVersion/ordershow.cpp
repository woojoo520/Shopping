#include "ordershow.h"
#include "ui_ordershow.h"

OrderShow::OrderShow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::OrderShow)
{
    ui->setupUi(this);
}

OrderShow::~OrderShow()
{
    delete ui;
}

#include "productshow.h"
#include "ui_productshow.h"

productShow::productShow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::productShow)
{
    ui->setupUi(this);
}

productShow::~productShow()
{
    delete ui;
}

#include "releaseproduct.h"
#include "ui_releaseproduct.h"

ReleaseProduct::ReleaseProduct(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ReleaseProduct)
{
    ui->setupUi(this);
}

ReleaseProduct::~ReleaseProduct()
{
    delete ui;
}

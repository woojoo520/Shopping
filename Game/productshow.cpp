#include "productshow.h"
#include "ui_productshow.h"

productShow::productShow(QWidget *parent,int labelID, QString productId) :
    QDialog(parent),
    ui(new Ui::productShow)
{
    ui->setupUi(this);
    this->ProductId = productId;
    this->labelId = labelID;
    pushButton = new QPushButton(this);
    pushButton->setText(tr("评价"));
    pushButton->setGeometry(100, 510, 80, 31);
    pushButton->show();
//    connect(pushButton, SIGNAL(clicked(bool)), this, SLOT(on_commentBtn_clicked()));
}

productShow::~productShow()
{
    delete ui;
}


void productShow::on_commentBtn_clicked()
{
    emit getComment(this->labelId, this->ProductId);
}

void productShow::Show() {
    this->show();
}

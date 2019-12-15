#include "productshow.h"
#include "ui_productshow.h"

/**
 * @brief   Click the product picture to display the product details interface
 * @param   labelID
 * @param   productId
 * Click the product picture to display the product details interface, which incluing the product's picture, product's description and price, and a comment button, an order button and a chat button
 */
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

/**
 * @brief delete the interface
 */
productShow::~productShow()
{
    delete ui;
}

/**
 * @brief emit the signal to require teh comment of the product 
 */
void productShow::on_commentBtn_clicked()
{
    emit getComment(this->labelId, this->ProductId);
}

/**
 * show the comment interface
 */
void productShow::Show() {
    this->show();
}

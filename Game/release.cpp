#include "release.h"
#include "ui_release.h"

Release::Release(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Release)
{
    ui->setupUi(this);
}

void Release::showRelease() {
    QGridLayout *layout = new QGridLayout;
    QWidget *containWidget = new QWidget;

    MylabelVec.clear();
    // 加载数据库中的图片信息
    for(int i = 0;i < releaseProduct.size();i++) {
        QString ID = releaseProduct[i].product_id;
        Mylabel *label = new Mylabel("this", this, ID);

        connect(label, SIGNAL(clicked(int,QString)), this, SLOT(createProductShow(int,QString)));
        label->resize(200, 200);
        QImage *img = new QImage;
        bool isLoadSucc = img->load(releaseProduct[i].src);
        if(!isLoadSucc) {
            img->load("E:\\Qt\\Shopping\\Game\\pic\\productPic\\unload.jpg");
        }
        QImage newImg = img->scaled(label->width(), label->height(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
        label->setPixmap(QPixmap::fromImage(newImg));
        label->tag = i;

        QLabel *textLabel = new QLabel(this);
        textLabel->setText(releaseProduct[i].description);
        textLabel->setWordWrap(true);
        QLabel *priceLabel = new QLabel(this);
        priceLabel->setText("￥" + QString("%1").arg(releaseProduct[i].price));
        layout->addWidget(label, 2 * i, 0, 2, 1);
        layout->addWidget(textLabel, 2 * i, 1, 1, 1);
        layout->addWidget(priceLabel, 2 * i + 1, 1, 1, 1);
        MylabelVec.push_back(label);
    }

    containWidget->setLayout(layout);
    ui->showArea->setWidgetResizable(true);
    ui->showArea->setWidget(containWidget);

}

Release::~Release()
{
    delete ui;
}

void Release::on_releaseBtn_clicked()
{
    QJsonObject productInfo;
    productInfo["discription"] = ui->discription_Edit->toPlainText();
    productInfo["quantity"] = ui->quantity_Box->text();
    productInfo["price"] = ui->price_Edit->text();
    productInfo["tag"] = ui->tag_Edit->toPlainText();
    productInfo["src"] = fileName;

    QMessageBox::warning(this, "warning", productInfo["quantity"].toString() + " " + QString::number(productInfo["price"].toString().toFloat()));

    if(productInfo["price"].toString() <= 0) {
        QMessageBox::warning(this, "warning", "Sorry, You must have the quantity at least one! " + productInfo["quantity"].toString() + " " + QString::number(productInfo["price"].toString().toInt()));
        return ;
    } else if(productInfo["src"] == "") {
        QMessageBox::warning(this, "warning", "Sorry, You must have the picture!");
        return ;
    }
    emit releasePro(productInfo);
}

void Release::on_chooseBtn_clicked()
{
    fileName = QFileDialog::getOpenFileName(
                this, tr("open image file"),
                "./", tr("Image files(*.bmp *.jpg *.pbm *.pgm *.png *.ppm *.xbm *.xpm);;All files (*.*)"));

    if(fileName.isEmpty())
    {
        QMessageBox::warning(this,"警告","打开图片失败!");
        return;
    } else {
        QImage *img = new QImage;
        img->load(fileName);
        QImage newImg = img->scaled(ui->product_Label->width(), ui->product_Label->height(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
        ui->product_Label->setPixmap(QPixmap::fromImage(newImg));
    }
}


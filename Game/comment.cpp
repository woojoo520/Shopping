#include "comment.h"
#include "ui_comment.h"

comment::comment(QWidget *parent,int labelId, QString productId) :
    QDialog(parent),
    ui(new Ui::comment)
{
    ui->setupUi(this);
    this->ProductId = productId;
    this->labelId = labelId;
}

comment::~comment()
{
    delete ui;
}

void comment::on_pushButton_clicked()
{
    QJsonObject commentJson;
    commentJson["productId"] = ProductId;
    commentJson["comment"] = ui->myComment->toPlainText();
    commentJson["labelId"] = this->labelId;
    commentJson["type"] = "sendComment";
    emit sendComment(commentJson);
}

void comment::showComment(QJsonArray commentInfo) {
    popularVec.clear();
    ui->myComment->clear();
    QGridLayout *layout = new QGridLayout;
    QWidget *containWidget = new QWidget;
    int row = 0;
    for(int i = 0;i < commentInfo.size();i++) {
        QJsonObject infoJson = commentInfo.at(i).toObject();
        int popular = infoJson["popular"].toInt();
        int id = infoJson["Id"].toInt();
        int labelId = infoJson["labelId"].toInt();
        int length = infoJson["User_name"].toString().length();
        QString productId = infoJson["Product_Id"].toString();
        QString src = infoJson["Img"].toString();
        QString str = infoJson["User_name"].toString() + "\n";
        str += infoJson["comment"].toString() + "\n";

        QLabel *labelComment = new QLabel(this);
        QLabel *logoLabel = new QLabel(this);
        myButton *button = new myButton(this, id, labelId, i, productId);
        QLabel *popularLabel = new QLabel(QString::number(popular));
        popularVec.push_back(popularLabel);
        logoLabel->resize(50, 50);
        QImage *img = new QImage;
        img->load(src);
        QImage newImg = img->scaled(logoLabel->width(), logoLabel->height(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
        logoLabel->setPixmap(QPixmap::fromImage(newImg));
        connect(button, SIGNAL(click(int, int, int, QString, bool)), this, SLOT(praise(int, int, int, QString, bool)));
        labelComment->setText(str);
        labelComment->setWordWrap(true);

        layout->addWidget(logoLabel, row, 0, 1, 1);
        layout->addWidget(labelComment, row, 1, 2, 8);
        layout->addWidget(button, row, 9, 1, 1);
        layout->addWidget(popularLabel, row, 10, 1, 1);
        row += qMax(2, length / 15);
    }

    if(commentInfo.size() < 4) {
        for(int i = 4 - commentInfo.size(); i >= 0;i--) {
            QLabel *labelComment = new QLabel(this);
            layout->addWidget(labelComment, row, 1, 2, 8);
            row += 2;
        }
    }

    containWidget->setLayout(layout);
    ui->scrollArea->setWidgetResizable(true);
    ui->scrollArea->setWidget(containWidget);
}

void comment::praise(int id, int labelId, int seq, QString ProductId, bool isadd) {
    QJsonObject praiseJson;
    praiseJson["type"] = "praise";
    praiseJson["Id"] = id;
    praiseJson["productId"] = ProductId;
    praiseJson["labelId"] = labelId;
    if(isadd) {
        praiseJson["isadd"] = "true";
        popularVec[seq]->setText(QString::number(popularVec[seq]->text().toInt() + 1));
    } else {
        praiseJson["isadd"] = "false";
        popularVec[seq]->setText(QString::number(popularVec[seq]->text().toInt() - 1));
    }
    emit sendPraise(praiseJson);
}

void comment::Show() {
    this->show();
    emit queryComment(this->labelId, this->ProductId);
}

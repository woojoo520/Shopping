#include "comment.h"
#include "ui_comment.h"

/*!
 * initialize paramenters
 * 
 * complete the initialization of lableId, productId in the constructor. For the comment is for one of the items
 * @param labelId the index of the shown lobel in mainWindow
 * @param productId the Id of the product 
 */
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

/**
 * finishing the function of commenting
 * 
 * It is a dlot function, which is aroused when the button is clicked. 
 * And get the information of the productId and labelId user comment, the comment info
 */
void comment::on_pushButton_clicked()
{
    QJsonObject commentJson;
    commentJson["productId"] = ProductId;
    commentJson["comment"] = ui->myComment->toPlainText();
    commentJson["labelId"] = this->labelId;
    commentJson["type"] = "sendComment";
    emit sendComment(commentJson);
}

/**
 * show the comment in GUI
 * 
 * get the infomation of the comment, including the content, the length, user's name and the popularity of the comments, the productId, labelId, src of the image of the product 
 * create a layout to place these items
 * create a button for every comment for uses to give the thumbs-up, and bounded the click signals of the button to the slot function of praise()
 */
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

    /**> for it may be to small comment of the product, it may change the layout of the product, and you can't get the ideal layout */
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

/**
 * approval function
 * when you are interested in one of the comments, you can clocked the "thumb" button, and then will trigger the slot funciton
 * it will get the information of the product and the information of the user, and change the popularity of the product in the database
 * the most important thing is to implement the function taht yyou can't approval for second time, that is, if you clicked the same button, it will default to cancel the "likes", and it will decrease the number of likes 
 */
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

/**
 * send a signal of getting the comment information
 */
void comment::Show() {
    this->show();
    emit queryComment(this->labelId, this->ProductId);
}

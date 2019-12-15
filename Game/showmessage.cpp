#include "showmessage.h"
#include "ui_showmessage.h"

/**
 * @brief   init the ui
 */
showMessage::showMessage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::showMessage)
{
    ui->setupUi(this);
}

/**
 * @brief   delete the ui
 */
showMessage::~showMessage()
{
    delete ui;
}

/**
 * @brief   Layout, displaying the order information received by the user, including unread and read
 */
void showMessage::showMsg() {
    QGridLayout *layout = new QGridLayout;
    QWidget *containWidget = new QWidget;
    for(int i = 0;i < unreadMsg.size() + readMsg.size();i++) {
        bool isread = i >= unreadMsg.size();
        QJsonObject infoJson;
        if(isread) {
            infoJson = readMsg.at(i - unreadMsg.size()).toObject();
        } else {
            infoJson = unreadMsg.at(i).toObject();
        }
        QString Msg = infoJson["Msg"].toString();
        QString user_name = infoJson["user_name"].toString();
        QLabel *labelMsg = new QLabel(this);
        labelMsg->setText(Msg);
        QLabel *labelName = new QLabel(this);
        labelName->setText(user_name);

        msgButton *isreadBtn;
        QJsonObject msgObj;
        if(isread) {
            msgObj = readMsg.at(i - unreadMsg.size()).toObject();
            isreadBtn = new msgButton(this, msgObj["Id"].toInt(), isread);
        } else {
            msgObj = unreadMsg.at(i).toObject();
            isreadBtn = new msgButton(this, msgObj["Id"].toInt(), isread);
        }

        connect(isreadBtn, SIGNAL(readXmsg(int)), this, SLOT(getMsgIndex(int)));
        isreadBtn->resize(20, 20);
        labelMsg->setWordWrap(true);
        layout->addWidget(labelName, 2 * i, 0, 1, 1);
        layout->addWidget(labelMsg, 2 * i + 1, 0, 1, 8);
        layout->addWidget(isreadBtn, 2 * i + 1, 8, 1, 1);
    }
    int Msgnum = unreadMsg.size() + readMsg.size();
    while(Msgnum < 10) {
        QLabel *label = new QLabel(this);
        layout->addWidget(label, Msgnum * 2, 0, 2, 1);
        Msgnum++;
    }

    containWidget->setLayout(layout);
    ui->scrollArea->setWidgetResizable(true);
    ui->scrollArea->setWidget(containWidget);
}

/**
 * @brief   emit a signal to get the message id in the database
 */
void showMessage::getMsgIndex(int id) {
    emit readXmsg(id);
}

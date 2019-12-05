#ifndef SHOWMESSAGE_H
#define SHOWMESSAGE_H

#include <QDialog>
#include <QGridLayout>
#include <QDebug>
#include <QJsonArray>
#include <QJsonObject>
#include <QMessageBox>
#include <QImage>
#include <QIcon>
#include <QLabel>
#include "mylabel.h"
#include "msgbutton.h"


namespace Ui {
class showMessage;
}

class showMessage : public QDialog
{
    Q_OBJECT
signals:
    void readXmsg(int Id);
public:
    explicit showMessage(QWidget *parent = 0);
    ~showMessage();
    QJsonArray unreadMsg;
    QJsonArray readMsg;
public slots:
    void showMsg();
    void getMsgIndex(int id);
private:
    Ui::showMessage *ui;

};

#endif // SHOWMESSAGE_H

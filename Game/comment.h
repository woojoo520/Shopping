#ifndef COMMENT_H
#define COMMENT_H

/**
 * \file
 * \brief the comment infomation from different people of the specific product
 * \author MengYeqing
 * \date 2019.11.26
 * \version 1.0
 * \note
 * to show the comment of each product, I add a comment GUI to show the comment of the product and see others' evaluation to decide whether to buy this product or not. You can "thumb-up" only once when you agree someone's opiniion. And post your own comments 
 */ 

#include <QDialog>
#include <QGridLayout>
#include <QDebug>
#include <QJsonArray>
#include <QJsonObject>
#include <QMessageBox>
#include <QImage>
#include <QIcon>
#include "qmath.h"
#include "mybutton.h"

namespace Ui {
class comment;
}

class comment : public QDialog
{
    Q_OBJECT
signals:
    void sendComment(QJsonObject commentJson);
    void queryComment(int labelId, QString ProductId);
    void sendPraise(QJsonObject);
public:
    explicit comment(QWidget *parent = 0, int labelId = 0, QString productId = "");
    ~comment();
private slots:
    void on_pushButton_clicked();
    void praise(int id, int labelId, int seq, QString ProductId, bool isadd);
public slots:
    void showComment(QJsonArray commentInfo);
    void Show();
private:
    QVector<QLabel*> popularVec;
    QString ProductId;
    Ui::comment *ui;
    int labelId;
};

#endif // COMMENT_H

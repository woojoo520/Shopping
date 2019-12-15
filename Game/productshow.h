#ifndef PRODUCTSHOW_H
#define PRODUCTSHOW_H

/**
 * @file
 * @brief   show the product's detailed information
 * @author  MengYeqing
 * @date    2019/11/23
 * @note
 */
#include <QDialog>
#include <QVector>
#include <QString>
#include <QDebug>
#include <QJsonArray>
#include <QJsonObject>
#include "product.h"
#include "comment.h"

class DB;

namespace Ui {
class productShow;
}

class productShow : public QDialog
{
    Q_OBJECT

public:
    explicit productShow(QWidget *parent = 0,int labelID = 0, QString productId = "");
    ~productShow();
signals:
    void getComment(int labelId, QString productId);
public slots:
    void Show();
    void on_commentBtn_clicked();
private:
    Ui::productShow *ui;
public:
    QString ProductId;
    QPushButton *pushButton;
    int labelId;
};

#endif // PRODUCTSHOW_H

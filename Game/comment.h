#ifndef COMMENT_H
#define COMMENT_H

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

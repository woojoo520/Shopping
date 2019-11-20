#ifndef MYLABEL_H
#define MYLABEL_H
#include <QLabel>
#include <QString>
#include <QWidget>
#include <QMainWindow>
#include <QJsonArray>
#include <QObject>
#include <QLineEdit>
#include "QMessageBox"
#include "productshow.h"

class Mylabel:public QLabel
{
    Q_OBJECT
public:
    Mylabel(const QString &text,QWidget *parent=0, QString productId = "");
    ~Mylabel(){}
signals:
    void clicked(int tag, QString productId);
    void showC(QJsonArray commentInfo);
public slots:
    void showComment();
protected:
    void mousePressEvent(QMouseEvent* event);
private:
public:
    QString productId;
    QJsonArray commentInfo;
    int tag;
    QLineEdit lineEdit;
};

#endif // MYLABEL_H

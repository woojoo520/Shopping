#ifndef DB_H
#define DB_H

#include <QObject>
#include <QApplication>
#include <QSql>
#include <QDialog>
#include <QDebug>
#include <QMessageBox>
#include<QSqlError>
#include<QSqlDatabase>
#include<QSqlQuery>
#include "product.h"

class DB : public QObject
{
    Q_OBJECT
public:
    explicit DB(QObject *parent = nullptr);
    QVector<Product> searchProductInfo();
    bool OpenDatabase();
    QString UserRegister(QVector<QString> InfoVec);
    QVector<QString> isLogon(QVector<QString> InfoVec);
signals:
    void sendImg();
public slots:
    bool updateImgSrc(QVector<QString> InfoVec);
private:
    QSqlDatabase db;
};

#endif // DB_H

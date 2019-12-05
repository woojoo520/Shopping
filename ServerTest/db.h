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
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonValue>

#include "product.h"

class DB : public QObject
{
    Q_OBJECT
public:
    explicit DB(QObject *parent = nullptr);
    QJsonArray searchProductInfo(QJsonObject infoJson);
    bool OpenDatabase();
    QString UserRegister(QJsonObject infoJson);
    QJsonObject isLogon(QJsonObject infoJson);
    bool logout(QString user_name);
    QJsonArray queryComment(QString ProductId);
    QJsonObject insertComment(QJsonObject commentJson);
    void praise(QJsonObject praiseJson);
    QJsonArray getReleaseInfo(QJsonObject releaseInfo);
    QJsonObject releasePro(QJsonObject releseInfo);
    bool checkLogon(QString name);
    void addLogonUser(QJsonObject info);
    int getSeq(QJsonObject info);
    void addUnreadMsg(QJsonObject Info);
    QJsonArray getUnreadMsg(QJsonObject Info);
    QJsonArray getReadMsg(QJsonObject Info);
    void changeUnreadToRead(QJsonObject Info);
signals:
    void sendImg();
    void sendQueryRes(QJsonArray res);
public slots:
    bool updateImgSrc(QJsonObject infoJson);
    QJsonArray queryResult(QJsonObject query);

private:
    QSqlDatabase db;
};

#endif // DB_H

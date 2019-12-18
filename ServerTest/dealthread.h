#ifndef DEALTHREAD_H
#define DEALTHREAD_H
/**
 * @file dealthread.h
 * @author Meng Yeqing
 * @brief 
 * @version 0.1
 * @date 2019-12-15
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#include <QThread>
#include <QString>
#include <QtNetwork>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonArray>
//#include <QRunnable>
#include <QtCore>
#include "db.h"

class dealThread : public QThread
{
    Q_OBJECT
public:
    explicit dealThread(QJsonObject Info, QTcpSocket* conn);
    ~dealThread();
//    bool dealWithMsg(QJsonObject Info);
    void run();     // 声明继承于QThread虚函数 run()
signals:
    void forceLogOut(QString user_name, QTcpSocket* conn, QJsonObject user_out, QJsonObject user_in);
    void addUserToMap(QString user_name, QTcpSocket* conn);
//    void resultReady(const QString &s);

private:
    QTcpSocket* conn;
    QJsonObject Info;
    QByteArray sendInfo;
    DB db;
};



#endif // DEALTHREAD_H

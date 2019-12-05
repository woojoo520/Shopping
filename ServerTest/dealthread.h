#ifndef DEALTHREAD_H
#define DEALTHREAD_H

#include <QThread>
#include <QString>
#include <QtNetwork>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonArray>
#include "db.h"

class dealThread : public QThread
{
public:
    dealThread(QJsonObject Info, QTcpSocket* conn);
    ~dealThread();
    void dealWithMsg(QJsonObject Info);
    void run();     // 声明继承于QThread虚函数 run()
private:
    QTcpSocket* conn;

    QJsonObject Info;
    QByteArray sendInfo;
    DB db;
};

#endif // DEALTHREAD_H

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
#include <QRunnable>
#include "db.h"

class dealThread : public QThread, public QRunnable
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

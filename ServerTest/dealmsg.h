#ifndef DEALMSG_H
#define DEALMSG_H

/**
 * @file dealmsg.h
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
#include "db.h"

class dealMsg : public QObject, public QRunnable
{
public:
    dealMsg(QJsonObject Info, QTcpSocket* conn);
private:
    QTcpSocket* conn;

    QJsonObject Info;
    QByteArray sendInfo;
    DB db;
};

#endif // DEALMSG_H

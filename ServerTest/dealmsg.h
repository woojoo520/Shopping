#ifndef DEALMSG_H
#define DEALMSG_H

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

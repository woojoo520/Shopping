#ifndef SERVERCONNECT_H
#define SERVERCONNECT_H

#include <QJsonArray>
#include <QJsonObject>
#include <QTcpSocket>
#include <QJsonDocument>

class ServerConnect
{
public:
    ServerConnect();
    QString executeQuery();
    void inform(const QString &msg, QTcpSocket *conn);
private:

};

#endif // SERVERCONNECT_H

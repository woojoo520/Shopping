#ifndef SERVERCONNECT_H
#define SERVERCONNECT_H

/**
 * @file serverconnect.h
 * @author Meng Yeqing
 * @brief 
 * @version 0.1
 * @date 2019-12-15
 * 
 * @copyright Copyright (c) 2019
 * 
 */
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

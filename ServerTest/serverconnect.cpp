#include "serverconnect.h"

ServerConnect::ServerConnect()
{

}

QString ServerConnect::executeQuery() {
    return "Successfully!" + QString::number(qrand());
}

void ServerConnect::inform(const QString &msg, QTcpSocket *conn) {
    if (conn->state() == QTcpSocket::ConnectedState) {
        QJsonDocument jdoc;
        QJsonObject jobj, payload;
        payload.insert("msg", msg);
        jdoc.setObject(jobj);
        auto x = jdoc.toJson(QJsonDocument::Compact);
        conn->write(x);
    }
}

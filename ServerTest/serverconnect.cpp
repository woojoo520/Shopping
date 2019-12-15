#include "serverconnect.h"

/**
 * @brief Construct a new Server Connect:: Server Connect object
 * 
 */
ServerConnect::ServerConnect()
{

}

/**
 * @brief Execute new request
 * 
 * @return QString 
 */
QString ServerConnect::executeQuery() {
    return "Successfully!" + QString::number(qrand());
}

/**
 * @brief Decoding new requests
 * 
 * @param msg 
 * @param conn 
 */
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

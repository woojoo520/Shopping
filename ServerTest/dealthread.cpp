#include "dealthread.h"

/**
 * @brief Construct a new deal Thread::deal Thread object
 * 
 * @param Info 
 * @param conn 
 */
dealThread::dealThread(QJsonObject Info, QTcpSocket* conn)
{
    this->conn = conn;
    this->Info = Info;
    dealWithMsg(Info);

    qDebug() << QJsonDocument::fromJson(sendInfo).object();

    this->conn->write(sendInfo);
}

/**
 * @brief Destroy the deal Thread::deal Thread object
 * 
 */
dealThread::~dealThread() {
    qDebug() << "析构" << endl;
}

/**
 * @brief run a thread
 * 
 */
void dealThread::run() {
    qDebug() << "Sending reply" << endl;
}

/**
 * @brief Process the information sent from the client, and call different functions to process according to the information in the type field
 * 
 * @param Info 
 */
bool dealThread::dealWithMsg(QJsonObject Info) {
    QJsonObject infoJson;
    infoJson["type"] = Info["type"];
    if(Info["type"] == "searchProductInfo") {
        QJsonArray infoArray = db.searchProductInfo(Info);
        if(infoArray.size() > 0)  {
            infoJson["warning"] = "Successfully!";
        } else {
            infoJson["warning"] = "failed!";
        }
        infoJson["array"] = infoArray;
        infoJson["object"] = Info["object"];
        sendInfo = QJsonDocument(infoJson).toJson();
    } else if(Info["type"] == "isLogon") {
        QJsonObject infoJson = db.isLogon(Info);
        infoJson["type"] = "isLogon";
        sendInfo = QJsonDocument(infoJson).toJson();
    } else if(Info["type"] == "UserRegister") {
        QString str = db.UserRegister(Info);
        if(str == "successfully") {
            infoJson["warning"] = "Successfully!";
        } else {
            infoJson["warning"] = "failed!";
        }
        sendInfo = QJsonDocument(infoJson).toJson();
    } else if(Info["type"] == "updateImgSrc") {
        bool isSucc = db.updateImgSrc(Info);
        if(isSucc) {
            infoJson["warning"] = "Successfully!";
        } else {
            infoJson["warning"] = "failed!";
        }
        sendInfo = QJsonDocument(infoJson).toJson();
    } else if(Info["type"] == "queryComment") {
        QJsonArray commentInfo = db.queryComment(Info["ProductId"].toString());
        infoJson["array"] = commentInfo;
        infoJson["labelId"] = Info["labelId"];
//            qDebug() << "labelId = " << Info["labelId"] << " " << Info["labelId"].toInt();
        sendInfo = QJsonDocument(infoJson).toJson();
    } else if(Info["type"] == "queryResult") {
        QJsonArray array = db.queryResult(Info);
        if(array.size() > 0) {
            infoJson["warning"] = "Successfully!";
        } else {
            infoJson["warning"] = "failed!";
        }
        infoJson["array"] = array;
        sendInfo = QJsonDocument(infoJson).toJson();
    } else if(Info["type"] == "logout") {
        bool isLogOutSucc = db.logout(Info["User_name"].toString());
        QJsonObject infoJson;
        infoJson["type"] = "logout";
        infoJson["isLogOutSucc"] = isLogOutSucc ? "true" : "false";
        sendInfo = QJsonDocument(infoJson).toJson();
    } else if(Info["type"] == "sendComment") {
        QJsonObject infoJson = db.insertComment(Info);
        infoJson["labelId"] = Info["labelId"].toInt();
        sendInfo = QJsonDocument(infoJson).toJson();
    } else if(Info["type"] == "praise") {
        db.praise(Info);
    } else if(Info["type"] == "releaseProduct") {
        QJsonObject infoJson;
        infoJson = db.releasePro(Info);
        infoJson["type"] = "releaseProduct";

        QJsonArray infoArray = db.searchProductInfo(Info);
        sendInfo = QJsonDocument(infoJson).toJson();
//            qDebug() << "size = " << infoArray.size() << " type = " << infoJson["warning"] << endl;
        if(infoArray.size() > 0)  {
            infoJson["warning"] = "Successfully!";
        } else {
            infoJson["warning"] = "failed!";
        }
        infoJson["array"] = infoArray;
        infoJson["object"] = Info["object"];
        sendInfo = QJsonDocument(infoJson).toJson();
    } else if(Info["type"] == "order") {
//            Info["user_name"] = "MYQ";
//            Info["SellerName"]
        bool isLogon = db.checkLogon(Info["user_name"].toString());
        if(isLogon) {
            // 如果已经登陆的话，就直接将有消息的内容发送给用户
            int seq = db.getSeq(Info);
            if(seq >= 0) {
                QJsonObject infoJson;
                infoJson["type"] = "sendMsg";
                infoJson["Msg"] = Info;
            }
        }
        // 将消息发送到未读队列当中
        db.addUnreadMsg(Info);
    } else if(Info["type"] == "readMsg") {
        // 将未读消息转移到已读消息中

    } else if(Info["type"] == "getMsg") {
        // 给用户发送他们的消息，包括已读消息和未读消息
        QJsonObject infoJson;
        infoJson["readMsg"] = db.getReadMsg(Info);
        infoJson["unreadMsg"] = db.getUnreadMsg(Info);
        infoJson["type"] = "getMsg";
        sendInfo = QJsonDocument(infoJson).toJson();
    } else if(Info["type"] == "readXMsg") {
        db.changeUnreadToRead(Info);
    } else if(Info["type"] == "productShowMsg") {
        QJsonObject infoJson = db.productShowMsg(Info);
        sendInfo = QJsonDocument(infoJson).toJson();
    } else if(Info["type"] == "rearr_Unread") {
        db.rearrangeUnreadId();
        return false;
    } else if(Info["type"] == "rearr_Read") {
        db.rearrangeReadId();
        return false;
    }
//    else if(Info["type"] == "del_Invalid") {
//        db.delInvalidId();
//        return false;
//    }
    return true;

}


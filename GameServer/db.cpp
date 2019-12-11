#include "db.h"

DB::DB(QObject *parent) : QObject(parent)
{
    OpenDatabase();
}

bool DB::OpenDatabase()
{
    db = QSqlDatabase::addDatabase("QODBC");   //数据库驱动类型为SQL Server
    qDebug()<<"ODBC driver?"<<db.isValid();
    QString dsn = QString::fromLocal8Bit("GameInfo");       //数据源名称
    db.setHostName("localhost");                            //选择本地主机，127.0.1.1
    db.setDatabaseName(dsn);                                //设置数据源名称
    db.setUserName("MYQ");                                  //登录用户
    db.setPassword("0504");                                 //密码
    if(!db.open())                                          //打开数据库
    {
        qDebug()<<db.lastError().text();
        QMessageBox::critical(0, QObject::tr("Database error"), db.lastError().text());
        return false;                                       //打开失败
    }
    else
    {
        qDebug()<<"database open success!";
        QSqlQuery query(db); //查询Card表并输出，测试能否正常操作数据库
        query.exec("SELECT * FROM Card");
        while(query.next())
        {
            qDebug()<<query.value(0).toInt() <<query.value(1).toString() <<query.value(2).toInt();
        }

    }
    return true;
}

QJsonArray DB::searchProductInfo() {
    QJsonArray productArray;
    QSqlQuery query(db);
    QString searchStr = "SELECT * FROM Product ORDER BY popular";
    query.exec(searchStr);
    while(query.next()) {
        QJsonObject productJson;
        productJson["product_id"] = query.value(0).toString();
        productJson["seller_name"] = query.value(1).toString();
        productJson["state"] = query.value(2).toString();
        productJson["price"] = query.value(3).toString();
        productJson["description"] = query.value(4).toString();
        productJson["src"] = query.value(5).toString();
        productJson["tag"] = query.value(6).toString();
        productArray.append(productJson);
    }
    return productArray;
}

QJsonObject DB::isLogon(QJsonObject infoJson) {
    QJsonObject resJson;
    if(infoJson["User_name"] == "" || infoJson["User_pwd"] == "") {
        resJson["warning"] = "Sorry, Please complete the infomation";
//        resInfo.push_back("Sorry, Please complete the infomation");
    } else {
        QString name =infoJson["User_name"].toString();
        QString pwd = infoJson["User_pwd"].toString();
        QString str = QString("SELECT * FROM UserInfo WHERE user_name = '%1' AND user_pwd = '%2'").arg(name, pwd);
        qDebug() << str << endl;
        QSqlQuery query(db);
        query.exec(str);
        if(query.next()) {
            if(query.value(5).toString() == "1") {
                resJson["warning"] = "Sorry, the user has been signed in!";
            } else {
                QSqlQuery query2(db);
                QString searchStr2 = "UPDATE UserInfo SET isLogon = 1 WHERE user_name = '" + infoJson["User_name"].toString() + "'";
//                qDebug() << searchStr2 << endl;
                bool isSuccess = query2.exec(searchStr2);
                if(isSuccess) {
                    resJson["warning"] = "Logon Successfully!";
                    resJson["usr_logo"] = query.value(4).toString();
                    resJson["usr_name"] = infoJson["User_name"];
                } else {
                    resJson["warning"] = "Sorry, Logon failed!";
                }
            }
        } else {
            resJson["warning"] = "Sorry, your password is wrong";
        }
    }
    return resJson;
}

bool DB::updateImgSrc(QJsonObject infoJson) {
    QSqlQuery query(db);
    QString searchStr = "UPDATE UserInfo SET Img = '" + infoJson["savePath"].toString() + "' WHERE user_name = '" + infoJson["User_name"].toString() + "'";
    qDebug() << searchStr << endl;
    bool isUpdate = query.exec(searchStr);
    if(isUpdate) {
        qDebug() << "更新src成功" << endl;
        return true;
    } else {
        return false;
        // 暂时还没有实现成功或失败的提示
    }
}

QString DB::UserRegister(QJsonObject infoJson) {
    qDebug() << "name = " << infoJson["User_Name"].toString() << endl;
    qDebug() <<  infoJson.size() << endl;
    if(infoJson.size() < 7) {
        return "Sorry, the information you provide is not enough";
    } else if(infoJson["User_pwd"].toString() != infoJson["resurePwd"].toString()) {
        return "Sorry, the passwords you input are inconsistent";
    }
    QSqlQuery query(db);
    QString searchStr = "SELECT * FROM UserInfo WHERE user_name = " + infoJson["User_Name"].toString();
    query.exec(searchStr);
    if(query.next()) {
        return "Sorry, the user name has been registered";
    }
//    searchStr = "INSERT INTO UserInfo VALUES(\'%1\', \'%2\', \'%3\', \'%4\')".arg(InfoVec[0], InfoVec[1], InfoVec[2], InfoVec[3]);
    searchStr = "INSERT INTO UserInfo VALUES( \'" + infoJson["User_Name"].toString() + "\', \'" + infoJson["User_pwd"].toString() + "\', \'" + infoJson["User_Address"].toString() + "\', \'" + infoJson["User_Phone"].toString() + "\', \'" + infoJson["fileName"].toString() + "\', 0)";
    qDebug() << searchStr;
    bool isSucc = query.exec(searchStr);
    if(!isSucc) {
        return "failed!";
    } else {
        // 当注册成功的时候，需要将用户的头像存储的位置全部保存到本地服务器的指定位置
        return "successfully";
    }
}

QJsonArray DB::queryResult(QJsonObject queryInfo) {
    QJsonArray productArray;
    QSqlQuery query(db);
    QString priceDesc = queryInfo["priceQuery"].toString().toUtf8() == tr("from low to high") ? "ASC" : "DESC";
    QString newDesc = queryInfo["newQuery"].toString() == ("from new to old") ?  "ASC" : "DESC";
    QString searchStr = "SELECT * FROM Product ";
    if(queryInfo["searchP"] != "") {
        searchStr += "WHERE description LIKE '%" + queryInfo["searchP"].toString() + "%' OR tag LIKE '%" + queryInfo["searchP"].toString() + "%'";
    }else if(queryInfo["catogary"] != "") {
        searchStr += "WHERE description LIKE '%" + queryInfo["catogary"].toString() + "%' OR tag LIKE '%" + queryInfo["catogary"].toString() + "%'";
    }
    searchStr += " ORDER BY price " + priceDesc + ", date " + newDesc + ", popular ASC";
    qDebug() << searchStr << endl;
    bool isSucc = query.exec(searchStr);
    if(!isSucc) {
        qDebug() << "failed!" << endl;
        return productArray;
    }
    while(query.next()) {
        QJsonObject productJson;
        productJson["product_id"] = query.value(0).toString();
        productJson["seller_name"] = query.value(1).toString();
        productJson["state"] = query.value(2).toString();
        productJson["price"] = query.value(3).toString();
        productJson["description"] = query.value(4).toString();
        productJson["src"] = query.value(5).toString();
        productJson["tag"] = query.value(6).toString();
        productArray.append(productJson);
    }
    return productArray;
}

bool DB::logout(QString user_name) {
    QSqlQuery query(db);
    QString searchStr = "UPDATE UserInfo SET isLogon = 0 WHERE user_name = '" + user_name + "'";
    qDebug() << searchStr << endl;
    bool isSuccess = query.exec(searchStr);
    if(isSuccess) {
        return true;
    }
    return false;
}

QJsonArray DB::queryComment(QString ProductId) {
    QJsonArray jsonArray;
    QSqlQuery query(db);
    QString searchStr = "SELECT UserInfo.user_name, comment, Img, popular, Product_Id, Id  FROM UserInfo JOIN comment ON UserInfo.user_name = comment.User_name WHERE Product_Id = '" + ProductId + "' ORDER BY popular desc";
    qDebug() << searchStr << endl;
    bool isSuccess = query.exec(searchStr);
    if(!isSuccess) {
        qDebug() << "No" << endl;
        return jsonArray;
    }
    while(query.next()) {
        QJsonObject jsonObject;
        jsonObject["User_name"] = query.value(0).toString();
        jsonObject["comment"] = query.value(1).toString();
        jsonObject["Img"] = query.value(2).toString();
        jsonObject["popular"] = query.value(3).toInt();
        jsonObject["Product_Id"] = query.value(4).toString();
        jsonObject["Id"] = query.value(5).toInt();
        jsonArray.append(jsonObject);
    }
    return jsonArray;
}

QJsonObject DB::insertComment(QJsonObject commentJson) {
    QJsonObject res;
    res["type"] = "queryComment";
    res["productId"] = commentJson["productId"].toString();
    QSqlQuery query(db);
    query.exec("Select count(*) from comment");
    int num = 0;
    while(query.next()) {
        num = query.value(0).toInt();
    }
    qDebug() << num << endl;
    QString searchStr = "Insert into comment values('" + commentJson["productId"].toString() + "', '" + commentJson["User_name"].toString() + "', '" + commentJson["comment"].toString() + "', 0, DEFAULT, " + QString::number(num + 1) + ")";
    qDebug() << searchStr << endl;
    bool isSuccess = query.exec(searchStr);
    if(!isSuccess) {
        res["warning"] = "failed";
        return res;
    } else {
        res["warning"] = "Successfully!";
        res["array"] = queryComment(commentJson["productId"].toString());
        return res;
    }
}


void DB::praise(QJsonObject praiseJson) {
    QSqlQuery query(db);
    qDebug() << praiseJson["Id"].toInt();
    QString searchStr;
    if(praiseJson["isadd"].toString() == "true") {
        searchStr = "update comment set popular = popular + 1 where Id = " + QString::number(praiseJson["Id"].toInt());
    } else {
        searchStr = "update comment set popular = popular - 1 where Id = " + QString::number(praiseJson["Id"].toInt());
    }
    qDebug() << searchStr;
    query.exec(searchStr);

}

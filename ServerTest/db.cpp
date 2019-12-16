#include "db.h"

/**
 * @brief Construct a new DB::DB object
 * open the database
 * @param parent 
 */
DB::DB(QObject *parent) : QObject(parent)
{
    OpenDatabase();
}
/**
 * @brief open the database
 * Connect to database according to account password
 * @return true 
 * @return false 
 */
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

/**
 * @brief Get information about the specified product
 * 
 * @param infoJson 
 * @return QJsonObject 
 */
QJsonObject DB::productShowMsg(QJsonObject infoJson) {
    QJsonObject resJson;
    resJson["type"] = "productShowMsg";
    QSqlQuery query(db);
    QString searchStr = "select product_name, price, state, seller_name, description, src from Product where product_Id = '" + infoJson["productId"].toString() + "'";
    qDebug() << "msg: " << searchStr;
    bool isSucc = query.exec(searchStr);
    if(isSucc) {
        if(query.next()) {
            resJson["productId"] = infoJson["productId"];
            resJson["product_name"] = query.value(0).toString();
            resJson["price"] = query.value(1).toString();
            resJson["state"] = query.value(2).toString();
            resJson["seller_name"] = query.value(3).toString();
            resJson["description"] = query.value(4).toString();
            resJson["src"] = query.value(5).toString();
            return resJson;
        }
    }
}

/**
 * @brief Get information about the product
 * Get information about the product from the database (commodity ID, name, price, remaining quantity, seller, detailed description of the product and product image address), and return it to the client
 * @param infoJson 
 * @return QJsonArray 
 */
QJsonArray DB::searchProductInfo(QJsonObject infoJson) {
    QJsonArray productArray;
    QSqlQuery query(db);

    QString searchStr = "";
    if(infoJson["object"] == "user") {
        searchStr = "SELECT * FROM Product ORDER BY popular";
    } else {
        searchStr = "SELECT P.product_id, P.seller_name, P.state, P.price, P.description, P.src, P.tag\
                     FROM Seller_product AS S JOIN Product AS P ON S.product_id = P.product_id\
                     WHERE S.user_name = '" + infoJson["User_name"].toString() + "'";
//        qDebug() << searchStr << endl;
    }

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
        if(infoJson["object"] == "user") {
            productJson["product_name"] = query.value(9).toString();
        }
        productArray.append(productJson);
    }
    return productArray;
}

/**
 * @brief User login
 * Query whether the user's login information is correct. If it is not, an error will be reported. If it is correct, query whether someone has logged in at present. If it is, you cannot log in repeatedly
 * @param infoJson 
 * @return QJsonObject 
 */
QJsonObject DB::isLogon(QJsonObject infoJson) {
    QJsonObject resJson;
    if(infoJson["User_name"] == "" || infoJson["User_pwd"] == "") {
        resJson["warning"] = "Sorry, Please complete the infomation";
//        resInfo.push_back("Sorry, Please complete the infomation");
    } else {
        QString name =infoJson["User_name"].toString();
        QString pwd = infoJson["User_pwd"].toString();
        QString str = QString("SELECT * FROM UserInfo WHERE user_name = '%1' AND user_pwd = '%2'").arg(name, pwd);
//        qDebug() << str << endl;
        QSqlQuery query(db);
        query.exec(str);
        if(query.next()) {
            if(query.value(5).toString() == "1") {
//                resJson["warning"] = "Sorry, the user has been signed in!";
                resJson["warning"] = "Sorry, your account has been logged in elsewhere, you are forced to go offline";
            } else {
                QSqlQuery query2(db);
                QString searchStr2 = "UPDATE UserInfo SET isLogon = 1 WHERE user_name = '" + infoJson["User_name"].toString() + "'";
//                qDebug() << searchStr2 << endl;
                bool isSuccess = query2.exec(searchStr2);
                if(isSuccess) {
                    addLogonUser(infoJson);
                    resJson["warning"] = "Logon Successfully!";
                    resJson["usr_logo"] = query.value(4).toString();
                    resJson["usr_name"] = infoJson["User_name"];
                    // 登录成功的时候需要查看一下当前是否有消息，如果有则需要将消息返回
                    resJson["readMsg"] = getReadMsg(infoJson);
                    resJson["unreadMsg"] = getUnreadMsg(infoJson);

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

/**
 * @brief Get user's unprocessed order message
 * 
 * @param Info 
 * @return QJsonArray 
 */
QJsonArray DB::getUnreadMsg(QJsonObject Info) {
    QJsonArray msgArray;
    QSqlQuery query(db);
    QString searchStr = "select UserMsg, UserName, Id from Unread_Msg where SellerName = '" + Info["User_name"].toString() + "'";
    query.exec(searchStr);
//    qDebug() << searchStr << endl;
    while(query.next()) {
        QJsonObject msgObj;
        msgObj["Msg"] = query.value(0).toString();
        msgObj["user_name"] = query.value(1).toString();
        msgObj["Id"] = query.value(2).toInt();
        msgArray.append(msgObj);
    }
    return msgArray;
}

QJsonArray DB::getReadMsg(QJsonObject Info) {
    QJsonArray msgArray;
    QSqlQuery query(db);
    QString searchStr = "select UserMsg, UserName, Id from read_Msg where SellerName = '" + Info["User_name"].toString() + "'";
//    qDebug() << searchStr << endl;
    query.exec(searchStr);
    while(query.next()) {
        QJsonObject msgObj;
        msgObj["Msg"] = query.value(0).toString();
        msgObj["user_name"] = query.value(1).toString();
        msgObj["Id"] = query.value(2).toInt();
        msgArray.append(msgObj);
    }
    return msgArray;
}

/**
 * @brief Get the data of the product that this user has published
 * 
 * @param releaseInfo 
 * @return QJsonArray 
 */
QJsonArray DB::getReleaseInfo(QJsonObject releaseInfo) {
    QSqlQuery query(db);
    QJsonArray res;
    QString searchStr = "SELECT P.product_id, .src, P.price, P.description, S.quantity\
                         FROM Seller_product AS S JOIN Product AS P ON S.product_id = P.product_id\
                         WHERE S.SellerName = \'" + releaseInfo["User_name"].toString() + "\'";
    query.exec(searchStr);
    while(query.next()) {
        QJsonObject productJson;
        productJson["product_id"] = query.value(0).toString();
        productJson["price"] = query.value(1).toFloat();
        productJson["description"] = query.value(2).toString();
        productJson["quantity"] = query.value(3).toInt();
        res.push_back(productJson);
    }
    return res;
}

QJsonObject DB::releasePro(QJsonObject releseInfo) {
    QJsonObject ret;
    QSqlQuery query(db);
    QString searchStr = "select count(*) from Product";
    query.exec(searchStr);
    int ID = 0;
    if(query.next()) {
        ID = query.value(0).toInt();
    }

    searchStr = "insert into Product values('" + QString::number(ID + 1) + "', '" + releseInfo["seller_name"].toString() + "', " + QString::number(releseInfo["quantity"].toString().toInt()) + ", " + QString::number(releseInfo["price"].toString().toFloat()) + ", '" + releseInfo["discription"].toString() + "', '" + releseInfo["src"].toString() + "', '" + releseInfo["tag"].toString() + "', 0, NULL)";
//    qDebug() << searchStr;
    bool isSucc1 = query.exec(searchStr);
    searchStr = "insert into Seller_product values('" + releseInfo["seller_name"].toString() +"', '" + QString::number(ID + 1) + "', " + QString::number(releseInfo["quantity"].toInt()) + ")";
    bool isSucc2 = query.exec(searchStr);
//    qDebug() <<searchStr << endl;
    if(isSucc1 && isSucc2) {
        ret["warning"] = "successfully!";
    } else {
        ret["warning"] = "failed!";
    }
    return ret;
}

/**
 * @brief Update user's picture information
 * 
 * @param infoJson 
 * @return true 
 * @return false 
 */
bool DB::updateImgSrc(QJsonObject infoJson) {
    QSqlQuery query(db);
    QString searchStr = "UPDATE UserInfo SET Img = '" + infoJson["savePath"].toString() + "' WHERE user_name = '" + infoJson["User_name"].toString() + "'";
//    qDebug() << searchStr << endl;
    bool isUpdate = query.exec(searchStr);
    if(isUpdate) {
//        qDebug() << "更新src成功" << endl;
        return true;
    } else {
        return false;
        // 暂时还没有实现成功或失败的提示
    }
}

/**
 * @brief New user registration
 * According to the user's registration information, first judge whether the information is complete, then judge whether to use the duplicate name. If all meet the requirements, return true, otherwise, return false
 * @param infoJson 
 * @return QString 
 */
QString DB::UserRegister(QJsonObject infoJson) {
//    qDebug() << "name = " << infoJson["User_Name"].toString() << endl;
//    qDebug() <<  infoJson.size() << endl;
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
//    qDebug() << searchStr;
    bool isSucc = query.exec(searchStr);
    if(!isSucc) {
        return "failed!";
    } else {
        // 当注册成功的时候，需要将用户的头像存储的位置全部保存到本地服务器的指定位置
        return "successfully";
    }
}

/**
 * @brief Determine whether the account name has been logged in
 * 
 * @param name 
 * @return true 
 * @return false 
 */
bool DB::checkLogon(QString name) {
    QSqlQuery query(db);
    QString searchStr = "select isLogon from UserInfo where user_name = '" + name + "'";
    query.exec(searchStr);
    if(query.next()) {
        int isLogon = query.value(0).toInt();
        if(isLogon) {
            return true;
        }
    }
    return false;
}

/**
 * @brief Get filtered product information
 * Get the filtered product information according to the keywords given by the user, the sorting order selected on the interface and the category information on the left side of the interface 
 * 
 * @param queryInfo 
 * @return QJsonArray 
 */
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
//    qDebug() << searchStr << endl;
    bool isSucc = query.exec(searchStr);
    if(!isSucc) {
//        qDebug() << "failed!" << endl;
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

/**
 * @brief Add the user's login information to the database
 * 
 * @param info 
 */
void DB::addLogonUser(QJsonObject info) {
    QSqlQuery query(db);
    QString searchStr = "insert into logon values('" + info["User_name"].toString() + "', " + info["seq"].toString() + ")";
//    qDebug() << searchStr;
    query.exec(searchStr);
    return ;
}

/**
 * @brief Get user's sequence
 * 
 * @param info 
 * @return int 
 */
int DB::getSeq(QJsonObject info) {
    QSqlQuery query(db);
    QString searchStr = "select seq from logon where user_name = '" + info["SellerName"].toString() +  "'";
    query.exec(searchStr);
    if(query.next()) {
        return query.value(0).toInt();
    } else {
        return -1;
    }
}

/**
 * @brief New order information needs to be recorded and added to the seller's unprocessed message
 * 
 * @param Info 
 */
void DB::addUnreadMsg(QJsonObject Info) {
    QSqlQuery query(db);
    QString searchStr = "select count(*) from Unread_Msg";
    query.exec(searchStr);
    int msgNum = 0;
    if(query.next()) {
        msgNum = query.value(0).toInt();
    }
    searchStr = "insert into Unread_Msg values (" + QString::number(msgNum + 1) + ", '" + Info["SellerName"].toString() + "', '" + Info["Msg"].toString() + "', '" + Info["user_name"].toString() + "', DEFAULT, GETDATE())";
    query.exec(searchStr);
//    qDebug() << searchStr << endl;
    return ;
}

/**
 * @brief User logout
 * When users log out, they need to modify their login status
 * @param user_name 
 * @return true 
 * @return false 
 */
bool DB::logout(QString user_name) {
    QSqlQuery query(db);
    QString searchStr = "UPDATE UserInfo SET isLogon = 0 WHERE user_name = '" + user_name + "'";
//    qDebug() << searchStr << endl;
    bool isSuccess = query.exec(searchStr);
    if(isSuccess) {
        searchStr = "delete from logon where user_name = '" + user_name + "'";
        query.exec(searchStr);
        return true;
    }
    return false;
}

/**
 * @brief Get the user's comments on a specific product
 * 
 * @param ProductId 
 * @return QJsonArray 
 */
QJsonArray DB::queryComment(QString ProductId) {
    QJsonArray jsonArray;
    QSqlQuery query(db);
    QString searchStr = "SELECT UserInfo.user_name, comment, Img, popular, Product_Id, Id  FROM UserInfo JOIN comment ON UserInfo.user_name = comment.User_name WHERE Product_Id = '" + ProductId + "' ORDER BY popular desc";
    qDebug() << searchStr << endl;
    bool isSuccess = query.exec(searchStr);
    if(!isSuccess) {
//        qDebug() << "No" << endl;
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
    qDebug() << jsonArray.size() <<endl;
    return jsonArray;
}

/**
 * @brief When the user finishes processing the order, he needs to take the order out of the unprocessed order and put it into the processed order
 * 
 * @param Info 
 */
void DB::changeUnreadToRead(QJsonObject Info) {
    int Id = Info["Id"].toInt();
    QSqlQuery query(db);

    QString searchStr = "select count(*) from read_Msg";
    query.exec(searchStr);
    int read_num = 0;
    if(query.next()) {
        read_num = query.value(0).toInt();
//        qDebug() << read_num << endl;
    }

    searchStr = "select Id, SellerName, UserMsg, UserName, date from Unread_Msg where Id = " + QString::number(Id);
//    qDebug() << searchStr << endl;
    query.exec(searchStr);
    if(query.next()) {
        QString res = QString::number(read_num + 1) + ", '" + query.value(1).toString() + "', '" + query.value(2).toString() + "', '" + query.value(3).toString() + "', DEFAULT, '" + query.value(4).toString() + "'";
        searchStr = "insert into read_Msg values(" + res + ")";
//        qDebug() << searchStr << endl;
        query.exec(searchStr);
    }
    searchStr = "delete from Unread_Msg where Id = " + QString::number(Id);
//    qDebug() << searchStr << endl;
    query.exec(searchStr);
}

/**
 * @brief Add comment information
 * 
 * @param commentJson 
 * @return QJsonObject 
 */
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
//    qDebug() << num << endl;
    QString searchStr = "Insert into comment values('" + commentJson["productId"].toString() + "', '" + commentJson["User_name"].toString() + "', '" + commentJson["comment"].toString() + "', 0, DEFAULT, " + QString::number(num + 1) + ")";
//    qDebug() << searchStr << endl;
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

/**
 * @brief Record user's likes
 * 
 * @param praiseJson 
 */
void DB::praise(QJsonObject praiseJson) {
    QSqlQuery query(db);
//    qDebug() << praiseJson["Id"].toInt();
    QString searchStr;
    if(praiseJson["isadd"].toString() == "true") {
        searchStr = "update comment set popular = popular + 1 where Id = " + QString::number(praiseJson["Id"].toInt());
    } else {
        searchStr = "update comment set popular = popular - 1 where Id = " + QString::number(praiseJson["Id"].toInt());
    }
//    qDebug() << searchStr;
    query.exec(searchStr);

}

void DB::rearrangeUnreadId() {
    QSqlQuery query(db);
    QString searchStr("EXEC RearrangeUnread");
    query.exec(searchStr);
}

void DB::rearrangeReadId() {
    QSqlQuery query(db);
    QString searchStr("EXEC RearrangeRead");
    bool isSucc = query.exec(searchStr);
    if(!isSucc) {
        qDebug() << "Failed" << endl;
    }
}

void DB::delInvalidId() {
    QSqlQuery query(db);
    QString searchStr("EXEC DelInvalidId");
    query.exec(searchStr);
}

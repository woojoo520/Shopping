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

QVector<Product> DB::searchProductInfo() {
    QVector<Product> productVec;
    QSqlQuery query(db);
    QString searchStr = "SELECT * FROM Product ORDER BY popular";
    query.exec(searchStr);
    while(query.next()) {
        Product product;
        product.product_id = query.value(0).toString();
        product.seller_name = query.value(1).toString();
        product.state = query.value(2).toInt();
        product.price = query.value(3).toFloat();
        product.description = query.value(4).toString();
        product.src = query.value(5).toString();
        product.tag = query.value(6).toString();
        productVec.push_back(product);
    }
    return productVec;
}

QVector<QString> DB::isLogon(QVector<QString> InfoVec) {
    QVector<QString> resInfo;
    if(InfoVec[0] == "" || InfoVec[1] == "") {
        resInfo.push_back("Sorry, Please complete the infomation");
    } else {
        QString str = QString("SELECT * FROM UserInfo WHERE user_name = '%1' AND user_pwd = '%2'").arg(InfoVec[0], InfoVec[1]);
        qDebug() << str << endl;
        QSqlQuery query(db);
        query.exec(str);
        if(query.next()) {
            if(query.value(5).toString() == "1") {
                resInfo.push_back("Sorry, the user has been signed in!");
            } else {
                QSqlQuery query2(db);
                QString searchStr2 = "UPDATE UserInfo SET isLogon = 1 WHERE user_name = '" + InfoVec[0] + "'";
//                qDebug() << searchStr2 << endl;
                bool isSuccess = query2.exec(searchStr2);
                if(isSuccess) {
                    resInfo.push_back("Logon Successfully!");
                    QString usr_logo = query.value(4).toString();
                    QString usr_name = InfoVec[0];
                    resInfo.push_back(usr_name);
                    resInfo.push_back(usr_logo);
                }
                resInfo.push_back("Sorry, Logon failed!");
            }
        } else {
            resInfo.push_back("Sorry, your password is wrong");
        }
    }
    return resInfo;
}

bool DB::updateImgSrc(QVector<QString> InfoVec) {
    QSqlQuery query(db);
    QString searchStr = "UPDATE UserInfo SET Img = '" + InfoVec[1] + "' WHERE user_name = '" + InfoVec[0] + "'";
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

QString DB::UserRegister(QVector<QString> InfoVec) {
    if(InfoVec.size() < 6) {
        return "Sorry, the information you provide is not enough";
    } else if(InfoVec[1] != InfoVec[2]) {
        return "Sorry, the passwords you input are inconsistent";
    }
    QSqlQuery query(db);
    QString searchStr = "SELECT * FROM UserInfo WHERE user_name = " + InfoVec[0];
    query.exec(searchStr);
    if(query.next()) {
        return "Sorry, the user name has been registered";
    }
//    searchStr = "INSERT INTO UserInfo VALUES(\'%1\', \'%2\', \'%3\', \'%4\')".arg(InfoVec[0], InfoVec[1], InfoVec[2], InfoVec[3]);
    searchStr = "INSERT INTO UserInfo VALUES( \'" + InfoVec[0] + "\', \'" + InfoVec[1] + "\', \'" + InfoVec[3] + "\', \'" + InfoVec[4]+ "\', \'" + InfoVec[5] + "\', 0)";
    qDebug() << searchStr;
    bool isSucc = query.exec(searchStr);
    if(!isSucc) {
        return "Register failed!";
    } else {
        // 当注册成功的时候，需要将用户的头像存储的位置全部保存到本地服务器的指定位置
        emit sendImg();
        return "Register successfully";
    }
}

void DB::queryResult(QMap<QString, QString> queryInfo) {
    qDebug() << "queryResult" << endl;
    QVector<Product> productVec;
    QSqlQuery query(db);
    QString priceDesc = queryInfo["priceQuery"] == tr("从低到高") ? "ASC" : "DESC";
    QString newDesc = queryInfo["newQuery"] == ("从新到旧") ?  "ASC" : "DESC";
    QString searchStr = "SELECT * FROM Product ";
    if(queryInfo["searchP"] != "") {
        searchStr += "WHERE description LIKE '%" + queryInfo["searchP"] + "%' OR tag LIKE '%" + queryInfo["searchP"] + "%'";
    }else if(queryInfo["catogary"] != "") {
        searchStr += "WHERE description LIKE '%" + queryInfo["catogary"] + "%' OR tag LIKE '%" + queryInfo["catogary"] + "%'";
    }
    searchStr += " ORDER BY price " + priceDesc + ", date " + newDesc + ", popular ASC";
    qDebug() << searchStr << endl;
    bool isSucc = query.exec(searchStr);
    if(!isSucc) {
        qDebug() << "failed!" << endl;
        return ;
    }
    while(query.next()) {
        Product product;
        product.product_id = query.value(0).toString();
        product.seller_name = query.value(1).toString();
        product.state = query.value(2).toInt();
        product.price = query.value(3).toFloat();
        product.description = query.value(4).toString();
        product.src = query.value(5).toString();
        product.tag = query.value(6).toString();
        productVec.push_back(product);
    }
    for(int i = 0;i < productVec.size();i++) {
        qDebug() << productVec[i].price << endl;
    }
    emit sendQueryRes(productVec);
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

QVector<QPair<QString, QString>> DB::queryComment(QString ProductId) {
    QVector<QPair<QString, QString>> res;
    QSqlQuery query(db);
    QString searchStr = "SELECT User_name, comment FROM comment WHERE Product_Id = '" + ProductId + "'";
    qDebug() << searchStr << endl;
    bool isSuccess = query.exec(searchStr);
    if(!isSuccess) {
        qDebug() << "No" << endl;
        return res;
    }
    while(query.next()) {
        QPair<QString, QString> Info;
        Info.first = query.value(0).toString();
        Info.second = query.value(1).toString();
        res.push_back(Info);
    }
    return res;
}

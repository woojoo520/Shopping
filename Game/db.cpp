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
    QString searchStr = "SELECT * FROM Product";
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
            resInfo.push_back("Logon Successfully!");
            QString usr_logo = query.value(4).toString();
            QString usr_name = InfoVec[0];
            resInfo.push_back(usr_name);
            resInfo.push_back(usr_logo);
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
    searchStr = "INSERT INTO UserInfo VALUES( \'" + InfoVec[0] + "\', \'" + InfoVec[1] + "\', \'" + InfoVec[3] + "\', \'" + InfoVec[4]+ "\', \'" + InfoVec[5] + "\', NULL)";
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

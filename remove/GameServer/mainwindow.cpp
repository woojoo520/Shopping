#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //初始化QTcpServer对象
    server = new QTcpServer();
    //当服务器被客户端访问时，会触发newConnection信号，可以利用该信号作为触发信号，绑定槽函数server_New_connect
    connect(server,&QTcpServer::newConnection,this,&MainWindow::server_New_Connect);
    //设置默认IP和端口号
    ui->lineEdit_IP->setText("127.0.0.1");
    ui->lineEdit_Port->setText("6666");
    initDB();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initDB() {
    if(!db.OpenDatabase()) {
        QMessageBox::warning(this, "Warning", "Sorry, Can't access SQL Server");
    }
    getData();
//    PrintProductInfo();
}

// 从数据库获取Product信息
void MainWindow::getData() {
    QJsonArray ProductInfo;
    QJsonObject obj;
    obj["object"] = "user";
    ProductInfo = db.searchProductInfo(obj);
}

void MainWindow::on_pushButton_Listen_clicked(bool checked)
{
    //侦听一个端口，客户端可以使用这个端口访问服务器
    //服务器端IP
    QHostAddress IP(ui->lineEdit_IP->text());
    quint16 port = ui->lineEdit_Port->text().toUInt();

    //监听客户端ip和port
    if(server->listen(IP,port)) {
        //监听成功
    } else {
        //监听失败
        //QMessageBox::warning(this,"warning",tr("监听失败"));
    }
}

void MainWindow::socket_Send_Data(int index) {
    qDebug() << "index = " << index << endl;
    QTcpSocket *socket = socketList.at(index);
    //发送socket数据包
    qint64 writeResult = socket->write(sendInfo);
    bool BoolFlush = socket->flush();
    //从缓冲区读写数据，如果从缓冲区读写了数据，则返回true，否则返回false
    if(writeResult != -1 && BoolFlush == 1) {
        //返回值不为-1，则发送数据包成功！
        if(writeResult == 0) {
            QMessageBox::warning(this,"warning",tr("对不起，数据没有更新完成"));
        }
//        QMessageBox::warning(this,"warning",tr("写数据成功！%1").arg(writeResult),QMessageBox::Yes,QMessageBox::No);
    }
}

void MainWindow::on_pushButton_send_clicked()
{
    QMessageBox::warning(this, "warning", "clicked");
    qDebug() << socketList.size() << endl;
    QJsonObject infoJson;
    infoJson["content"] = ui->textEdit_Send->toPlainText();
    sendInfo = QJsonDocument(infoJson).toJson();
    for(int i = 0;i < socketList.size();i++) {
        socket_Send_Data(i);
    }
}

void MainWindow::server_New_Connect() {
    //获取客户端连接
    QTcpSocket *socket = server->nextPendingConnection();
    socketList.push_back(socket);
    //&QTcpSocket::readyRead 表示服务器接收到客户端数据后，自动触发readyRead信号
    QObject::connect(socket,&QTcpSocket::readyRead,this,&MainWindow::socket_Read_Data);
    QMessageBox::warning(this, "Info", "Server is connected!");
}

void MainWindow::socket_Read_Data() {
    buffer.clear();
//    qDebug() << Info["type"] << endl;
    for(unsigned int i = 0;i < socketList.size();i++) {
        QTcpSocket *socket = socketList.at(i);
        //读取缓冲区数据
        buffer = socket->readAll();
        if(buffer.isEmpty()) {
            continue;
        }
        Info = QJsonDocument::fromBinaryData(buffer).object();
        ui->textEdit->setText(QString(QJsonDocument(Info).toJson(QJsonDocument::Compact)));
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
            socket_Send_Data(i);
        } else if(Info["type"] == "isLogon") {
            Info["seq"] = QString::number(i);
            QJsonObject infoJson = db.isLogon(Info);
            infoJson["type"] = "isLogon";
            sendInfo = QJsonDocument(infoJson).toJson();
            QString str = sendInfo;
            ui->textEdit_Send->setText(str);
            socket_Send_Data(i);
        } else if(Info["type"] == "UserRegister") {
            QString str = db.UserRegister(Info);
            if(str == "successfully") {
                infoJson["warning"] = "Successfully!";
            } else {
                infoJson["warning"] = "failed!";
            }
            sendInfo = QJsonDocument(infoJson).toJson();
            socket_Send_Data(i);
        } else if(Info["type"] == "updateImgSrc") {
            bool isSucc = db.updateImgSrc(Info);
            if(isSucc) {
                infoJson["warning"] = "Successfully!";
            } else {
                infoJson["warning"] = "failed!";
            }
            sendInfo = QJsonDocument(infoJson).toJson();
            socket_Send_Data(i);
        } else if(Info["type"] == "queryComment") {
            QJsonArray commentInfo = db.queryComment(Info["ProductId"].toString());
            infoJson["array"] = commentInfo;
            infoJson["labelId"] = Info["labelId"];
            ui->textEdit_Send->setText(QString(QJsonDocument(infoJson).toJson(QJsonDocument::Compact)));
//            qDebug() << "labelId = " << Info["labelId"] << " " << Info["labelId"].toInt();
            sendInfo = QJsonDocument(infoJson).toJson();
            socket_Send_Data(i);
        } else if(Info["type"] == "queryResult") {
            QJsonArray array = db.queryResult(Info);
            if(array.size() > 0) {
                infoJson["warning"] = "Successfully!";
            } else {
                infoJson["warning"] = "failed!";
            }
            infoJson["array"] = array;
            sendInfo = QJsonDocument(infoJson).toJson();
            socket_Send_Data(i);
        } else if(Info["type"] == "logout") {
            bool isLogOutSucc = db.logout(Info["User_name"].toString());
            QJsonObject infoJson;
            infoJson["type"] = "logout";
            infoJson["isLogOutSucc"] = isLogOutSucc ? "true" : "false";
            sendInfo = QJsonDocument(infoJson).toJson();
            socket_Send_Data(i);
        } else if(Info["type"] == "sendComment") {
            QJsonObject infoJson = db.insertComment(Info);
            infoJson["labelId"] = Info["labelId"].toInt();
            sendInfo = QJsonDocument(infoJson).toJson();
            socket_Send_Data(i);
        } else if(Info["type"] == "praise") {
            db.praise(Info);
        } else if(Info["type"] == "releaseProduct") {
//            qDebug() << Info << endl;
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
            socket_Send_Data(i);

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
                    socket_Send_Data(seq);
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
            socket_Send_Data(i);
        } else if(Info["type"] == "readXMsg") {
            db.changeUnreadToRead(Info);
        }
    }
}

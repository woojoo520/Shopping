#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //初始化客户端对象
    socket = new QTcpSocket();
    connect_socket();

    //连接槽信号
    //关联readyRead和socket_Read_Data槽函数。服务器有数据发送时，会自动触发readyRead信号
    QObject::connect(socket,&QTcpSocket::readyRead,this,&MainWindow::socket_Read_Data);
    connect(&logon, SIGNAL(needRegister()), this, SLOT(showRegister()));
    logon.show();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showRegister() {
    logon.hide();
    reg.show();
}

void MainWindow::send_socketInfo(QJsonObject infoJson) {
    qint64 writeResult = socket->write(QJsonDocument(infoJson).toBinaryData());
    bool BoolFlush = socket->flush();
    if(writeResult != -1 && BoolFlush == 1) {
        //返回值不为-1，则发送数据成功
        if(writeResult == 0) {
            QMessageBox::warning(this,"warning",tr("写数据结果的返回值为0"));
        }
    }
}

//连接槽函数
void MainWindow::connect_socket()
{
    //取消所有连接
    socket->abort();
    //连接服务器
    socket->connectToHost("127.0.0.1",6666);
    if(!socket->waitForConnected(3000)) {
        qDebug() << "连接服务器请求失败，请重新操作";
    } else {
        qDebug() << "连接服务器成功" << endl;
        QMessageBox::warning(this,"warning",tr("连接服务器成功"),QMessageBox::Yes,QMessageBox::No);
    }
}

//读缓冲区槽函数
void MainWindow::socket_Read_Data() {
    QByteArray buffer;
    //读取缓冲区数据
    buffer = socket->readAll();
    //显示缓冲区数据
    QMessageBox::warning(this, "socket_info", buffer);
    QJsonObject jsonObject = QJsonDocument::fromJson(buffer).object();
    if(jsonObject["type"] == "order") {
//        QString ;
    } else if (jsonObject["type"] == "SellerLogon") {
        if(jsonObject["warning"].toString() == "Logon Successfully!") {
            logon.hide();
            release.show();
        } else {
            QMessageBox::warning(this, "warning", jsonObject["warning"].toString());
        }
    } else if(jsonObject["type"] == "SellerRegister") {
        if(jsonObject["warning"].toString() == "Successfully!") {
            reg.hide();
            logon.show();
        }
    }
}

void MainWindow::socket_Disconnected() {

}

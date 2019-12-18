#include "mainwindow.h"
#include "ui_mainwindow.h"

/**
 * @brief Construct a new Main Window:: Main Window object
 * 
 * @param parent 
 */
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    server = new QTcpServer;
    connect(server, &QTcpServer::newConnection, this, &MainWindow::newConn);
    listen(QHostAddress::Any, 23333);
    pool.setMaxThreadCount(1000);


    QString localHostName = QHostInfo::localHostName();
    qDebug() << "localHostName: " << localHostName;
    QHostInfo info = QHostInfo::fromName(localHostName);
    qDebug() << "IP Address: " << info.addresses();

}

/**
 * @brief Monitor connection information
 * 
 * @param address 
 * @param port 
 * @return true 
 * @return false 
 */
bool MainWindow::listen(const QHostAddress &address, quint16 port) {
    if(server) {
        return server->listen(address, port);
    }
    return false;
}

/**
 * @brief Listen for disconnected and server-side links
 * 
 */
void MainWindow::connDisconnected() {
    auto conn = qobject_cast<QTcpSocket*>(sender());
    socks.removeOne(conn);
    qDebug() << "disconnect" << endl;
}

/**
 * @brief Listen for new and server-side links
 * 
 */
void MainWindow::newConn() {
    qDebug() << "New Connection inbound\n";
    socks.push_back(server->nextPendingConnection());
    qDebug() << "connection established: " << socks.back() << "\n";
    connect(socks.back(), &QTcpSocket::readyRead, this, &MainWindow::dataArrived);
    connect(socks.back(), &QTcpSocket::disconnected, this, &MainWindow::connDisconnected);
}

/**
 * @brief Monitor the signal of data coming
 * When new data is transmitted, a sleeping thread needs to be taken out of the thread pool and waked up to process messages
 * 
 */
void MainWindow::dataArrived() {
    auto conn = qobject_cast<QTcpSocket*>(sender());
    buffer = conn->readAll();
    qDebug() << "Request from " << conn << endl;

    Info = QJsonDocument::fromBinaryData(buffer).object();
    ui->receiveEdit->setText(QString(QJsonDocument(Info).toJson(QJsonDocument::Compact)));


    dealThread *thread = new dealThread(Info, conn);
    connect(thread, SIGNAL(finished()), thread, SLOT(deleteLater()));
    connect(thread, &dealThread::forceLogOut, this, &MainWindow::forceLogoutUser);
    connect(thread, &dealThread::addUserToMap, this, &MainWindow::addUserToMap);
//    thread->start();
    thread->start();
//    pool.start(thread);

}

void MainWindow::addUserToMap(QString user_name, QTcpSocket* socket) {
    QMessageBox::warning(this, "warning", "addUserToMap");
    user_socket.insert(user_name, socket);
    return ;
}

void MainWindow::forceLogoutUser(QString user_name, QTcpSocket* socket, QJsonObject user_out, QJsonObject user_in) {
//    QMessageBox::warning(this, "warning", "forceLogoutUser");
    qDebug() << "size = " << user_socket.size() << endl;
    qDebug() << user_name << endl;
    if(user_socket.find(user_name) != user_socket.end()) {
        qDebug() << "******************************" << endl;
        qDebug() << user_out << endl;
        qDebug() << "******************************" << endl;
        qDebug() << user_in << endl;

        qint64 writeResult = user_socket.value(user_name)->write(QJsonDocument(user_out).toJson());
        bool BoolFlush = user_socket.value(user_name)->flush();
        if(writeResult != -1 && BoolFlush == 1) {
            //返回值不为-1，则发送数据成功
            if(writeResult == 0) {
                qDebug() << "发送成功" << endl;
            }
        }
        user_socket.remove(user_name);
        user_socket.insert(user_name, socket);
        return ;
    }
    return ;
}

/**
 * @brief Destroy the Main Window:: Main Window object
 * 
 */
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_rearr_Unread_Btn_clicked()
{
    auto conn = qobject_cast<QTcpSocket*>(server);
    QJsonObject Info;
    Info["type"] = "rearr_Unread";
    dealThread *thread = new dealThread(Info, conn);
    connect(thread, SIGNAL(finished()), thread, SLOT(deleteLater()));
    thread->start();
//    pool.start(thread);
}

void MainWindow::on_rearr_Read_Btn_clicked()
{
    auto conn = qobject_cast<QTcpSocket*>(server);
    QJsonObject Info;
    Info["type"] = "rearr_Read";
    dealThread *thread = new dealThread(Info, conn);
    connect(thread, SIGNAL(finished()), thread, SLOT(deleteLater()));
    thread->start();
//    pool.start(thread);
}



void MainWindow::on_del_Invalid_Btn_clicked()
{
//    auto conn = qobject_cast<QTcpSocket*>(server);
//    QJsonObject Info;
//    Info["type"] = "del_Invalid";
//    dealThread *thread = new dealThread(Info, conn);
//    connect(thread, SIGNAL(finished()), thread, SLOT(deleteLater()));
//    pool.start(thread);
}


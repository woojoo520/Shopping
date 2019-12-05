#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    server = new QTcpServer;
    connect(server, &QTcpServer::newConnection, this, &MainWindow::newConn);
    listen(QHostAddress::Any, 23333);
    pool.setMaxThreadCount(1000);
}

bool MainWindow::listen(const QHostAddress &address, quint16 port) {
    if(server) {
        return server->listen(address, port);
    }
    return false;
}

void MainWindow::connDisconnected() {
    auto conn = qobject_cast<QTcpSocket*>(sender());
    socks.removeOne(conn);
    qDebug() << "disconnect" << endl;
}

void MainWindow::newConn() {
    qDebug() << "New Connection inbound\n";
    socks.push_back(server->nextPendingConnection());
    qDebug() << "connection established: " << socks.back() << "\n";
    connect(socks.back(), &QTcpSocket::readyRead, this, &MainWindow::dataArrived);
    connect(socks.back(), &QTcpSocket::disconnected, this, &MainWindow::connDisconnected);

}

void MainWindow::dataArrived() {
    auto conn = qobject_cast<QTcpSocket*>(sender());
//    QString str = conn->readAll();
    buffer = conn->readAll();
    qDebug() << "Request from " << conn << endl;

    Info = QJsonDocument::fromBinaryData(buffer).object();
    ui->receiveEdit->setText(QString(QJsonDocument(Info).toJson(QJsonDocument::Compact)));

    dealThread *thread = new dealThread(Info, conn);
    connect(thread, SIGNAL(finished()), thread, SLOT(deleteLater()));
    thread->start();

}


MainWindow::~MainWindow()
{
    delete ui;
}










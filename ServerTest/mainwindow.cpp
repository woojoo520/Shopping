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
//    QString str = conn->readAll();
    buffer = conn->readAll();
    qDebug() << "Request from " << conn << endl;

    Info = QJsonDocument::fromBinaryData(buffer).object();
    ui->receiveEdit->setText(QString(QJsonDocument(Info).toJson(QJsonDocument::Compact)));

    dealThread *thread = new dealThread(Info, conn);
    connect(thread, SIGNAL(finished()), thread, SLOT(deleteLater()));
//    thread->start();
    pool.start(thread);

}

/**
 * @brief Destroy the Main Window:: Main Window object
 * 
 */
MainWindow::~MainWindow()
{
    delete ui;
}










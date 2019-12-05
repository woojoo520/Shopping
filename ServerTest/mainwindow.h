#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QDebug>
#include <QThread>
#include <QtNetwork>
#include <QCoreApplication>
#include <QVector>
#include <QMessageBox>
#include <QTcpServer>
#include <QTcpSocket>
#include <QJsonObject>
#include <QMap>
#include <QThreadPool>

#include "serverconnect.h"
#include "dealthread.h"
#include "dealmsg.h"

class ServerConnect;


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

private slots:
    void connDisconnected();
    void newConn();
    void dataArrived();

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    bool listen(const QHostAddress &address = QHostAddress::Any, quint16 port = 0);
    void dealWithMsg(QJsonObject Info);

private:
    Ui::MainWindow *ui;
    QVector<QTcpSocket*> socks;
    QMutex lockSocks;
    QTcpServer *server;
    ServerConnect scc;

    QByteArray buffer;
    QJsonObject Info;
    QThreadPool pool;

};

#endif // MAINWINDOW_H

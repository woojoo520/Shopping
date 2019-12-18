#ifndef MAINWINDOW_H
#define MAINWINDOW_H
/**
 * @file mainwindow.h
 * @author Meng Yeqing
 * @brief 
 * @version 0.1
 * @date 2019-12-15
 * 
 * @copyright Copyright (c) 2019
 * 
 */
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
#include <QHostInfo>

#include "serverconnect.h"
#include "dealthread.h"

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

    void on_rearr_Unread_Btn_clicked();

    void on_rearr_Read_Btn_clicked();

    void on_del_Invalid_Btn_clicked();
//public slots:
    void forceLogoutUser(QString user_name, QTcpSocket* socket, QJsonObject user_out, QJsonObject user_in);
    void addUserToMap(QString user_name, QTcpSocket* socket);
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    bool listen(const QHostAddress &address = QHostAddress::Any, quint16 port = 0);
    void dealWithMsg(QJsonObject Info);

//    void forceLogoutUser(QString user_name, QTcpSocket* socket, QJsonObject user_out, QJsonObject user_in);
//    void addUserToMap(QString user_name, QTcpSocket* socket);

private:
    Ui::MainWindow *ui;
    QVector<QTcpSocket*> socks;
    QMutex lockSocks;
    QTcpServer *server;
    ServerConnect scc;

    QByteArray buffer;
    QJsonObject Info;
    QThreadPool pool;
    QMap<QString, QTcpSocket*> user_socket;
};

#endif // MAINWINDOW_H

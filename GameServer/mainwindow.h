#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QTcpServer>
#include <QTcpSocket>
#include <QJsonObject>
#include "db.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
private slots:
    //服务器接收到客户端信息，触发连接槽函数(连接客户端)
    void server_New_Connect();

    void socket_Read_Data();
    //监听按钮槽函数
//    void on_pushButton_Listen_clicked();
    //发送信息按钮槽函数

    void on_pushButton_Listen_clicked(bool checked);

    void on_pushButton_send_clicked();
private:
    void initDB();
    void getData();
    void socket_Send_Data(int index);
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    QList<QTcpSocket*> socketList;
    QMap<int,QString> Socket_Name;
    QMap<QString,int> Name_Socket;
    QByteArray buffer;
    QByteArray sendInfo;
    QJsonObject Info;
    //创建TCP的服务器对象
    QTcpServer *server;

private:
    Ui::MainWindow *ui;
    DB db;
};

#endif // MAINWINDOW_H

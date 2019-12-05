#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpSocket>
#include <QMessageBox>
#include <QDebug>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonDocument>
#include <QTextCodec>
#include "releaseproduct.h"
#include "ordershow.h"
#include "logon.h"
#include "register.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
private:
    void connect_socket();
private slots:
    void socket_Read_Data();
    //断开与服务器连接槽函数
    void socket_Disconnected();
    void send_socketInfo(QJsonObject infoJson);
public slots:
    void showRegister();
private:
    Ui::MainWindow *ui;
    QTcpSocket *socket;
    ReleaseProduct release;
    LogOn logon;
    Register reg;
};

#endif // MAINWINDOW_H

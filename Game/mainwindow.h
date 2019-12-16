#ifndef MAINWINDOW_H
#define MAINWINDOW_H

/**
 * @file
 * @brief implement the interaction with server
 * @author MengYeqing
 * @date 2019.12.7
 * @version 1.0
 * @note
 * the mainWindow work as a client using TCP/IP to interact with server, sending and receiving data in JSON format, the type field the data represents the type of information the client sent, such as "request for product", "login" and so on.
 */ 

#include <QMainWindow>
#include <QButtonGroup>
#include <QImage>
#include <QLabel>
#include <QScrollBar>
#include <QScrollArea>
#include <QPalette>
#include <QVector>
#include <QMap>
#include <QQueue>
#include <QString>
#include <QHostAddress>
#include <QNetworkInterface>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonDocument>
#include <QTextCodec>
#include <QTcpSocket>
#include <QPainter>
#include <QDataStream>
#include <QThread>
#include <QtCore>
#include <QtNetwork>
#include <QCoreApplication>
#include "logon.h"
#include "mydialog.h"
#include "productshow.h"
#include "mylabel.h"
#include "register.h"
#include "release.h"
#include "showmessage.h"
#define CONNECTPARAM "127.0.0.1", 23333

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    void setConnaddr(const QString &connaddr);
    void connectToHost(const QString &hostName, quint16 port);


private:
    void init_Combobox();
    void showRecommend();
    void setScrollBar();
    void initDB();
    void initBtnGroup();
    void getData();
    void PrintProductInfo();
    QVector<Product> getProductInfo();
    void changeLogOnPic();
    void connect_socket();
    void showLogon(QJsonObject jsonObject);
    void SaveProductInfo(QJsonArray array, QString type);
    void createProductShow(QJsonObject info);
    void forcedToLogout();

public:
    explicit MainWindow(QWidget *parent = 0);
//    void getRegisterInfo(QVector<QString> InfoVec);
    ~MainWindow();
signals:
    void queryInfo(QJsonObject query);
    void commentInfo(QVector<QPair<QString, QString>> comment);
    void showRelease();
    void showMsgSignal();


    void sendData(QString data);
private slots:
    //断开与服务器连接槽函数
    void connDisconnected();


    void on_searchBtn_clicked();
    void on_messageBtn_clicked();
    void on_MyBtn_clicked();
    void on_releaseBtn_clicked();
    void on_firstPageBtn_clicked();
    void on_LogonBtn_clicked();
    void updateImgSrc(QJsonObject infoJson);
    //读服务器数据槽函数
    void socket_Read_Data();
    void send_socketInfo(QJsonObject infoJson);

    void hideLogOn();
    void showRegister();
    void getRegisterInfo(QJsonObject infoJson);
    void getUserLogon(QJsonObject Infojson);
    void showQueryRes(QVector<Product> productRes);
    void getComment(int lableId, QString productId);
    void sendComment(QJsonObject commentJson);
//    void createProductShow(QJsonObject info);
    void sendPraise(QJsonObject praiseJson);
    void releaseProduct(QJsonObject productInfo);
    void getMsgIndex(int id);
    void productShowMsg(int i, QString productId);
private:
    Ui::MainWindow *ui;
    QButtonGroup *buttonGroup;
    LogOn logon;
    MyDialog mydialog;
    productShow productshow;
    QVector<Product> ProductInfo;

    Register registerW;
    Release release;
    QTcpSocket *socket;
    QVector<Mylabel*> MylabelVec;
    showMessage showmsg;

    QDataStream in;
    QString currentFortune;


//    QTcpSocket *conn;
    QQueue<QString> dataQ;
};

#endif // MAINWINDOW_H

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QButtonGroup>
#include <QImage>
#include <QLabel>
#include <QScrollBar>
#include <QScrollArea>
#include <QPalette>
#include <QVector>
#include <QMap>
#include <QHostAddress>
#include <QNetworkInterface>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonDocument>
#include <QTextCodec>
#include <QTcpSocket>
#include "logon.h"
#include "mydialog.h"
#include "productshow.h"
#include "mylabel.h"
#include "register.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
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
    void SaveProductInfo(QJsonArray array);

public:
    explicit MainWindow(QWidget *parent = 0);
//    void getRegisterInfo(QVector<QString> InfoVec);
    ~MainWindow();
signals:
    void queryInfo(QJsonObject query);
    void commentInfo(QVector<QPair<QString, QString>> comment);

private slots:
    void on_searchBtn_clicked();
    void on_messageBtn_clicked();
    void on_MyBtn_clicked();
    void on_releaseBtn_clicked();
    void on_firstPageBtn_clicked();
    void on_LogonBtn_clicked();
    void updateImgSrc(QJsonObject infoJson);
    //读服务器数据槽函数
    void socket_Read_Data();
    //断开与服务器连接槽函数
    void socket_Disconnected();
    void send_socketInfo(QJsonObject infoJson);

    void hideLogOn();
    void showRegister();
    void getRegisterInfo(QJsonObject infoJson);
    void getUserLogon(QJsonObject Infojson);
    void showQueryRes(QVector<Product> productRes);
    void getComment(int lableId, QString productId);
    void sendComment(QJsonObject commentJson);
    void createProductShow(int i, QString productId);
    void sendPraise(QJsonObject praiseJson);

private:
    Ui::MainWindow *ui;
    QButtonGroup *buttonGroup;
    LogOn logon;
    MyDialog mydialog;
    productShow productshow;
    QVector<Product> ProductInfo;
    Register registerW;
    QTcpSocket *socket;
    QVector<Mylabel*> MylabelVec;
};

#endif // MAINWINDOW_H

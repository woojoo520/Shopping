#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QImage>
#include <QLabel>
#include <QScrollBar>
#include <QScrollArea>
#include <QPalette>
#include <QVector>
#include <QMap>
#include "logon.h"
#include "mydialog.h"
#include "productshow.h"
#include "db.h"
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
    void getData();
    void PrintProductInfo();
    QVector<Product> getProductInfo();


public:
    explicit MainWindow(QWidget *parent = 0);
//    void getRegisterInfo(QVector<QString> InfoVec);
    ~MainWindow();


private slots:
    void on_searchBtn_clicked();
    void on_messageBtn_clicked();
    void on_MyBtn_clicked();
    void on_releaseBtn_clicked();
    void on_firstPageBtn_clicked();
    void on_LogonBtn_clicked();
public slots:
    void hideLogOn();
    void registerUser();
    void showRegister();
    void getRegisterInfo(QVector<QString> InfoVec);
    void getUserLogon(QVector<QString> InfoVec);

private:
    Ui::MainWindow *ui;
    LogOn logon;
    MyDialog mydialog;
    productShow productshow;
    QVector<Product> ProductInfo;
    Register registerW;
    DB db;
};

#endif // MAINWINDOW_H

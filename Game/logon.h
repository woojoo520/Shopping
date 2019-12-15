#ifndef LOGON_H
#define LOGON_H

/**
 * \file 
 * \brief implement user login function
 * \author MengYeqing
 * \date 2019.11.20
 * \version 1.0
 * \note
 * this cpp is to implement the login function when someone already has its account. Only when the user name and the password is correct as the database can the user login. Or the user can just watch the pruduct and the comment but can't buy the product. 
 */ 

#include <QDialog>
#include <QPushButton>
#include <QMessageBox>
#include <QSql>
#include <QSqlQuery>
#include <QDebug>
#include <QJsonObject>
namespace Ui {
class LogOn;
}

class LogOn : public QDialog
{
    Q_OBJECT

public:
    explicit LogOn(QWidget *parent = 0);
    ~LogOn();
signals:
    void logOnSucc();
    void needRegister();
    void sendLogOnInfo(QJsonObject Infojson);

private slots:
    void on_LogOn_Btn_clicked();
    void on_Register_Btn_clicked();

private:
    Ui::LogOn *ui;
};

#endif // LOGON_H

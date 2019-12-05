#include "logon.h"
#include "ui_logon.h"
#include "string"

LogOn::LogOn(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LogOn)
{
    ui->setupUi(this);
    ui->User_pwd->setEchoMode(QLineEdit::Password);
}

LogOn::~LogOn()
{
    delete ui;
}



void LogOn::on_LogOn_Btn_clicked()
{
    QJsonObject Infojson;
    Infojson["type"] = "SellerLogon";
    Infojson["User_name"] = ui->User_Name->text();
    Infojson["User_pwd"] = ui->User_pwd->text();
    emit sendLogOnInfo(Infojson);
}

void LogOn::on_Register_Btn_clicked()
{
    needRegister();
}

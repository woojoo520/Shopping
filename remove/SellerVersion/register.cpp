#include "register.h"
#include "ui_register.h"

Register::Register(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Register)
{
    ui->setupUi(this);
    ui->User_pwd->setEchoMode(QLineEdit::Password);
    ui->resurePwd->setEchoMode(QLineEdit::Password);
}

Register::~Register()
{
    delete ui;
}

void Register::on_registerBtn_clicked()
{
    QJsonObject infoJson;
    infoJson["type"] = "SellerRegister";
    infoJson["User_Name"] = ui->User_Name->text();
    infoJson["User_pwd"] = ui->User_pwd->text();
    infoJson["resurePwd"] = ui->resurePwd->text();
    emit sendInfo(infoJson);
}



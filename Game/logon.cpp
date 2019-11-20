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
    Infojson["type"] = "isLogon";
    Infojson["User_name"] = ui->User_Name->text();
    Infojson["User_pwd"] = ui->User_pwd->text();
//    infoVec.push_back(ui->User_Name->text());
//    infoVec.push_back(ui->User_pwd->text());
    emit sendLogOnInfo(Infojson);
}

void LogOn::on_Register_Btn_clicked()
{
    needRegister();
    /*
    QString name = ui->User_Name->text();
    QString pwd = ui->User_pwd->text();
    if(name == NULL || pwd == NULL) {
        QMessageBox::warning(this, "Warning", "Please input the complete infomation");
    } else {
        QString str = QString("SELECT * FROM UserInfo WHERE User_name = '%1'").arg(name);
        QSqlQuery query;
        query.exec(str);
        QString user;
        while(query.next()) {
            user = query.value(0).toString();
        }
        if(user == NULL) {
            query.prepare("INSERT INTO UserInfo(User_name, User_pwd) VALUES (:Name, :Pwd)");
            query.bindValue(":Name", name);
            query.bindValue(":Pwd", pwd);
            if(!query.exec()) {
                QMessageBox::warning(this, "Warning", "Sorry, Some unexcepted error happen!");
            } else {
                QMessageBox::about(this, "Successful", "Register Successful!");
            }
        } else {
            QMessageBox::warning(this, "Warning", "Sorry, the user already exists.");
        }
        ui->User_Name->clear();
        ui->User_pwd->clear();
    }
    */
}

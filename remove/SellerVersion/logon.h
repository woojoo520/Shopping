#ifndef LOGON_H
#define LOGON_H

#include <QDialog>
#include <QPushButton>
#include <QMessageBox>
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

#ifndef LOGON_H
#define LOGON_H

#include <QDialog>
#include <QPushButton>
#include <QMessageBox>
#include <QSql>
#include <QSqlQuery>
#include <QDebug>
namespace Ui {
class LogOn;
}

class LogOn : public QDialog
{
    Q_OBJECT

public:
    explicit LogOn(QWidget *parent = 0);
    ~LogOn();

private slots:
    void on_OKbtn_clicked(bool checked);

    void on_LogOn_Btn_clicked();

    void on_Register_Btn_clicked();

private:
    Ui::LogOn *ui;
};

#endif // LOGON_H

#ifndef REGISTER_H
#define REGISTER_H

#include <QDialog>
#include <QString>
#include <QVector>
#include <QDebug>
#include <QFileDialog>
#include <QJsonObject>
#include <QDateTime>
#include <QMessageBox>
#include <QScreen>
#include <QDir>

namespace Ui {
class Register;
}

class Register : public QDialog
{
    Q_OBJECT

public:
    explicit Register(QWidget *parent = 0);
    ~Register();
    void SaveImg();
signals:
    void sendInfo(QJsonObject infoJason);
    void ImgSrcSignal(QJsonObject InfoVec);
public slots:
    QVector<QString> getInfoMation();
private slots:
    void on_registerBtn_clicked();
    void on_logoBtn_clicked();

private:
    Ui::Register *ui;
    QString fileName;
};

#endif // REGISTER_H

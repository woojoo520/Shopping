#ifndef REGISTER_H
#define REGISTER_H

#include <QDialog>
#include <QString>
#include <QVector>
#include <QDebug>
#include <QFileDialog>
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
signals:
    void sendInfo(QVector<QString> InfoVec);
    void ImgSrcSignal(QVector<QString> InfoVec);
public slots:
    QVector<QString> getInfoMation();
    void SaveImg();
private slots:
    void on_registerBtn_clicked();
    void on_logoBtn_clicked();

private:
    Ui::Register *ui;
    QString fileName;
};

#endif // REGISTER_H

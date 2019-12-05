#ifndef RELEASE_H
#define RELEASE_H

#include <QDialog>
#include <QImage>
#include <QLabel>
#include <QScrollBar>
#include <QScrollArea>
#include <QPalette>
#include <QString>
#include <QVector>
#include <QDebug>
#include <QFileDialog>
#include <QJsonObject>
#include <QDateTime>
#include <QMessageBox>
#include <QScreen>
#include <QDir>
#include "mylabel.h"

namespace Ui {
class Release;
}

class Release : public QDialog
{
    Q_OBJECT

public:
    explicit Release(QWidget *parent = 0);
    ~Release();
signals:
    void releasePro(QJsonObject productInfo);
private slots:
    void on_releaseBtn_clicked();
    void on_chooseBtn_clicked();
public slots:
    void showRelease();
private:
    Ui::Release *ui;
    QVector<Mylabel*> MylabelVec;
public:
    QVector<Product> releaseProduct;
    QString fileName;
};

#endif // RELEASE_H

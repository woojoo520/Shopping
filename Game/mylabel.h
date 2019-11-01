#ifndef MYLABEL_H
#define MYLABEL_H
#include <QLabel>
#include <QString>
#include <QWidget>
#include <QMainWindow>
#include "QMessageBox"
#include "productshow.h"

class Mylabel:public QLabel
{
    Q_OBJECT
public:
    Mylabel(const QString &text,QWidget *parent=0);
    ~Mylabel(){}
signals:
    void clicked();
public slots:
    void showDetail();
protected:
    void mousePressEvent(QMouseEvent* event);

};

#endif // MYLABEL_H

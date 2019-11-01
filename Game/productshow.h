#ifndef PRODUCTSHOW_H
#define PRODUCTSHOW_H

#include <QDialog>
#include <QVector>
#include <QString>
#include <QDebug>
#include "product.h"
#include "db.h"

class DB;

namespace Ui {
class productShow;
}

class productShow : public QDialog
{
    Q_OBJECT

public:
    explicit productShow(QWidget *parent = 0);
    ~productShow();


private:
    Ui::productShow *ui;
};

#endif // PRODUCTSHOW_H

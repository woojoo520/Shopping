#ifndef ORDERSHOW_H
#define ORDERSHOW_H

#include <QDialog>

namespace Ui {
class OrderShow;
}

class OrderShow : public QDialog
{
    Q_OBJECT

public:
    explicit OrderShow(QWidget *parent = 0);
    ~OrderShow();

private:
    Ui::OrderShow *ui;
};

#endif // ORDERSHOW_H

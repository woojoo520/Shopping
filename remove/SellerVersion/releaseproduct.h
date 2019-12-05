#ifndef RELEASEPRODUCT_H
#define RELEASEPRODUCT_H

#include <QDialog>

namespace Ui {
class ReleaseProduct;
}

class ReleaseProduct : public QDialog
{
    Q_OBJECT

public:
    explicit ReleaseProduct(QWidget *parent = 0);
    ~ReleaseProduct();

private:
    Ui::ReleaseProduct *ui;
};

#endif // RELEASEPRODUCT_H

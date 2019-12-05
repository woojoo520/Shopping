/********************************************************************************
** Form generated from reading UI file 'ordershow.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ORDERSHOW_H
#define UI_ORDERSHOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>

QT_BEGIN_NAMESPACE

class Ui_OrderShow
{
public:

    void setupUi(QDialog *OrderShow)
    {
        if (OrderShow->objectName().isEmpty())
            OrderShow->setObjectName(QStringLiteral("OrderShow"));
        OrderShow->resize(400, 300);

        retranslateUi(OrderShow);

        QMetaObject::connectSlotsByName(OrderShow);
    } // setupUi

    void retranslateUi(QDialog *OrderShow)
    {
        OrderShow->setWindowTitle(QApplication::translate("OrderShow", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class OrderShow: public Ui_OrderShow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ORDERSHOW_H

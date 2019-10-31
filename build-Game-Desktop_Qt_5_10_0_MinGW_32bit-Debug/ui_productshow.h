/********************************************************************************
** Form generated from reading UI file 'productshow.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PRODUCTSHOW_H
#define UI_PRODUCTSHOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_productShow
{
public:
    QLabel *productLabel;
    QPushButton *chatBtn;
    QPushButton *addBtn;

    void setupUi(QDialog *productShow)
    {
        if (productShow->objectName().isEmpty())
            productShow->setObjectName(QStringLiteral("productShow"));
        productShow->resize(500, 600);
        productLabel = new QLabel(productShow);
        productLabel->setObjectName(QStringLiteral("productLabel"));
        productLabel->setGeometry(QRect(48, 49, 411, 431));
        chatBtn = new QPushButton(productShow);
        chatBtn->setObjectName(QStringLiteral("chatBtn"));
        chatBtn->setGeometry(QRect(390, 510, 61, 31));
        addBtn = new QPushButton(productShow);
        addBtn->setObjectName(QStringLiteral("addBtn"));
        addBtn->setGeometry(QRect(250, 510, 121, 31));

        retranslateUi(productShow);

        QMetaObject::connectSlotsByName(productShow);
    } // setupUi

    void retranslateUi(QDialog *productShow)
    {
        productShow->setWindowTitle(QApplication::translate("productShow", "Dialog", nullptr));
        productLabel->setText(QApplication::translate("productShow", "Product Label", nullptr));
        chatBtn->setText(QApplication::translate("productShow", "\350\201\212\345\244\251", nullptr));
        addBtn->setText(QApplication::translate("productShow", "\345\212\240\345\205\245\350\264\255\347\211\251\350\275\246", nullptr));
    } // retranslateUi

};

namespace Ui {
    class productShow: public Ui_productShow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PRODUCTSHOW_H

/********************************************************************************
** Form generated from reading UI file 'mydialog.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYDIALOG_H
#define UI_MYDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_MyDialog
{
public:
    QPushButton *cartBtn;
    QPushButton *myReleaseBtn;
    QPushButton *orderBtn;
    QLabel *detailLabel;
    QPushButton *accountBtn;

    void setupUi(QDialog *MyDialog)
    {
        if (MyDialog->objectName().isEmpty())
            MyDialog->setObjectName(QStringLiteral("MyDialog"));
        MyDialog->resize(800, 800);
        cartBtn = new QPushButton(MyDialog);
        cartBtn->setObjectName(QStringLiteral("cartBtn"));
        cartBtn->setGeometry(QRect(150, 70, 91, 31));
        myReleaseBtn = new QPushButton(MyDialog);
        myReleaseBtn->setObjectName(QStringLiteral("myReleaseBtn"));
        myReleaseBtn->setGeometry(QRect(310, 70, 121, 31));
        orderBtn = new QPushButton(MyDialog);
        orderBtn->setObjectName(QStringLiteral("orderBtn"));
        orderBtn->setGeometry(QRect(500, 70, 91, 31));
        detailLabel = new QLabel(MyDialog);
        detailLabel->setObjectName(QStringLiteral("detailLabel"));
        detailLabel->setGeometry(QRect(60, 170, 661, 451));
        accountBtn = new QPushButton(MyDialog);
        accountBtn->setObjectName(QStringLiteral("accountBtn"));
        accountBtn->setGeometry(QRect(640, 670, 81, 41));

        retranslateUi(MyDialog);

        QMetaObject::connectSlotsByName(MyDialog);
    } // setupUi

    void retranslateUi(QDialog *MyDialog)
    {
        MyDialog->setWindowTitle(QApplication::translate("MyDialog", "Dialog", nullptr));
        cartBtn->setText(QApplication::translate("MyDialog", "\350\264\255\347\211\251\350\275\246", nullptr));
        myReleaseBtn->setText(QApplication::translate("MyDialog", "\346\210\221\345\217\221\345\270\203\347\232\204", nullptr));
        orderBtn->setText(QApplication::translate("MyDialog", "\350\256\242\345\215\225", nullptr));
        detailLabel->setText(QApplication::translate("MyDialog", "show Detail", nullptr));
        accountBtn->setText(QApplication::translate("MyDialog", "\347\273\223\347\256\227", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MyDialog: public Ui_MyDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYDIALOG_H

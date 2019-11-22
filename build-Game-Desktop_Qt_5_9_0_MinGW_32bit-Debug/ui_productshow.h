/********************************************************************************
** Form generated from reading UI file 'productshow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_productShow
{
public:
    QPushButton *chatBtn;
    QPushButton *addBtn;
    QLabel *label1;
    QLabel *description;
    QLabel *name;
    QLabel *state;
    QLabel *seller;
    QLabel *price;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label_5;
    QLabel *label_2;
    QLabel *label;
    QLabel *label_3;
    QLabel *label_4;

    void setupUi(QDialog *productShow)
    {
        if (productShow->objectName().isEmpty())
            productShow->setObjectName(QStringLiteral("productShow"));
        productShow->resize(500, 600);
        chatBtn = new QPushButton(productShow);
        chatBtn->setObjectName(QStringLiteral("chatBtn"));
        chatBtn->setGeometry(QRect(390, 510, 61, 31));
        addBtn = new QPushButton(productShow);
        addBtn->setObjectName(QStringLiteral("addBtn"));
        addBtn->setGeometry(QRect(250, 510, 121, 31));
        label1 = new QLabel(productShow);
        label1->setObjectName(QStringLiteral("label1"));
        label1->setGeometry(QRect(100, 10, 251, 221));
        description = new QLabel(productShow);
        description->setObjectName(QStringLiteral("description"));
        description->setGeometry(QRect(10, 400, 461, 51));
        name = new QLabel(productShow);
        name->setObjectName(QStringLiteral("name"));
        name->setGeometry(QRect(10, 340, 81, 41));
        state = new QLabel(productShow);
        state->setObjectName(QStringLiteral("state"));
        state->setGeometry(QRect(120, 340, 81, 41));
        seller = new QLabel(productShow);
        seller->setObjectName(QStringLiteral("seller"));
        seller->setGeometry(QRect(240, 340, 81, 41));
        price = new QLabel(productShow);
        price->setObjectName(QStringLiteral("price"));
        price->setGeometry(QRect(370, 340, 71, 41));
        layoutWidget = new QWidget(productShow);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(0, 240, 491, 81));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName(QStringLiteral("label_5"));

        horizontalLayout->addWidget(label_5);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout->addWidget(label_2);

        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout->addWidget(label_3);

        label_4 = new QLabel(productShow);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(10, 320, 61, 31));

        retranslateUi(productShow);

        QMetaObject::connectSlotsByName(productShow);
    } // setupUi

    void retranslateUi(QDialog *productShow)
    {
        productShow->setWindowTitle(QApplication::translate("productShow", "Dialog", Q_NULLPTR));
        chatBtn->setText(QApplication::translate("productShow", "\350\201\212\345\244\251", Q_NULLPTR));
        addBtn->setText(QApplication::translate("productShow", "\345\212\240\345\205\245\350\264\255\347\211\251\350\275\246", Q_NULLPTR));
        label1->setText(QString());
        description->setText(QString());
        name->setText(QApplication::translate("productShow", "TextLabel", Q_NULLPTR));
        state->setText(QApplication::translate("productShow", "TextLabel", Q_NULLPTR));
        seller->setText(QApplication::translate("productShow", "TextLabel", Q_NULLPTR));
        price->setText(QApplication::translate("productShow", "TextLabel", Q_NULLPTR));
        label_5->setText(QApplication::translate("productShow", "product name", Q_NULLPTR));
        label_2->setText(QApplication::translate("productShow", "state", Q_NULLPTR));
        label->setText(QApplication::translate("productShow", "seller name", Q_NULLPTR));
        label_3->setText(QApplication::translate("productShow", "price", Q_NULLPTR));
        label_4->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class productShow: public Ui_productShow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PRODUCTSHOW_H

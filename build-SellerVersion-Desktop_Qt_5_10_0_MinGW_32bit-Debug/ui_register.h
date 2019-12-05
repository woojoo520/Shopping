/********************************************************************************
** Form generated from reading UI file 'register.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTER_H
#define UI_REGISTER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Register
{
public:
    QPushButton *registerBtn;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *User_Name;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *User_pwd;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_5;
    QLineEdit *resurePwd;

    void setupUi(QDialog *Register)
    {
        if (Register->objectName().isEmpty())
            Register->setObjectName(QStringLiteral("Register"));
        Register->resize(500, 600);
        registerBtn = new QPushButton(Register);
        registerBtn->setObjectName(QStringLiteral("registerBtn"));
        registerBtn->setGeometry(QRect(370, 500, 80, 41));
        layoutWidget = new QWidget(Register);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(80, 30, 351, 441));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(50);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        User_Name = new QLineEdit(layoutWidget);
        User_Name->setObjectName(QStringLiteral("User_Name"));

        horizontalLayout->addWidget(User_Name);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(60);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_2->addWidget(label_2);

        User_pwd = new QLineEdit(layoutWidget);
        User_pwd->setObjectName(QStringLiteral("User_pwd"));

        horizontalLayout_2->addWidget(User_pwd);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(40);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName(QStringLiteral("label_5"));

        horizontalLayout_5->addWidget(label_5);

        resurePwd = new QLineEdit(layoutWidget);
        resurePwd->setObjectName(QStringLiteral("resurePwd"));

        horizontalLayout_5->addWidget(resurePwd);


        verticalLayout->addLayout(horizontalLayout_5);

        verticalLayout->setStretch(0, 1);
        verticalLayout->setStretch(1, 1);
        verticalLayout->setStretch(2, 1);

        retranslateUi(Register);

        QMetaObject::connectSlotsByName(Register);
    } // setupUi

    void retranslateUi(QDialog *Register)
    {
        Register->setWindowTitle(QApplication::translate("Register", "Dialog", nullptr));
        registerBtn->setText(QApplication::translate("Register", "Register", nullptr));
        label->setText(QApplication::translate("Register", "\347\224\250\346\210\267\345\220\215", nullptr));
        label_2->setText(QApplication::translate("Register", "\345\257\206\347\240\201", nullptr));
        label_5->setText(QApplication::translate("Register", "\347\241\256\350\256\244\345\257\206\347\240\201", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Register: public Ui_Register {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTER_H

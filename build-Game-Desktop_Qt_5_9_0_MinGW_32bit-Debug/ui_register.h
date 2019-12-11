/********************************************************************************
** Form generated from reading UI file 'register.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
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
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QLineEdit *User_Address;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QLineEdit *User_Phone;
    QHBoxLayout *horizontalLayout_6;
    QPushButton *logoBtn;
    QLabel *logo_Label;

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

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(60);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_3->addWidget(label_3);

        User_Address = new QLineEdit(layoutWidget);
        User_Address->setObjectName(QStringLiteral("User_Address"));

        horizontalLayout_3->addWidget(User_Address);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(60);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_4->addWidget(label_4);

        User_Phone = new QLineEdit(layoutWidget);
        User_Phone->setObjectName(QStringLiteral("User_Phone"));

        horizontalLayout_4->addWidget(User_Phone);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(0);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        logoBtn = new QPushButton(layoutWidget);
        logoBtn->setObjectName(QStringLiteral("logoBtn"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(30);
        sizePolicy.setHeightForWidth(logoBtn->sizePolicy().hasHeightForWidth());
        logoBtn->setSizePolicy(sizePolicy);

        horizontalLayout_6->addWidget(logoBtn);

        logo_Label = new QLabel(layoutWidget);
        logo_Label->setObjectName(QStringLiteral("logo_Label"));

        horizontalLayout_6->addWidget(logo_Label);

        horizontalLayout_6->setStretch(0, 2);
        horizontalLayout_6->setStretch(1, 3);

        verticalLayout->addLayout(horizontalLayout_6);

        verticalLayout->setStretch(0, 1);
        verticalLayout->setStretch(1, 1);
        verticalLayout->setStretch(2, 1);
        verticalLayout->setStretch(3, 1);
        verticalLayout->setStretch(4, 1);
        verticalLayout->setStretch(5, 2);

        retranslateUi(Register);

        QMetaObject::connectSlotsByName(Register);
    } // setupUi

    void retranslateUi(QDialog *Register)
    {
        Register->setWindowTitle(QApplication::translate("Register", "Dialog", Q_NULLPTR));
        registerBtn->setText(QApplication::translate("Register", "Register", Q_NULLPTR));
        label->setText(QApplication::translate("Register", "\347\224\250\346\210\267\345\220\215", Q_NULLPTR));
        label_2->setText(QApplication::translate("Register", "\345\257\206\347\240\201", Q_NULLPTR));
        label_5->setText(QApplication::translate("Register", "\347\241\256\350\256\244\345\257\206\347\240\201", Q_NULLPTR));
        label_3->setText(QApplication::translate("Register", "\344\275\217\345\235\200", Q_NULLPTR));
        label_4->setText(QApplication::translate("Register", "\347\224\265\350\257\235", Q_NULLPTR));
        logoBtn->setText(QApplication::translate("Register", "\351\200\211\346\213\251\345\244\264\345\203\217", Q_NULLPTR));
        logo_Label->setText(QApplication::translate("Register", "logoLabel", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Register: public Ui_Register {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTER_H

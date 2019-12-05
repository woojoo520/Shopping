/********************************************************************************
** Form generated from reading UI file 'logon.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGON_H
#define UI_LOGON_H

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

class Ui_LogOn
{
public:
    QPushButton *pushButton;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *User_Name;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *User_pwd;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *Register_Btn;
    QPushButton *LogOn_Btn;

    void setupUi(QDialog *LogOn)
    {
        if (LogOn->objectName().isEmpty())
            LogOn->setObjectName(QStringLiteral("LogOn"));
        LogOn->resize(500, 600);
        pushButton = new QPushButton(LogOn);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(30, 60, 201, 61));
        QFont font;
        font.setFamily(QStringLiteral("Monotype Corsiva"));
        font.setPointSize(20);
        font.setItalic(true);
        pushButton->setFont(font);
        layoutWidget = new QWidget(LogOn);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(30, 120, 431, 401));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setFont(font);

        horizontalLayout->addWidget(label);

        User_Name = new QLineEdit(layoutWidget);
        User_Name->setObjectName(QStringLiteral("User_Name"));

        horizontalLayout->addWidget(User_Name);

        horizontalLayout->setStretch(0, 3);
        horizontalLayout->setStretch(1, 6);

        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font);

        horizontalLayout_2->addWidget(label_2);

        User_pwd = new QLineEdit(layoutWidget);
        User_pwd->setObjectName(QStringLiteral("User_pwd"));

        horizontalLayout_2->addWidget(User_pwd);

        horizontalLayout_2->setStretch(0, 3);
        horizontalLayout_2->setStretch(1, 6);

        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(20);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        Register_Btn = new QPushButton(layoutWidget);
        Register_Btn->setObjectName(QStringLiteral("Register_Btn"));
        Register_Btn->setFont(font);

        horizontalLayout_3->addWidget(Register_Btn);

        LogOn_Btn = new QPushButton(layoutWidget);
        LogOn_Btn->setObjectName(QStringLiteral("LogOn_Btn"));
        LogOn_Btn->setFont(font);

        horizontalLayout_3->addWidget(LogOn_Btn);


        verticalLayout->addLayout(horizontalLayout_3);


        retranslateUi(LogOn);

        QMetaObject::connectSlotsByName(LogOn);
    } // setupUi

    void retranslateUi(QDialog *LogOn)
    {
        LogOn->setWindowTitle(QApplication::translate("LogOn", "Dialog", nullptr));
        pushButton->setText(QApplication::translate("LogOn", "GameRule", nullptr));
        label->setText(QApplication::translate("LogOn", "Seller Name:", nullptr));
        label_2->setText(QApplication::translate("LogOn", "Seller Password", nullptr));
        Register_Btn->setText(QApplication::translate("LogOn", "Register", nullptr));
        LogOn_Btn->setText(QApplication::translate("LogOn", "LogOn", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LogOn: public Ui_LogOn {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGON_H

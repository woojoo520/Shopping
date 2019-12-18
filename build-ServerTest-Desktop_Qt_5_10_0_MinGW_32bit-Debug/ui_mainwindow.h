/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QTextEdit *sendEdit;
    QTextEdit *receiveEdit;
    QPushButton *rearr_Unread_Btn;
    QPushButton *rearr_Read_Btn;
    QPushButton *del_Invalid_Btn;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QPushButton *pushButton;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(600, 800);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        sendEdit = new QTextEdit(centralWidget);
        sendEdit->setObjectName(QStringLiteral("sendEdit"));
        sendEdit->setGeometry(QRect(40, 80, 481, 201));
        receiveEdit = new QTextEdit(centralWidget);
        receiveEdit->setObjectName(QStringLiteral("receiveEdit"));
        receiveEdit->setGeometry(QRect(40, 300, 481, 291));
        rearr_Unread_Btn = new QPushButton(centralWidget);
        rearr_Unread_Btn->setObjectName(QStringLiteral("rearr_Unread_Btn"));
        rearr_Unread_Btn->setGeometry(QRect(40, 620, 91, 41));
        rearr_Read_Btn = new QPushButton(centralWidget);
        rearr_Read_Btn->setObjectName(QStringLiteral("rearr_Read_Btn"));
        rearr_Read_Btn->setGeometry(QRect(240, 620, 91, 41));
        del_Invalid_Btn = new QPushButton(centralWidget);
        del_Invalid_Btn->setObjectName(QStringLiteral("del_Invalid_Btn"));
        del_Invalid_Btn->setGeometry(QRect(430, 620, 91, 41));
        widget = new QWidget(centralWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(40, 30, 481, 31));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        lineEdit = new QLineEdit(widget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        horizontalLayout->addWidget(lineEdit);

        lineEdit_2 = new QLineEdit(widget);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));

        horizontalLayout->addWidget(lineEdit_2);

        pushButton = new QPushButton(widget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout->addWidget(pushButton);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 17));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        rearr_Unread_Btn->setText(QApplication::translate("MainWindow", "\351\207\215\347\275\256\346\234\252\350\257\273\346\266\210\346\201\257\347\232\204Id", nullptr));
        rearr_Read_Btn->setText(QApplication::translate("MainWindow", "\351\207\215\347\275\256\345\267\262\350\257\273\346\266\210\346\201\257\347\232\204Id", nullptr));
        del_Invalid_Btn->setText(QApplication::translate("MainWindow", "\345\210\240\351\231\244\345\267\262\347\273\217\345\244\261\346\225\210\347\232\204\345\225\206\345\223\201", nullptr));
        pushButton->setText(QApplication::translate("MainWindow", "OK", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
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
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *priceBtn;
    QPushButton *newBtn;
    QPushButton *chooseBtn;
    QLabel *pic_label;
    QLabel *productLabel;
    QLineEdit *searchEdit;
    QPushButton *searchBtn;
    QWidget *widget;
    QVBoxLayout *verticalLayout_4;
    QLabel *userName_label;
    QLabel *imgLabel;
    QWidget *widget1;
    QVBoxLayout *verticalLayout_3;
    QRadioButton *category1;
    QRadioButton *category2;
    QRadioButton *category3;
    QRadioButton *category4;
    QWidget *widget2;
    QHBoxLayout *horizontalLayout;
    QPushButton *firstPageBtn;
    QPushButton *releaseBtn;
    QPushButton *messageBtn;
    QPushButton *MyBtn;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QButtonGroup *buttonGroup;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(800, 800);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        priceBtn = new QPushButton(centralWidget);
        priceBtn->setObjectName(QStringLiteral("priceBtn"));
        priceBtn->setGeometry(QRect(410, 150, 71, 31));
        newBtn = new QPushButton(centralWidget);
        newBtn->setObjectName(QStringLiteral("newBtn"));
        newBtn->setGeometry(QRect(540, 150, 71, 31));
        chooseBtn = new QPushButton(centralWidget);
        chooseBtn->setObjectName(QStringLiteral("chooseBtn"));
        chooseBtn->setGeometry(QRect(680, 150, 71, 31));
        pic_label = new QLabel(centralWidget);
        pic_label->setObjectName(QStringLiteral("pic_label"));
        pic_label->setGeometry(QRect(50, 70, 251, 111));
        productLabel = new QLabel(centralWidget);
        productLabel->setObjectName(QStringLiteral("productLabel"));
        productLabel->setGeometry(QRect(250, 230, 501, 391));
        searchEdit = new QLineEdit(centralWidget);
        searchEdit->setObjectName(QStringLiteral("searchEdit"));
        searchEdit->setGeometry(QRect(411, 97, 251, 31));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(searchEdit->sizePolicy().hasHeightForWidth());
        searchEdit->setSizePolicy(sizePolicy);
        searchBtn = new QPushButton(centralWidget);
        searchBtn->setObjectName(QStringLiteral("searchBtn"));
        searchBtn->setGeometry(QRect(681, 98, 71, 31));
        widget = new QWidget(centralWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(680, 10, 111, 71));
        verticalLayout_4 = new QVBoxLayout(widget);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        userName_label = new QLabel(widget);
        userName_label->setObjectName(QStringLiteral("userName_label"));

        verticalLayout_4->addWidget(userName_label);

        imgLabel = new QLabel(widget);
        imgLabel->setObjectName(QStringLiteral("imgLabel"));

        verticalLayout_4->addWidget(imgLabel);

        verticalLayout_4->setStretch(0, 1);
        widget1 = new QWidget(centralWidget);
        widget1->setObjectName(QStringLiteral("widget1"));
        widget1->setGeometry(QRect(30, 230, 141, 331));
        verticalLayout_3 = new QVBoxLayout(widget1);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        category1 = new QRadioButton(widget1);
        buttonGroup = new QButtonGroup(MainWindow);
        buttonGroup->setObjectName(QStringLiteral("buttonGroup"));
        buttonGroup->addButton(category1);
        category1->setObjectName(QStringLiteral("category1"));

        verticalLayout_3->addWidget(category1);

        category2 = new QRadioButton(widget1);
        buttonGroup->addButton(category2);
        category2->setObjectName(QStringLiteral("category2"));

        verticalLayout_3->addWidget(category2);

        category3 = new QRadioButton(widget1);
        buttonGroup->addButton(category3);
        category3->setObjectName(QStringLiteral("category3"));

        verticalLayout_3->addWidget(category3);

        category4 = new QRadioButton(widget1);
        buttonGroup->addButton(category4);
        category4->setObjectName(QStringLiteral("category4"));

        verticalLayout_3->addWidget(category4);

        widget2 = new QWidget(centralWidget);
        widget2->setObjectName(QStringLiteral("widget2"));
        widget2->setGeometry(QRect(230, 670, 521, 51));
        horizontalLayout = new QHBoxLayout(widget2);
        horizontalLayout->setSpacing(70);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        firstPageBtn = new QPushButton(widget2);
        firstPageBtn->setObjectName(QStringLiteral("firstPageBtn"));

        horizontalLayout->addWidget(firstPageBtn);

        releaseBtn = new QPushButton(widget2);
        releaseBtn->setObjectName(QStringLiteral("releaseBtn"));

        horizontalLayout->addWidget(releaseBtn);

        messageBtn = new QPushButton(widget2);
        messageBtn->setObjectName(QStringLiteral("messageBtn"));

        horizontalLayout->addWidget(messageBtn);

        MyBtn = new QPushButton(widget2);
        MyBtn->setObjectName(QStringLiteral("MyBtn"));

        horizontalLayout->addWidget(MyBtn);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 800, 17));
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
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        priceBtn->setText(QApplication::translate("MainWindow", "\346\214\211\344\273\267\346\240\274", Q_NULLPTR));
        newBtn->setText(QApplication::translate("MainWindow", "\346\214\211\346\226\260\346\227\247", Q_NULLPTR));
        chooseBtn->setText(QApplication::translate("MainWindow", "\347\255\233\351\200\211", Q_NULLPTR));
        pic_label->setText(QApplication::translate("MainWindow", "Pic", Q_NULLPTR));
        productLabel->setText(QApplication::translate("MainWindow", "used to show product", Q_NULLPTR));
        searchBtn->setText(QApplication::translate("MainWindow", "Search", Q_NULLPTR));
        userName_label->setText(QApplication::translate("MainWindow", "UserName", Q_NULLPTR));
        imgLabel->setText(QApplication::translate("MainWindow", "\345\244\264\345\203\217", Q_NULLPTR));
        category1->setText(QApplication::translate("MainWindow", "\347\261\273\345\210\2531", Q_NULLPTR));
        category2->setText(QApplication::translate("MainWindow", "\347\261\273\345\210\2532", Q_NULLPTR));
        category3->setText(QApplication::translate("MainWindow", "\347\261\273\345\210\2533", Q_NULLPTR));
        category4->setText(QApplication::translate("MainWindow", "\347\261\273\345\210\2534", Q_NULLPTR));
        firstPageBtn->setText(QApplication::translate("MainWindow", "\351\246\226\351\241\265", Q_NULLPTR));
        releaseBtn->setText(QApplication::translate("MainWindow", "\345\217\221\345\270\203", Q_NULLPTR));
        messageBtn->setText(QApplication::translate("MainWindow", "\346\266\210\346\201\257", Q_NULLPTR));
        MyBtn->setText(QApplication::translate("MainWindow", "\346\210\221\347\232\204", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

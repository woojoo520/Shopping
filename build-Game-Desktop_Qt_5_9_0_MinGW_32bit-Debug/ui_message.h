/********************************************************************************
** Form generated from reading UI file 'message.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MESSAGE_H
#define UI_MESSAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>

QT_BEGIN_NAMESPACE

class Ui_Message
{
public:
    QTextBrowser *receiveEdit;
    QLabel *Blabel;
    QTextBrowser *sendEdit;
    QPushButton *sendBtn;

    void setupUi(QDialog *Message)
    {
        if (Message->objectName().isEmpty())
            Message->setObjectName(QStringLiteral("Message"));
        Message->resize(400, 500);
        receiveEdit = new QTextBrowser(Message);
        receiveEdit->setObjectName(QStringLiteral("receiveEdit"));
        receiveEdit->setGeometry(QRect(0, 50, 401, 321));
        Blabel = new QLabel(Message);
        Blabel->setObjectName(QStringLiteral("Blabel"));
        Blabel->setGeometry(QRect(140, 16, 131, 20));
        sendEdit = new QTextBrowser(Message);
        sendEdit->setObjectName(QStringLiteral("sendEdit"));
        sendEdit->setGeometry(QRect(0, 380, 401, 81));
        sendBtn = new QPushButton(Message);
        sendBtn->setObjectName(QStringLiteral("sendBtn"));
        sendBtn->setGeometry(QRect(310, 470, 80, 21));

        retranslateUi(Message);

        QMetaObject::connectSlotsByName(Message);
    } // setupUi

    void retranslateUi(QDialog *Message)
    {
        Message->setWindowTitle(QApplication::translate("Message", "Dialog", Q_NULLPTR));
        Blabel->setText(QApplication::translate("Message", "\345\225\206\345\256\266", Q_NULLPTR));
        sendBtn->setText(QApplication::translate("Message", "\345\217\221\351\200\201", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Message: public Ui_Message {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MESSAGE_H

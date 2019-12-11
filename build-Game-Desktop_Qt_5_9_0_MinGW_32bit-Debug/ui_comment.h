/********************************************************************************
** Form generated from reading UI file 'comment.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COMMENT_H
#define UI_COMMENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_comment
{
public:
    QTextEdit *myComment;
    QPushButton *pushButton;
    QLabel *label;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;

    void setupUi(QDialog *comment)
    {
        if (comment->objectName().isEmpty())
            comment->setObjectName(QStringLiteral("comment"));
        comment->resize(400, 500);
        myComment = new QTextEdit(comment);
        myComment->setObjectName(QStringLiteral("myComment"));
        myComment->setGeometry(QRect(20, 360, 361, 91));
        pushButton = new QPushButton(comment);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(300, 460, 80, 21));
        label = new QLabel(comment);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(190, 20, 81, 21));
        scrollArea = new QScrollArea(comment);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setGeometry(QRect(19, 49, 361, 301));
        scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 359, 299));
        scrollArea->setWidget(scrollAreaWidgetContents);

        retranslateUi(comment);

        QMetaObject::connectSlotsByName(comment);
    } // setupUi

    void retranslateUi(QDialog *comment)
    {
        comment->setWindowTitle(QApplication::translate("comment", "Dialog", Q_NULLPTR));
        pushButton->setText(QApplication::translate("comment", "\345\217\221\351\200\201", Q_NULLPTR));
        label->setText(QApplication::translate("comment", "\350\257\204\350\256\272\345\214\272", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class comment: public Ui_comment {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COMMENT_H

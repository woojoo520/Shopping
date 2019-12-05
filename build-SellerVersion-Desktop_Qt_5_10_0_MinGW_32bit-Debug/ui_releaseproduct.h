/********************************************************************************
** Form generated from reading UI file 'releaseproduct.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RELEASEPRODUCT_H
#define UI_RELEASEPRODUCT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>

QT_BEGIN_NAMESPACE

class Ui_ReleaseProduct
{
public:

    void setupUi(QDialog *ReleaseProduct)
    {
        if (ReleaseProduct->objectName().isEmpty())
            ReleaseProduct->setObjectName(QStringLiteral("ReleaseProduct"));
        ReleaseProduct->resize(400, 300);

        retranslateUi(ReleaseProduct);

        QMetaObject::connectSlotsByName(ReleaseProduct);
    } // setupUi

    void retranslateUi(QDialog *ReleaseProduct)
    {
        ReleaseProduct->setWindowTitle(QApplication::translate("ReleaseProduct", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ReleaseProduct: public Ui_ReleaseProduct {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RELEASEPRODUCT_H

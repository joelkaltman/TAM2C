/********************************************************************************
** Form generated from reading UI file 'ApPanels.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_APPANELS_H
#define UI_APPANELS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ApPanelsClass
{
public:

    void setupUi(QWidget *ApPanelsClass)
    {
        if (ApPanelsClass->objectName().isEmpty())
            ApPanelsClass->setObjectName(QString::fromUtf8("ApPanelsClass"));
        ApPanelsClass->resize(600, 400);

        retranslateUi(ApPanelsClass);

        QMetaObject::connectSlotsByName(ApPanelsClass);
    } // setupUi

    void retranslateUi(QWidget *ApPanelsClass)
    {
        ApPanelsClass->setWindowTitle(QApplication::translate("ApPanelsClass", "ApPanels", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ApPanelsClass: public Ui_ApPanelsClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_APPANELS_H

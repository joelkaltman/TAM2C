/********************************************************************************
** Form generated from reading UI file 'JtanPanels.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_JTANPANELS_H
#define UI_JTANPANELS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_JtanPanelsClass
{
public:
    QLabel *JTAN_Background;

    void setupUi(QWidget *JtanPanelsClass)
    {
        if (JtanPanelsClass->objectName().isEmpty())
            JtanPanelsClass->setObjectName(QString::fromUtf8("JtanPanelsClass"));
        JtanPanelsClass->resize(1920, 1080);
        JTAN_Background = new QLabel(JtanPanelsClass);
        JTAN_Background->setObjectName(QString::fromUtf8("JTAN_Background"));
        JTAN_Background->setGeometry(QRect(0, 0, 1920, 1080));

        retranslateUi(JtanPanelsClass);

        QMetaObject::connectSlotsByName(JtanPanelsClass);
    } // setupUi

    void retranslateUi(QWidget *JtanPanelsClass)
    {
        JtanPanelsClass->setWindowTitle(QApplication::translate("JtanPanelsClass", "JtanPanels", nullptr));
        JTAN_Background->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class JtanPanelsClass: public Ui_JtanPanelsClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_JTANPANELS_H

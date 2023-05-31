/********************************************************************************
** Form generated from reading UI file 'axevertical.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AXEVERTICAL_H
#define UI_AXEVERTICAL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AxeVertical
{
public:

    void setupUi(QWidget *AxeVertical)
    {
        if (AxeVertical->objectName().isEmpty())
            AxeVertical->setObjectName(QStringLiteral("AxeVertical"));
        AxeVertical->resize(400, 300);

        retranslateUi(AxeVertical);

        QMetaObject::connectSlotsByName(AxeVertical);
    } // setupUi

    void retranslateUi(QWidget *AxeVertical)
    {
        AxeVertical->setWindowTitle(QApplication::translate("AxeVertical", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AxeVertical: public Ui_AxeVertical {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AXEVERTICAL_H

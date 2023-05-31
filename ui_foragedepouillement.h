/********************************************************************************
** Form generated from reading UI file 'foragedepouillement.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORAGEDEPOUILLEMENT_H
#define UI_FORAGEDEPOUILLEMENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ForageDepouillement
{
public:

    void setupUi(QWidget *ForageDepouillement)
    {
        if (ForageDepouillement->objectName().isEmpty())
            ForageDepouillement->setObjectName(QStringLiteral("ForageDepouillement"));
        ForageDepouillement->resize(1182, 662);
        QPalette palette;
        QBrush brush(QColor(238, 238, 236, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(255, 255, 255, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Base, brush1);
        QBrush brush2(QColor(0, 0, 0, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Window, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush2);
        QBrush brush3(QColor(190, 190, 190, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush2);
        ForageDepouillement->setPalette(palette);
        ForageDepouillement->setStyleSheet(QStringLiteral(""));

        retranslateUi(ForageDepouillement);

        QMetaObject::connectSlotsByName(ForageDepouillement);
    } // setupUi

    void retranslateUi(QWidget *ForageDepouillement)
    {
        ForageDepouillement->setWindowTitle(QApplication::translate("ForageDepouillement", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ForageDepouillement: public Ui_ForageDepouillement {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORAGEDEPOUILLEMENT_H

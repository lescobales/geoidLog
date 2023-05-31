/********************************************************************************
** Form generated from reading UI file 'foragecoupe.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORAGECOUPE_H
#define UI_FORAGECOUPE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ForageCoupe
{
public:

    void setupUi(QWidget *ForageCoupe)
    {
        if (ForageCoupe->objectName().isEmpty())
            ForageCoupe->setObjectName(QStringLiteral("ForageCoupe"));
        ForageCoupe->resize(251, 478);
        QPalette palette;
        QBrush brush(QColor(239, 41, 41, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        QBrush brush1(QColor(255, 255, 255, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Base, brush1);
        QBrush brush2(QColor(0, 0, 0, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Window, brush2);
        palette.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
        QBrush brush3(QColor(190, 190, 190, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        ForageCoupe->setPalette(palette);
        ForageCoupe->setMouseTracking(true);
        ForageCoupe->setStyleSheet(QStringLiteral(""));

        retranslateUi(ForageCoupe);

        QMetaObject::connectSlotsByName(ForageCoupe);
    } // setupUi

    void retranslateUi(QWidget *ForageCoupe)
    {
        ForageCoupe->setWindowTitle(QApplication::translate("ForageCoupe", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ForageCoupe: public Ui_ForageCoupe {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORAGECOUPE_H

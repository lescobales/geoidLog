/********************************************************************************
** Form generated from reading UI file 'graphique.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GRAPHIQUE_H
#define UI_GRAPHIQUE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Graphique
{
public:

    void setupUi(QWidget *Graphique)
    {
        if (Graphique->objectName().isEmpty())
            Graphique->setObjectName(QStringLiteral("Graphique"));
        Graphique->resize(400, 300);

        retranslateUi(Graphique);

        QMetaObject::connectSlotsByName(Graphique);
    } // setupUi

    void retranslateUi(QWidget *Graphique)
    {
        Graphique->setWindowTitle(QApplication::translate("Graphique", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Graphique: public Ui_Graphique {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GRAPHIQUE_H

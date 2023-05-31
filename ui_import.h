/********************************************************************************
** Form generated from reading UI file 'import.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IMPORT_H
#define UI_IMPORT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Import
{
public:
    QGridLayout *gridLayout;
    QSpacerItem *verticalSpacer_11;
    QVBoxLayout *verticalLayout_3;
    QLabel *lb_chantier;
    QListWidget *lw_Chantier;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer_12;
    QPushButton *bt_Valider;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer_2;
    QLabel *lb_Ville;
    QSpacerItem *verticalSpacer_5;
    QLabel *lb_Date;
    QSpacerItem *verticalSpacer_6;
    QLabel *lb_Adresse;
    QSpacerItem *verticalSpacer_7;
    QLabel *lb_NbreForage;
    QSpacerItem *verticalSpacer;
    QVBoxLayout *verticalLayout_2;
    QSpacerItem *verticalSpacer_3;
    QLineEdit *le_Ville;
    QSpacerItem *verticalSpacer_8;
    QLineEdit *le_Date;
    QSpacerItem *verticalSpacer_9;
    QLineEdit *le_Adresse;
    QSpacerItem *verticalSpacer_10;
    QLineEdit *le_NbreForage;
    QSpacerItem *verticalSpacer_4;
    QSpacerItem *horizontalSpacer;
    QLabel *lb_Titre;

    void setupUi(QWidget *Import)
    {
        if (Import->objectName().isEmpty())
            Import->setObjectName(QStringLiteral("Import"));
        Import->resize(1171, 693);
        gridLayout = new QGridLayout(Import);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalSpacer_11 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_11, 3, 2, 1, 1);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        lb_chantier = new QLabel(Import);
        lb_chantier->setObjectName(QStringLiteral("lb_chantier"));
        lb_chantier->setMaximumSize(QSize(16777215, 16777215));
        QFont font;
        font.setPointSize(12);
        lb_chantier->setFont(font);
        lb_chantier->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(lb_chantier);

        lw_Chantier = new QListWidget(Import);
        lw_Chantier->setObjectName(QStringLiteral("lw_Chantier"));
        lw_Chantier->setMaximumSize(QSize(16777215, 16777215));

        verticalLayout_3->addWidget(lw_Chantier);


        gridLayout->addLayout(verticalLayout_3, 2, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 2, 3, 1, 1);

        verticalSpacer_12 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_12, 1, 1, 1, 1);

        bt_Valider = new QPushButton(Import);
        bt_Valider->setObjectName(QStringLiteral("bt_Valider"));

        gridLayout->addWidget(bt_Valider, 4, 2, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        lb_Ville = new QLabel(Import);
        lb_Ville->setObjectName(QStringLiteral("lb_Ville"));
        QFont font1;
        font1.setPointSize(16);
        font1.setBold(false);
        font1.setWeight(50);
        lb_Ville->setFont(font1);

        verticalLayout->addWidget(lb_Ville);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_5);

        lb_Date = new QLabel(Import);
        lb_Date->setObjectName(QStringLiteral("lb_Date"));
        lb_Date->setFont(font1);

        verticalLayout->addWidget(lb_Date);

        verticalSpacer_6 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_6);

        lb_Adresse = new QLabel(Import);
        lb_Adresse->setObjectName(QStringLiteral("lb_Adresse"));
        lb_Adresse->setFont(font1);

        verticalLayout->addWidget(lb_Adresse);

        verticalSpacer_7 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_7);

        lb_NbreForage = new QLabel(Import);
        lb_NbreForage->setObjectName(QStringLiteral("lb_NbreForage"));
        lb_NbreForage->setFont(font1);

        verticalLayout->addWidget(lb_NbreForage);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_3);

        le_Ville = new QLineEdit(Import);
        le_Ville->setObjectName(QStringLiteral("le_Ville"));
        le_Ville->setMinimumSize(QSize(200, 0));
        le_Ville->setReadOnly(true);

        verticalLayout_2->addWidget(le_Ville);

        verticalSpacer_8 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_8);

        le_Date = new QLineEdit(Import);
        le_Date->setObjectName(QStringLiteral("le_Date"));
        le_Date->setMinimumSize(QSize(200, 0));
        le_Date->setReadOnly(true);

        verticalLayout_2->addWidget(le_Date);

        verticalSpacer_9 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_9);

        le_Adresse = new QLineEdit(Import);
        le_Adresse->setObjectName(QStringLiteral("le_Adresse"));
        le_Adresse->setMinimumSize(QSize(200, 0));
        le_Adresse->setReadOnly(true);

        verticalLayout_2->addWidget(le_Adresse);

        verticalSpacer_10 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_10);

        le_NbreForage = new QLineEdit(Import);
        le_NbreForage->setObjectName(QStringLiteral("le_NbreForage"));
        le_NbreForage->setMinimumSize(QSize(200, 0));
        le_NbreForage->setReadOnly(true);

        verticalLayout_2->addWidget(le_NbreForage);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_4);


        horizontalLayout->addLayout(verticalLayout_2);


        gridLayout->addLayout(horizontalLayout, 2, 2, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 2, 0, 1, 1);

        lb_Titre = new QLabel(Import);
        lb_Titre->setObjectName(QStringLiteral("lb_Titre"));
        QFont font2;
        font2.setPointSize(24);
        lb_Titre->setFont(font2);
        lb_Titre->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(lb_Titre, 0, 1, 1, 2);


        retranslateUi(Import);

        QMetaObject::connectSlotsByName(Import);
    } // setupUi

    void retranslateUi(QWidget *Import)
    {
        Import->setWindowTitle(QApplication::translate("Import", "Form", nullptr));
        lb_chantier->setText(QApplication::translate("Import", "S\303\251lectionner le chantier \303\240 importer", nullptr));
        bt_Valider->setText(QApplication::translate("Import", "Valider", nullptr));
        lb_Ville->setText(QApplication::translate("Import", "Ville", nullptr));
        lb_Date->setText(QApplication::translate("Import", "Date", nullptr));
        lb_Adresse->setText(QApplication::translate("Import", "Adresse", nullptr));
        lb_NbreForage->setText(QApplication::translate("Import", "Nombre forage", nullptr));
        lb_Titre->setText(QApplication::translate("Import", "Importer un chantier", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Import: public Ui_Import {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IMPORT_H

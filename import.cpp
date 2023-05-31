#include "import.h"
#include "ui_import.h"

#include <QDebug>

Import::Import(QTabWidget *tabChantier, QTabWidget *tabForage, QWidget *parent) :
  QWidget(parent),
  ui(new Ui::Import)
{
  ui->setupUi(this);

  chantierTab = tabChantier;
  forageTab = tabForage;
  row = -1;
  listData = new QStringList;
}

Import::~Import()
{
  delete ui;
}

void Import::setFileName(QString fileName)
{
  QStringList listFileName;
  listFileName = fileName.split("/");
  listFileName.removeLast();
  this->fileName = listFileName.join("/");
}

void Import::show()
{
  if(!fileName.isEmpty())
    {
      QFile file(fileName+"/chantier.txt");
      if(file.open(QIODevice::ReadOnly))
        {
          QTextStream stream(&file);
              while(!stream.atEnd())
              {
                  listChantier.append(stream.readLine());
              }
              QString chantier;
              QStringList elementChantier;
              for(int i = 0; i < listChantier.length(); i++)
                {
                  chantier = listChantier.at(i);
                  elementChantier = chantier.split(";");
                  QListWidgetItem *newItem = new QListWidgetItem;
                  newItem->setText(elementChantier.at(1));
                  ui->lw_Chantier->insertItem(i, newItem);
                  ui->lw_Chantier->currentRowChanged(i);
                }
        }
    }
  else
    {
      qDebug() << "Erreur d'ouverture";
    }



  QWidget::show();
}

void Import::rechercheForage(QString dossierForage)
{
  if(!fileName.isEmpty())
    {
      foragePath = fileName+"/"+dossierForage;
      QFile file(fileName+"/"+dossierForage+"/forage.txt");
      if(file.open(QIODevice::ReadOnly))
        {
          QStringList list;
          QTextStream stream(&file);
              while(!stream.atEnd())
              {
                  list.append(stream.readLine());
              }
              listForage.clear();
              listForage = list;
              ui->le_NbreForage->setText(QString::number(list.length()));
        }
    }
}

QStringList *Import::getDataForage(QString pathForage)
{
  QStringList *dataForage = new QStringList;
  QFile file(pathForage);
      if(file.open(QIODevice::ReadOnly))
        {
          QTextStream stream(&file);
              while(!stream.atEnd())
              {
                  dataForage->append(stream.readLine());
              }
        }
      return dataForage;
}

void Import::on_lw_Chantier_currentRowChanged(int currentRow)
{
  row = currentRow;
  ///Renseignement des données dans les labels
  QStringList elementChantier;
  elementChantier = listChantier.at(currentRow).split(";");
  rechercheForage(elementChantier.at(0));
  ui->le_Adresse->setText(elementChantier.at(3));
  ui->le_Ville->setText(elementChantier.at(2));
  ui->le_Date->setText(elementChantier.at(0));
}

void Import::on_bt_Valider_clicked()
{
  if(row != -1)
    {
      QStringList elementChantier = listChantier.at(row).split(";");
      ///Insertions des données dans les tab chantier et forage
      ForageDepouillement *dep= new ForageDepouillement;
      dep->setGeometry(this->x(), this->y()+50, this->width(),this->height());
      dep->setItemGeometry(this->x(), this->y(),this->width(),this->height());
      chantierTab->setGeometry(dep->geometry());
      QStringList list;
      QString nomForage;
      forageTab = new QTabWidget(chantierTab);
      for(int i = 0; i < listForage.length(); i++)
        {
          nomForage =listForage.at(i);
          list = nomForage.split(";");
          foragePath += "/" + list.at(0) + ".txt";
          QStringList *dataForage = new QStringList;
          dataForage = getDataForage(foragePath);
          ForageDepouillement *dep= new ForageDepouillement;
          dep->setData(dataForage);
          dep->setGeometry(this->x(), this->y()+50, this->width(),this->height());
          dep->setItemGeometry(this->x(), this->y(),this->width(),this->height());
          forageTab->addTab(dep, list.at(1));
        }
      chantierTab->addTab(forageTab, elementChantier.at(1));
      chantierTab->setVisible(true);
      this->close();
    }
}

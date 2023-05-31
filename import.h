#ifndef IMPORT_H
#define IMPORT_H

#include <QWidget>
#include <QFile>
#include <QTabWidget>

#include "foragedepouillement.h"
namespace Ui {
  class Import;
}

class Import : public QWidget
{
  Q_OBJECT

public:
  explicit Import(QTabWidget *tabChantier, QTabWidget *tabForage, QWidget *parent = 0);
  ~Import();
  void setFileName(QString fileName);
  void show();
  void rechercheForage(QString dossierForage);
  QStringList* getDataForage(QString pathForage);

private slots:
  void on_lw_Chantier_currentRowChanged(int currentRow);

  void on_bt_Valider_clicked();

private:
  Ui::Import *ui;
  QString fileName, foragePath;
  QStringList listChantier;
  QStringList listForage;
  QTabWidget *chantierTab;
  QTabWidget *forageTab;
  int row;
  QStringList *listData;

};

#endif // IMPORT_H

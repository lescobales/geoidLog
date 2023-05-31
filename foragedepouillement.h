#ifndef FORAGEDEPOUILLEMENT_H
#define FORAGEDEPOUILLEMENT_H

#include <QWidget>
#include <QPaintEvent>
#include <QPainter>

#include "foragecoupe.h"
#include "axevertical.h"
#include "graphique.h"

namespace Ui {
  class ForageDepouillement;
}

class ForageDepouillement : public QWidget
{
  Q_OBJECT

public:
  explicit ForageDepouillement(QWidget *parent = 0);
  ~ForageDepouillement();
  void paintEvent(QPaintEvent *event);
  void setItemGeometry(int x, int y, int w, int h);
  void setData(QStringList *listData);

private:
  Ui::ForageDepouillement *ui;
  ForageCoupe *coupe;
  AxeVertical *vAxe;
  Graphique *graphVia;
  Graphique *graphPO;
  Graphique *graphCR;
  Graphique *graphPI;
  QList<Graphique*> listGraph;

};

#endif // FORAGEDEPOUILLEMENT_H

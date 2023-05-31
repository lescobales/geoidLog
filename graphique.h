#ifndef GRAPHIQUE_H
#define GRAPHIQUE_H

#include <QWidget>
#include <QPaintEvent>
#include <QPen>
#include <QBrush>
#include <QPainter>

namespace Ui {
  class Graphique;
}

class Graphique : public QWidget
{
  Q_OBJECT

public:
  explicit Graphique(int typGraph, QWidget *parent = 0);
  ~Graphique();
  void paintEvent(QPaintEvent *);
  void initGraph(int type);
  void setData(QStringList *listData);

  typedef enum
      {
          via = 0,
          PO,
          CR,
          PI
      }Type_Graph;

private:
  Ui::Graphique *ui;
  int typGraph;
  QList<QBrush> listBrush;
  QList<QPen> listPen;
  QStringList *listDataForage;
  QPolygonF polyVia;
};

#endif // GRAPHIQUE_H

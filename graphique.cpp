#include "graphique.h"
#include "ui_graphique.h"

#include <QThread>

Graphique::Graphique(int typGraph, QWidget *parent) :
  QWidget(parent),
  ui(new Ui::Graphique)
{
  ui->setupUi(this);

  QBrush polygonViaBrush, polygonPOBrush, polygonCRBrush, polygonPIBrush;
  listBrush << polygonViaBrush << polygonPOBrush << polygonCRBrush << polygonPIBrush;

  QPen polygonViaPen, polygonPOPen, polygonCRPen, polygonPIPen;
  listPen << polygonViaPen << polygonPOPen << polygonCRPen << polygonPIPen;
  initGraph(typGraph);
}

Graphique::~Graphique()
{
  delete ui;
}

void Graphique::paintEvent(QPaintEvent *)
{
  QPainter painter;
  QBrush background = QBrush(QColor(255,255,255));
  painter.begin(this);
  painter.setRenderHint(QPainter::Antialiasing);
  QRect rect(1,1,this->width()-2,this->height() - 2);
  painter.fillRect(rect, background);

  painter.translate(2,0);
  painter.setBrush(listBrush.at(typGraph));
  painter.setPen(listPen.at(typGraph));

  QString data;
  QStringList listDonne;
  for(int i = 0; i < 100/*listDataForage->length()*/; i++)
    {
      data = listDataForage->at(i);
      listDonne = data.split(";");

      QPointF point(listDonne.at(1).toFloat()*80/1000, listDonne.at(0).toFloat());
      polyVia << point;
    }
  QPointF fermeture(0,listDonne.at(0).toFloat());
  polyVia << fermeture;
  QThread::sleep(1000);
  painter.drawPolygon(polyVia);
  painter.end();
}

void Graphique::initGraph(int type)
{
  typGraph = type;

  switch(typGraph)
    {
      case via:
            listBrush[typGraph] = QBrush(Qt::red);
            listPen[typGraph] = QPen(Qt::black);
            listPen[typGraph].setWidthF(0.1);
            listPen[typGraph].setStyle(Qt::SolidLine);
          break;
      case PO:
            listBrush[typGraph] = QBrush(Qt::yellow);
            listPen[typGraph] = QPen(Qt::black);
            listPen[typGraph].setWidthF(0.1);
          break;

      case CR:
            listBrush[typGraph] = QBrush(Qt::green);
            listPen[typGraph] = QPen(Qt::black);
            listPen[typGraph].setWidthF(0.1);
          break;

      case PI:
            listBrush[typGraph] = QBrush(Qt::blue);
            listPen[typGraph] = QPen(Qt::black);
            listPen[typGraph].setWidthF(0.1);
          break;
    }
}

void Graphique::setData(QStringList *listData)
{
  listDataForage = listData;
}

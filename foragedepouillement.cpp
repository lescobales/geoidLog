#include "foragedepouillement.h"
#include "ui_foragedepouillement.h"

ForageDepouillement::ForageDepouillement(QWidget *parent) :
  QWidget(parent),
  ui(new Ui::ForageDepouillement)
{
  ui->setupUi(this);
  coupe = new ForageCoupe(this);
  vAxe = new AxeVertical(this);
  graphVia = new Graphique(0,this);
  graphPO = new Graphique(1,this);
  graphCR = new Graphique(2,this);
  graphPI = new Graphique(3,this);
  listGraph << graphVia << graphPO << graphCR << graphPI;

  coupe->show();
  vAxe->show();
  for(int i = 0; i < listGraph.length(); i++)
    {
      listGraph.at(i)->show();
    }
}

ForageDepouillement::~ForageDepouillement()
{
  delete ui;
}

void ForageDepouillement::paintEvent(QPaintEvent *event)
{
  QPainter painter;
  QBrush background = QBrush(QColor(0, 0, 0));
  painter.begin(this);
  painter.setRenderHint(QPainter::Antialiasing);
  QRect rect(1,1,this->width()-2,this->height() - 2);
  painter.fillRect(rect, background);
  painter.setPen(QColor(0,0,0));
  painter.drawText(200,200,"Hello");
  painter.end();

}

void ForageDepouillement::setItemGeometry(int x, int y, int w, int h)
{
  coupe->setGeometry(x,y,w/3,h);
  coupe->setItemGeometry(x,y,w/3,h);

  vAxe->setGeometry(w/3,y,40,h);

  int dx = coupe->width() + vAxe->width();
  for(int i = 0; i < listGraph.length(); i++)
    {
      listGraph.at(i)->setGeometry(dx,y,this->width()/12,this->height());
      dx += this->width()/12;
    }
}

void ForageDepouillement::setData(QStringList *listData)
{
  for(int i = 0; i < listGraph.length(); i++)
    {
      listGraph.at(i)->setData(listData);
    }
}


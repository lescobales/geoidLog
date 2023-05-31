#include "axevertical.h"
#include "ui_axevertical.h"

AxeVertical::AxeVertical(QWidget *parent) :
  QWidget(parent),
  ui(new Ui::AxeVertical)
{
  ui->setupUi(this);
}

AxeVertical::~AxeVertical()
{
  delete ui;
}

void AxeVertical::paintEvent(QPaintEvent *ev)
{
  QPainter painter;
  QBrush background = QBrush(QColor(255,255,255));
  painter.begin(this);
  painter.setRenderHint(QPainter::Antialiasing);
  QRect rect(1,1,this->width()-2,this->height() - 2);
  painter.fillRect(rect, background);

  painter.setPen(QColor(0,0,0));
  QLine vLine(30,0,30,this->height());
  painter.drawLine(vLine);

  for(int i = 0; i < this->height(); i+=50)
    {
      QLine hLine(27,i,33,i);
      painter.drawLine(hLine);
    }

  painter.setFont(QFont("Arial",8));
  for(float i = 0; i < this->height(); i+=50)
    {
      painter.drawText(5,i,QString::number(i/100));
    }
  painter.end();
}

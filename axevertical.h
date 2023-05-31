#ifndef AXEVERTICAL_H
#define AXEVERTICAL_H

#include <QWidget>
#include <QPaintEvent>
#include <QPainter>

namespace Ui {
  class AxeVertical;
}

class AxeVertical : public QWidget
{
  Q_OBJECT

public:
  explicit AxeVertical(QWidget *parent = 0);
  ~AxeVertical();
  void paintEvent(QPaintEvent *ev);

private:
  Ui::AxeVertical *ui;
};

#endif // AXEVERTICAL_H

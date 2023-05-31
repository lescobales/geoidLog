#ifndef FORAGECOUPE_H
#define FORAGECOUPE_H

#include <QWidget>
#include <QMouseEvent>
#include <QPaintEvent>
#include <QPainter>
#include <QTextEdit>
#include <QPushButton>
#include <QMap>
#include <QDoubleSpinBox>
#include <QDateTime>
#include <QTimer>
#include <QCursor>
#include <QFileDialog>

namespace Ui {
  class ForageCoupe;
}

class ForageCoupe : public QWidget
{
  Q_OBJECT

public:
  explicit ForageCoupe(QWidget *parent = 0);
  ~ForageCoupe();
  void mousePressEvent(QMouseEvent *ev);
  void mouseReleaseEvent(QMouseEvent *ev);
  void mouseMoveEvent(QMouseEvent *e);
  void paintEvent(QPaintEvent *);
  void triCroissant();
  void cliqueLeftBoutton(QMouseEvent *ev);
  void updateZone();
  void setItemGeometry(int x, int y, int w, int h);

private:
  Ui::ForageCoupe *ui;
  QStringList listTextCoupe;
  QList<QList<double>> listCoteCoupe;
  int pos; //Permet de savoir si nouveau element et à quelle position pour modification
  QTextEdit *t;
  QWidget *w;
  QDoubleSpinBox *debut;
  QDoubleSpinBox *fin;
  QList<QRect> listRectZone;
  QList<QRect> listRectLitho;
  bool decBas;
  bool decHaut;
  bool rectHeightZero;
  QList<QRect> listRectZeroHeight;
  quint64 mLastPressTime=0;
  static const quint64 MY_LONG_PRESS_THRESHOLD=1000;
  bool longPress;
  bool pressingMouse;
  int mouseYPos;
  QTimer *mousePress;
  bool deplacementV;
  int deplacementXPos;
  int lithoXPos;
  int largeurLitho;
  int largeurDeplacement;
  int posZeroHeight;
  QStringList listLithoFileName;
  bool isRectZone;

public slots:
  void valider();
  void appuiLong();
};

#endif // FORAGECOUPE_H

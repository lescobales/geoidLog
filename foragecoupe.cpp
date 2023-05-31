#include "foragecoupe.h"
#include "ui_foragecoupe.h"

#include <QDebug>

ForageCoupe::ForageCoupe(QWidget *parent) :
  QWidget(parent),
  ui(new Ui::ForageCoupe)
{
  ui->setupUi(this);
  pos = 0;
  decBas = decHaut = false;
  rectHeightZero = false;
  longPress = false;
  pressingMouse = false;
  mouseYPos = 0;
  mousePress = new QTimer(this);
  deplacementV = false;

  largeurDeplacement = 20;
  largeurLitho = 40;
  isRectZone = false;

  for(int i = 0; i < 50; i++)
    {
      listLithoFileName << "";
    }

  connect(mousePress,SIGNAL(timeout()),this,SLOT(appuiLong()));
}

ForageCoupe::~ForageCoupe()
{
  delete ui;
}

void ForageCoupe::mousePressEvent(QMouseEvent *ev)
{
  if(!pressingMouse)
    {
      mLastPressTime=QDateTime::currentMSecsSinceEpoch();
      pressingMouse = true;
      mouseYPos = ev->y();
      mousePress->start(250);

      for(int i = 0; i < listRectZone.length(); i++)
        {
          if(listRectZone.at(i).contains(5,ev->y()))
            {
              pos = i;
            }
        }
      if(pos < listRectZone.length())
        {
          QRect rect(listRectZone.at(pos));
          rect.setX(deplacementXPos);
          rect.setWidth(largeurDeplacement);
          if(rect.contains(ev->x(),ev->y()))
            deplacementV = true;
        }

      QRect rectZone(0,0,lithoXPos,this->height());
      if(rectZone.contains(ev->x(), ev->y()))
        isRectZone = true;
    }
}

void ForageCoupe::appuiLong()
{
  const quint64 pressTime = QDateTime::currentMSecsSinceEpoch() - mLastPressTime;
  if( pressTime > MY_LONG_PRESS_THRESHOLD)
    {
      longPress = true;
      mousePress->stop();
      if(deplacementV)
        this->setCursor(Qt::SizeVerCursor);
    }
}

void ForageCoupe::mouseReleaseEvent(QMouseEvent *ev)
{

  if(ev->button() == Qt::LeftButton && !longPress)
    {
      mousePress->stop();
      pressingMouse = false;
      longPress = false;
      cliqueLeftBoutton(ev);
    }
  else if(ev->button() == Qt::LeftButton && longPress)
    {
      longPress = false;
      pressingMouse = false;
      this->setCursor(Qt::ArrowCursor);
      pos = listCoteCoupe.length();
    }
}

void ForageCoupe::mouseMoveEvent(QMouseEvent *e)
{
  if(longPress && pos < listRectZone.length())
    {
      QRect rect(listRectZone.at(pos));
      rect.setX(deplacementXPos);
      rect.setWidth(largeurDeplacement);
          //if(listRectZone.at(pos).contains(e->x(), e->y()))
      if(rect.contains(e->x(), e->y()))
            {
              fin = new QDoubleSpinBox;
              debut = new QDoubleSpinBox;
              debut->setValue((double)listRectZone.at(pos).y()/100);
              double dec = (e->y()-mouseYPos);
              if(dec == 1)
                dec = 1.5;
              if(dec == -1)
                dec = -1.5;
              fin->setValue((double)(dec+listRectZone.at(pos).y()+listRectZone.at(pos).height())/100);
              //qDebug() << (e->y()-mouseYPos); //<<listRectZone.at(pos).y()+listRectZone.at(pos).height();
              mouseYPos = e->y();

              t = new QTextEdit;
              t->setText(listTextCoupe.at(pos));
              valider();
              debut->~QDoubleSpinBox();
              fin->~QDoubleSpinBox();
              t->~QTextEdit();
            }

    }
}

void ForageCoupe::paintEvent(QPaintEvent *)
{
  QPainter painter;
  QBrush background = QBrush(QColor(255,255,255));
  painter.begin(this);
  painter.setRenderHint(QPainter::Antialiasing);
  QRect rect(1,1,this->width()-2,this->height() - 2);
  painter.fillRect(rect, background);

  ///Verification de zone non valide
  if(rectHeightZero)
    {
      listRectZone.removeAt(posZeroHeight);
      listCoteCoupe.removeAt(posZeroHeight);
      listTextCoupe.removeAt(posZeroHeight);
      listLithoFileName.replace(posZeroHeight,"");
      rectHeightZero = false;
      //pos = listCoteCoupe.length();
    }

  for(int i = 0; i < listCoteCoupe.length(); i++)
    {
      if(listRectZone.at(i).height() != 0)
        {
          painter.setPen(QColor("#E2E5E1"));
          painter.drawRect(listRectLitho.at(i));

          QRect source(0.0,0.0,180.0,180.0);
          if(listLithoFileName.at(i) != "")
            {
              QPixmap litho(listLithoFileName.at(i));
              QRect lithoRect(listRectLitho.at(i));

              int nbrRect = lithoRect.height() / 50 + 1;
              lithoRect.setHeight(50);
              for(int j = 0; j < nbrRect; j++)
                {
                  lithoRect.setY(listRectLitho.at(i).y() + 50*j);
                  lithoRect.setHeight(50);
                  if(j == nbrRect - 1)
                    lithoRect.setHeight(listRectLitho.at(i).y() + listRectLitho.at(i).height() - lithoRect.y());
                  painter.drawPixmap(lithoRect,litho,source);
                }

            }

          QRect rectF(30,listRectZone.at(i).top(),deplacementXPos - 30, listRectZone.at(i).bottom());
          painter.setPen(QColor(255,0,0));
          painter.drawLine(0,listRectZone.at(i).top(),lithoXPos,listRectZone.at(i).top());

          painter.setPen(QColor(0,255,0));
          QRectF rectCote(lithoXPos - 50,listRectZone.at(i).bottom() - 20,50,20);
          painter.drawText(rectCote,QString::number(listCoteCoupe.at(i).at(1)));
          painter.drawLine(0,listRectZone.at(i).bottom(),lithoXPos,listRectZone.at(i).bottom());

          painter.setPen(QColor(0,0,0));
          painter.drawText(rectF,Qt::TextWordWrap, listTextCoupe.at(i));
        }
    }

  ///Rectangle pour deplacement vertical des zones
  QRect rectDeplacement(deplacementXPos,0,largeurDeplacement,this->height());
  painter.setBrush(QBrush(QColor(128,128,128,1)));
  painter.drawRect(rectDeplacement);

  painter.end();
}

void ForageCoupe::triCroissant()//Tri par ordre croissant les zones
{
  if(listRectZone.length() > 1)
    {
      QList<QRect> tmpListRect;
      QList<QList<double>> tmpListCote;
      QStringList tmpListText;
      int pos = 0;
      for(int i = 0; i < listRectZone.length(); i++)
        {
          pos = i;
          int y = listRectZone.at(i).y();
          for(int j = i; j < listRectZone.length(); j++)
            {
              int y2 = listRectZone.at(j).y();
              if(y > y2)
                {
                  y = y2;
                  pos = j;
                }

              if(j == listRectZone.length() - 1)
                {
                  QRect tmpRect = listRectZone.at(pos);
                  listRectZone.removeAt(pos);
                  listRectZone.prepend(tmpRect);
                  tmpListRect.append(tmpRect);

                  QList<double> tmpCoteCoupe = listCoteCoupe.at(pos);
                  listCoteCoupe.removeAt(pos);
                  listCoteCoupe.prepend(tmpCoteCoupe);
                  tmpListCote.append(tmpCoteCoupe);

                  QString tmpTextCoupe = listTextCoupe.at(pos);
                  listTextCoupe.removeAt(pos);
                  listTextCoupe.prepend(tmpTextCoupe);
                  tmpListText.append(tmpTextCoupe);
                }
            }
        }
      listRectZone = tmpListRect;
      listCoteCoupe = tmpListCote;
      listTextCoupe = tmpListText;
    }
}

void ForageCoupe::cliqueLeftBoutton(QMouseEvent *ev)
{
  QString textEdit("");
  double start = 0.00;
  double end = 0.00;

  ///Récupération des cotes pour affichage
  if(!listCoteCoupe.isEmpty())
    {
      start = listCoteCoupe.last().at(1) / 100;
      end = (100+listCoteCoupe.last().at(1)) / 100;
    }

  for(int i = 0; i < listRectZone.length(); i++)
    {
      if(listRectZone.at(i).contains(ev->x(),ev->y()))
        {
        start = listCoteCoupe[i][0] / 100;
        end = listCoteCoupe[i][1] / 100;
        textEdit = listTextCoupe.at(i);
        pos = i;
        }
    }

  bool isLithoZone = false;
  for(int i =0; i < listRectLitho.length(); i++)
    {
      if(listRectLitho.at(i).contains(ev->x(),ev->y()))
        {
          isLithoZone = true;
          pos = i;
        }
    }

  ///Ouverture dialogue pour choix de la litho
  if(isLithoZone)
    {
      listLithoFileName.replace(pos, QFileDialog::getOpenFileName(this, tr("Lithologie figuré"), QString(), tr("*.png")));
      QFile file(listLithoFileName.at(pos));
      if(!file.open(QIODevice::ReadOnly)){
          return;
      }
      update();
    }
  ///Création de la fenetre de renseignement de la coupe
  if(isRectZone)
    {
      isRectZone = false;
      w = new QWidget;
      w->setWindowFlags(Qt::FramelessWindowHint);
      w->setGeometry(ev->x(), ev->y()+200, 200, 200);
      t = new QTextEdit(w);
      t->setGeometry(10,10,180,100);
      t->setText(textEdit);
      debut = new QDoubleSpinBox(w);
      debut->setGeometry(10, 150, 50,30);
      debut->setFont(QFont("Arial",8));
      debut->setValue(start);
      fin= new QDoubleSpinBox(w);
      fin->setGeometry(70,150, 50 ,30);
      fin->setFont(QFont("Arial",8));
      fin->setValue(end);
      QPushButton *b = new QPushButton(w);
      b->setGeometry(130,120,60,60);
      b->setText("Valider");
      connect(b,SIGNAL(clicked(bool)),this,SLOT(valider()));
      w->show();
    }
}

void ForageCoupe::valider()
{
  ///Vérification des valeurs
  if(fin->value() - debut->value() < 0 && !longPress)
    return;

  ///Récupération des valeurs
  QList<double> list;
  list << debut->value() * 100 << fin->value() * 100; // *100 pour convertir en cm

  QRect rectZone;
  rectZone.setX(0);
  rectZone.setY(debut->value() * 100);
  rectZone.setWidth(lithoXPos-50);
  rectZone.setHeight((fin->value() * 100) - (debut->value() * 100));

  QRect rectLitho(lithoXPos,rectZone.y(),largeurLitho,rectZone.height());

  ///Verification de superposition
  bool superposition = false;

  ///Ajout de zone
  if(listCoteCoupe.length() <= pos)//condition d'ajout
    {
      listCoteCoupe << list;
      listTextCoupe << t->toPlainText();
      listRectZone << rectZone;
      listRectLitho << rectLitho;
      pos++;
      triCroissant();
      decBas = decHaut = false;
      updateZone();
    }
  else//condition de mise à jour
    {

      if(list.at(1) > listCoteCoupe.at(pos).at(1))
        {
          decBas = true;
          decHaut = false;
          if(pos < listCoteCoupe.length() - 1)
            {
              int ecart = listCoteCoupe.at(pos+1).at(0) - list.at(1);
              if(ecart < 0)
                {
                  superposition = true;
                }
            }
        }
      else if(list.at(0) < listCoteCoupe.at(pos).at(0))
        {
          decHaut = true;
          decBas = false;
          int ecart = list.at(0) - listCoteCoupe.at(pos-1).at(1);
          if(ecart < 0)
            {
              superposition = true;
            }
        }

      ///Mise à jour des cotes
      listCoteCoupe.replace(pos,list);
      ///Mise à jour des cotes des autres zones
      if(decBas && superposition)
        {
          for(int i = pos+1; i < listCoteCoupe.length(); i++)
            {
              list.replace(0,list.at(1));
              list.replace(1,listCoteCoupe.at(i).at(1));
              listCoteCoupe.replace(i,list);
            }
        }

      else if(decHaut && pos > 0 && superposition)
        {
          list.replace(1,list.at(0));
          list.replace(0,listCoteCoupe.at(pos-1).at(0));
          listCoteCoupe.replace(pos-1,list);
        }

      ///Mise à jour du texte et des zones
      listTextCoupe.replace(pos, t->toPlainText());
      listRectZone.replace(pos, rectZone);
      listRectLitho.replace(pos, rectLitho);

      ///Calcul des zones à mettre à jour
      updateZone();
    }
  if(!longPress)
    w->~QWidget();
  update();
}

void ForageCoupe::updateZone()
{
  for(int i = 0; i < listRectZone.length() - 1; i++)
    {
      int finZone = listRectZone.at(i).y() + listRectZone.at(i).height();
      int debutZone = listRectZone.at(i).y();

      int finZone2 = listRectZone.at(i+1).y() + listRectZone.at(i+1).height();
      int debutZone2 = listRectZone.at(i+1).y();

      if(finZone > debutZone2 && decBas && !decHaut) //Mise a jour et superposition vers le bas
        {
          //qDebug() << "insertion et superposition en dessous";
          //QRect newRectZone(0,finZone,this->width(),listRectZone.at(i+1).height());//Decalage vers le bas
          QRect newRectZone(0,finZone,this->width(),listRectZone.at(i+1).height() - (finZone - debutZone2));
          QRect newRectLitho(lithoXPos,newRectZone.y(),largeurLitho,newRectZone.height());
          if(finZone > finZone2)
            {
            rectHeightZero = true;
            posZeroHeight = i+1;
            }
          listRectZone.replace(i+1, newRectZone);
          listRectLitho.replace(i+1,newRectLitho);

        }

      else if(debutZone2 < finZone && decHaut && !decBas) //Mise a jour et superposition vers le haut
        {
          //qDebug() << "Update et superposition en dessus";
          QRect newRectZone(0,listRectZone.at(i).y(),this->width(),listRectZone.at(i).height() - (finZone - debutZone2));
          QRect newRectLitho(lithoXPos,newRectZone.y(),largeurLitho,newRectZone.height());
          listRectZone.replace(i, newRectZone);
          listRectLitho.replace(i,newRectLitho);
        }

      else if(finZone > debutZone2 /*&& debutZone < finZone2*/ && !decHaut && !decBas && i < listRectZone.length() - 2) //Lors de l'insertion avec superposition en dessus et en dessous
        {
          //qDebug() << "insertion et superposition en dessus et en dessous";
          QRect newRectZone(0,listRectZone.at(i).y(),this->width(),listRectZone.at(i).height() - (finZone - debutZone2));
          QRect newRectLitho(lithoXPos,newRectZone.y(),largeurLitho,newRectZone.height());
          listRectZone.replace(i, newRectZone);
          listRectLitho.replace(i,newRectLitho);
          QList<double> list;
          list << listRectZone.at(i).y() << debutZone2;
          listCoteCoupe.replace(i,list);

          int y = debutZone2 + listRectZone.at(i+1).height();
          newRectZone.setRect(0,y,this->width(),listRectZone.at(i+2).y()+listRectZone.at(i+2).height()-y);
          newRectLitho.setRect(lithoXPos,newRectZone.y(),largeurLitho,newRectZone.height());
          listRectZone.replace(i+2, newRectZone);
          listRectLitho.replace(i+2,newRectLitho);
          list.clear();
          list << y << listRectZone.at(i+2).y()+listRectZone.at(i+2).height();
          listCoteCoupe.replace(i+2,list);

          decHaut = decBas = true;
        }

      else if(finZone > debutZone2 && !decHaut && !decBas) //Lors de l'insertion avec superposition en dessus
        {
          //qDebug() << "insertion et superposition en dessus";
          QRect newRectZone(0,listRectZone.at(i).y(),this->width(),listRectZone.at(i).height() - (finZone - debutZone2));
          QRect newRectLitho(lithoXPos,newRectZone.y(),largeurLitho,newRectZone.height());
          listRectZone.replace(i, newRectZone);
          listRectLitho.replace(i,newRectLitho);
          QList<double> list;
          list << listRectZone.at(i).y() << debutZone2;
          listCoteCoupe.replace(i,list);
        }

      /*else if(debutZone > debutZone2 && !decHaut && !decBas)
        {
          qDebug() << "Zone haute";
        }*/
    }
  if(!longPress)
    pos = listCoteCoupe.length();
}

void ForageCoupe::setItemGeometry(int x, int y, int w, int h)
{
  deplacementXPos = w - largeurDeplacement;
  lithoXPos = deplacementXPos - largeurLitho;
}

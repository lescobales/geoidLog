#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::MainWindow)
{
  ui->setupUi(this);
  chantierTab = new QTabWidget(this);
  chantierTab->setVisible(false);


  connect(ui->actionImporter,SIGNAL(triggered(bool)),this,SLOT(onImpoterClicked()));
}

MainWindow::~MainWindow()
{
  delete ui;
}

void MainWindow::onImpoterClicked()
{
  QString filename = QFileDialog::getOpenFileName(this, tr("Import File"), QString(), tr("chantier.txt"));
  QFile file(filename);
  if(!file.open(QIODevice::ReadOnly)){
      return;
  }

  Import *im = new Import(chantierTab, forageTab, this);
  im->setGeometry(this->geometry());
  im->setFileName(filename);
  chantierTab->setVisible(false);
  im->show();
}

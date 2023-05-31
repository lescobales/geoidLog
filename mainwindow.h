#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QTabWidget>

#include "import.h"

namespace Ui {
  class MainWindow;
}

class MainWindow : public QMainWindow
{
  Q_OBJECT

public:
  explicit MainWindow(QWidget *parent = 0);
  ~MainWindow();

private:
  Ui::MainWindow *ui;
  QTabWidget *forageTab;
  QTabWidget *chantierTab;


public slots:
  void onImpoterClicked();
};

#endif // MAINWINDOW_H

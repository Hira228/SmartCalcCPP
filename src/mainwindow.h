#ifndef CPP3_S21_SMARTCALC_V2_S21_MAINWINDOW_H
#define CPP3_S21_SMARTCALC_V2_S21_MAINWINDOW_H

#include <QLineEdit>
#include <QMainWindow>
#include <QVector>

#include "Controller.h"
#include "creditcalc.h"
#include "graph.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  MainWindow(s21::Controller controller, QWidget *parent = nullptr);
  ~MainWindow();

 private slots:
  void on_pushButton_graph_clicked();

 private slots:
  void expandWindow();
  void CreditCalc();

 private slots:
  void add_lexems();
  void clearText();
  void calc_result();

 private:
  Ui::MainWindow *ui;
  QAction *expandCalculatorAction;
  QAction *creditCalculatorAction;
  QMenu *fileMenu;
  QLineEdit *inputXLineEdit;
  QLineEdit *inputXlineEdit_min;
  QLineEdit *inputXlineEdit_max;
  QLineEdit *inputYlineEdit_min;
  QLineEdit *inputYlineEdit_max;
  Graph *graph_ui;
  class CreditCalc *creditcalc_ui;
  s21::Controller controller_;

  double h, X;
  int N;

  QVector<double> x, y;
};

#endif  // CPP3_S21_SMARTCALC_V2_S21_MAINWINDOW_H

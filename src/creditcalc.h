#ifndef CPP3_S21_SMARTCALC_V2_S21_CREDITCALC_H
#define CPP3_S21_SMARTCALC_V2_S21_CREDITCALC_H

#include <QDialog>
#include <QPropertyAnimation>

#include "Controller.h"

namespace Ui {
class CreditCalc;
}

class CreditCalc : public QDialog {
  Q_OBJECT

 public:
  explicit CreditCalc(s21::Controller controller, QWidget *parent = nullptr);
  ~CreditCalc();

 private slots:
  void on_pushButton_2_clicked();

 private slots:
  void on_pushButton_1_clicked();

 private slots:
  void on_pushButton_3_clicked();

 private slots:
  void on_comboBox_currentIndexChanged(int index);

 private:
  Ui::CreditCalc *ui;

  double sum_credit;
  double interest_rate;
  double pay;
  int deadline;
  s21::Controller contr_;
};

#endif  // CPP3_S21_SMARTCALC_V2_S21_CREDITCALC_H

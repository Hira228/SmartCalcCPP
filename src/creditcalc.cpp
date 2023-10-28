#include "creditcalc.h"

#include <QDebug>
#include <QDoubleValidator>
#include <QPropertyAnimation>
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>

#include "ui_creditcalc.h"

CreditCalc::CreditCalc(s21::Controller controller, QWidget *parent)
    : contr_(controller), QDialog(parent), ui(new Ui::CreditCalc) {
  ui->setupUi(this);
  ui->lineEdit->setValidator(new QDoubleValidator(0, 1000000, 7, this));
  ui->lineEdit_2->setValidator(new QDoubleValidator(0, 10000000, 7, this));
  ui->lineEdit_6->setValidator(new QDoubleValidator(0, 10000000, 7, this));

  ui->lineEdit_8->setValidator(new QDoubleValidator(0, 1000000, 7, this));
  ui->lineEdit_5->setValidator(new QDoubleValidator(0, 10000000, 7, this));
  ui->lineEdit_7->setValidator(new QDoubleValidator(0, 10000000, 7, this));

  ui->lineEdit_11->setValidator(new QDoubleValidator(0, 1000000, 7, this));
  ui->lineEdit_10->setValidator(new QDoubleValidator(0, 10000000, 7, this));
  ui->lineEdit_9->setValidator(new QDoubleValidator(0, 10000000, 7, this));
}

CreditCalc::~CreditCalc() { delete ui; }

void CreditCalc::on_comboBox_currentIndexChanged(int index) {
  QPropertyAnimation *animation = new QPropertyAnimation(this, "geometry");
  if (index == 0) {
    ui->lineEdit->setText(0);
    ui->lineEdit_2->setText(0);
    ui->lineEdit_6->setText(0);
    ui->stackedWidget->setCurrentWidget(ui->page_1);
    if (height() == 550) {
      animation->setEndValue(QRect(geometry().x(), geometry().y(), 715, 350));
    }
    animation->setDuration(500);
    animation->setEasingCurve(QEasingCurve::InOutQuad);
  }
  if (index == 1) {
    ui->lineEdit_8->setText(0);
    ui->lineEdit_5->setText(0);
    ui->lineEdit_7->setText(0);
    ui->stackedWidget->setCurrentWidget(ui->page_2);
    if (height() == 550) {
      animation->setEndValue(QRect(geometry().x(), geometry().y(), 715, 350));
    }
    animation->setDuration(500);
    animation->setEasingCurve(QEasingCurve::InOutQuad);
  }
  if (index == 2) {
    ui->lineEdit_11->setText(0);
    ui->lineEdit_10->setText(0);
    ui->lineEdit_9->setText(0);
    ui->stackedWidget->setCurrentWidget(ui->page_3);
    if (height() == 550) {
      animation->setEndValue(QRect(geometry().x(), geometry().y(), 715, 350));
    }
    animation->setDuration(500);
    animation->setEasingCurve(QEasingCurve::InOutQuad);
  }
  animation->start(QAbstractAnimation::DeleteWhenStopped);
}

void CreditCalc::on_pushButton_3_clicked() {
  contr_.SetZero();
  int FLAG_ERROR = 0;
  int FLAG_ERROR_1 = 0;
  QString sum_credit_temp = NULL;
  QString percent_pay = NULL;
  QString percent_plus_credit = NULL;

  QString deadline_str = ui->lineEdit_11->text();
  contr_.SetDeadline(deadline_str.toInt());

  QString pay_str = ui->lineEdit_10->text();
  pay = pay_str.toDouble();
  contr_.SetPay(pay_str.toDouble());
  double pay_temp = contr_.GetPay();

  QString interest_rate_str = ui->lineEdit_9->text();
  interest_rate = interest_rate_str.toDouble();
  contr_.SetInterestRate(interest_rate_str.toDouble() / 12.0 / 100.0);

  if (contr_.GetInterestRate() < 0) {
    FLAG_ERROR_1 = 1;
  }

  if (ui->comboBox_2->currentIndex() == 0) {
    if (contr_.GetDeadline() > 50) FLAG_ERROR = 1;
    contr_.SetDeadline(contr_.GetDeadline() * 12);
  } else if (contr_.GetDeadline() > 600)
    FLAG_ERROR = 1;

  if (FLAG_ERROR == 0 && FLAG_ERROR_1 == 0) {
    contr_.SetSumCreditPlusSumPercent(pay_temp * contr_.GetDeadline());
    contr_.maxCredit();
    percent_pay = QString::number(contr_.GetSumPercent(), 'f', 2);
    sum_credit_temp = QString::number(contr_.GetSumCredit(), 'f', 2);
    percent_plus_credit =
    QString::number(contr_.GetSumCreditPlusSumPercent(), 'f', 2);

    ui->label_28->setText(percent_pay);
    ui->label_29->setText(sum_credit_temp);
    ui->label_30->setText(percent_plus_credit);

    QPropertyAnimation *animation = new QPropertyAnimation(this, "geometry");

    if (height() == 350) {
      animation->setEndValue(QRect(geometry().x(), geometry().y(), 715, 550));
    }
    animation->setDuration(500);
    animation->setEasingCurve(QEasingCurve::InOutQuad);

    animation->start(QAbstractAnimation::DeleteWhenStopped);
  }

  else if (FLAG_ERROR == 1) {
    if (ui->comboBox_2->currentIndex() == 0)
      ui->lineEdit_11->setText("Максимум 50");
    else
      ui->lineEdit_11->setText("Максимум 600");
  } else if (FLAG_ERROR_1 == 1) {
    ui->lineEdit_9->setText("Процентная ставка меньше 0");
  }
}

void CreditCalc::on_pushButton_1_clicked() {
  contr_.SetZero();
  int FLAG_ERROR = 0;
  int FLAG_ERROR_1 = 0;
  QString points = "...";
  QString mounth_pay = NULL;
  QString diff_pay_2_temp = NULL;
  QString percent_pay = NULL;
  QString percent_plus_credit = NULL;
  double sum_credit_plus_sum_percent = 0;
  QString sum_credit_str = ui->lineEdit->text();
  contr_.SetSumCredit(sum_credit_str.toInt());

  QString deadline_str = ui->lineEdit_2->text();
  contr_.SetDeadline(deadline_str.toInt());

  QString interest_rate_str = ui->lineEdit_6->text();
  contr_.SetInterestRate(interest_rate_str.toDouble() / 12.0 / 100.0);

  if (contr_.GetInterestRate() < 0) {
    FLAG_ERROR_1 = 1;
  }

  if (ui->comboBox_3->currentIndex() == 0) {
    if (contr_.GetDeadline() > 50) FLAG_ERROR = 1;
    contr_.SetDeadline(contr_.GetDeadline() * 12);
  } else if (contr_.GetDeadline() > 600)
    FLAG_ERROR = 1;

  QPropertyAnimation *animation = new QPropertyAnimation(this, "geometry");

  if (ui->radioButton->isChecked() && FLAG_ERROR == 0 && FLAG_ERROR_1 == 0) {
    contr_.anuitCredit();
    mounth_pay = QString::number(contr_.GetPay(), 'f', 2);
    percent_pay = QString::number(contr_.GetSumPercent(), 'f', 2);
    percent_plus_credit =
    QString::number(contr_.GetSumCreditPlusSumPercent(), 'f', 2);

    ui->label_36->setText(mounth_pay);
    ui->label_35->setText(percent_pay);
    ui->label_34->setText(percent_plus_credit);

    if (height() == 350) {
      animation->setEndValue(QRect(geometry().x(), geometry().y(), 715, 550));
    }
    animation->setDuration(500);
    animation->setEasingCurve(QEasingCurve::InOutQuad);

    animation->start(QAbstractAnimation::DeleteWhenStopped);
  } else if (ui->radioButton_2->isChecked() && FLAG_ERROR == 0 &&
             FLAG_ERROR_1 == 0) {
    contr_.diffCredit();

    mounth_pay = QString::number(contr_.GetDiffPay_1(), 'f', 2);
    diff_pay_2_temp = QString::number(contr_.GetDiffPay_2(), 'f', 2);
    mounth_pay += points;
    mounth_pay += diff_pay_2_temp;
    percent_pay = QString::number(contr_.GetSumPercent(), 'f', 2);
    percent_plus_credit =
        QString::number(contr_.GetSumCreditPlusSumPercent(), 'f', 2);

    ui->label_36->setText(mounth_pay);
    ui->label_35->setText(percent_pay);
    ui->label_34->setText(percent_plus_credit);

    if (height() == 350) {
      animation->setEndValue(QRect(geometry().x(), geometry().y(), 715, 550));
    }
    animation->setDuration(500);
    animation->setEasingCurve(QEasingCurve::InOutQuad);

    animation->start(QAbstractAnimation::DeleteWhenStopped);
  } else if (FLAG_ERROR == 1) {
    if (ui->comboBox_3->currentIndex() == 0)
      ui->lineEdit_2->setText("Максимум 50");
    else
      ui->lineEdit_2->setText("Максимум 600");
  } else {
    ui->lineEdit_6->setText("Процентная ставка меньше 0");
  }
}

void CreditCalc::on_pushButton_2_clicked() {
  contr_.SetZero();
  int FLAG_ERROR_1 = 0;

  QString deadline_temp = NULL;
  QString sum_percent_pay = NULL;
  QString percent_plus_credit = NULL;
  QString ERROR = "Минимальный платеж: ";
  deadline = 0;

  double sum_credit_temp = 0;
  double sum_percent = 0;
  double sum_credit_plus_sum_percent = 0;

  QString sum_credit_str = ui->lineEdit_8->text();
  contr_.SetSumCredit(sum_credit_str.toInt());

  contr_.SetSumCreditTempNone(contr_.GetSumCredit());

  QString pay_str = ui->lineEdit_5->text();
  contr_.SetPay(pay_str.toInt());

  QString interest_rate_str = ui->lineEdit_7->text();
  contr_.SetInterestRate(interest_rate_str.toDouble() / 12.0 / 100.0);

  if (contr_.GetInterestRate() < 0) {
    FLAG_ERROR_1 = 1;
  }

  int minimum_pay = (contr_.GetSumCredit() * contr_.GetInterestRate()) + 0.5;
  QString minimum_pay_str = QString::number(minimum_pay);
  minimum_pay_str = ERROR + minimum_pay_str;

  if (contr_.GetSumCredit() * contr_.GetInterestRate() < contr_.GetPay() &&
      FLAG_ERROR_1 == 0) {
    contr_.creditTerm();
    deadline_temp = QString::number(contr_.GetDeadline());
    sum_percent_pay = QString::number(contr_.GetSumPercent(), 'f', 2);
    percent_plus_credit =
        QString::number(contr_.GetSumCreditPlusSumPercent(), 'f', 2);

    ui->label_33->setText(deadline_temp);
    ui->label_32->setText(sum_percent_pay);
    ui->label_31->setText(percent_plus_credit);

    QPropertyAnimation *animation = new QPropertyAnimation(this, "geometry");
    if (height() == 350) {
      animation->setEndValue(QRect(geometry().x(), geometry().y(), 715, 550));
    }
    animation->setDuration(500);
    animation->setEasingCurve(QEasingCurve::InOutQuad);

    animation->start(QAbstractAnimation::DeleteWhenStopped);
  } else if (contr_.GetSumCredit() * contr_.GetInterestRate() >
             contr_.GetPay()) {
    ui->lineEdit_5->setText(minimum_pay_str);
  } else {
    ui->lineEdit_7->setText("Процентная ставка меньше 0");
  }
}

#ifndef CPP3_S21_SMARTCALC_V2_S21_CONTROLLER_H
#define CPP3_S21_SMARTCALC_V2_S21_CONTROLLER_H

#include "Model.h"

namespace s21 {

class Controller {
 private:
  Model *model;

 public:
  Controller(Model *m) : model(m){};
  std::string equal(const std::string math_expression);
  std::string convertWithX(const std::string math_expression, double X) {
    return model->strWithGraph(math_expression, X);
  }
  int checkXStr(const std::string math_expression) {
    return model->checkXStr(math_expression);
  }
  void maxCredit() { model->maxSumCredit(); }
  void diffCredit() { model->countDeadline(); }
  void anuitCredit() { model->annuityCredit(); }
  void creditTerm() { model->creditPeriod(); }

  // setters
  void SetDeadline(int a) { model->SetDeadline(a); }
  void SetSumPercent(double a) { model->SetSumPercent(a); }
  void SetPay(double a) { model->SetPay(a); }
  void SetSumCredit(double a) { model->SetSumCredit(a); }
  void SetInterestRate(double a) { model->SetInterestRate(a); }
  void SetSumCreditPlusSumPercent(double a) {
    model->SetSumCreditPlusSumPercent(a);
  }
  void SetDiffPay_1(double a) { model->SetDiffPay_1(a); }
  void SetDiffPay_2(double a) { model->SetDiffPay_2(a); }
  void SetSumCreditTemp(double a) { model->SetSumCreditTemp(a); }
  void SetSumCreditTempNone(double a) { model->SetSumCreditTempNone(a); }
  void SetZero();

  // getters
  int GetDeadline() { return model->GetDeadline(); }
  double GetSumPercent() { return model->GetSumPercent(); }
  double GetPay() { return model->GetPay(); };
  double GetSumCredit() { return model->GetSumCredit(); }
  double GetInterestRate() { return model->GetInterestRate(); }
  double GetSumCreditPlusSumPercent() {
    return model->GetSumCreditPlusSumPercent();
  }
  double GetDiffPay_1() { return model->GetDiffPay_1(); }
  double GetDiffPay_2() { return model->GetDiffPay_2(); }
  double GetSumCreditTemp() { return model->GetSumCreditTemp(); }
  double GetSumCreditTempNone() { return model->GetSumCreditTempNone(); }
};

}  // namespace s21

#endif  // CPP3_S21_SMARTCALC_V2_S21_CONTROLLER_H

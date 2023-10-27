#include "Controller.h"

namespace s21 {
std::string Controller::equal(const std::string math_expression) {
  model->model(math_expression);
  return model->getData();
}

void Controller::SetZero() {
  SetDeadline(0);
  SetSumPercent(0);
  SetPay(0);
  SetSumCredit(0);
  SetInterestRate(0);
  SetSumCreditPlusSumPercent(0);
  SetDiffPay_1(0);
  SetDiffPay_2(0);
  SetSumCreditTemp(0);
  SetSumCreditTempNone(0);
}
}  // namespace s21

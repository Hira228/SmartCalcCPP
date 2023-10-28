#ifndef CPP3_S21_SMARTCALC_V2_S21_MODEL_H_
#define CPP3_S21_SMARTCALC_V2_S21_MODEL_H_
#include <cmath>
#include <iostream>
#include <stack>
#include <vector>

enum type {
  NUMBER = 2,
  PLUS = 3,
  MINUS = 4,
  PRNTS_OPEN = 5,
  PRNTS_CLOSE = 6,
  MULTI = 7,
  DIV = 8,
  POW = 9,
  SIN = 10,
  COS = 11,
  MOD = 12,
  SQRT = 13,
  TAN = 14,
  LN = 15,
  LOG = 16,
  ASIN = 17,
  ACOS = 18,
  ATAN = 19,
  UNARY_MINUS = 20,
  UNARY_PRNTS = 21,
};

struct Data {
  double value;
  int type;
  int priority;
};

namespace s21 {
class parsing {
 public:
  parsing() {}
  ~parsing() {}

 protected:
  void newParsingStr(const std::string &Str) noexcept;
  void lexemParsing();
  int elementDefinition(char c, int &i);
  int checkCosFunction(int &i);
  int checkTanFunction(int &i);
  int checkModFunction(int &i);
  int checkSFunctions(int &i);
  int checkLogFunctions(int &i);
  int checkAFunctions(int &i);
  void numberEntry(std::string &number_str, int &i);
  void reverseStack() noexcept;
  std::string newStrParsing;
  std::stack<Data> stack_lexems;
};

class Model : public parsing {
 public:
  Model() : parsing() {}
  ~Model() {}
  std::string getData() { return answer; }
  void model(const std::string math_expression);
  std::string strWithGraph(const std::string str_with_x, double x);
  int checkXStr(const std::string str);
  void maxSumCredit();
  void countDeadline();
  void annuityCredit();
  void creditPeriod();
  std::pair<std::vector<double>, std::vector<double>> createGraph(
      double xValue_begin, double xValue_end, std::string math_exp_str);
  void clearDataGraph() {
    x.clear();
    y.clear();
  }

  // setters
  void SetDeadline(int a) { deadline = a; }
  void SetSumPercent(double a) { sum_percent = a; }
  void SetPay(double a) { pay = a; }
  void SetSumCredit(double a) { sum_credit = a; }
  void SetInterestRate(double a) { interest_rate = a; }
  void SetSumCreditPlusSumPercent(double a) { sum_credit_plus_sum_percent = a; }
  void SetDiffPay_1(double a) { diff_pay_1 = a; }
  void SetDiffPay_2(double a) { diff_pay_2 = a; }
  void SetSumCreditTemp(double a) { sum_credit_temp = a; }
  void SetSumCreditTempNone(double a) { sum_credit_temp_none = a; }

  // getters
  int GetDeadline() { return deadline; }
  double GetSumPercent() { return sum_percent; }
  double GetPay() { return pay; };
  double GetSumCredit() { return sum_credit; }
  double GetInterestRate() { return interest_rate; }
  double GetSumCreditPlusSumPercent() { return sum_credit_plus_sum_percent; }
  double GetDiffPay_1() { return diff_pay_1; }
  double GetDiffPay_2() { return diff_pay_2; }
  double GetSumCreditTemp() { return sum_credit_temp; }
  double GetSumCreditTempNone() { return sum_credit_temp_none; }

 private:
  void reversePolishNotaton();
  int checkUnaryMinus() noexcept;
  void reverseStack() noexcept;
  void calculate();
  void clearStack(std::stack<Data> &s);
  std::stack<Data> reverse_polish_notation;
  std::stack<Data> stack_calculate;
  std::string answer;
  std::vector<double> x;
  std::vector<double> y;
  int deadline;
  double sum_percent;
  double pay;
  double sum_credit;
  double interest_rate;
  double sum_credit_plus_sum_percent;
  double diff_pay_1;
  double diff_pay_2;
  double sum_credit_temp;
  double sum_credit_temp_none;
};
}  // namespace s21

#endif  // CPP3_S21_SMARTCALC_V2_S21_MODEL_H_

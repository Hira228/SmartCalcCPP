#include "Model.h"

namespace s21 {
void parsing::newParsingStr(const std::string &Str) noexcept {
  std::string str_temp;
  for (size_t i = 0; i < Str.length(); i++) {
    if (Str[i] == ' ') {
      continue;
    }
    str_temp.push_back(Str[i]);
  }
  for (size_t i = 0; i < str_temp.length(); i++) {
    if ((str_temp[i] >= '0' && str_temp[i] <= '9') && str_temp[i + 1] == '(') {
      newStrParsing.push_back(str_temp[i]);
      newStrParsing.push_back('*');
    } else if ((str_temp[i] >= '0' && str_temp[i] <= '9') &&
               str_temp[i + 1] == 'x') {
      newStrParsing.push_back(str_temp[i]);
      newStrParsing.push_back('*');
    } else if (str_temp[i] == ')' &&
               (str_temp[i + 1] >= '0' && str_temp[i + 1] <= '9')) {
      newStrParsing.push_back(str_temp[i]);
      newStrParsing.push_back('*');
    } else if (str_temp[i] == ')' && str_temp[i + 1] == '(') {
      newStrParsing.push_back(str_temp[i]);
      newStrParsing.push_back('*');
    } else if ((str_temp[i] >= '0' && str_temp[i] <= '9') &&
               (str_temp[i + 1] == 's' || str_temp[i + 1] == 'c' ||
                str_temp[i + 1] == 't' || str_temp[i + 1] == 'a' ||
                str_temp[i + 1] == 'l')) {
      newStrParsing.push_back(str_temp[i]);
      newStrParsing.push_back('*');
    } else if ((str_temp[i] == '/' || str_temp[i] == '^' ||
                str_temp[i] == '-' || str_temp[i] == '*') &&
               str_temp[i + 1] == '+') {
      newStrParsing.push_back(str_temp[i]);
      i++;
    } else if (str_temp[0] == '+' && i == 0) {
      newStrParsing.push_back('0');
      newStrParsing.push_back(str_temp[i]);
    } else if (str_temp[i] == '(' && str_temp[i + 1] == '+') {
      newStrParsing.push_back(str_temp[i]);
      i++;
    } else if (str_temp[0] == '-' && i == 0) {
      newStrParsing.push_back('0');
      newStrParsing.push_back(str_temp[i]);
    } else if (str_temp[i] == '(' && str_temp[i + 1] == '-') {
      newStrParsing.push_back(str_temp[i]);
      newStrParsing.push_back('0');
    } else
      newStrParsing.push_back(str_temp[i]);
  }
}

void s21::parsing::lexemParsing() {
  int i = 0;
  std::string number_str;
  if (newStrParsing[0] == '\0') throw std::string{"Empty expression"};

  while (newStrParsing[i] != '\0') {
    switch (elementDefinition(newStrParsing[i], i)) {
      case NUMBER:
        numberEntry(number_str, i);
        stack_lexems.push({std::stod(number_str), NUMBER, 0});
        number_str.clear();
        break;

      case PRNTS_OPEN:
        stack_lexems.push({0, PRNTS_OPEN, 4});
        break;

      case PRNTS_CLOSE:
        stack_lexems.push({0, PRNTS_CLOSE, 4});
        break;

      case PLUS:
        stack_lexems.push({0, PLUS, 1});
        break;

      case MINUS:
        stack_lexems.push({0, MINUS, 1});
        break;

      case MULTI:
        stack_lexems.push({0, MULTI, 2});
        break;

      case DIV:
        stack_lexems.push({0, DIV, 2});
        break;

      case MOD:
        stack_lexems.push({0, MOD, 2});
        break;

      case POW:
        stack_lexems.push({0, POW, 3});
        break;

      case SIN:
        stack_lexems.push({0, SIN, 4});
        break;

      case SQRT:
        stack_lexems.push({0, SQRT, 4});
        break;

      case COS:
        stack_lexems.push({0, COS, 4});
        break;

      case TAN:
        stack_lexems.push({0, TAN, 4});
        break;

      case LN:
        stack_lexems.push({0, LN, 4});
        break;

      case LOG:
        stack_lexems.push({0, LOG, 4});
        break;

      case ASIN:
        stack_lexems.push({0, ASIN, 4});
        break;

      case ACOS:
        stack_lexems.push({0, ACOS, 4});
        break;

      case ATAN:
        stack_lexems.push({0, ATAN, 4});
        break;

      default:
        break;
    }
    i++;
  }
  reverseStack();
}

int parsing::elementDefinition(char c, int &i) {
  if (c >= '0' && c <= '9') return NUMBER;

  if (c == '+') return PLUS;

  if (c == '-') return MINUS;

  if (c == '(') return PRNTS_OPEN;

  if (c == ')') return PRNTS_CLOSE;

  if (c == '*') return MULTI;

  if (c == '/') return DIV;

  if (c == '^') return POW;

  if (c == 'm') return checkModFunction(i);

  if (c == 's') return checkSFunctions(i);

  if (c == 'c') return checkCosFunction(i);

  if (c == 't') return checkTanFunction(i);

  if (c == 'l') return checkLogFunctions(i);

  if (c == 'a') return checkAFunctions(i);

  throw std::string{"Expression error(parsing)"};
}

int parsing::checkCosFunction(int &i) {
  if (newStrParsing[i + 1] == 'o' && newStrParsing[i + 2] == 's') {
    i += 2;
    return COS;
  }

  throw std::string{"Expression error(parsing)"};
}

int parsing::checkTanFunction(int &i) {
  if (newStrParsing[i + 1] == 'a' && newStrParsing[i + 2] == 'n') {
    i += 2;
    return TAN;
  }

  throw std::string{"Expression error(parsing)"};
}

int parsing::checkModFunction(int &i) {
  if (newStrParsing[i + 1] == 'o' && newStrParsing[i + 2] == 'd') {
    i += 2;
    return MOD;
  }

  throw std::string{"Expression error(parsing)"};
}

int parsing::checkSFunctions(int &i) {
  if (newStrParsing[i + 1] == 'i' && newStrParsing[i + 2] == 'n') {
    i += 2;
    return SIN;
  }
  if (newStrParsing[i + 1] == 'q' && newStrParsing[i + 2] == 'r' &&
      newStrParsing[i + 3] == 't') {
    i += 3;
    return SQRT;
  }

  throw std::string{"Expression error(parsing)"};
}

int parsing::checkLogFunctions(int &i) {
  if (newStrParsing[i + 1] == 'n') {
    i += 1;
    return LN;
  }
  if (newStrParsing[i + 1] == 'o' && newStrParsing[i + 2] == 'g') {
    i += 2;
    return LOG;
  }

  throw std::string{"Expression error(parsing)"};
}

int parsing::checkAFunctions(int &i) {
  if (newStrParsing[i + 1] == 'c') {
    ++i;
    if (checkCosFunction(i) == COS) return ACOS;
  }

  if (newStrParsing[i + 1] == 's') {
    ++i;
    if (checkSFunctions(i) == SIN) return ASIN;
  }

  if (newStrParsing[i + 1] == 't') {
    ++i;
    if (checkTanFunction(i) == TAN) return ATAN;
  }
  throw std::string{"Expression error(parsing)"};
}

void parsing::numberEntry(std::string &number_str, int &i) {
  while ((newStrParsing[i] >= '0' && newStrParsing[i] <= '9') ||
         newStrParsing[i] == '.') {
    if (newStrParsing[i] == '.') {
      if (!(newStrParsing[i + 1] >= '0' && newStrParsing[i + 1] <= '9'))
        throw std::string{"Expression error(parsing)"};
    }
    number_str.push_back(newStrParsing[i]);
    i++;
  }
  i--;
}

void parsing::reverseStack() noexcept {
  std::stack<Data> temp_;
  while (!stack_lexems.empty()) {
    temp_.push(stack_lexems.top());
    stack_lexems.pop();
  }
  stack_lexems = temp_;
}

void Model::reversePolishNotaton() {
  int flag_unary = 1;
  std::stack<Data> stack_operator_;
  while (!stack_lexems.empty()) {
    if (flag_unary == UNARY_MINUS) {
      stack_lexems.pop();
    }
    if (stack_lexems.top().type == NUMBER) {
      reverse_polish_notation.push(
          {(flag_unary == UNARY_MINUS ? (stack_lexems.top().value) * (-1)
                                      : (stack_lexems.top().value)),
           stack_lexems.top().type, stack_lexems.top().priority});
      if (flag_unary == UNARY_MINUS) flag_unary = 1;
    }

    else if (stack_lexems.top().type != NUMBER &&
             stack_lexems.top().type != PRNTS_OPEN &&
             stack_lexems.top().type != PRNTS_CLOSE) {
      while (!stack_operator_.empty() &&
             stack_operator_.top().priority >= stack_lexems.top().priority &&
             stack_operator_.top().type != PRNTS_OPEN) {
        reverse_polish_notation.push({stack_operator_.top().value,
                                      stack_operator_.top().type,
                                      stack_operator_.top().priority});
        stack_operator_.pop();
      }
      stack_operator_.push({stack_lexems.top().value, stack_lexems.top().type,
                            stack_lexems.top().priority});

      flag_unary = checkUnaryMinus();
      if (flag_unary == UNARY_PRNTS) {
        stack_operator_.pop();
        flag_unary = 1;
      }
    }

    else if (stack_lexems.top().type == PRNTS_OPEN) {
      stack_operator_.push({stack_lexems.top().value, stack_lexems.top().type,
                            stack_lexems.top().priority});
    }

    else if (stack_lexems.top().type == PRNTS_CLOSE) {
      while (!stack_operator_.empty() &&
             stack_operator_.top().type != PRNTS_OPEN) {
        reverse_polish_notation.push({stack_operator_.top().value,
                                      stack_operator_.top().type,
                                      stack_operator_.top().priority});
        stack_operator_.pop();
      }
      if (!stack_operator_.empty() &&
          stack_operator_.top().type == PRNTS_OPEN) {
        stack_operator_.pop();
      } else {
        throw std::string{"Expression error(parsing)"};
      }
    }
    stack_lexems.pop();
  }
  while (!stack_operator_.empty()) {
    if (stack_operator_.top().type == PRNTS_OPEN) {
      throw std::string{"Expression error()"};
    }
    reverse_polish_notation.push({stack_operator_.top().value,
                                  stack_operator_.top().type,
                                  stack_operator_.top().priority});
    stack_operator_.pop();
  }
  reverseStack();
}

int Model::checkUnaryMinus() noexcept {
  std::stack<Data> temp;
  std::stack<Data> stack_lexems_temp_ = stack_lexems;
  if (!stack_lexems_temp_.empty()) {
    stack_lexems_temp_.pop();
    temp = stack_lexems_temp_;
  }
  if (!temp.empty() && temp.top().type == MINUS) {
    temp.pop();
    std::stack<Data> next_elem = temp;
    if (next_elem.top().type == NUMBER && !next_elem.empty())
      return UNARY_MINUS;
    else if (next_elem.top().type == PRNTS_OPEN && !next_elem.empty())
      return UNARY_PRNTS;
  }
  return 1;
}

void Model::reverseStack() noexcept {
  std::stack<Data> temp_;
  while (!reverse_polish_notation.empty()) {
    temp_.push(reverse_polish_notation.top());
    reverse_polish_notation.pop();
  }
  reverse_polish_notation = temp_;
}

void Model::calculate() {
  while (!reverse_polish_notation.empty()) {
    if (reverse_polish_notation.top().type == NUMBER)
      stack_calculate.push({reverse_polish_notation.top().value,
                            reverse_polish_notation.top().type,
                            reverse_polish_notation.top().priority});
    else {
      double a = 0;
      double b = 0;
      if (!stack_calculate.empty()) {
        a = stack_calculate.top().value;
        stack_calculate.pop();
      } else
        throw std::string{"Calculating error()"};
      switch (reverse_polish_notation.top().type) {
        case PLUS:
          if (stack_calculate.empty())
            throw std::string{"Calculating error()"};
          else {
            b = stack_calculate.top().value;
            stack_calculate.pop();
            stack_calculate.push({a + b, NUMBER, 0});
          }
          break;

        case MINUS:
          if (stack_calculate.empty())
            throw std::string{"Calculating error()"};
          else {
            b = stack_calculate.top().value;
            stack_calculate.pop();
            stack_calculate.push({b - a, NUMBER, 0});
          }
          break;

        case MULTI:
          if (stack_calculate.empty())
            throw std::string{"Calculating error()"};
          else {
            b = stack_calculate.top().value;
            stack_calculate.pop();
            stack_calculate.push({a * b, NUMBER, 0});
          }
          break;

        case DIV:
          if (stack_calculate.empty() || a == 0.0f)
            throw std::string{"Calculating error()"};
          else {
            b = stack_calculate.top().value;
            stack_calculate.pop();
            stack_calculate.push({b / a, NUMBER, 0});
          }
          break;

        case POW:
          if (stack_calculate.empty())
            throw std::string{"Calculating error()"};
          else {
            b = stack_calculate.top().value;
            stack_calculate.pop();
            stack_calculate.push({std::pow(b, a), NUMBER, 0});
          }
          break;

        case MOD:
          if (stack_calculate.empty())
            throw std::string{"Calculating error()"};
          else {
            b = stack_calculate.top().value;
            stack_calculate.pop();
            stack_calculate.push({std::fmod(b, a), NUMBER, 0});
          }
          break;

        case SIN:
          if (std::fabs(std::sin(a) - (-0.0f)) < 1e-6) {
            stack_calculate.push({0.0f, NUMBER, 0});
          } else
            stack_calculate.push({std::sin(a), NUMBER, 0});

          break;

        case COS:
          if (std::fabs(std::cos(a) - (-0.0f)) < 1e-6) {
            stack_calculate.push({0.0f, NUMBER, 0});
          } else
            stack_calculate.push({std::cos(a), NUMBER, 0});
          break;
        case SQRT:
          if (a >= 0.0f)
            stack_calculate.push({std::sqrt(a), NUMBER, 0});
          else
            throw std::string{"Calculating error()"};
          break;

        case TAN:
          if (fabs(tan(a) - (-0.0f)) < 1e-6) {
            stack_calculate.push({0.0f, NUMBER, 0});
          } else
            stack_calculate.push({std::tan(a), NUMBER, 0});
          break;

        case LN:
          if (a > 0.0f)
            stack_calculate.push({std::log(a), NUMBER, 0});
          else
            throw std::string{"Calculating error()"};
          break;

        case LOG:
          if (a > 0.0f)
            stack_calculate.push({std::log10(a), NUMBER, 0});
          else
            throw std::string{"Calculating error()"};
          break;

        case ASIN:
          stack_calculate.push({std::asin(a), NUMBER, 0});
          break;

        case ACOS:
          stack_calculate.push({std::acos(a), NUMBER, 0});
          break;

        case ATAN:
          stack_calculate.push({std::atan(a), NUMBER, 0});
          break;

        default:
          break;
      }
    }
    reverse_polish_notation.pop();
  }
}

void Model::model(const std::string math_expression) {
  bool flag_d = 0;
  try {
    newParsingStr(math_expression);
    lexemParsing();
    reversePolishNotaton();
    calculate();
  } catch (std::string error) {
    answer = error;
    flag_d = 1;
  }
  if (flag_d == 0) answer = std::to_string(stack_calculate.top().value);
  clearStack(reverse_polish_notation);
  clearStack(stack_calculate);
  clearStack(stack_lexems);
  newStrParsing.clear();
}

std::string Model::strWithGraph(const std::string str_with_x, double x) {
  std::string new_str;
  char val[256] = {0};
  sprintf(val, "%.7lf", x);
  for (size_t i = 0; i < str_with_x.length(); i++) {
    if (str_with_x[i] == 'x') {
      new_str.push_back('(');
      for (int j = 0; val[j] != '\0'; j++) {
        new_str.push_back(val[j]);
      }
      new_str.push_back(')');
    } else {
      new_str.push_back(str_with_x[i]);
    }
  }
  return new_str;
}

int Model::checkXStr(const std::string str) {
  for (int i = 0; str.length(); i++) {
    if (str[i] == 'x') {
      return 1;
    }
  }
  return 0;
}

void Model::clearStack(std::stack<Data> &s) {
  while (!s.empty()) {
    s.pop();
  }
}

void Model::maxSumCredit() {
  while (deadline != 0) {
    sum_percent = pay * interest_rate;
    pay -= sum_percent;
    sum_credit += pay;
    deadline--;
  }
  sum_percent = sum_credit_plus_sum_percent - sum_credit;
}

void Model::countDeadline() {
  for (int i = 0; i <= deadline; i++) {
    pay = sum_credit / deadline +
          (sum_credit - (i - 1) * (sum_credit / deadline)) * interest_rate;
    sum_percent += pay;
    if (i == 0) diff_pay_1 = pay;
  }
  diff_pay_2 = pay;
  sum_credit_plus_sum_percent = sum_percent;
  sum_percent -= sum_credit;
}

void Model::annuityCredit() {
  pay = (sum_credit * interest_rate) / (1 - pow(1 + interest_rate, -deadline));
  sum_percent = pay * deadline - sum_credit;
  sum_credit_plus_sum_percent = sum_credit + sum_percent;
}

void Model::creditPeriod() {
  while (sum_credit >= 0) {
    sum_credit_temp = sum_credit;
    sum_credit *= (interest_rate + 1);
    sum_percent += (sum_credit - sum_credit_temp);
    sum_credit -= pay;
    deadline++;
  }
  sum_credit_plus_sum_percent = sum_percent + sum_credit_temp_none;
}

std::pair<std::vector<double>, std::vector<double>> Model::createGraph(double xValue_begin, double xValue_end, std::string math_exp_str) {
  std::string temp_str;
  std::string result;
  double yValue;

  for (double X = xValue_begin; X <= xValue_end; X += 0.1) {
    temp_str = strWithGraph(math_exp_str, X);
    model(temp_str);
    result = getData();
    if (result[0] != 'C') {
      yValue =std::stod(result);
      x.push_back(X);
      y.push_back(yValue);
    } else {
      x.push_back(X);
      y.push_back(std::numeric_limits<double>::quiet_NaN());
    }
  }
  return std::make_pair(x, y);
}


}  // namespace s21

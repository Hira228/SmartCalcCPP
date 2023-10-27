#include "s21_smart_calc_tests.h"

namespace s21 {
TEST(test_unary_minus, test_unary_minus_one) {
  Model a;
  Controller b(&a);
  std::string answer = "1.000000";
  const std::string math_exp = "- 2 + 3";
  b.equal(math_exp);
  std::string result = b.equal(math_exp);
  EXPECT_TRUE(answer == result);
}

TEST(test_unary_minus, test_unary_minus_two) {
  Model a;
  Controller b(&a);
  std::string answer = "-1.000000";
  const std::string math_exp = "2 + (3 / -1)";
  b.equal(math_exp);
  std::string result = b.equal(math_exp);
  EXPECT_TRUE(answer == result);
}
}  // namespace s21
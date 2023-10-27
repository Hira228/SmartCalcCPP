#include "s21_smart_calc_tests.h"

namespace s21 {
TEST(test_sqrt, test_sqrt_one) {
  Model a;
  Controller b(&a);
  std::string answer = "1.414214";
  const std::string math_exp = "sqrt2";
  b.equal(math_exp);
  std::string result = b.equal(math_exp);
  EXPECT_TRUE(answer == result);
}

TEST(test_sqrt, test_sqrt_two) {
  Model a;
  Controller b(&a);
  std::string answer = "1.000000";
  const std::string math_exp = "sqrt1";
  b.equal(math_exp);
  std::string result = b.equal(math_exp);
  EXPECT_TRUE(answer == result);
}
}  // namespace s21

#include "s21_smart_calc_tests.h"

namespace s21 {
TEST(test_cos, test_cos_one) {
  Model a;
  Controller b(&a);
  std::string answer = "-1.000000";
  const std::string math_exp = "cos3.1415";
  b.equal(math_exp);
  std::string result = b.equal(math_exp);
  EXPECT_TRUE(answer == result);
}

TEST(test_cos, test_cos_two) {
  Model a;
  Controller b(&a);
  std::string answer = "0.000000";
  const std::string math_exp = "cos(3.1415927/2)";
  b.equal(math_exp);
  std::string result = b.equal(math_exp);
  EXPECT_TRUE(answer == result);
}
}  // namespace s21
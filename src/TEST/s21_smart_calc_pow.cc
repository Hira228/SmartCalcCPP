#include "s21_smart_calc_tests.h"

namespace s21 {
TEST(test_pow, test_pow_one) {
  Model a;
  Controller b(&a);
  std::string answer = "16.000000";
  const std::string math_exp = "4 ^ 2";
  b.equal(math_exp);
  std::string result = b.equal(math_exp);
  EXPECT_TRUE(answer == result);
}

TEST(test_pow, test_pow_two) {
  Model a;
  Controller b(&a);
  std::string answer = "1.000000";
  const std::string math_exp = "1 ^ 2";
  b.equal(math_exp);
  std::string result = b.equal(math_exp);
  EXPECT_TRUE(answer == result);
}
}  // namespace s21

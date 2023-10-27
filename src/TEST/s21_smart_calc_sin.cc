#include "s21_smart_calc_tests.h"

namespace s21 {
TEST(test_sin, test_sin_one) {
  Model a;
  Controller b(&a);
  std::string answer = "0.841471";
  const std::string math_exp = "sin1";
  b.equal(math_exp);
  std::string result = b.equal(math_exp);
  EXPECT_TRUE(answer == result);
}

TEST(test_sin, test_sin_two) {
  Model a;
  Controller b(&a);
  std::string answer = "0.000000";
  const std::string math_exp = "sin3.1415927";
  b.equal(math_exp);
  std::string result = b.equal(math_exp);
  EXPECT_TRUE(answer == result);
}
}  // namespace s21

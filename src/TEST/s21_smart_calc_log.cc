#include "s21_smart_calc_tests.h"

namespace s21 {
TEST(test_log, test_log_one) {
  Model a;
  Controller b(&a);
  std::string answer = "1.000000";
  const std::string math_exp = "log10";
  b.equal(math_exp);
  std::string result = b.equal(math_exp);
  EXPECT_TRUE(answer == result);
}

TEST(test_log, test_log_two) {
  Model a;
  Controller b(&a);
  std::string answer = "1.230449";
  const std::string math_exp = "log17";
  b.equal(math_exp);
  std::string result = b.equal(math_exp);
  EXPECT_TRUE(answer == result);
}
}  // namespace s21

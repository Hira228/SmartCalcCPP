#include "s21_smart_calc_tests.h"

namespace s21 {
TEST(test_ln, test_ln_one) {
  Model a;
  Controller b(&a);
  std::string answer = "0.000000";
  const std::string math_exp = "ln1";
  b.equal(math_exp);
  std::string result = b.equal(math_exp);
  EXPECT_TRUE(answer == result);
}

TEST(test_ln, test_ln_two) {
  Model a;
  Controller b(&a);
  std::string answer = "0.693147";
  const std::string math_exp = "ln2";
  b.equal(math_exp);
  std::string result = b.equal(math_exp);
  EXPECT_TRUE(answer == result);
}
}  // namespace s21
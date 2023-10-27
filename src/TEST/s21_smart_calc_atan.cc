#include "s21_smart_calc_tests.h"

namespace s21 {
TEST(test_atan, test_atan_one) {
  Model a;
  Controller b(&a);
  std::string answer = "0.380506";
  const std::string math_exp = "atan0.4";
  b.equal(math_exp);
  std::string result = b.equal(math_exp);
  EXPECT_TRUE(answer == result);
}

TEST(test_atan, test_atan_two) {
  Model a;
  Controller b(&a);
  std::string answer = "0.463648";
  const std::string math_exp = "atan0.5";
  b.equal(math_exp);
  std::string result = b.equal(math_exp);
  EXPECT_TRUE(answer == result);
}
}  // namespace s21

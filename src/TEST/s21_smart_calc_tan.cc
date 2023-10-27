#include "s21_smart_calc_tests.h"
namespace s21 {
TEST(test_tan, test_tan_one) {
  Model a;
  Controller b(&a);
  std::string answer = "1.557408";
  const std::string math_exp = "tan1";
  b.equal(math_exp);
  std::string result = b.equal(math_exp);
  EXPECT_TRUE(answer == result);
}

TEST(test_tan, test_tan_two) {
  Model a;
  Controller b(&a);
  std::string answer = "-2.185040";
  const std::string math_exp = "tan2";
  b.equal(math_exp);
  std::string result = b.equal(math_exp);
  EXPECT_TRUE(answer == result);
}
}  // namespace s21

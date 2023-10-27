#include "s21_smart_calc_tests.h"
namespace s21 {
TEST(test_calc_with_prnts, test_calc_with_prnts_one) {
  Model a;
  Controller b(&a);
  std::string answer = "20.000000";
  const std::string math_exp = "4 * (2 + 3)";
  b.equal(math_exp);
  std::string result = b.equal(math_exp);
  EXPECT_TRUE(answer == result);
}

TEST(test_calc_with_prnts, test_calc_with_prnts_two) {
  Model a;
  Controller b(&a);
  std::string answer = "6.000000";
  const std::string math_exp = "1 + ( 2 + 3 )";
  b.equal(math_exp);
  std::string result = b.equal(math_exp);
  EXPECT_TRUE(answer == result);
}
}  // namespace s21

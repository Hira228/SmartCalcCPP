#include "s21_smart_calc_tests.h"
namespace s21 {
TEST(test_acos, test_acos_one) {
  Model a;
  Controller b(&a);
  std::string answer = "0.927295";
  const std::string math_exp = "acos0.6";
  b.equal(math_exp);
  std::string result = b.equal(math_exp);
  EXPECT_TRUE(answer == result);
}

TEST(test_acos, test_acos_two) {
  Model a;
  Controller b(&a);
  std::string answer = "1.369438";
  const std::string math_exp = "acos0.2";
  b.equal(math_exp);
  std::string result = b.equal(math_exp);
  EXPECT_TRUE(answer == result);
}
}  // namespace s21

#include "s21_smart_calc_tests.h"

namespace s21 {
TEST(test_asin, test_asin_one) {
  Model a;
  Controller b(&a);
  std::string answer = "0.411517";
  const std::string math_exp = "asin0.4";
  b.equal(math_exp);
  std::string result = b.equal(math_exp);
  EXPECT_TRUE(answer == result);
}

TEST(test_asin, test_asin_two) {
  Model a;
  Controller b(&a);
  std::string answer = "0.643501";
  const std::string math_exp = "asin0.6";
  b.equal(math_exp);
  std::string result = b.equal(math_exp);
  EXPECT_TRUE(answer == result);
}
}  // namespace s21

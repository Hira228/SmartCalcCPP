#include "s21_smart_calc_tests.h"

namespace s21 {
TEST(test_gather, test_gather_one) {
  Model a;
  Controller b(&a);
  std::string answer = "-30.072165";
  const std::string math_exp =
      "15/(7-(1+1))*3-(2+(1+1))*15/(7-(200+1))3-(2+(1+1))(15/"
      "(7-(1+1))*3-(2+(1+1))+15/(7-(1+1))*3-(2+(1+1)))";
  b.equal(math_exp);
  std::string result = b.equal(math_exp);
  EXPECT_TRUE(answer == result);
}

TEST(test_gather, test_gather_two) {
  Model a;
  Controller b(&a);
  std::string answer = "-11711.769490";
  const std::string math_exp =
      "1+2-3/4*5^6+sin3.1415927+cos(3.1415927/"
      "2)+sqrt2+2mod2+tan1+ln2+log10+asin0.3+acos0.1+atan0.6+-2+(1-+2)";
  b.equal(math_exp);
  std::string result = b.equal(math_exp);
  EXPECT_TRUE(answer == result);
}
}  // namespace s21

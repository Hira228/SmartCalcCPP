#include "s21_smart_calc_tests.h"

namespace s21 {
TEST(test_parsing, test_parsing_one) {
  Model a;
  Controller b(&a);
  std::string answer = "Calculating error()";
  const std::string math_exp = "2+";
  b.equal(math_exp);
  std::string result = b.equal(math_exp);
  EXPECT_TRUE(answer == result);
}

TEST(test_parsing, test_parsing_two) {
  Model a;
  Controller b(&a);
  std::string answer = "6.000000";
  const std::string math_exp = "2(3)";
  b.equal(math_exp);
  std::string result = b.equal(math_exp);
  EXPECT_TRUE(answer == result);
}

TEST(test_parsing, test_parsing_three) {
  Model a;
  Controller b(&a);
  std::string answer = "9.000000";
  const std::string math_exp = "(1+2)(1 + 2)";
  b.equal(math_exp);
  std::string result = b.equal(math_exp);
  EXPECT_TRUE(answer == result);
}

TEST(test_parsing, test_parsing_four) {
  Model a;
  Controller b(&a);
  std::string answer = "9.000000";
  const std::string math_exp = "(1+2)3";
  b.equal(math_exp);
  std::string result = b.equal(math_exp);
  EXPECT_TRUE(answer == result);
}

TEST(test_parsing, test_parsing_five) {
  Model a;
  Controller b(&a);
  std::string answer = "0.000000";
  const std::string math_exp = "2sin3.1415927";
  b.equal(math_exp);
  std::string result = b.equal(math_exp);
  EXPECT_TRUE(answer == result);
}

TEST(test_parsing, test_parsing_six) {
  Model a;
  Controller b(&a);
  std::string answer = "2.000000";
  const std::string math_exp = "2/+1";
  b.equal(math_exp);
  std::string result = b.equal(math_exp);
  EXPECT_TRUE(answer == result);
}

TEST(test_parsing, test_parsing_seven) {
  Model a;
  Controller b(&a);
  std::string answer = "3.000000";
  const std::string math_exp = "+1+2";
  b.equal(math_exp);
  std::string result = b.equal(math_exp);
  EXPECT_TRUE(answer == result);
}

TEST(test_parsing, test_parsing_eight) {
  Model a;
  Controller b(&a);
  std::string answer = "3.000000";
  const std::string math_exp = "(+2+1)";
  b.equal(math_exp);
  std::string result = b.equal(math_exp);
  EXPECT_TRUE(answer == result);
}

TEST(test_parsing, test_parsing_nine) {
  Model a;
  Controller b(&a);
  std::string answer = "-1.000000";
  const std::string math_exp = "(-2 + 1)";
  b.equal(math_exp);
  std::string result = b.equal(math_exp);
  EXPECT_TRUE(answer == result);
}

TEST(test_parsing, test_parsing_ten) {
  Model a;
  Controller b(&a);
  std::string answer = "Expression error(parsing)";
  const std::string math_exp = "1+DSD";
  b.equal(math_exp);
  std::string result = b.equal(math_exp);
  EXPECT_TRUE(answer == result);
}

TEST(test_parsing, test_parsing_eleven) {
  Model a;
  Controller b(&a);
  std::string answer = "Expression error(parsing)";
  const std::string math_exp = "1+(2))";
  b.equal(math_exp);
  std::string result = b.equal(math_exp);
  EXPECT_TRUE(answer == result);
}

TEST(test_parsing, test_parsing_twelve) {
  Model a;
  Controller b(&a);
  std::string answer = "Expression error(parsing)";
  const std::string math_exp = "aco2";
  b.equal(math_exp);
  std::string result = b.equal(math_exp);
  EXPECT_TRUE(answer == result);
}

TEST(test_parsing, test_parsing_thirteen) {
  Model a;
  Controller b(&a);
  std::string answer = "Expression error(parsing)";
  const std::string math_exp = "asi2";
  b.equal(math_exp);
  std::string result = b.equal(math_exp);
  EXPECT_TRUE(answer == result);
}

TEST(test_parsing, test_parsing_fourteen) {
  Model a;
  Controller b(&a);
  std::string answer = "Expression error(parsing)";
  const std::string math_exp = "ata2";
  b.equal(math_exp);
  std::string result = b.equal(math_exp);
  EXPECT_TRUE(answer == result);
}

TEST(test_parsing, test_parsing_fiveteen) {
  Model a;
  Controller b(&a);
  std::string answer = "Expression error(parsing)";
  const std::string math_exp = "2mo2";
  b.equal(math_exp);
  std::string result = b.equal(math_exp);
  EXPECT_TRUE(answer == result);
}

TEST(test_parsing, test_parsing_sixteen) {
  Model a;
  Controller b(&a);
  std::string answer = "Expression error(parsing)";
  const std::string math_exp = "co2";
  b.equal(math_exp);
  std::string result = b.equal(math_exp);
  EXPECT_TRUE(answer == result);
}

TEST(test_parsing, test_parsing_seventeen) {
  Model a;
  Controller b(&a);
  std::string answer = "Expression error(parsing)";
  const std::string math_exp = "si2";
  b.equal(math_exp);
  std::string result = b.equal(math_exp);
  EXPECT_TRUE(answer == result);
}

TEST(test_parsing, test_parsing_eighteen) {
  Model a;
  Controller b(&a);
  std::string answer = "(2.0000000)+(2.0000000)";
  double x = 2;
  const std::string math_exp = "x+x";
  std::string result = b.convertWithX(math_exp, x);
  EXPECT_TRUE(answer == result);
}
}  // namespace s21

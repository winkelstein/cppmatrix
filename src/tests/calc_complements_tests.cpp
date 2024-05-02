#include "tests.h"

TEST_F(S21MatrixTest, CalcComplements1) {
  S21Matrix a(3, 3), expected_result(3, 3);

  a(0, 0) = 1;
  a(0, 1) = 2;
  a(0, 2) = 3;
  a(1, 0) = 0;
  a(1, 1) = 4;
  a(1, 2) = 2;
  a(2, 0) = 5;
  a(2, 1) = 2;
  a(2, 2) = 1;

  expected_result(0, 0) = 0;
  expected_result(0, 1) = 10;
  expected_result(0, 2) = -20;
  expected_result(1, 0) = 4;
  expected_result(1, 1) = -14;
  expected_result(1, 2) = 8;
  expected_result(2, 0) = -8;
  expected_result(2, 1) = -2;
  expected_result(2, 2) = 4;

  S21Matrix b = a.CalcComplements();

  EXPECT_EQ(b.EqMatrix(expected_result), true);
}

TEST_F(S21MatrixTest, CalcComplements2) {
  S21Matrix a(2, 3);

  EXPECT_THROW(a.CalcComplements(), std::range_error);
}
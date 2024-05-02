#include "tests.h"

TEST_F(S21MatrixTest, OperatorMulMatrix1) {
  S21Matrix a(3, 2), b(2, 3), expected_result(3, 3);

  a(0, 0) = 1;
  a(0, 1) = 4;
  a(1, 0) = 2;
  a(1, 1) = 5;
  a(2, 0) = 3;
  a(2, 1) = 6;

  b(0, 0) = 1;
  b(0, 1) = -1;
  b(0, 2) = 1;
  b(1, 0) = 2;
  b(1, 1) = 3;
  b(1, 2) = 4;

  expected_result(0, 0) = 9;
  expected_result(0, 1) = 11;
  expected_result(0, 2) = 17;
  expected_result(1, 0) = 12;
  expected_result(1, 1) = 13;
  expected_result(1, 2) = 22;
  expected_result(2, 0) = 15;
  expected_result(2, 1) = 15;
  expected_result(2, 2) = 27;

  S21Matrix c = a * b;

  EXPECT_EQ(c.EqMatrix(expected_result), true);
}
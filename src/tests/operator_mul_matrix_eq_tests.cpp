#include "tests.h"

TEST_F(S21MatrixTest, OperatorMulMatrixEq1) {
  S21Matrix a(3, 3), b(3, 3), expected_result(3, 3);

  a(0, 0) = 1;
  a(0, 1) = 2;
  a(0, 2) = 3;
  a(1, 0) = 0;
  a(1, 1) = 4;
  a(1, 2) = 5;
  a(2, 0) = 0;
  a(2, 1) = 0;
  a(2, 2) = 6;

  b(0, 0) = 1;
  b(0, 1) = 0;
  b(0, 2) = 0;
  b(1, 0) = 2;
  b(1, 1) = 0;
  b(1, 2) = 0;
  b(2, 0) = 3;
  b(2, 1) = 4;
  b(2, 2) = 1;

  expected_result(0, 0) = 14;
  expected_result(0, 1) = 12;
  expected_result(0, 2) = 3;
  expected_result(1, 0) = 23;
  expected_result(1, 1) = 20;
  expected_result(1, 2) = 5;
  expected_result(2, 0) = 18;
  expected_result(2, 1) = 24;
  expected_result(2, 2) = 6;

  a *= b;

  EXPECT_EQ(a.EqMatrix(expected_result), true);
}

TEST_F(S21MatrixTest, OperatorMulMatrixEq2) {
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

  a *= b;

  EXPECT_EQ(a.EqMatrix(expected_result), true);
}

TEST_F(S21MatrixTest, OperatorMulMatrixEq3) {
  S21Matrix a(2, 3), b(2, 2);

  a(0, 0) = 12;
  a(0, 1) = -1;
  a(1, 0) = -5;
  a(1, 1) = 0;

  b(0, 0) = -4;
  b(0, 1) = -3;
  b(1, 0) = 15;
  b(1, 1) = 7;

  EXPECT_THROW(a *= b, std::range_error);
}
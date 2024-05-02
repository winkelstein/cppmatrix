#include "tests.h"

TEST_F(S21MatrixTest, Transpose1) {
  S21Matrix a(2, 3), expected_result(3, 2);

  a(0, 0) = 0.14;
  a(0, 1) = -9;
  a(0, 2) = 5;
  a(1, 0) = 16;
  a(1, 1) = 98;
  a(1, 2) = 3;

  expected_result(0, 0) = 0.14;
  expected_result(0, 1) = 16;
  expected_result(1, 0) = -9;
  expected_result(1, 1) = 98;
  expected_result(2, 0) = 5;
  expected_result(2, 1) = 3;

  S21Matrix b = a.Transpose();
  EXPECT_EQ(b.EqMatrix(expected_result), true);
}

TEST_F(S21MatrixTest, Transpose2) {
  S21Matrix a(3, 2), expected_result(2, 3);

  expected_result(0, 0) = 0.14;
  expected_result(0, 1) = -9;
  expected_result(0, 2) = 5;
  expected_result(1, 0) = 16;
  expected_result(1, 1) = 98;
  expected_result(1, 2) = 3;

  a(0, 0) = 0.14;
  a(0, 1) = 16;
  a(1, 0) = -9;
  a(1, 1) = 98;
  a(2, 0) = 5;
  a(2, 1) = 3;

  S21Matrix b = a.Transpose();
  EXPECT_EQ(b.EqMatrix(expected_result), true);
}
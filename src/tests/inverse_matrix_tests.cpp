#include "tests.h"

TEST_F(S21MatrixTest, InverseMatrix1) {
  S21Matrix a(3, 3), expected_result(3, 3);

  a(0, 0) = 2;
  a(0, 1) = 5;
  a(0, 2) = 7;
  a(1, 0) = 6;
  a(1, 1) = 3;
  a(1, 2) = 4;
  a(2, 0) = 5;
  a(2, 1) = -2;
  a(2, 2) = -3;

  expected_result(0, 0) = 1;
  expected_result(0, 1) = -1;
  expected_result(0, 2) = 1;
  expected_result(1, 0) = -38;
  expected_result(1, 1) = 41;
  expected_result(1, 2) = -34;
  expected_result(2, 0) = 27;
  expected_result(2, 1) = -29;
  expected_result(2, 2) = 24;

  S21Matrix inversed = a.InverseMatrix();

  EXPECT_EQ(inversed.EqMatrix(expected_result), true);
}

TEST_F(S21MatrixTest, InverseMatrix2) {
  S21Matrix a(1, 1);

  a(0, 0) = 24.0;

  S21Matrix inversed = a.InverseMatrix();

  EXPECT_EQ(inversed(0, 0), 1.0 / a(0, 0));
}

TEST_F(S21MatrixTest, InverseMatrix3) {
  S21Matrix a(2, 3);

  EXPECT_THROW(a.InverseMatrix(), std::range_error);
}
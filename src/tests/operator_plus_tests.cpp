#include "tests.h"

TEST_F(S21MatrixTest, OperatorPlus1) {
  S21Matrix a(2, 2), b(2, 2);

  a(0, 0) = 5;
  a(0, 1) = 9;
  a(1, 0) = -3;
  a(1, 1) = 6;

  b(0, 0) = 13;
  b(0, 1) = 11;
  b(1, 0) = -66;
  b(1, 1) = 5;

  S21Matrix result = a + b;

  for (int i = 0; i < result.Rows(); i++) {
    for (int j = 0; j < result.Cols(); j++) {
      EXPECT_EQ(result(i, j), a(i, j) + b(i, j));
    }
  }
}
#include "tests.h"

TEST_F(S21MatrixTest, OperatorMulNumber1) {
  S21Matrix a = *this->m3x3;

  double number = 99.4;
  S21Matrix c = number * a;

  for (int i = 0; i < a.Rows(); i++)
    for (int j = 0; j < a.Cols(); j++)
      EXPECT_EQ(c(i, j), (*this->m3x3)(i, j) * number);
}
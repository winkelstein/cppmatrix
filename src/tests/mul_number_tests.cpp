#include "tests.h"

TEST_F(S21MatrixTest, MulNumber1) {
  S21Matrix a = *this->m1x1;

  double number = 15.0;
  a.MulNumber(number);

  for (int i = 0; i < a.Rows(); i++)
    for (int j = 0; j < a.Cols(); j++)
      EXPECT_EQ(a(i, j), (*this->m1x1)(i, j) * number);
}

TEST_F(S21MatrixTest, MulNumber2) {
  S21Matrix a = *this->m2x2;

  double number = -6.0;
  a.MulNumber(number);

  for (int i = 0; i < a.Rows(); i++)
    for (int j = 0; j < a.Cols(); j++)
      EXPECT_EQ(a(i, j), (*this->m2x2)(i, j) * number);
}

TEST_F(S21MatrixTest, MulNumber3) {
  S21Matrix a = *this->m3x3;

  double number = 99.4;
  a.MulNumber(number);

  for (int i = 0; i < a.Rows(); i++)
    for (int j = 0; j < a.Cols(); j++)
      EXPECT_EQ(a(i, j), (*this->m3x3)(i, j) * number);
}

TEST_F(S21MatrixTest, MulNumber4) {
  S21Matrix a = *this->m2x3;

  double number = 0.0;
  a.MulNumber(number);

  for (int i = 0; i < a.Rows(); i++)
    for (int j = 0; j < a.Cols(); j++)
      EXPECT_EQ(a(i, j), (*this->m2x3)(i, j) * number);
}

TEST_F(S21MatrixTest, MulNumber5) {
  S21Matrix a = *this->m3x2;

  double number = 18.0;
  a.MulNumber(number);

  for (int i = 0; i < a.Rows(); i++)
    for (int j = 0; j < a.Cols(); j++)
      EXPECT_EQ(a(i, j), (*this->m3x2)(i, j) * number);
}
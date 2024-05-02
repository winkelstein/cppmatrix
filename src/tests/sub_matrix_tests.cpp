#include "tests.h"

TEST_F(S21MatrixTest, SubMatrix1) {
  S21Matrix a = *this->m2x3;
  S21Matrix b = a;

  a.SubMatrix(b);

  for (int i = 0; i < 2; i++)
    for (int j = 0; j < 3; j++) EXPECT_EQ(a(i, j), 0);
}

TEST_F(S21MatrixTest, SubMatrix2) {
  S21Matrix a = *this->m2x3;
  S21Matrix b = a;

  b *= -1;

  a.SubMatrix(b);

  for (int i = 0; i < 2; i++)
    for (int j = 0; j < 3; j++) EXPECT_EQ(a(i, j), (*this->m2x3)(i, j) * 2);
}

TEST_F(S21MatrixTest, SubMatrix3) {
  S21Matrix a = *this->m3x3;
  S21Matrix b = *this->m1x1;

  EXPECT_THROW(a.SubMatrix(b), std::range_error);
}
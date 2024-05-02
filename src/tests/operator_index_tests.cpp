#include "tests.h"

TEST_F(S21MatrixTest, OperatorIndex1) {
  S21Matrix a = *this->m3x2;
  for (int i = 0; i < a.Rows(); i++) {
    for (int j = 0; j < a.Cols(); j++) {
      EXPECT_EQ(a(i, j), this->m3x2->Data()[i][j]);
    }
  }
}

TEST_F(S21MatrixTest, OperatorIndex2) {
  S21Matrix a = *this->m2x2;
  a(0, 1) = -9.0;

  for (int i = 0; i < a.Rows(); i++) {
    for (int j = 0; j < a.Cols(); j++) {
      EXPECT_EQ(a(i, j), a.Data()[i][j]);
    }
  }
}

TEST_F(S21MatrixTest, OperatorIndex3) {
  S21Matrix a = *this->m3x3;

  EXPECT_THROW(a(3, 0), std::out_of_range);
}
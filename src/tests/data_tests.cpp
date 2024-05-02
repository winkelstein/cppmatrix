#include "tests.h"

TEST_F(S21MatrixTest, Data1) {
  S21Matrix a = *this->m2x2;

  double** matrix_ = a.Data();
  for (int i = 0; i < a.Rows(); i++) {
    for (int j = 0; j < a.Cols(); j++) {
      EXPECT_EQ(matrix_[i][j], a(i, j));
    }
  }
}

TEST_F(S21MatrixTest, Data2) {
  S21Matrix a = *this->m2x2;

  double** matrix_ = a.Data();
  matrix_[0][0] = 5.0;
  for (int i = 0; i < a.Rows(); i++) {
    for (int j = 0; j < a.Cols(); j++) {
      EXPECT_EQ(matrix_[i][j], a(i, j));
    }
  }
}
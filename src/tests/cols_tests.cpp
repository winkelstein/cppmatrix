#include "tests.h"

TEST_F(S21MatrixTest, Cols1) {
  S21Matrix a = *this->m1x1;

  EXPECT_EQ(a.Cols(), 1);
}

TEST_F(S21MatrixTest, Cols2) {
  S21Matrix a = *this->m2x2;

  EXPECT_EQ(a.Cols(), 2);
}

TEST_F(S21MatrixTest, Cols3) {
  S21Matrix a = *this->m2x3;

  EXPECT_EQ(a.Cols(), 3);
}

TEST_F(S21MatrixTest, Cols4) {
  S21Matrix a = *this->m3x2;

  EXPECT_EQ(a.Cols(), 2);
}

TEST_F(S21MatrixTest, Cols5) {
  S21Matrix a = *this->m3x3;

  EXPECT_EQ(a.Cols(), 3);
}
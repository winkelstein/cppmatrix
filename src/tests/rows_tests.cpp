#include "tests.h"

TEST_F(S21MatrixTest, Rows1) {
  S21Matrix a = *this->m1x1;

  EXPECT_EQ(a.Rows(), 1);
}

TEST_F(S21MatrixTest, Rows2) {
  S21Matrix a = *this->m2x2;

  EXPECT_EQ(a.Rows(), 2);
}

TEST_F(S21MatrixTest, Rows3) {
  S21Matrix a = *this->m2x3;

  EXPECT_EQ(a.Rows(), 2);
}

TEST_F(S21MatrixTest, Rows4) {
  S21Matrix a = *this->m3x2;

  EXPECT_EQ(a.Rows(), 3);
}

TEST_F(S21MatrixTest, Rows5) {
  S21Matrix a = *this->m3x3;

  EXPECT_EQ(a.Rows(), 3);
}
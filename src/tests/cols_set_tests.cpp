#include "tests.h"

TEST_F(S21MatrixTest, ColsSet1) {
  S21Matrix a = *this->m1x1;
  a.Cols(2);

  EXPECT_EQ(a.Rows(), 1);
  EXPECT_EQ(a.Cols(), 2);

  EXPECT_EQ(a(0, 0), (*this->m1x1)(0, 0));
  EXPECT_EQ(a(0, 1), 0.0);
}

TEST_F(S21MatrixTest, ColsSet2) {
  S21Matrix a = *this->m2x2;
  a.Cols(1);

  EXPECT_EQ(a.Rows(), 2);
  EXPECT_EQ(a.Cols(), 1);

  EXPECT_EQ(a(0, 0), (*this->m2x2)(0, 0));
  EXPECT_EQ(a(1, 0), (*this->m2x2)(1, 0));
}
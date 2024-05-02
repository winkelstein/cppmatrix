#include "tests.h"

TEST_F(S21MatrixTest, Determinant1) {
  S21Matrix a(3, 3);

  a(0, 0) = 2;
  a(0, 1) = 5;
  a(0, 2) = 7;
  a(1, 0) = 6;
  a(1, 1) = 3;
  a(1, 2) = 4;
  a(2, 0) = 5;
  a(2, 1) = -2;
  a(2, 2) = -3;

  EXPECT_EQ(a.Determinant(), -1);
}

TEST_F(S21MatrixTest, Determinant2) {
  S21Matrix a(2, 3);

  EXPECT_THROW(a.Determinant(), std::range_error);
}

TEST_F(S21MatrixTest, Determinant3) {
  S21Matrix a(1, 1);

  a(0, 0) = -9.0;

  EXPECT_EQ(a.Determinant(), -9.0);
}

TEST_F(S21MatrixTest, Determinant4) {
  S21Matrix a(3, 3);

  a(0, 0) = 1;
  a(0, 1) = 2;
  a(0, 2) = 3;
  a(1, 0) = 4;
  a(1, 1) = 5;
  a(1, 2) = 6;
  a(2, 0) = 7;
  a(2, 1) = 8;
  a(2, 2) = 9;

  EXPECT_EQ(a.Determinant(), 0.0);
}
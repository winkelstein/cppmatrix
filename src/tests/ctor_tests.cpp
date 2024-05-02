#include "tests.h"

TEST_F(S21MatrixTest, SimpleCtor) {
  S21Matrix matrix;
  EXPECT_EQ(matrix.Rows(), 1);
  EXPECT_EQ(matrix.Cols(), 1);
}

TEST_F(S21MatrixTest, RowsAndColsCtor) {
  S21Matrix matrix(3, 8);
  EXPECT_EQ(matrix.Rows(), 3);
  EXPECT_EQ(matrix.Cols(), 8);
}

TEST_F(S21MatrixTest, CopyCtor) {
  S21Matrix source(9, 3);
  source(0, 0) = 18.0;
  source(8, 2) = -5.0;

  S21Matrix matrix(source);

  EXPECT_EQ(matrix.Rows(), 9);
  EXPECT_EQ(matrix.Cols(), 3);

  EXPECT_EQ(matrix(0, 0), 18.0);
  EXPECT_EQ(matrix(8, 2), -5.0);

  source(0, 0) = 0.0;

  EXPECT_EQ(matrix(0, 0), 18.0);
}

TEST_F(S21MatrixTest, MoveCtor) {
  S21Matrix source(9, 3);
  source(0, 0) = 18.0;
  source(8, 2) = -5.0;

  S21Matrix matrix(std::move(source));

  EXPECT_EQ(matrix.Rows(), 9);
  EXPECT_EQ(matrix.Cols(), 3);

  EXPECT_EQ(matrix(0, 0), 18.0);
  EXPECT_EQ(matrix(8, 2), -5.0);

  EXPECT_EQ(source.Rows(), 0);
  EXPECT_EQ(source.Cols(), 0);
}
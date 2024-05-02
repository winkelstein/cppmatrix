#ifndef S21_MATRIX_OOP_TESTS_H
#define S21_MATRIX_OOP_TESTS_H
#include <gtest/gtest.h>

#include <utility>

#include "../s21_matrix_oop.h"

class S21MatrixTest : public testing::Test {
 protected:
  S21Matrix* m1x1;
  S21Matrix* m2x2;
  S21Matrix* m3x3;
  S21Matrix* m2x3;
  S21Matrix* m3x2;

 protected:
  void SetUp() override;
  void TearDown() override;

 private:
  void FillRandomMatrix(S21Matrix& matrix);
};
#endif
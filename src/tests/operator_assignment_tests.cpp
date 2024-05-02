#include "tests.h"

TEST_F(S21MatrixTest, OperatorAssignment1) {
  S21Matrix a = *this->m3x3;
  EXPECT_EQ(a == *this->m3x3, true);
}

TEST_F(S21MatrixTest, OperatorAssignmentConst1) {
  S21Matrix a = (const S21Matrix&)*this->m2x2;

  EXPECT_EQ(a == *this->m2x2, true);
}
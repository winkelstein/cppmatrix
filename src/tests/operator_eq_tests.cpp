#include "tests.h"

TEST_F(S21MatrixTest, OperatorEqMatri1) {
  EXPECT_EQ(*this->m1x1 == *this->m2x2, false);
}

TEST_F(S21MatrixTest, OperatorEqMatrix2) {
  S21Matrix m_new = *this->m2x3;
  EXPECT_EQ(*this->m2x3 == m_new, true);
}

TEST_F(S21MatrixTest, OperatorEqMatrix3) {
  S21Matrix m_new = *this->m3x3;
  m_new(0, 0) = -9.8;

  EXPECT_EQ(m_new == *this->m3x3, false);
}
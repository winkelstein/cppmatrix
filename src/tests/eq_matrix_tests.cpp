#include "tests.h"

TEST_F(S21MatrixTest, EqMatri1) {
  EXPECT_EQ(this->m1x1->EqMatrix(*this->m2x2), false);
}

TEST_F(S21MatrixTest, EqMatrix2) {
  S21Matrix m_new = *this->m2x3;
  EXPECT_EQ(this->m2x3->EqMatrix(m_new), true);
}

TEST_F(S21MatrixTest, EqMatrix3) {
  S21Matrix m_new = *this->m3x3;
  m_new(0, 0) = -9.8;

  EXPECT_EQ(m_new.EqMatrix(*this->m3x3), false);
}
#include "tests.h"

void S21MatrixTest::SetUp() {
  this->m1x1 = new S21Matrix(1, 1);
  this->m2x2 = new S21Matrix(2, 2);
  this->m3x3 = new S21Matrix(3, 3);
  this->m2x3 = new S21Matrix(2, 3);
  this->m3x2 = new S21Matrix(3, 2);

  this->FillRandomMatrix(*this->m1x1);
  this->FillRandomMatrix(*this->m2x2);
  this->FillRandomMatrix(*this->m3x3);
  this->FillRandomMatrix(*this->m2x3);
  this->FillRandomMatrix(*this->m3x2);
}
void S21MatrixTest::TearDown() {
  delete this->m1x1;
  delete this->m2x2;
  delete this->m3x3;
  delete this->m2x3;
  delete this->m3x2;
}

void S21MatrixTest::FillRandomMatrix(S21Matrix& matrix) {
  for (int i = 0; i < matrix.Rows(); i++)
    for (int j = 0; j < matrix.Cols(); j++) matrix(i, j) = rand() % 100;
}

int main(int argc, const char** argv) {
  testing::InitGoogleTest(&argc, (char**)argv);
  return RUN_ALL_TESTS();
}
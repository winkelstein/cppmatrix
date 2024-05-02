#include "s21_matrix_oop.h"

S21Matrix::S21Matrix() : S21Matrix(1, 1) {}

S21Matrix::S21Matrix(int rows, int cols) : rows_(rows), cols_(cols) {
  if (rows < 1 || cols < 1) {
    throw std::invalid_argument("Rows or cols less than 1");
  }
  this->Create();
}

S21Matrix::S21Matrix(const S21Matrix& other)
    : rows_(other.rows_), cols_(other.cols_) {
  this->Create();
  this->Copy(other);
}

S21Matrix::S21Matrix(S21Matrix&& other)
    : rows_(other.rows_), cols_(other.cols_), matrix_(other.matrix_) {
  other.rows_ = 0;
  other.cols_ = 0;
  other.matrix_ = nullptr;
}

S21Matrix::~S21Matrix() noexcept { this->Destroy(); }

bool S21Matrix::EqMatrix(const S21Matrix& other) const {
  bool result = true;

  if ((this->rows_ == other.rows_) && (this->cols_ == other.cols_)) {
    for (int i = 0; i < this->rows_; i++) {
      for (int j = 0; j < this->cols_; j++) {
        if (fabs(this->matrix_[i][j] - other.matrix_[i][j]) >= 1e-7) {
          result = false;
        }
      }
    }
  } else {
    result = false;
  }

  return result;
}

void S21Matrix::SumMatrix(const S21Matrix& other) {
  if (this->rows_ != other.rows_ || this->cols_ != other.cols_) {
    throw std::range_error("Matrices has different shapes");
  }

  int rows = this->rows_;
  int columns = this->cols_;
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      this->matrix_[i][j] = this->matrix_[i][j] + other.matrix_[i][j];
    }
  }
}

void S21Matrix::SubMatrix(const S21Matrix& other) {
  if (this->rows_ != other.rows_ || this->cols_ != other.cols_) {
    throw std::range_error("Matrices has different shapes");
  }

  int rows = this->rows_;
  int columns = this->cols_;
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      this->matrix_[i][j] = this->matrix_[i][j] - other.matrix_[i][j];
    }
  }
}

void S21Matrix::MulNumber(const double num) {
  for (int i = 0; i < this->rows_; i++) {
    for (int j = 0; j < this->cols_; j++) {
      this->matrix_[i][j] = this->matrix_[i][j] * num;
    }
  }
}

void S21Matrix::MulMatrix(const S21Matrix& other) {
  if ((this->rows_ != other.cols_) || (this->cols_ != other.rows_)) {
    throw std::range_error(
        "Matrices has invalid shapes: expected A.rows == B.cols || A.cols == "
        "B.rows");
  }

  S21Matrix result = S21Matrix(this->rows_, other.cols_);

  if (this->rows_ == 1 && this->cols_ == 1) {
    result.matrix_[0][0] = this->matrix_[0][0] * other.matrix_[0][0];

  } else {
    for (int i = 0; i < this->rows_; i++) {
      for (int j = 0; j < other.cols_; j++) {
        for (int k = 0; k < other.rows_; k++) {
          result.matrix_[i][j] += this->matrix_[i][k] * other.matrix_[k][j];
        }
      }
    }
  }

  *this = result;
}

S21Matrix S21Matrix::Transpose() const {
  S21Matrix result(this->cols_, this->rows_);
  for (int i = 0; i < this->rows_; i++) {
    for (int j = 0; j < this->cols_; j++) {
      result.matrix_[j][i] = this->matrix_[i][j];
    }
  }
  return result;
}

S21Matrix S21Matrix::CalcComplements() const {
  if (this->rows_ != this->cols_) {
    throw std::range_error("Expected square matrix");
  }

  S21Matrix result(this->rows_, this->cols_);
  for (int i = 0; i < this->rows_; i++) {
    for (int j = 0; j < this->cols_; j++) {
      this->Complement(i, j, result);
    }
  }

  return result;
}

double S21Matrix::Determinant() const {
  if (this->rows_ != this->cols_) {
    throw std::range_error("Expected square matrix");
  }

  return this->DeterminantRecursive(*this);
}

S21Matrix S21Matrix::InverseMatrix() const {
  if (this->rows_ != this->cols_) {
    throw std::range_error("Expected square matrix");
  }

  S21Matrix result(this->rows_, this->cols_);

  if (this->rows_ == 1 && this->cols_ == 1) {
    result.matrix_[0][0] = 1.0 / this->matrix_[0][0];
  } else {
    S21Matrix alg_comp = this->CalcComplements();
    S21Matrix alg_comp_t = alg_comp.Transpose();

    double det = this->Determinant();

    result = det * alg_comp_t;
  }

  return result;
}

S21Matrix S21Matrix::Minor(int excluded_row, int excluded_col) const {
  if (excluded_row >= this->rows_ || excluded_col >= this->cols_) {
    throw std::out_of_range(
        "Excluded row or column must be less than rows or columns count");
  }

  S21Matrix result(this->rows_ - 1, this->cols_ - 1);
  for (int i = 0, minor_i = 0; i < this->rows_; i++) {
    if (i != excluded_row) {
      for (int j = 0, minor_j = 0; j < this->cols_; j++) {
        if (j != excluded_col) {
          result.matrix_[minor_i][minor_j] = this->matrix_[i][j];
          minor_j++;
        }
      }
      minor_i++;
    }
  }
  return result;
}

void S21Matrix::Complement(int i, int j, S21Matrix& result) const {
  S21Matrix minor = this->Minor(i, j);
  double det = minor.Determinant();
  result.matrix_[i][j] = pow(-1, i + j) * det;
}

S21Matrix S21Matrix::operator+(const S21Matrix& other) const {
  S21Matrix result(*this);
  result.SumMatrix(other);
  return result;
}

S21Matrix S21Matrix::operator-(const S21Matrix& other) const {
  S21Matrix result(*this);
  result.SubMatrix(other);
  return result;
}

S21Matrix S21Matrix::operator*(const S21Matrix& other) const {
  S21Matrix result(*this);
  result.MulMatrix(other);
  return result;
}

S21Matrix operator*(double number, const S21Matrix& matrix) noexcept {
  S21Matrix result(matrix);
  result.MulNumber(number);
  return result;
}

bool S21Matrix::operator==(const S21Matrix& other) const {
  return this->EqMatrix(other);
}

S21Matrix& S21Matrix::operator=(const S21Matrix& other) {
  this->Destroy();
  this->rows_ = other.rows_;
  this->cols_ = other.cols_;
  this->Create();
  this->Copy(other);

  return *this;
}

S21Matrix& S21Matrix::operator=(S21Matrix&& other) noexcept {
  this->Destroy();
  this->rows_ = other.rows_;
  this->cols_ = other.cols_;
  this->matrix_ = other.matrix_;

  other.rows_ = 0;
  other.cols_ = 0;
  other.matrix_ = nullptr;

  return *this;
}

S21Matrix& S21Matrix::operator+=(const S21Matrix& other) {
  this->SumMatrix(other);
  return *this;
}

S21Matrix& S21Matrix::operator-=(const S21Matrix& other) {
  this->SubMatrix(other);
  return *this;
}

S21Matrix& S21Matrix::operator*=(const S21Matrix& other) {
  this->MulMatrix(other);
  return *this;
}

S21Matrix& S21Matrix::operator*=(const double num) {
  this->MulNumber(num);
  return *this;
}

double& S21Matrix::operator()(int i, int j) {
  if ((i >= this->rows_) || (j >= this->cols_) || (i < 0) || (j < 0)) {
    throw std::out_of_range(
        "Invalid i or j argument: i and j must be less than matrix rows and "
        "cols and greater than zero");
  }
  return this->matrix_[i][j];
}

const double& S21Matrix::operator()(int i, int j) const {
  if ((i >= this->rows_) || (j >= this->cols_) || (i < 0) || (j < 0)) {
    throw std::out_of_range(
        "Invalid i or j argument: i and j must be less than matrix rows and "
        "cols and greater than zero");
  }
  return this->matrix_[i][j];
}

std::ostream& operator<<(std::ostream& os, const S21Matrix& matrix) noexcept {
  os << '[';

  for (int i = 0; i < matrix.rows_; i++) {
    if (i != 0) {
      os << ' ';
    }
    os << '[';
    for (int j = 0; j < matrix.cols_; j++) {
      os << matrix.matrix_[i][j];
      if (j != matrix.cols_ - 1) {
        os << ", ";
      }
    }
    os << "]";
    if (i != matrix.rows_ - 1) {
      os << ",\n";
    }
  }

  os << ']';

  return os;
}

void S21Matrix::Rows(int rows_) {
  if (rows_ < 1) {
    throw std::range_error("Argument rows_ cannot be less than 1");
  }

  S21Matrix temp(*this);
  this->Destroy();
  this->rows_ = rows_;
  this->cols_ = temp.cols_;
  this->Create();

  if (this->rows_ > temp.rows_) {
    for (int i = 0; i < temp.rows_; i++) {
      for (int j = 0; j < this->cols_; j++) {
        this->matrix_[i][j] = temp.matrix_[i][j];
      }
    }
  } else {
    this->Copy(temp);
  }
}

void S21Matrix::Cols(int cols_) {
  if (cols_ < 1) {
    throw std::range_error("Argument cols_ cannot be less than 1");
  }

  S21Matrix temp = *this;
  this->Destroy();
  this->rows_ = temp.rows_;
  this->cols_ = cols_;
  this->Create();

  if (this->cols_ > temp.cols_) {
    for (int i = 0; i < this->rows_; i++) {
      for (int j = 0; j < temp.cols_; j++) {
        this->matrix_[i][j] = temp.matrix_[i][j];
      }
    }
  } else {
    this->Copy(temp);
  }
}

void S21Matrix::Create() noexcept {
  this->matrix_ = new double*[this->rows_];

  for (int i = 0; i < this->rows_; i++) {
    this->matrix_[i] = new double[this->cols_];

    for (int j = 0; j < this->cols_; j++) {
      this->matrix_[i][j] = 0.0;
    }
  }
}

void S21Matrix::Destroy() noexcept {
  if (this->matrix_ == nullptr || (this->rows_ && this->cols_) == 0) return;

  for (int i = 0; i < this->rows_; i++) delete[] this->matrix_[i];

  delete[] this->matrix_;
  this->matrix_ = nullptr;
  this->rows_ = 0;
  this->cols_ = 0;
}

void S21Matrix::Copy(const S21Matrix& src) {
  for (int i = 0; i < this->rows_; i++) {
    for (int j = 0; j < this->cols_; j++) {
      this->matrix_[i][j] = src(i, j);
    }
  }
}

double S21Matrix::Determinant2x2(const S21Matrix& a) const {
  return a.matrix_[0][0] * a.matrix_[1][1] - a.matrix_[0][1] * a.matrix_[1][0];
}

double S21Matrix::DeterminantRecursive(const S21Matrix& a) const {
  int size = a.rows_;
  double result = 0.0;

  if (size == 1) {
    result = a.matrix_[0][0];
  } else if (size == 2) {
    result = this->Determinant2x2(a);
  } else {
    double det = 0.0;
    S21Matrix submatrix(size - 1, size - 1);

    for (int col = 0; col < size; col++) {
      int submatrix_row = 0;
      for (int i = 1; i < size; i++) {
        int submatrix_col = 0;
        for (int j = 0; j < size; j++) {
          if (j != col) {
            submatrix.matrix_[submatrix_row][submatrix_col++] = a.matrix_[i][j];
          }
        }
        submatrix_row++;
      }

      double submatrix_det = this->DeterminantRecursive(submatrix);

      det += (col % 2 == 0 ? 1 : -1) * a.matrix_[0][col] * submatrix_det;
    }

    result = det;
  }

  return result;
}
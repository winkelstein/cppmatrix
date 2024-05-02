#ifndef S21_MATRIX_OOP_H
#define S21_MATRIX_OOP_H

#include <cmath>
#include <iostream>

class S21Matrix final {
 private:
  int rows_, cols_;
  double** matrix_;

 public:
  S21Matrix();

  S21Matrix(int rows, int cols);
  S21Matrix(const S21Matrix& other);
  S21Matrix(S21Matrix&& other);

  ~S21Matrix() noexcept;

 public:
  bool EqMatrix(const S21Matrix& other) const;
  void SumMatrix(const S21Matrix& other);
  void SubMatrix(const S21Matrix& other);
  void MulNumber(const double num);
  void MulMatrix(const S21Matrix& other);
  S21Matrix Transpose() const;
  S21Matrix CalcComplements() const;
  double Determinant() const;
  S21Matrix InverseMatrix() const;

 public:
  S21Matrix operator+(const S21Matrix& other) const;
  S21Matrix operator-(const S21Matrix& other) const;
  S21Matrix operator*(const S21Matrix& other) const;
  friend S21Matrix operator*(double number, const S21Matrix& matrix) noexcept;
  bool operator==(const S21Matrix& other) const;
  S21Matrix& operator=(const S21Matrix& other);
  S21Matrix& operator=(S21Matrix&& other) noexcept;
  S21Matrix& operator+=(const S21Matrix& other);
  S21Matrix& operator-=(const S21Matrix& other);
  S21Matrix& operator*=(const S21Matrix& other);
  S21Matrix& operator*=(const double num);
  double& operator()(int i, int j);
  const double& operator()(int i, int j) const;

  friend std::ostream& operator<<(std::ostream& os,
                                  const S21Matrix& matrix) noexcept;

 public:
  inline int Rows() const { return this->rows_; }
  inline int Cols() const { return this->cols_; }
  inline double** Data() const { return this->matrix_; }

  void Rows(int rows_);
  void Cols(int cols_);

 private:
  void Create() noexcept;
  void Destroy() noexcept;
  void Copy(const S21Matrix& src);

  S21Matrix Minor(int excluded_row, int excluded_col) const;
  void Complement(int i, int j, S21Matrix& result) const;

  double Determinant2x2(const S21Matrix& a) const;
  double DeterminantRecursive(const S21Matrix& a) const;
};

#endif
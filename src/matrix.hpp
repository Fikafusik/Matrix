
#ifndef __MATRIX_HPP__
#define __MATRIX_HPP__

class Matrix {
public:
  double **mtrx;
  int rows;
  int cols;

  void alloc_space();
  void dealloc_space();

public:
  Matrix();
  Matrix(int, int);
  Matrix(const Matrix &);

  ~Matrix();
  
  Matrix operator+();
  Matrix operator-();
  
  Matrix & operator=(const Matrix &);

  Matrix & operator*=(double);
  Matrix & operator/=(double);

  Matrix & operator+=(const Matrix &);
  Matrix & operator-=(const Matrix &);
  Matrix & operator*=(const Matrix &);

  Matrix transponse();
};

Matrix operator*(const Matrix &, double);
Matrix operator*(double, const Matrix &);
Matrix operator/(const Matrix &, double);

Matrix operator+(const Matrix &, const Matrix &);
Matrix operator-(const Matrix &, const Matrix &);
Matrix operator*(const Matrix &, const Matrix &);

bool operator==(const Matrix &, const Matrix &);
bool operator!=(const Matrix &, const Matrix &);

#endif
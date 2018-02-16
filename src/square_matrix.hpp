
#ifndef __SQUARE_MATRIX_HPP__
#define __SQUARE_MATRIX_HPP__

#include "matrix.hpp"

class SquareMatrix : public Matrix {
public:
  SquareMatrix();
  SquareMatrix(int);
  SquareMatrix(const SquareMatrix &);

  ~SquareMatrix();

  // determinant
  double det();
  // permanent
  double per();
  // trace
  double tr();

  SquareMatrix inverse();
  
};

#endif

#include "square_matrix.hpp"

SquareMatrix::SquareMatrix() : Matrix() { }

SquareMatrix::SquareMatrix(int n) : Matrix(n, n) { }

double SquareMatrix::det() {

}

double SquareMatrix::per() {

}

double SquareMatrix::tr() {
    double trace = 0.0;
    for (int i = 0; i < rows; ++i)
        trace += mtrx[i][i];
    return trace;
}

SquareMatrix SquareMatrix::inverse() {

}
  
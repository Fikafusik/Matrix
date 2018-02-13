
#include "matrix.hpp"

void Matrix::alloc_space() {
    mtrx = new double*[rows];
    for (int i = 0; i < rows; ++i) 
        mtrx[i] = new double[cols];
    return;
}

void Matrix::dealloc_space() {
    for (int i = 0; i < rows; ++i)
        delete[] mtrx[i];
    delete[] mtrx;
}

Matrix::Matrix() : rows(1), cols(1) {
    alloc_space();
    mtrx[0][0] = 0.0;
} 

Matrix::Matrix(int rows, int columns) : rows(rows), cols(columns) {
    alloc_space();
    for (int i = 0; i < rows; ++i) 
        for (int j = 0; j < cols; ++j)
            mtrx[i][j] = 0.0;
}

Matrix::Matrix(const Matrix &m) : rows(m.rows), cols(m.cols) {
    alloc_space();
    for (int i = 0; i < rows; ++i) 
        for (int j = 0; j < cols; ++j)
            mtrx[i][j] = m.mtrx[i][j];
}

Matrix::~Matrix() {
    dealloc_space();
}

Matrix & Matrix::operator=(const Matrix &m) {
    if (this == &m)
        return *this;
    if (rows != m.rows || cols != m.cols) {
        dealloc_space();
        rows = m.rows;
        cols = m.cols;
        alloc_space();
    }
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            mtrx[i][j] = m.mtrx[i][j];
    return *this;
}

Matrix & Matrix::operator*=(double rv) {
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            mtrx[i][j] *= rv;
    return *this;
}

Matrix & Matrix::operator/=(double rv) {
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            mtrx[i][j] /= rv;
    return *this;
}

Matrix & Matrix::operator+=(const Matrix &rm) {
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            mtrx[i][j] += rm.mtrx[i][j];
    return *this;
}

Matrix & Matrix::operator-=(const Matrix &rm) {
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            mtrx[i][j] -= rm.mtrx[i][j];
    return *this;
}

Matrix & Matrix::operator*=(const Matrix &rm) {
    Matrix m = Matrix(rows, rm.cols);
    for (int i = 0; i < m.rows; ++i)
        for (int j = 0; j < m.cols; ++j)
            for (int k = 0; k < cols; ++k)
                m.mtrx[i][j] += mtrx[i][k] * rm.mtrx[k][j];
    return (*this = m);
}

Matrix Matrix::transponse() {
    Matrix m = Matrix(cols, rows);
    for (int i = 0; i < rows; ++i) 
        for (int j = 0; j < cols; ++j)
            m.mtrx[j][i] = mtrx[i][j];
    return m;
}

double Matrix::tr() {
    if (rows != cols)
        return 42.0;
    double trace = 0.0;
    for (int i = 0; i < rows; ++i)
        trace += mtrx[i][i];
    return trace;
}

Matrix operator*(const Matrix &lm, double rv) {
    Matrix m = Matrix(lm.rows, lm.cols);
    for (int i = 0; i < m.rows; ++i)
        for (int j = 0; j < m.cols; ++j)
            m.mtrx[i][j] = lm.mtrx[i][j] * rv;
    return m;    
}

Matrix operator*(double lv, const Matrix &rm) {
    Matrix m = Matrix(rm.rows, rm.cols);
    for (int i = 0; i < m.rows; ++i)
        for (int j = 0; j < m.cols; ++j)
            m.mtrx[i][j] = lv * rm.mtrx[i][j];
    return m;
}

Matrix operator/(const Matrix &lm, double rv) {
    Matrix m = Matrix(lm.rows, lm.cols);
    for (int i = 0; i < m.rows; ++i)
        for (int j = 0; j < m.cols; ++j)
            m.mtrx[i][j] = lm.mtrx[i][j] / rv;
    return m;    
}

Matrix operator+(const Matrix &lm, const Matrix &rm) {
    Matrix m = Matrix(lm.rows, lm.cols);
    for (int i = 0; i < m.rows; ++i)
        for (int j = 0; j < m.cols; ++j)
            m.mtrx[i][j] = lm.mtrx[i][j] + rm.mtrx[i][j];
    return m;
}

Matrix operator-(const Matrix &lm, const Matrix &rm) {
    Matrix m = Matrix(lm.rows, lm.cols);
    for (int i = 0; i < m.rows; ++i)
        for (int j = 0; j < m.cols; ++j)
            m.mtrx[i][j] = lm.mtrx[i][j] - rm.mtrx[i][j];
    return m;
}

Matrix operator*(const Matrix &lm, const Matrix &rm) {
    Matrix m = Matrix(lm.rows, rm.cols);
    for (int i = 0; i < m.rows; ++i) 
        for (int j = 0; i < m.cols; ++j)
            for (int k = 0; k < m.cols; ++k)
                m.mtrx[i][j] += lm.mtrx[i][k] * rm.mtrx[k][j];
    return m;
}

bool operator==(const Matrix &lm, const Matrix &rm) {
    if (&lm == &rm)
        return true;
    if (lm.rows != rm.rows || lm.cols != rm.cols)
        return false;
    for (int i = 0; i < lm.rows; ++i)
        for (int j = 0; j < lm.cols; ++j)
            if (lm.mtrx[i][j] != rm.mtrx[i][j])
                return false;
    return true;
}

bool operator!=(const Matrix &lm, const Matrix &rm) {
    if (&lm == &rm)
        return false;
    if (lm.rows != rm.rows || lm.cols != rm.cols)
        return true;
    for (int i = 0; i < lm.rows; ++i)
        for (int j = 0; j < lm.cols; ++j)
            if (lm.mtrx[i][j] != rm.mtrx[i][j])
                return true;
    return false;
}

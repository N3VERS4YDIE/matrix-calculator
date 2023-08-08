#ifndef MATRIX_H
#define MATRIX_H

#include <vector>

typedef std::vector<std::vector<float>> Matrix;
typedef std::pair<int, int> Dimension;

Matrix new_matrix(const int M, const int N);
Dimension dim(const Matrix &A);
void validate_matrix(const Matrix &A);
Matrix trn(const Matrix &A);
Matrix sub(const Matrix &A, const int ROW, const int COL);
float det(Matrix A);
float minor(const Matrix &A, const int ROW, const int COL);
Matrix cof(const Matrix &A);
Matrix adj(const Matrix &A);
Matrix inv(const Matrix &A);

#endif // MATRIX_H
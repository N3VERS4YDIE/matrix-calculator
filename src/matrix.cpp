#include "../include/matrix.h"
#include <cmath>
#include <stdexcept>
#include <tuple>
#include <vector>

/**
 * Creates a new rectangular matrix with dimensions `M` x `N` and initializes all its elements to 0.
 *
 * @param M Number of rows.
 * @param N Number of columns.
 *
 * @return A new matrix.
 */
Matrix new_matrix(const int M, const int N)
{
    return Matrix(M, std::vector<float>(N, 0));
}

/**
 * Creates a pair of integers with the dimensions of a matrix. The first integer represents
 * the number of rows and the second integer represents the number of columns.
 *
 * @param A Rectangular matrix.
 *
 * @return A pair with the dimensions of `A`.
 */
Dimension dim(const Matrix &A)
{
    const int M = A.size(), N = A[0].size();
    return std::make_pair(M, N);
}

/**
 * Checks if a matrix is rectangular and not empty, throws an excpetion otherwise.
 *
 * @param A Rectangular matrix.
 */
void validate_matrix(const Matrix &A)
{
    if (A.empty() || A[0].empty())
    {
        throw std::invalid_argument("Empty matrix");
    }

    int m, n;
    std::tie(m, n) = dim(A);
    for (int i = 1; i < m; ++i)
    {
        if ((int)A[i].size() != n)
        {
            throw std::invalid_argument("Irregular matrix");
        }
    }
}

/**
 * Calculates the transpose of a matrix by swapping rows and columns.
 *
 * @param A Rectangular matrix.
 *
 * @return the transpose matrix of `A`.
 */
Matrix trn(const Matrix &A)
{
    int m, n;
    std::tie(m, n) = dim(A);
    Matrix B = new_matrix(n, m);
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            B[i][j] = A[j][i];
        }
    }
    return B;
}

/**
 * Calculates the submatrix of a matrix removing a row and column.
 *
 * @param A Rectangular matrix.
 * @param ROW Row index of the element in the matrix `A` to exclude.
 * @param COL Column index of the element in the matrix `A` to exclude.
 *
 * @return the submatrix of `A`.
 */
Matrix sub(const Matrix &A, const int ROW, const int COL)
{
    int m, n;
    std::tie(m, n) = dim(A);
    Matrix B = new_matrix(m - 1, n - 1);
    for (int i = 0; i < m; ++i)
    {
        if (i == ROW)
        {
            continue;
        }
        for (int j = 0; j < n; ++j)
        {
            if (j == COL)
            {
                continue;
            }
            B[i - (i > ROW)][j - (j > COL)] = A[i][j];
        }
    }
    return B;
}

/**
 * Calculates the determinant of a matrix using Gaussian elimination.
 *
 * @param A Square matrix.
 *
 * @return the determinant value of `A`.
 */
float det(Matrix A)
{
    int m, n;
    std::tie(m, n) = dim(A);

    if (m != n)
    {
        throw std::invalid_argument("Non square matrix");
    }

    for (int p = 0; p < n - 1; ++p) // pivot row
    {
        for (int i = p + 1; i < n; ++i)
        {
            if (A[i][p] == 0)
            {
                continue;
            }

            const float C = A[i][p] / A[p][p];
            for (int j = 0; j < n; ++j)
            {
                A[i][j] -= C * A[p][j];
            }
        }
    }

    float sum = 1; // diagonal sum
    for (int i = 0; i < n; ++i)
    {
        sum *= A[i][i];
    }
    return sum;
}

/**
 * Calculates the minor of a matrix by finding the determinant of its submatrix at one row and one colum.
 *
 * @param A Square Matrix.
 * @param ROW Row index of the element in the matrix `A` to exclude.
 * @param COL Column index of the element in the matrix `A` to exclude.
 *
 * @return the minor of `A`.
 */
float minor(const Matrix &A, const int ROW, const int COL)
{
    return det(sub(A, ROW, COL));
}

/**
 * Calculates the cofactors of a matrix by finding the complementary minor of each element.
 *
 * @param A Rectangular matrix.
 *
 * @return the cofactor matrix of `A`.
 */
Matrix cof(const Matrix &A)
{
    int m, n;
    std::tie(m, n) = dim(A);
    Matrix B = new_matrix(m, n);
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            B[i][j] = pow(-1, i + j) * minor(A, i, j);
        }
    }
    return B;
}

/**
 * Calculates the adjugate of a matrix by finding the cofactors of its transpose.
 *
 * @param A Rectangular matrix.
 *
 * @return the adjugate matrix of `A`.
 */
Matrix adj(const Matrix &A)
{
    int m, n;
    std::tie(m, n) = dim(A);
    return cof(trn(A));
}

/**
 * Calculates the inverse of a matrix by finding its adjugate, and dividing each element by the
 * determinant of the original matrix.
 *
 * @param A Invertible matrix.
 *
 * @return the inverse matrix of `A`.
 */
Matrix inv(const Matrix &A)
{
    int m, n;
    std::tie(m, n) = dim(A);
    const float DET = det(A);

    if (DET == 0)
    {
        throw std::invalid_argument("Singular matrix");
    }

    Matrix B = adj(A);
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            B[i][j] /= DET;
        }
    }
    return B;
}
#include "../include/matrix.h"
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>

const int DECIMALS = 2;

Matrix in_matrix();
void out_matrix(const Matrix &A);

int main()
{
    Matrix A = in_matrix();
    validate_matrix(A);

    printf("A:\n");
    out_matrix(A);

    printf("\ndim(A): ");
    Dimension dim_A = dim(A);
    printf("%i x %i\n", dim_A.first, dim_A.second);

    printf("\ntrn(A):\n");
    out_matrix(trn(A));

    printf("\ncof(A):\n");
    out_matrix(cof(A));

    printf("\nadj(A):\n");
    out_matrix(adj(A));

    printf("\n|A|: ");
    printf("%.*f\n", DECIMALS, det(A));

    printf("\nA^-1:\n");
    out_matrix(inv(A));

    printf("\n");

    return 0;
}

/**
 * Takes user input to create a matrix.
 * 
 * @return a matrix.
 */
Matrix in_matrix()
{
    Matrix A;
    printf("\nInput a matrix separating each element by a space (press Enter after each row, and Enter twice to finish):\n\n");
    std::string line;
    while (std::getline(std::cin, line) && !line.empty())
    {
        std::vector<float> row;
        std::istringstream iss(line);
        float element;
        while (iss >> element)
        {
            row.push_back(element);
        }
        A.push_back(row);
    }
    return A;
}

/**
 * Prints a matrix.
 *
 * @param A Rectangular matrix.
 */
void out_matrix(const Matrix &A)
{
    const int WIDTH = DECIMALS + 4;

    for (const std::vector<float> &row : A)
    {
        printf("|");
        for (const float &element : row)
        {
            std::cout << printf("%*.*f", WIDTH, DECIMALS, element);
        }
        printf("  |\n");
    }
}
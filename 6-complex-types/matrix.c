#include <stdio.h>
#include <assert.h>

#define MAXDATA 1024

typedef struct
{
    double data[MAXDATA];
    int nrows;
    int ncols;
} Matrix;

void printmat(Matrix M);
Matrix matrixmult(Matrix A, Matrix B);
double dot(int x, int y, Matrix A, Matrix B);

int main(int argc, char *argv[])
{
    Matrix A = {{1.2, 2.3,
                 3.4, 4.5,
                 5.6, 6.7},
                3,
                2};
    Matrix B = {{5.5, 6.6, 7.7,
                 1.2, 2.1, 3.3},
                2,
                3};

    printf("=== printmat(A) ===\n");
    printmat(A);

    printf("\n");

    printf("=== printmat(B) ===\n");
    printmat(B);

    printf("\n");

    Matrix C = matrixmult(A, B);

    printf("=== printmat(C = A x B) ===\n");
    printmat(C);

    return 0;
}

// your code goes below...

void printmat(Matrix M)
{
    double *data = M.data;
    int nrows = M.nrows;
    int ncols = M.ncols;

    printf("== Values ==\n");

    for (int x = 0; x < nrows; x++)
    {
        for (int y = 0; y < ncols; y++)
        {
            printf("data[%d][%d] = %.2f\n", x, y, data[x * ncols + y]);
        }
    }

    printf("== Layout ==\n");

    printf("[ ");

    for (int x = 0; x < nrows; x++)
    {
        if (x > 0)
        {
            // Alignment
            printf("  ");
        }

        for (int y = 0; y < ncols; y++)
        {
            if (y == 0)
            {
                printf("[ %.2f, ", data[x * ncols + y]);
            }
            else if (y == ncols - 1)
            {
                printf("%.2f ]", data[x * ncols + y]);
            }
            else
            {
                printf("%.2f, ", data[x * ncols + y]);
            }
        }

        if (x < nrows - 1)
        {
            printf(", \n");
        }
    }

    printf(" ]\n");
}

/**
 * @brief Compute the dot product of ith row of A and jth column of B.
 *
 * @param x
 * @param y
 * @param A
 * @param B
 * @return double
 */
double dot(int x, int y, Matrix A, Matrix B)
{
    // c_ij = ai1b1j + ai2b2j + ... + ainbnj

    assert(A.ncols == B.nrows);

    int n = A.ncols; // or B.nrows
    double s = 0;

    for (int k = 0; k < n; k++)
    {
        s += A.data[x * A.ncols + k] * B.data[k * B.ncols + y];
    }

    return s;
}

Matrix matrixmult(Matrix A, Matrix B)
{
    Matrix C;

    assert(A.ncols == B.nrows);
    assert(B.ncols * A.nrows < MAXDATA);

    C.ncols = B.ncols;
    C.nrows = A.nrows;

    for (int x = 0; x < C.nrows; x++)
    {
        for (int y = 0; y < C.ncols; y++)
        {
            C.data[x * C.ncols + y] = dot(x, y, A, B);
        }
    }

    return C;
}

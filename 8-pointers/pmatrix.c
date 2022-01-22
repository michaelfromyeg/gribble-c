#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct
{
    double *data;
    int nrows;
    int ncols;
} Matrix;

void printmat(Matrix *M);
void matrixmult(Matrix *A, Matrix *B, Matrix *C);
double dot(int x, int y, Matrix *A, Matrix *B);

Matrix *createMatrix(int nrows, int ncols);
void destroyMatrix(Matrix *M);

int main(int argc, char *argv[])
{
    Matrix *A = createMatrix(3, 2);
    A->data[0] = 1.2;
    A->data[1] = 2.3;
    A->data[2] = 3.4;
    A->data[3] = 4.5;
    A->data[4] = 5.6;
    A->data[5] = 6.7;

    Matrix *B = createMatrix(2, 3);
    B->data[0] = 5.5;
    B->data[1] = 6.6;
    B->data[2] = 7.7;
    B->data[3] = 1.2;
    B->data[4] = 2.1;
    B->data[5] = 3.3;

    printf("=== printmat(A) ===\n");
    printmat(A);

    printf("\n");

    printf("=== printmat(B) ===\n");
    printmat(B);

    printf("\n");

    Matrix *C = createMatrix(3, 3);
    matrixmult(A, B, C);

    printf("=== printmat(C = A x B) ===\n");
    printmat(C);

    destroyMatrix(A);
    destroyMatrix(B);
    destroyMatrix(C);

    return 0;
}

Matrix *createMatrix(int nrows, int ncols)
{
    Matrix *m = malloc(sizeof(Matrix));

    m->data = calloc(nrows * ncols, sizeof(double));
    m->ncols = ncols;
    m->nrows = nrows;

    return m;
}

void destroyMatrix(Matrix *M)
{
    free(M->data);
    free(M);
}

void printmat(Matrix *M)
{
    double *data = M->data;
    int nrows = M->nrows;
    int ncols = M->ncols;

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
double dot(int x, int y, Matrix *A, Matrix *B)
{
    // c_ij = ai1b1j + ai2b2j + ... + ainbnj

    assert(A->ncols == B->nrows);

    int n = A->ncols; // or B.nrows
    double s = 0;

    for (int k = 0; k < n; k++)
    {
        s += A->data[x * A->ncols + k] * B->data[k * B->ncols + y];
    }

    return s;
}

void matrixmult(Matrix *A, Matrix *B, Matrix *C)
{

    assert(A->ncols == B->nrows);

    C->ncols = B->ncols;
    C->nrows = A->nrows;

    for (int x = 0; x < C->nrows; x++)
    {
        for (int y = 0; y < C->ncols; y++)
        {
            C->data[x * C->ncols + y] = dot(x, y, A, B);
        }
    }
}

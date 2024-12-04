#include <stdlib.h>

void dgemm(size_t n, double *A, double *B, double *C)
{
    for (size_t i = 0; i < n; ++i)
        for (size_t j = 0; j < n; ++j)
        {
            double cij = C[i + j * n]; /* cij = C[i][j] */
            for (size_t k = 0; k < n; k++)
                cij += A[i + k * n] * B[k + j * n]; /* cij += A[i][k]*B[k][j] */
            C[i + j * n] = cij;                     /* C[i][j] = cij */
        }
}

#include "dgemm.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <mm_malloc.h>

#define VERBOSE 0

// Helper function to initialize a matrix with random values
void initialize_matrix(double *matrix, int n, int is_random) {
    for (int i = 0; i < n * n; ++i) {
        matrix[i] = is_random ? ((double)rand() / RAND_MAX) : 0.0;
    }
}

void benchmark_dgemm(int n) {
    // Allocate memory for matrices
    double *A = (double *)_mm_malloc(n * n * sizeof(double), 32);
    double *B = (double *)_mm_malloc(n * n * sizeof(double), 32);
    double *C = (double *)_mm_malloc(n * n * sizeof(double), 32);

    if (!A || !B || !C) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    // Initialize matrices
    initialize_matrix(A, n, 1); // Random values for A
    initialize_matrix(B, n, 1); // Random values for B
    initialize_matrix(C, n, 0); // Zeros for C

    // Measure time
    clock_t start = clock();
    dgemm(n, A, B, C);
    clock_t end = clock();

    // Calculate elapsed time
    double time_taken = (double)(end - start) / CLOCKS_PER_SEC;
    if (VERBOSE) {
        printf("n = %d, Time = %f seconds\n", n, time_taken);
    } else {
        printf("%f\n", time_taken);
    }

    // Free allocated memory
    _mm_free(A);
    _mm_free(B);
    _mm_free(C);
}

int main() {
    // Seed random number generator
    srand((unsigned int)time(NULL));

    // Run benchmarks for various matrix sizes
    int sizes[] = {1024};
    int num_sizes = sizeof(sizes) / sizeof(sizes[0]);

    for (int i = 0; i < num_sizes; ++i) {
        benchmark_dgemm(sizes[i]);
    }

    return 0;
}

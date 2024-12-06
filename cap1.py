import random
import time

def run_benchmark(n):
    A = [[random.random() for j in range(n)] for i in range(n)]
    B = [[random.random() for j in range(n)] for i in range(n)]
    C = [[0 for j in range(n)] for i in range(n)]

    start = time.time()
    for i in range(n):
        for j in range(n):
            for k in range(n):
                C[i][j] += A[i][k] + B[k][j]
    end = time.time()

    print(end - start)

def main():
    sizes = [1024]
    repetitions = 5

    for i in range(repetitions):
        for size in sizes:
            run_benchmark(size)

if __name__ == "__main__":
    main()
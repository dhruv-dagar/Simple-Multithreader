#include "simple-multithreader.h"
#include <cassert>
#include <algorithm>
#include <cstdio>

int main(int argc, char** argv) {
    int numThread = argc > 1 ? atoi(argv[1]) : 2;
    int size = argc > 2 ? atoi(argv[2]) : 1024;

    int** A = new int*[size];
    int** B = new int*[size];
    int** C = new int*[size];

    parallel_for(0, size, [=](int i) {
        A[i] = new int[size];
        B[i] = new int[size];
        C[i] = new int[size];
        std::fill(A[i], A[i] + size, 1);
        std::fill(B[i], B[i] + size, 1);
        std::fill(C[i], C[i] + size, 0);
    }, numThread);

    parallel_for(0, size, 0, size, [&](int i, int j) {
        for (int k = 0; k < size; k++) C[i][j] += A[i][k] * B[k][j];
    }, numThread);

    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++) assert(C[i][j] == size);
    printf("Matrix test success.\n");

    parallel_for(0, size, [=](int i) {
        delete[] A[i]; delete[] B[i]; delete[] C[i];
    }, numThread);
    delete[] A; delete[] B; delete[] C;
    return 0;
}

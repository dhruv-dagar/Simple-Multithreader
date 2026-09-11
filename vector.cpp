#include "simple-multithreader.h"
#include <cassert>
#include <iostream>
#include <algorithm>

int main(int argc, char** argv) {
    int numThread = argc > 1 ? atoi(argv[1]) : 2;
    int size = argc > 2 ? atoi(argv[2]) : 48000000;

    int* A = new int[size];
    int* B = new int[size];
    int* C = new int[size];
    std::fill(A, A + size, 1);
    std::fill(B, B + size, 1);
    std::fill(C, C + size, 0);

    parallel_for(0, size, [&](int i) { C[i] = A[i] + B[i]; }, numThread);

    for (int i = 0; i < size; i++) assert(C[i] == 2);
    std::cout << "Vector test success\n";

    delete[] A; delete[] B; delete[] C;
    return 0;
}

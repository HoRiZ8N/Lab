#include "functions.h"

int* createMatrix() {
    int* matrix = new int[effSize];
    return matrix;
}

void fillMatrix(int* matrix) {
    for (int i = 0; i < effSize; i++) {
        matrix[i] = rand() % 10 + 1;
    } 
}

int getIndex(int i, int j) {
    return (j * (j + 1)) / 2 + i;
}

void printMatrix(int* matrix) {
    std::cout << '\n';
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            if (i <= j) {
                int index = getIndex(i, j);
                std::cout << matrix[index] << ' ';
            } else {
                std::cout << "0 ";
            }
        }
        std::cout << '\n';
    }
}

void getMatrixSquared(int* sourceMatrix, int* resultMatrix) {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = i; j < SIZE; ++j) {
            int sum = 0;
            for (int k = i; k <= j; ++k) {
                sum += sourceMatrix[getIndex(i, k)] * sourceMatrix[getIndex(k, j)];
            }
            resultMatrix[getIndex(i, j)] = sum;
        }
    }
}

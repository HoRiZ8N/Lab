#include "func.h"

int getIndex(int i, int j) {
    return i * SIZE + j;
}

int** create2dMatrix() {
    int** matrix = new int*[SIZE];
    for (int i = 0; i < SIZE; i++) {
        matrix[i] = new int[SIZE];
    }
    return matrix;
}

void delete2dMatrix(int** matrix) {
    for (int i = 0; i < SIZE; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

void fill2dMatrix(int** matrix) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            matrix[i][j] = rand() % MAXNUMSIZE + 1;
        }
    }
}

int **square2dMatrix(int **matrix) {
    int** res = create2dMatrix();
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            res[i][j] = 0;
            for (int k = 0; k < SIZE; ++k) {
                res[i][j] += matrix[i][k] * matrix[k][j];
            }
        }
    }
    return res;
}

void print2dMatrix(int **matrix) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            std::cout << matrix[i][j] << ' ';
        }
        std::cout << '\n';
    }
    std::cout << '\n';
}

int* multiply2dMatrixVector(int **matrix, int *vector) {
    int* res = new int[SIZE];
    for (int i = 0; i < SIZE; ++i) {
        res[i] = 0; 
        for (int j = 0; j < SIZE; ++j) {
            res[i] += matrix[i][j] * vector[j];
        }
    }
    return res;
}

int* create1dMatrix() {
    int* matrix = new int[SIZE * SIZE];
    return matrix;
}

void fill1dMatrix(int* matrix) {
    for (int i = 0; i < SIZE * SIZE; i++) {
        matrix[i] = rand() % MAXNUMSIZE + 1;
    }
}

int *square1dMatrix(int *matrix) {
    int* ans = create1dMatrix();
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            ans[getIndex(i, j)] = 0;
            for (int k = 0; k < SIZE; ++k) {
                ans[getIndex(i, j)] += matrix[getIndex(i, k)] * matrix[getIndex(k, j)];
            }
        }
    }
    return ans;
}

void print1dMatrix(int *matrix) {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            std::cout << matrix[getIndex(i, j)] << ' ';
        }
        std::cout << '\n';
    } 
    std::cout << '\n';
}

void printVector(int *vector) {
    for (int i = 0; i < SIZE; i++) {
        std::cout << vector[i] << ' ';
    }
    std::cout << "\n\n";
}

int* multiply1dMatrixVector(int *matrix, int *vector) {
    int* res = create1dMatrix();
    for (int i = 0; i < SIZE; ++i) {
        res[i] = 0;
        for (int j = 0; j < SIZE; ++j) {
            res[i] += matrix[getIndex(i, j)] * vector[j];
        }
    }
    return res;
}

void fillVector(int *vector) {
    for (int i = 0; i < SIZE; i++) {
        vector[i] = rand() % MAXNUMSIZE + 1;
    } 
}


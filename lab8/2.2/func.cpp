#include "func.h"

int getIndex(int i, int j, int size) {
    return i * size + j;
}

int** create2dMatrix(int size) {
    int** matrix = new int*[size];
    for (int i = 0; i < size; i++) {
        matrix[i] = new int[size];
    }
    return matrix;
}

void delete2dMatrix(int** matrix, int size) {
    for (int i = 0; i < size; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

void fill2dMatrix(int** matrix, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            matrix[i][j] = rand() % MAXNUMSIZE + 1;
        }
    }
}

void square2dMatrix(int **matrix, int size) {
    int** temp = create2dMatrix(size);

    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            temp[i][j] = 0;
            for (int k = 0; k < size; ++k) {
                temp[i][j] += matrix[i][k] * matrix[k][j];
            }
        }
    }

    for (int i = 0; i < size; ++i)
    {
        for (int j = 0; j < size; j++)
        {
            matrix[i][j] = temp[i][j];
        }
        
    }
    
    delete2dMatrix(temp, size);
}

void print2dMatrix(int **matrix, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            std::cout << matrix[i][j] << ' ';
        }
        std::cout << '\n';
    }
    std::cout << '\n';
}

int* multiply2dMatrixVector(int **matrix, int *vector, int size) {
    int* res = new int[size];
    for (int i = 0; i < size; ++i) {
        res[i] = 0; 
        for (int j = 0; j < size; ++j) {
            res[i] += matrix[i][j] * vector[j];
        }
    }
    return res;
}

int* create1dMatrix(int size) {
    int* matrix = new int[size * size];
    return matrix;
}

void fill1dMatrix(int* matrix, int size) {
    for (int i = 0; i < size * size; i++) {
        matrix[i] = rand() % MAXNUMSIZE + 1;
    }
}

void square1dMatrix(int *matrix, int size) {
    int* temp = create1dMatrix(size);
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            temp[getIndex(i, j, size)] = 0;
            for (int k = 0; k < size; ++k) {
                temp[getIndex(i, j, size)] += matrix[getIndex(i, k, size)] * matrix[getIndex(k, j, size)];
            }
        }
    }
    
    for (int i = 0; i < size * size; ++i) {
        matrix[i] = temp[i];
    }
    
    delete[] temp; 
}

void print1dMatrix(int *matrix, int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            std::cout << matrix[getIndex(i, j, size)] << ' ';
        }
        std::cout << '\n';
    } 
    std::cout << '\n';
}

void printVector(int *vector, int size) {
    for (int i = 0; i < size; i++) {
        std::cout << vector[i] << ' ';
    }
    std::cout << "\n\n";
}

int* multiply1dMatrixVector(int *matrix, int *vector, int size) {
    int* res = create1dMatrix(size);
    for (int i = 0; i < size; ++i) {
        res[i] = 0;
        for (int j = 0; j < size; ++j) {
            res[i] += matrix[getIndex(i, j, size)] * vector[j];
        }
    }
    return res;
}

void fillVector(int *vector, int size) {
    for (int i = 0; i < size; i++) {
        vector[i] = rand() % MAXNUMSIZE + 1;
    } 
}
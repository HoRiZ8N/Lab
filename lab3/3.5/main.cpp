#include "functions.h"

int main() {
    srand(time(0));
    int* matrixA = createMatrix();
    fillMatrix(matrixA);
    // printMatrix(matrixA);

    int* matrixB = createMatrix();
    getMatrixSquared(matrixA, matrixB);
    // printMatrix(matrixB);

    delete[] matrixA;
    delete[] matrixB;
    
    return 0;
}
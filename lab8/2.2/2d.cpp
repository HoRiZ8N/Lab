#include "func.h"

int main() {
    srand(time(0));
    int** matrix = create2dMatrix();
    fill2dMatrix(matrix);
    print2dMatrix(matrix);
    int** squaredMatrix = square2dMatrix(matrix);
    print2dMatrix(squaredMatrix);
    delete2dMatrix(matrix);
    int* vect = new int[SIZE];
    fillVector(vect);
    printVector(vect);
    int* ans = multiply2dMatrixVector(squaredMatrix, vect);
    delete2dMatrix(squaredMatrix);
    delete[] vect;
    printVector(ans);
    delete[] ans;

    return 0;
}
#include "func.h"

int main() {
    srand(time(0));
    int* matrix = create1dMatrix();
    fill1dMatrix(matrix);  
    print1dMatrix(matrix);
    int* squaredMatrix = square1dMatrix(matrix);
    print1dMatrix(squaredMatrix);
    delete[] matrix;
    int* vect = new int[SIZE];
    fillVector(vect);
    printVector(vect);
    int* ans = multiply1dMatrixVector(squaredMatrix, vect);
    delete[] squaredMatrix;
    delete[] vect;
    printVector(ans);
    delete[] ans;

    return 0;
}
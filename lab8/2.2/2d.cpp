#include "func.h"

int main() {
    srand(time(0));

    int size;
    std::cout << "Enter matrix and vector size: ";
    std::cin >> size;

    int** matrix = create2dMatrix(size);
    int* vect = new int[size];

    fill2dMatrix(matrix, size);
    fillVector(vect, size);

    std::cout << "\nInitial matrix:\n"; 

    print2dMatrix(matrix, size);
    square2dMatrix(matrix, size);

    std::cout << "Squared matrix:\n";
    print2dMatrix(matrix, size);


    std::cout << "Vector:\n";
    printVector(vect, size);

    int* result = multiply2dMatrixVector(matrix, vect, size);

    std::cout << "Result:\n";
    printVector(result, size);

    delete2dMatrix(matrix, size);
    delete[] vect;
    delete[] result;

    return 0;
}
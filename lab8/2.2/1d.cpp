#include "func.h"

int main() {
    srand(time(0));

    int size;
    std::cout << "Enter matrix and vector size: ";
    std::cin >> size;

    int* matrix = create1dMatrix(size);
    int* vect = new int[size];

    fill1dMatrix(matrix, size);
    fillVector(vect, size);

    std::cout << "\nInitial matrix:\n"; 
    print1dMatrix(matrix, size);

    square1dMatrix(matrix, size);

    std::cout << "Squared matrix:\n";

    print1dMatrix(matrix, size);
    
    std::cout << "Vector:\n";
    printVector(vect, size);
    
    int* result = multiply1dMatrixVector(matrix, vect, size);

    std::cout << "Result:\n";
    printVector(result, size);

    delete[] vect;
    delete[] matrix;
    delete[] result;

    return 0;
}
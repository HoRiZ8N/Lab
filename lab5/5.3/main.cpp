#include <iostream>
#include <algorithm>

void fillMatrix(int rows, int cols, int** matrix) {
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            matrix[i][j] = rand();
        }
    }
}

void deleteMatrix(int rows,int** matrix) {
    for (int i = 0; i < rows; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

void printMatrix(int rows, int cols, int** matrix) {
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            std::cout << matrix[i][j] << ' ';
        }
        std::cout << '\n';
    }
    
}


int main() {

    srand(time(0));
    int rows, cols;
    std::cout << "Enter matrix size: ";
    std::cin >> rows >> cols;

    int** unsortedMatrix = new int*[rows];
    for (int i = 0; i < rows; ++i) {
        unsortedMatrix[i] = new int[cols];
    }
    
    int** sortedMatrix = new int*[rows];
    for (int i = 0; i < rows; ++i) {
        sortedMatrix[i] = new int[cols];
    }

    fillMatrix(rows, cols, unsortedMatrix);

    int** pointerArray = new int*[rows]; // pointer array to the first column
    for (int i = 0; i < rows; i++)
    {
        pointerArray[i] = unsortedMatrix[i];
    }

    std::sort(pointerArray, pointerArray + rows, // sort pointers by their values
        [](int* a, int* b) {
            if (*a < *b) {
                return true;
            } else {
                return false;
            }  
        }
    );   

    std::cout << "\nUnsorted matrix:\n\n";
    // printMatrix(rows, cols, unsortedMatrix);
    
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
           sortedMatrix[i][j] = *(pointerArray[i] + j);
        }
    }
    
    std::cout << "\nSorted matrix\n\n";
    // printMatrix(rows, cols, sortedMatrix);
    
    deleteMatrix(rows, unsortedMatrix);
    deleteMatrix(rows, sortedMatrix);
    delete[] pointerArray;

    return 0;
}
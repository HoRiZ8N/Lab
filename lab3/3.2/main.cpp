#include <iostream>

const int SIZE = 10;

int main() {
    srand(time(0));
    int** matrixA = new int*[SIZE]; // given matrix
    for (int i = 0; i < SIZE; i++)
    {
        matrixA[i] = new int[SIZE];
        for (int j = 0; j < SIZE; j++)
        {
            matrixA[i][j] = rand() % 1000;
            std::cout << matrixA[i][j] << ' ';
        }
        std::cout << '\n';
    }
    std::cout << "\n\n";
    
    int** matrixB = new int*[SIZE];  // new matrix
    for (int i = 0; i < SIZE; i++)
    {
        matrixB[i] = new int[SIZE];
    }

    int maxLeft = 0, maxBot = 0;
    for (int i = SIZE - 1; i >= 0; i--) // filling new matrix
    {
        for (int j = 0; j < SIZE; j++)
        {
            (j == 0) ? (maxLeft = 0) : (maxLeft = matrixB[i][j-1]);
            (i == SIZE - 1) ? (maxBot = 0) : (maxBot = matrixB[i+1][j]);
            matrixB[i][j] = std::max(std::max(maxBot, maxLeft), matrixA[i][j]);
        }
    }
    
    for (int i = 0; i < SIZE; i++) 
    {
        for (int j = 0; j < SIZE; j++)
        {
            std::cout << matrixB[i][j] << ' ';
        }
        std::cout << '\n';
    }
    

    for (int i = 0; i < SIZE; i++)
    {
        delete[] matrixA[i];
    }
    delete[] matrixA;
    for (int i = 0; i < SIZE; i++)
    {
        delete[] matrixB[i];
    }
    delete[] matrixB;

    return 0;
}
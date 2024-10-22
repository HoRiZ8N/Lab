#include <iostream>

const int SIZE = 3;
int currRight = SIZE - 1, currBottom = SIZE - 1, currLeft = 0, currTop = 0;
unsigned int direction = 0; // 0-r    1-t      2-l    3-b
int** matrix = new int*[SIZE];

void initializeMatrix(int** matrix) {
    for (int i = 0; i < SIZE; i++) {
        matrix[i] = new int[SIZE];
    }
}

void deleteMatrix(int** matrix) {
    for (int i = 0; i < SIZE; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

void enterMatrix(int** matrix) {
    int i = 0, j = 0; 
    std::cout << "Enter matrix of " << SIZE << " size:\n";
    for (; i < SIZE - 1; i++) {
        std::cin >> matrix[i][j];
    }
    
    while(true) {
        if (currBottom == currTop && currLeft == currRight && SIZE % 2 == 1) {
            std::cin >> matrix[i][j];
            break;
        } else if (SIZE % 2 == 0 && currLeft == (SIZE / 2) && currBottom == ((SIZE / 2) - 1) && currRight == (SIZE / 2) &&
        currTop == ((SIZE / 2) - 1)) {
            std::cin >> matrix[i][j];
            break;
        } 
        
        if (i == currTop && j == currLeft && direction % 4 == 3) {
            while (i != currBottom) {
                std::cin >> matrix[i][j];
                i++;
            }
            currTop++;
            direction++;
        } else if (i == currBottom && j == currLeft && direction % 4 == 0) {
            while (j != currRight) {
                std::cin >> matrix[i][j];
                j++;
            }
            currLeft++;
            direction++;
        } else if (i == currBottom && j == currRight && direction % 4 == 1) {
            while (i != currTop) {
                std::cin >> matrix[i][j];
                i--;
            }
            currBottom--;
            direction++;
        } else if (i == currTop && j == currRight && direction % 4 == 2) {
            while (j != currLeft) {
                std::cin >> matrix[i][j];
                j--;
            }
            currRight--;
            direction++;
        }
    }
    std::cout << "\n";
}

void printMatrix(int** matrix) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            std::cout << matrix[i][j] << ' ';
        }
        std::cout << '\n';
    }
}



int main() {
     
    initializeMatrix(matrix);
    enterMatrix(matrix);
    printMatrix(matrix);
    deleteMatrix(matrix);

    return 0;
}
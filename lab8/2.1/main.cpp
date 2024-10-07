#include <iostream>
#include <algorithm>

const int SIZE = 1000;
const int MAXVAL = 10'000'000;

int* arr = new int[SIZE];

void keyboardInitialization(int* array) {
    std::cout << "Enter " << SIZE << " numbers: ";
    for (int i = 0; i < SIZE; i++) {
        std::cin >> array[i];
    }
}

void randomInitialization(int* array) {
    for (int i = 0; i < SIZE; i++) {
        array[i] = rand() % MAXVAL + 1;
    }
}

void changeArray(int* array) {
    for (int i = 1; i <= MAXVAL; i++) {
        
    }
}

enum InitializationType{
    keyboard = 1,
    random = 2
};

int main() {
    srand(time(0));
    InitializationType type = random;
    switch (type)
    {
    case 1:
        keyboardInitialization(arr);
        break;
    case 2:
        randomInitialization(arr);
        break;
    default:
        return 1;
    }
    std::sort(arr, arr + SIZE);

    

    return 0;
}
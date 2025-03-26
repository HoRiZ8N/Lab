#include <iostream>
#include "MyVector.h"
#include <ctime>
#include <cstdlib>

const unsigned int MAX_VAL = 10'000'000;
const unsigned long long MAX_SEQUENCE_SIZE = 1'000'000'000'000;

enum InitializationType {
    KeyboardInput = 1,
    RandomGeneration = 2
};

void processNumber(MyVector<bool>& array, int number) {
    if (number > 0 && number <= MAX_VAL) {
        array[number] = true;
    }
}

int main() {
    unsigned long long n;
    std::cout << "Enter the length of the sequence (n <= " << MAX_SEQUENCE_SIZE << "): ";
    std::cin >> n;

    if (n <= 0 || n > MAX_SEQUENCE_SIZE) {
        std::cerr << "The value of n should be between 1 and " << MAX_SEQUENCE_SIZE << ".\n";
        return 1;
    }

    std::cout << "Choose initialization method:\n"
              << InitializationType::KeyboardInput << ": Keyboard\n"
              << InitializationType::RandomGeneration << ": Random generation\n";
    int choice;
    std::cin >> choice;

    InitializationType initType = static_cast<InitializationType>(choice);

    MyVector<bool> array(MAX_VAL + 1);

    switch (initType) {
    case InitializationType::KeyboardInput:
        std::cout << "Enter " << n << " natural numbers (each <= 10^7):\n";
        for (unsigned long long i = 0; i < n; ++i) {
            int number;
            std::cin >> number;
            processNumber(array, number);
        }
        break;

    case InitializationType::RandomGeneration:
        srand(time(0));
        for (unsigned long long i = 0; i < n; ++i) {
            unsigned int randomVal = rand() % MAX_VAL + 1;
            processNumber(array, randomVal);
        }
        break;

    default:
        std::cerr << "Invalid initialization type.\n";
        return 1;
    }

    MyVector<int> result;
    for (int i = 1; i < 100; i++)
    {
        if (!array[i])
        {
            result.PushBack(i);
        }
    }

    std::cout << "Missing numbers in ascending order:\n";
    std::cout << result;
    std::cout << std::endl;

    return 0;
}

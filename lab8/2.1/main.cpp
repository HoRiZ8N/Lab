#include <iostream>
#include <cstdlib>
#include <ctime>

const int MAX_VAL = 10'000'000;
const long long MAX_SEQUENCE_SIZE = 1'000'000'000'000;

enum InitializationType
{
    KeyboardInput = 1,
    RandomGeneration = 2
};

void fillArray(bool *arr, unsigned int size, InitializationType fillType)
{
    switch (fillType)
    {
    case InitializationType::KeyboardInput:
        std::cout << "Enter " << size << " natural numbers (each <= 10^7):\n";
        for (unsigned long long i = 0; i < size; ++i)
        {
            int number;
            std::cin >> number;
            if (number <= 0 || number > MAX_VAL)
            {
                std::cerr << "Number out of range! Please enter a number between 1 and " << MAX_VAL << ".\n";
                --i;
                continue;
            }
            arr[number] = true;
        }
        break;

    case InitializationType::RandomGeneration:
        srand(time(0));
        for (unsigned int i = 0; i < size; ++i)
        {
            unsigned int randomVal = rand() % (MAX_VAL + 1);
            arr[randomVal] = true;
        }
        break;

    default:
        std::cerr << "Invalid initialization type.\n";
        exit(1);
    }
}

void printArray(bool* array)
{
    for (int i = 0; i < MAX_VAL; i++)
    {
        if (array[i])
        {
            std::cout << i << " ";
        }
    }
    std::cout << "\n";
}

int main()
{
    long long n;
    std::cout << "Enter the length of the sequence (n <= 10^12): ";
    std::cin >> n;

    if (n > MAX_SEQUENCE_SIZE) {
        std::cerr << "The value of n should be less than or equal to " << MAX_SEQUENCE_SIZE << ".\n";
        return 1;
    }

    bool *arr = new bool[MAX_VAL + 1]();

    std::cout << "Choose initialization method:\n"
              << InitializationType::KeyboardInput << ": Keyboard\n"
              << InitializationType::RandomGeneration << ": Random generation\n";
    int choice;
    std::cin >> choice;

    InitializationType initType = static_cast<InitializationType>(choice);

    fillArray(arr, n, initType);

    std::cout << "Initial array:\n";
    printArray(arr);
    std::cout << "Missing numbers (up to " << n << "):" << '\n';
    for (int i = 1; i <= n; ++i) 
    {
        if (!arr[i])
        {
            std::cout << i << " ";
            if (i % 10 == 0)
            {
                std::cout << '\n';
            }
        }
    }
    std::cout << '\n';

    delete[] arr;

    return 0;
}

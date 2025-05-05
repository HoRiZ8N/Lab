#include <iostream>
#include <ctime>

const unsigned long long MAX_SEQUENCE_SIZE = 1e12;
const int MAX_VAL = 1e7;

enum InitializationType
{
    KeyboardInput = 1,
    RandomGeneration = 2
};

int main()
{
    unsigned long long n;
    std::cout << "Enter the length of the sequence (n <= 10^12): ";
    std::cin >> n;

    if (n <= 0 || n > MAX_SEQUENCE_SIZE)
    {
        std::cerr << "The value of n should be between 1 and " << MAX_SEQUENCE_SIZE << ".\n";
        return 1;
    }

    std::cout << "Choose initialization method:\n"
              << "1: Keyboard input\n"
              << "2: Random generation\n";
    int choice;
    std::cin >> choice;

    InitializationType initType = static_cast<InitializationType>(choice);

    bool *array = new bool[MAX_VAL + 1]();

    switch (initType)
    {
    case KeyboardInput:
        std::cout << "Enter " << n << " natural numbers (each <= 10^7):\n";
        for (unsigned long long i = 0; i < n; ++i)
        {
            int number;
            std::cin >> number;
            if (number > 0 && number <= MAX_VAL)
            {
                array[number] = true;
            }
            else
            {
                std::cerr << "Error";
                exit(0);
            }
        }
        break;

    case RandomGeneration:
        srand(time(0));
        for (unsigned long long i = 0; i < n; ++i)
        {
            unsigned int randomVal = rand() % MAX_VAL + 1;
            array[randomVal] = true;
        }
        break;

    default:
        std::cerr << "Invalid initialization type.\n";
        delete[] array;
        return 1;
    }

    int index = 0;
    int *missingNumbers = new int[missingCount];

    for (int i = 1; i <= MAX_VAL; ++i)
    {
        if (!array[i])
        {
            missingNumbers[index++] = i;
        }
    }

    std::cout << "Missing numbers in ascending order:\n";
    for (int i = 0; i < index; ++i)
    {
        std::cout << missingNumbers[i] << " ";
    }
    std::cout << "\n";

    delete[] array;
    delete[] missingNumbers;

    return 0;
}

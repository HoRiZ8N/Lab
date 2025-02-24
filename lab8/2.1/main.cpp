#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>

const int       MAX_VAL           = 10'000'000;        // максимальное значение
const long long MAX_SEQUENCE_SIZE = 1'000'000'000'000; // максимальная длина последовательности

enum InitializationType
{
    KeyboardInput = 1,
    RandomGeneration = 2
};

void fillArray(unsigned int *arr, unsigned int size, InitializationType fillType)
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
            arr[i] = number;
        }
        break;

    case InitializationType::RandomGeneration:
        srand(time(0));
        for (unsigned int i = 0; i < size; ++i)
        {
            unsigned int randomVal = rand() % MAX_VAL + 1; 
            arr[i] = randomVal;
        }
        break;

    default:
        std::cerr << "Invalid initialization type.\n";
        exit(1);
    }
}

void printArray(unsigned int *array, unsigned int size)
{
    for (unsigned int i = 0; i < size; i++)
    {
        std::cout << array[i] << " ";
    }
    std::cout << "\n";
}

unsigned int* getMissingValArr(unsigned int *source, long long n)
{
    bool *boolArr = new bool[MAX_VAL + 1]();
    unsigned int *dest = new unsigned int[MAX_VAL - n]();
    for (long long i = 0; i < n; i++)
    {
        boolArr[source[i]] = true;
    }
    int k = 0;
    for (int i = 1; i <= MAX_VAL; i++)
    {
        if (!boolArr[i])
        {
           dest[k++] = i;  
        }
    }
    delete[] boolArr;
    return dest;
}

int main()
{
    long long n;
    std::cout << "Enter the length of the sequence (n <= 10^12): ";
    std::cin >> n;

    if (n > MAX_SEQUENCE_SIZE)
    {
        std::cerr << "The value of n should be less than or equal to " << MAX_SEQUENCE_SIZE << ".\n";
        return 1;
    }
    else if (n <= 0)
    {
        std::cerr << "The value of n can't be less than or equal to 0";
        return 1;
    }

    std::cout << "Choose initialization method:\n"
              << InitializationType::KeyboardInput << ": Keyboard\n"
              << InitializationType::RandomGeneration << ": Random generation\n";
    int choice;
    std::cin >> choice;

    InitializationType initType = static_cast<InitializationType>(choice);

    unsigned int* sourceArr = new unsigned int[n];
    fillArray(sourceArr, n, initType);

    std::cout << "Initial array:\n";
    printArray(sourceArr, n);

    unsigned int* destArr = getMissingValArr(sourceArr, n);

    std::cout << "Missing numbers:" << '\n';
    printArray(destArr, MAX_VAL - n);

    delete[] sourceArr;
    delete[] destArr;

    return 0;
}

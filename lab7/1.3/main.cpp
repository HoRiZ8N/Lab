#include <iostream>
#include <algorithm>
#include <ctime>

enum InitializationType
{
    KeyboardInput = 1,
    RandomGeneration = 2
};

void printArray(int *arr, unsigned int size)
{
    for (int i = 0; i < size; i++)
    {
        std::cout << arr[i] << ' ';
    }
    std::cout << "\n\n";
}

void fillArray(int *arr, unsigned int size, InitializationType fillType)
{
    switch (fillType)
    {
    case KeyboardInput:
    std::cout << "Enter " << size << " numbers: ";
        for (int i = 0; i < size; i++)
        {
            std::cin >> arr[i];
        }
        break;
    case RandomGeneration:
        srand(time(0));
        for (int i = 0; i < size; i++)
        {
            arr[i] = rand() % 100;
        }
        break;
    default:
        std::cerr << "Invalid initialization type.\n";
        exit(1);
    }
}

void copyArray(int *arrToCopy, int *arrFromCopying, unsigned int size)
{
    for (int i = 0; i < size; i++)
    {
        arrToCopy[i] = arrFromCopying[i];
    }
}

int *findMax(int *newarr, int *arr, unsigned int size)
{
    if (size < 2) // Проверка на минимальный размер массива
    {
        if (size == 1)
        {
            return arr; // Если один элемент, он же и максимальный
        }
        return nullptr; // Если пустой массив
    }

    int *maxValPtr = nullptr;

    for (int i = 0; i < size - 2; i++)
    {
        if (newarr[i] == newarr[i + 1] && newarr[i] != newarr[i + 2])
        {
            maxValPtr = newarr + i;
            break;
        }
    }

    if (maxValPtr == nullptr && newarr[size - 2] == newarr[size - 1]) // Проверка конца массива
    {
        maxValPtr = newarr + size - 2;
    }

    if (maxValPtr != nullptr)
    {
        for (int i = 0; i < size; i++)
        {
            if (*maxValPtr == arr[i])
            {
                return arr + i;
            }
        }
    }

    // Если подходящих значений нет, ищем максимальное в arr
    maxValPtr = arr;
    for (int i = 1; i < size; i++)
    {
        if (arr[i] > *maxValPtr)
        {
            maxValPtr = arr + i;
        }
    }

    return maxValPtr;
}


int main()
{
    std::cout << "Enter array size: ";
    unsigned int size;
    std::cin >> size;

    int choice;
    std::cout << "Choose initialization method:\n"
              << KeyboardInput << ": Keyboard\n"
              << RandomGeneration << ": Random generation\n";
    std::cin >> choice;
    InitializationType initType = static_cast<InitializationType>(choice);
    int k;
    std::cout << "Enter k: ";
    std::cin >> k;

    int *array = new int[size];
    int *newArray = new int[size];

    fillArray(array, size, initType);
    copyArray(newArray, array, size);

    std::sort(newArray, newArray + size, [](int a, int b){ return a > b; });

    int *maxVal = findMax(newArray, array, size);

    std::cout << "Initial array:\n";
    printArray(array, size);
    
    if (maxVal)
    {
        *maxVal = k;
    }

    std::cout << "Changed array:\n";
    printArray(array, size);

    delete[] newArray;
    delete[] array;

    return 0;
}

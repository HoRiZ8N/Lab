#include <iostream>
#include <algorithm>
#include <cstdlib> // Для rand()
#include <ctime>   // Для srand()

enum InitializationType
{
    KeyboardInput = 1,
    RandomGeneration = 2
};

template <typename T>
void mergeSort(T* a, unsigned int start, unsigned int end)
{
    if (end - start < 2)
        return;

    if (end - start == 2)
    {
        if (a[start] > a[start + 1])
            std::swap(a[start], a[start + 1]);
        return;
    }

    unsigned int mid = start + (end - start) / 2;
    mergeSort(a, start, mid);
    mergeSort(a, mid, end);

    // Временный массив для хранения результатов слияния
    T* temp = new T[end - start];
    unsigned int b1 = start;
    unsigned int e1 = mid;
    unsigned int b2 = mid;
    unsigned int idx = 0;

    // Слияние двух отсортированных частей
    while (b1 < e1 && b2 < end)
    {
        if (a[b1] <= a[b2])
        {
            temp[idx++] = a[b1++];
        }
        else
        {
            temp[idx++] = a[b2++];
        }
    }

    // Копируем оставшиеся элементы
    while (b1 < e1)
    {
        temp[idx++] = a[b1++];
    }
    while (b2 < end)
    {
        temp[idx++] = a[b2++];
    }

    // Копируем обратно в массив
    for (unsigned int i = 0; i < end - start; ++i)
    {
        a[start + i] = temp[i];
    }

    delete[] temp;
}

template <typename T>
void fillArray(T* arr, unsigned int size, InitializationType fillType)
{
    switch (fillType)
    {
    case InitializationType::KeyboardInput:
        std::cout << "Enter " << size << " values: ";
        for (unsigned int i = 0; i < size; i++)
        {
            std::cin >> arr[i];
        }
        break;
    case InitializationType::RandomGeneration:
        srand(time(0));
        for (unsigned int i = 0; i < size; i++)
        {
            arr[i] = rand() % 100;
        }
        break;
    default:
        std::cerr << "Invalid initialization type.\n";
        exit(1);
    }
}

int main()
{
    InitializationType fillType;
    unsigned int size;

    std::cout << "Enter array size: ";
    std::cin >> size;

    std::cout << "Choose initialization method:\n"
              << InitializationType::KeyboardInput << ": Keyboard\n"
              << InitializationType::RandomGeneration << ": Random generation\n";
    int choice;
    std::cin >> choice;
    
    InitializationType initType = static_cast<InitializationType>(choice);

    int* arr = new int[size];

    fillArray(arr, size, initType);

    std::cout << "Array before sorting: ";
    for (unsigned int i = 0; i < size; ++i)
    {
        std::cout << arr[i] << ' ';
    }
    std::cout << '\n';

    mergeSort(arr, 0, size);

    std::cout << "Array after sorting: ";
    for (unsigned int i = 0; i < size; ++i)
    {
        std::cout << arr[i] << ' ';
    }
    std::cout << '\n';

    delete[] arr;

    return 0;
}

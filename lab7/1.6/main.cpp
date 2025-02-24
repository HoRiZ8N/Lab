#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <cstring>

enum DataTypes
{
    int_type = 1,
    double_type,
    string_type,
    char_type
};



template <typename T>
void mergeSort(T *a, unsigned int start, unsigned int end)
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
    T *temp = new T[end - start];
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

void mergeSort(char* a[], unsigned int start, unsigned int end)
{
    if (end - start < 2)
        return;

    if (end - start == 2)
    {
        if (strcmp(a[start], a[start + 1]) > 0)
        {
            std::swap(a[start], a[start + 1]);
        }
        return;
    }

    unsigned int mid = start + (end - start) / 2;
    mergeSort(a, start, mid);
    mergeSort(a, mid, end);

    // Временный массив для хранения результатов слияния
    char** temp = new char*[end - start];
    unsigned int b1 = start;
    unsigned int e1 = mid;
    unsigned int b2 = mid;
    unsigned int idx = 0;

    // Слияние двух отсортированных частей
    while (b1 < e1 && b2 < end)
    {
        if (strcmp(a[b1], a[b2]) <= 0)
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
void fillArray(T arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        std::cin >> arr[i];
    }
}

void fillArray(char* arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        std::cin >> arr[i];
    }
}

template <typename T>
void printArray(T arr[], int size)
{
    for (int i = 0; i < size; i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
}

void printArray(char *arr[], int size)
{
    for (int i = 0; i < size; i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
}

int main()
{
    unsigned int size;

    std::cout << "Enter array size: ";
    std::cin >> size;

    std::cout << "Choose data type:\n"
              << DataTypes::int_type << ": integer\n"
              << DataTypes::double_type << ": double\n"
              << DataTypes::char_type << ": char\n"
              << DataTypes::string_type << ": string\n";
    int choice;
    std::cin >> choice;

    DataTypes dataType = static_cast<DataTypes>(choice);

    if (dataType == DataTypes::int_type)
    {
        int *arr = new int[size];
        std::cout << "Enter " << size << " values:\n";
        fillArray(arr, size);
        std::cout << "Array before sorting:\n";
        printArray(arr, size);
        mergeSort(arr, 0, size);
        std::cout << "Array after sorting:\n";
        printArray(arr, size);
        delete[] arr;
    }

    else if (dataType == DataTypes::double_type)
    {
        double *arr = new double[size];
        std::cout << "Enter " << size << " values:\n";
        fillArray(arr, size);
        std::cout << "Array before sorting:\n";
        printArray(arr, size);
        mergeSort(arr, 0, size);
        std::cout << "Array after sorting:\n";
        printArray(arr, size);
        delete[] arr;
    }

    else if (dataType == DataTypes::char_type)
    {
        char *arr = new char[size];
        std::cout << "Enter " << size << " values:\n";
        fillArray(arr, size);
        std::cout << "Array before sorting:\n";
        printArray(arr, size);
        mergeSort(arr, 0, size);
        std::cout << "Array after sorting:\n";
        printArray(arr, size);
        delete[] arr;
    }

    else if (dataType == DataTypes::string_type)
    {
        const unsigned int MAX_STRING_SIZE = 1000;
        char **arr = new char *[size];
        for (int i = 0; i < size; i++)
        {
            arr[i] = new char[MAX_STRING_SIZE];
        }
        std::cout << "Enter " << size << " values:\n";
        fillArray(arr, size);
        std::cout << "Array before sorting:\n";
        printArray(arr, size);
        mergeSort(arr, 0, size);
        std::cout << "Array after sorting:\n";
        printArray(arr, size);
        for (int i = 0; i < size; i++)
        {
            delete[] arr[i];
        }
        delete[] arr;
    }

    return 0;
}

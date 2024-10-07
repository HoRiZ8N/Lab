#include <iostream>

enum ArrayFill
{
    keyboard,
    random
};

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        std::cout << arr[i] << '\n';
    }
}

int main()
{
    int n1, n2;
    ArrayFill type = keyboard; // Array fill variant

    std::cout << "\nSelect first array size: ";
    std::cin >> n1;
    int* arr1 = new int[n1];

    std::cout << "\nSelect second array size: ";
    std::cin >> n2;
    int* arr2 = new int[n2];

    switch (type) // Initialization of arrays
    {
    case keyboard:

        std::cout << "\nPrint " << n1 << " numbers in ascending order: ";
        for (int i = 0; i < n1; i++)
        {
            std::cin >> arr1[i];
        }

        std::cout << "\nPrint " << n2 << " numbers in ascending order: ";
        for (int i = 0; i < n2; i++)
        {
            std::cin >> arr2[i];
        }
        break;

    case random:
        srand(123);

        arr1[0] = rand();
        for (int i = 1; i < n1; i++)
        {
            int temp = rand();
            while (temp < arr1[i - 1])
            {
                temp = rand();
            }
            arr1[i] = temp;
        }

        arr2[0] = rand();
        for (int i = 1; i < n2; i++)
        {
            int temp = rand();
            while (temp < arr2[i - 1])
            {
                temp = rand();
            }
            arr2[i] = temp;
        }
        break;

    default:
        std::cout << "No such option found.";
        return 0;
    }

    int* new_arr = new int[n1 + n2];

    int i = 0, j = 0, k = 0;
    while (i < n1 && j < n2) //creating new sorted array
    {
        if (arr1[i] > arr2[j])
        {
            new_arr[k++] = arr2[j++];
        } else {
            new_arr[k++] = arr1[i++];
        }
    }
    if (i < n1) {
        for (int p = i; p < n1; p++) {
            new_arr[k++] = arr1[p];
        }
    } else {
        for (int p = j; p < n2; p++) {
            new_arr[k++] = arr2[p];
        }
    }
        
    std::cout << "\nFirst array:\n";
    printArray(arr1, n1);
    std::cout << '\n';
    std::cout << "Second array:\n";
    printArray(arr2, n2);
    std::cout << '\n';
    std::cout << "New array:\n";
    printArray(new_arr, n1 + n2);
    std::cout << '\n';


    delete [] arr1;
    delete [] arr2;
    delete [] new_arr;

    return 0;
}
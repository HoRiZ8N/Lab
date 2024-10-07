#include "header.hpp"
#include <iostream>
#include <stdio.h>

void selectionSort(int *arr, int size)
{
    int permutation = 0, comp = 0;
    for (int i = 0; i < size; i++)
    {
        int min_ind = i;
        for (int j = i + 1; j < size; j++)
        {
            comp++;
            if (arr[min_ind] > arr[j])
            {
                min_ind = j;
            }
        }
        if (i != min_ind)
        {
            std::swap(*(arr + i), *(arr + min_ind));
            permutation++;
        }
    }
    std::cout << "Amount of comparisons: " << comp << "\nAmount of permutations: " << permutation << '\n';
}

void selectionSort(float *arr, int size)
{
    int permutation = 0, comp = 0;
    for (int i = 0; i < size; i++)
    {
        int min_ind = i;
        for (int j = i + 1; j < size; j++)
        {
            comp++;
            if (arr[min_ind] > arr[j])
            {
                min_ind = j;
            }
        }
        if (i != min_ind)
        {
            std::swap(*(arr + i), *(arr + min_ind));
            permutation++;
        }
    }
    std::cout << "Amount of comparisons: " << comp << "\nAmount of permutations: " << permutation << '\n';
}

void selectionSort(double *arr, int size)
{
    int permutation = 0, comp = 0;
    for (int i = 0; i < size; i++)
    {
        int min_ind = i;
        for (int j = i + 1; j < size; j++)
        {
            comp++;
            if (arr[min_ind] > arr[j])
            {
                min_ind = j;
            }
        }
        if (i != min_ind)
        {
            std::swap(*(arr + i), *(arr + min_ind));
            permutation++;
        }
    }
    std::cout << "Amount of comparisons: " << comp << "\nAmount of permutations: " << permutation << '\n';
}

void selectionSort(char *arr, int size)
{
    int permutation = 0, comp = 0;
    for (int i = 0; i < size; i++)
    {
        int min_ind = i;
        for (int j = i + 1; j < size; j++)
        {
            comp++;
            if (arr[min_ind] > arr[j])
            {
                min_ind = j;
            }
        }
        if (i != min_ind)
        {
            std::swap(*(arr + i), *(arr + min_ind));
            permutation++;
        }
    }
    std::cout << "Amount of comparisons: " << comp << "\nAmount of permutations: " << permutation << '\n';
}

void bubbleSort(int *arr, int size)
{
    int permutation = 0, comp = 0;
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            comp++;
            if (*(arr + j) > *(arr + j + 1))
            {
                std::swap(*(arr + j), *(arr + j + 1));
                permutation++;
            }
        }
    }
    std::cout << "Amount of comparisons: " << comp << "\nAmount of permutations: " << permutation << '\n';
}

void bubbleSort(float *arr, int size)
{
    int permutation = 0, comp = 0;
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            comp++;
            if (*(arr + j) > *(arr + j + 1))
            {
                std::swap(*(arr + j), *(arr + j + 1));
                permutation++;
            }
        }
    }
    std::cout << "Amount of comparisons: " << comp << "\nAmount of permutations: " << permutation << '\n';
}

void bubbleSort(double *arr, int size)
{
    int permutation = 0, comp = 0;
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            comp++;
            if (*(arr + j) > *(arr + j + 1))
            {
                std::swap(*(arr + j), *(arr + j + 1));
                permutation++;
            }
        }
    }
    std::cout << "Amount of comparisons: " << comp << "\nAmount of permutations: " << permutation << '\n';
}

void bubbleSort(char *arr, int size)
{
    int permutation = 0, comp = 0;
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            comp++;
            if (*(arr + j) > *(arr + j + 1))
            {
                std::swap(*(arr + j), *(arr + j + 1));
                permutation++;
            }
        }
    }
    std::cout << "Amount of comparisons: " << comp << "\nAmount of permutations: " << permutation << '\n';
}

void randomFill(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        *(arr + i) = rand();
    }
}

void randomFill(float *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        *(arr + i) = (float)rand() / 10000 + rand();
    }
}

void randomFill(double *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        *(arr + i) = (double)rand() / 100000 + rand();
    }
}

void randomFill(char *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        *(arr + i) = rand() % 256 - 128;
    }
}

void increasingFill(int *arr, int size)
{
    *arr = rand();
    for (int i = 1; i < size; i++)
    {
        int num = rand();
        while (num <= *(arr + i - 1))
        {
            num = rand();
        }
        *(arr + i) = num;
    }
}

void increasingFill(float *arr, int size)
{
    *arr = (float)rand() / 100000 + rand();
    for (int i = 1; i < size; i++)
    {
        float num = (float)rand() / 100000 + rand();
        while (num <= *(arr + i - 1))
        {
            num = (float)rand() / 100000 + rand();
        }
        *(arr + i) = num;
    }
}

void increasingFill(double *arr, int size)
{
    *arr = (double)rand() / 10000000 + rand();
    for (int i = 1; i < size; i++)
    {
        double num = (double)rand() / 10000000 + rand();
        while (num <= *(arr + i - 1))
        {
            num = (double)rand() / 10000000 + rand();
        }
        *(arr + i) = num;
    }
}

void increasingFill(char *arr, int size)
{
    *arr = rand() % 256 - 128;
    for (int i = 1; i < size; i++)
    {
        char num = rand() % 256 - 128;
        while (num <= *(arr + i - 1))
        {
            num = rand() % 256 - 128;
        }
        *(arr + i) = num;
    }
}

void decreasingFill(int *arr, int size)
{
    *arr = rand();
    for (int i = 1; i < size; i++)
    {
        int num = rand();
        while (num >= *(arr + i - 1))
        {
            num = rand();
        }
        *(arr + i) = num;
    }
}

void decreasingFill(float *arr, int size)
{
    *arr = (float)rand() / 100000 + rand();
    for (int i = 1; i < size; i++)
    {
        float num = (float)rand() / 100000 + rand();
        while (num >= *(arr + i - 1))
        {
            num = (float)rand() / 100000 + rand();
        }
        *(arr + i) = num;
    }
}

void decreasingFill(double *arr, int size)
{
    *arr = (double)rand() / 100000 + rand();
    for (int i = 1; i < size; i++)
    {
        double num = (double)rand() / 100000 + rand();
        while (num >= *(arr + i - 1))
        {
            num = (double)rand() / 100000 + rand();
        }
        *(arr + i) = num;
    }
}

void decreasingFill(char *arr, int size)
{
    *arr = rand() % 256 - 128;
    for (int i = 1; i < size; i++)
    {
        char num = rand() % 256 - 128;
        while (num >= *(arr + i - 1))
        {
            num = rand() % 256 - 128;
        }
        *(arr + i) = num;
    }
}

void printArray(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        std::cout << *(arr + i) << '\n';
    }
}

void printArray(float *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        std::cout << *(arr + i) << '\n';
    }
}

void printArray(double *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        std::cout << *(arr + i) << '\n';
    }
}

void printArray(char *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        std::cout << (char)*(arr + i) << '\n';
    }
}

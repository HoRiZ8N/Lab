#include "header.hpp"
#include <iostream>

int main()
{

    srand(time(0));
    std::cout << std::fixed;

    int size;
    // std::cout << "Enter array size: ";
    // std::cin >> size;

    size = 100;

    short variableType = 3;
    // std::cout << "\nEnter variable type:\n1.Int\n2.Float\n3.Doable\n4.Char\n";
    // std::cin >> variableType;

    int *int_arr = new int[size];
    float *float_arr = new float[size];
    double *double_arr = new double[size];
    char *char_arr = new char[size];

    short fillType = 1;
    // std::cout << "\nSelect fill type:\n1.Random\n2.Increasing\n3.Decreasing\n";
    // std::cin >> fillType;

    short sortType = 2;
    // std::cout << "\nSelect sort type:\n1.Bubble\n2.Selection\n";
    // std::cin >> sortType;

    switch (variableType)
    {
    case 1:
        switch (fillType)
        {
        case 1:
            randomFill(int_arr, size);
            break;

        case 2:
            increasingFill(int_arr, size);
            break;

        case 3:
            decreasingFill(int_arr, size);
            break;

        default:
            break;
        }

        switch (sortType)
        {
        case 1:
            bubbleSort(int_arr, size);
            break;

        case 2:
            selectionSort(int_arr, size);
            break;

        default:
            break;
        }

        printArray(int_arr, size);

        break;

    case 2:

        switch (fillType)
        {
        case 1:
            randomFill(float_arr, size);
            break;

        case 2:
            increasingFill(float_arr, size);
            break;

        case 3:
            decreasingFill(float_arr, size);
            break;

        default:
            break;
        }

        switch (sortType)
        {
        case 1:
            bubbleSort(float_arr, size);
            break;

        case 2:
            selectionSort(float_arr, size);
            break;

        default:
            break;
        }

        printArray(float_arr, size);

        break;

    case 3:

        switch (fillType)
        {
        case 1:
            randomFill(double_arr, size);
            break;

        case 2:
            increasingFill(double_arr, size);
            break;

        case 3:
            decreasingFill(double_arr, size);
            break;

        default:
            break;
        }

        switch (sortType)
        {
        case 1:
            bubbleSort(double_arr, size);
            break;

        case 2:
            selectionSort(double_arr, size);
            break;

        default:
            break;
        }

        printArray(double_arr, size);

        break;

    case 4:
        switch (fillType)
        {
        case 1:
            randomFill(char_arr, size);
            break;

        case 2:
            increasingFill(char_arr, size);
            break;

        case 3:
            decreasingFill(char_arr, size);
            break;

        default:
            break;
        }

        switch (sortType)
        {
        case 1:
            bubbleSort(char_arr, size);
            break;

        case 2:
            selectionSort(char_arr, size);
            break;

        default:
            break;
        }

        printArray(char_arr, size);

        break;

    default:
        break;
    }

    delete[] float_arr;
    delete[] int_arr;
    delete[] double_arr;
    delete[] char_arr;
    return 0;
}
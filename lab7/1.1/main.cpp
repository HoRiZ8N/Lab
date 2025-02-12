#include <iostream>

constexpr int randNum = 100;

enum InitializationType
{
    KeyboardInput = 1,
    RandomGeneration = 2,
    ConstValues = 3
};

int** initializeMatrix(int size)
{
    int** matrix = new int*[size];
    for (int i = 0; i < size; i++)
    {
        matrix[i] = new int[size];
    }
    return matrix;
}

void getValues(int *array, int size, int choice)
{
    if (choice == KeyboardInput)
    {
        std::cout << "Enter " << size * size << " numbers:\n";
        for (int i = 0; i < size * size; i++)
        {
            std::cin >> array[i];
        }
    }
    else if (choice == RandomGeneration)
    {
        for (int i = 0; i < size * size; i++)
        {
            array[i] = rand() % randNum;
        }
    }
    else if(choice = ConstValues)
    {
        for (int i = 0; i < size * size; i++)
        {
            array[i] = i + 1;
        }
    }
    else 
    {
        std::cerr << "[ERROR] Invalid choice\n";
    }
}

void deleteMatrix(int **matrix, int size)
{
    for (int i = 0; i < size; i++)
    {
        delete[] matrix[i];
    }
    delete[] matrix;
}

void fillMatrix(int **matrix, int* values, int size)
{
    int top = 0, bottom = size - 1, left = 0, right = size - 1;
    int index = 0;

    while (left <= right && top <= bottom)
    {
        for (int i = top; i <= bottom; i++) // Движение вниз
            matrix[i][left] = values[index++];
        left++;

        for (int j = left; j <= right; j++) // Движение вправо
            matrix[bottom][j] = values[index++];
        bottom--;

        if (left <= right)
        {
            for (int i = bottom; i >= top; i--) // Движение вверх
                matrix[i][right] = values[index++];
            right--;
        }

        if (top <= bottom)
        {
            for (int j = right; j >= left; j--) // Движение влево
                matrix[top][j] = values[index++];
            top++;
        }
    }
}

void printMatrix(int** matrix, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            std::cout << matrix[i][j] << ' ';
        }
        std::cout << '\n';
    }
}

void printValues(int* values, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            std::cout << values[i * size + j] << " ";
        }
        std::cout << "\n";
    }
    std::cout << "\n";
}

int main()
{

    int size;

    std::cout << "Enter size of your matrix\n";
    std::cin >> size;

    int* values = new int [size * size];
    int** matrix = initializeMatrix(size);
    int choice;

    std::cout << "Choose initialization method:\n" << 
        InitializationType::KeyboardInput << ": Keyboard\n" <<
        InitializationType::RandomGeneration << ": Random generation\n" <<
        InitializationType::ConstValues << ": Constant numbers\n";
    std::cin >> choice;

    getValues(values, size, choice);
    printValues(values, size);
    fillMatrix(matrix, values, size);
    printMatrix(matrix, size);
    deleteMatrix(matrix, size);
    delete[] values;

    return 0;
}

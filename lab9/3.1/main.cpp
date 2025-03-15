#include <iostream>
#include <fstream>
#include <string>
#include <time.h>

bool isEven(int num)
{
    return num % 2 == 0;
}

void generateFile(const std::string &inputFile, const unsigned int size)
{
    if (!isEven(size))
    {
        std::cerr << "Size must be even!" << std::endl;
        return;
    }

    std::ofstream file(inputFile);
    if (!file.is_open())
    {
        std::cerr << "Error opening file!" << std::endl;
        return;
    }

    int evens = size / 2, odds = size / 2;
    srand(time(0));
    while (evens > 0 || odds > 0)
    {
        int num = rand() % 1000;
        if (isEven(num) && evens == 0)
        {
            continue;
        }
        if (!isEven(num) && odds == 0)
        {
            continue;
        }
        isEven(num) ? evens-- : odds--;
        file << num << ' ';
    }
}

void printFile(const std::string &fileName)
{
    int num;
    std::ifstream file(fileName);
    while (file >> num)
    {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

void createFile(const std::string &inputFile, const std::string &outputFile)
{
    std::ifstream input(inputFile);
    std::ofstream output(outputFile);

    if (!input.is_open() || !output.is_open())
    {
        std::cerr << "Error opening file!" << std::endl;
        return;
    }

    // Первое прохождение: считаем общее количество четных и нечетных чисел
    int evenCount = 0, oddCount = 0, number;
    while (input >> number)
    {
        isEven(number) ? ++evenCount : ++oddCount;
    }

    // Проверяем равное количество четных и нечетных чисел
    if (evenCount != oddCount)
    {
        std::cerr << "The file cannot be generated because the number of even and odd numbers does not match!" << std::endl;
        return;
    }

    // Возвращаемся в начало файла
    input.clear();
    input.seekg(0);

    std::ifstream evenStream(inputFile);
    std::ifstream oddStream(inputFile);

    // Чередуем числа и записываем в выходной файл
    for (int i = 0; i < evenCount * 2; ++i)
    {
        if (isEven(i))
        {
            while (evenStream >> number && !isEven(number)) {}
        }
        else
        {
            while (oddStream >> number && isEven(number)) {}
        }
        output << number << " ";
    }
}

int main()
{
    generateFile("f.txt", 10);
    createFile("f.txt", "g.txt");
    printFile("f.txt");
    printFile("g.txt");
    return 0;
}

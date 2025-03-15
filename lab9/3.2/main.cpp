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

    std::ofstream file(inputFile, std::ios::binary);
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
        file.write(reinterpret_cast<char*>(&num), sizeof(num));
    }
}

void printFile(const std::string &fileName)
{
    int num;
    std::ifstream file(fileName, std::ios::binary);
    while (file.read(reinterpret_cast<char*>(&num), sizeof(num)))
    {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

void createFile(const std::string &inputFile, const std::string &outputFile)
{
    std::ifstream input(inputFile, std::ios::binary);
    std::ofstream output(outputFile, std::ios::binary);

    if (!input.is_open() || !output.is_open())
    {
        std::cerr << "Error opening file!" << std::endl;
        return;
    }

    // Первое прохождение: считаем общее количество четных и нечетных чисел
    int evenCount = 0, oddCount = 0, number;
    while (input.read(reinterpret_cast<char*>(&number), sizeof(number)))
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

    std::ifstream evenStream(inputFile, std::ios::binary);
    std::ifstream oddStream(inputFile, std::ios::binary);

    // Чередуем числа и записываем в выходной файл
    for (int i = 0; i < evenCount * 2; ++i)
    {
        if (isEven(i))
        {
            while (evenStream.read(reinterpret_cast<char*>(&number), sizeof(number)) && !isEven(number)) {}
        }
        else
        {
            while (oddStream.read(reinterpret_cast<char*>(&number), sizeof(number)) && isEven(number)) {}
        }
        output.write(reinterpret_cast<char*>(&number), sizeof(number));
    }
}

int main()
{
    generateFile("f.dat", 10);
    createFile("f.dat", "g.dat");
    printFile("f.dat");
    printFile("g.dat");
    return 0;
}

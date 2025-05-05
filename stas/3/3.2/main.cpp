#include <iostream>
#include <fstream>
#include <string>
#include <ctime>

void generateFile(const std::string &inputFile, const unsigned int size)
{
    std::ofstream file(inputFile, std::ios::binary);
    if (!file.is_open())
    {
        std::cerr << "Error opening file!" << std::endl;
        return;
    }

    int positives = size / 2, negatives = size / 2;
    srand(static_cast<unsigned int>(time(0)));

    while (positives || negatives)
    {
        int num = rand() % 2001 - 1000; // от -1000 до 1000
        if (num >= 0 && !positives)
            continue;
        if (num < 0 && !negatives)
            continue;

        if (num >= 0)
            --positives;
        else
            --negatives;

        file.write(reinterpret_cast<char*>(&num), sizeof(int));
    }
}

void printFile(const std::string &fileName)
{
    std::ifstream file(fileName, std::ios::binary);
    if (!file.is_open())
    {
        std::cerr << "Error opening file!" << std::endl;
        return;
    }

    int number;
    while (file.read(reinterpret_cast<char*>(&number), sizeof(int)))
    {
        std::cout << number << " ";
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

    int number;
    while (input.read(reinterpret_cast<char*>(&number), sizeof(int)))
    {
        if (number >= 0)
        {
            output.write(reinterpret_cast<char*>(&number), sizeof(int));
        }
    }

    input.clear();
    input.seekg(0);

    while (input.read(reinterpret_cast<char*>(&number), sizeof(int)))
    {
        if (number < 0)
        {
            output.write(reinterpret_cast<char*>(&number), sizeof(int));
        }
    }
}

int main()
{
    generateFile("f.bin", 10);
    createFile("f.bin", "g.bin");
    std::cout << "f.bin: ";
    printFile("f.bin");
    std::cout << "g.bin: ";
    printFile("g.bin");
    return 0;
}

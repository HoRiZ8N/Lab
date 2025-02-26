#include <iostream>
#include <cstdlib>
#include <ctime>
#include "LinkedList.h"

enum InitializationType
{
    KeyboardInput = 1,
    RandomGeneration = 2
};

template <typename T>
void fillList(LinkedList<T>& list, int arrSize, InitializationType initType)
{
    switch (initType)
    {
    case InitializationType::RandomGeneration:
        srand(time(0));
        for (int i = 0; i < arrSize; i++)
        {
            char s = rand() % 94 + 33; // Limiting to printable characters
            list.add(s);
        }
        break;

    case InitializationType::KeyboardInput:
        std::cout << "Enter " << arrSize << " characters:\n";
        for (int i = 0; i < arrSize; i++)
        {
            char s;
            std::cin >> s;
            list.add(s);
        }
        break;

    default:
        std::cerr << "[ERROR] Invalid initialization method.\n";
        exit(0);
    }
}

int main()
{
    int arrSize;
    std::cout << "Enter array size: ";
    std::cin >> arrSize;
    std::cout << "Choose initialization method:\n"
              << InitializationType::KeyboardInput << ": Keyboard\n"
              << InitializationType::RandomGeneration << ": Random generation\n";
    int choice;
    std::cin >> choice;
    InitializationType initType = static_cast<InitializationType>(choice);

    LinkedList<char> myList(arrSize);
    fillList(myList, arrSize, initType);

    std::cout << "Values:\n";
    myList.print();
    
    LinkedList<char> listWithTwoOccurrences = myList.formListWithTwoOccurrences();

    std::cout << "\nSymbols that appear exactly twice:\n";
    myList.print();
    listWithTwoOccurrences.print();

    return 0;
}

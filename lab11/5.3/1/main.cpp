#include <iostream>
#include <list>
#include <ctime>

enum InitializationType {
    KeyboardInput = 1,
    RandomGeneration = 2
};

void printList(const std::list<char>& lst) {
    for (char symb : lst) {
        std::cout << symb << ' ';
    }
    std::cout << '\n';
}

int main() {
    int size;
    int numOfSymbols[256] = {0};
    std::list<char> symbols;

    std::cout << "Enter array size: ";
    std::cin >> size;
    std::cout << "Choose initialization method:\n"
              << InitializationType::KeyboardInput << ": Keyboard\n"
              << InitializationType::RandomGeneration << ": Random generation\n";
    int choice;
    std::cin >> choice;
    InitializationType initType = static_cast<InitializationType>(choice);

    switch (initType) {
    case InitializationType::RandomGeneration:
        srand(time(0));
        for (int i = 0; i < size; i++) {
            char s = rand() % 94 + 33; 
            symbols.push_back(s);
            numOfSymbols[static_cast<unsigned char>(s)]++;
        }
        break;

    case InitializationType::KeyboardInput:
        std::cout << "Enter " << size << " characters:\n";
        for (int i = 0; i < size; i++) {
            char s;
            std::cin >> s;
            symbols.push_back(s);
            numOfSymbols[static_cast<unsigned char>(s)]++;
        }
        break;

    default:
        std::cerr << "[ERROR] Invalid initialization method.\n";
        return 1;
    }

    std::cout << "Values:\n";
    printList(symbols);

    std::list<char> result;
    for (char symb : symbols) {
        if (numOfSymbols[static_cast<unsigned char>(symb)] == 2) {
            result.push_back(symb);
            numOfSymbols[static_cast<unsigned char>(symb)] = 0;
        }
    }

    std::cout << "\nSymbols that appear exactly twice:\n";
    printList(result);

    return 0;
}

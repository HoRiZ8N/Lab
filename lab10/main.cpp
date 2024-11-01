#include "MyVector.h"

const unsigned long long MAXVAL = 10'000'000;

enum InitializationType {
    KeyboardInput = 1,
    RandomGeneration = 2
};

int main() {
    srand(time(0));

    MyVector<bool> vect(MAXVAL + 1);
    // std::cout << vect.Capacity() << '\n' << vect.Size();
    int choice;
    std::cout << "Choose initialization method:\n1. Keyboard input\n2. Random generation\n";
    std::cin >> choice;

    if (choice != KeyboardInput && choice != RandomGeneration) {
        std::cerr << "Invalid choice! Please restart the program and choose 1 or 2.\n";
        return 1;
    }
    if (choice == KeyboardInput)
    {
        std::cout << "Enter natural numbers (each <= 10^7):\n";
    }

    unsigned int number;
    switch (choice)
    {
    case KeyboardInput:
        while (std::cin >> number) {
            std::cin >> number;
            if (number <= 0 || number > MAXVAL) {
                std::cerr << "Number out of range! Please enter a number between 1 and " << MAXVAL << ".\n";
                continue;
            }
            vect[number] = true;
        }
        break;
    
    case RandomGeneration:
        std::cout << "Enter amount of numbers to generate: ";
        std::cin >> number;
        for (size_t i = 0; i < number; i++)
        {
            unsigned long num;
            num = rand() % MAXVAL + 1;
            vect[num] = true;
        }
        break;
    }

    std::cout << "Missing numbers (up to " << MAXVAL << "):" << '\n';
    for (int i = 1; i <= MAXVAL; i++) {
        if (!vect[i]) {
            std::cout << i << " ";
            if (i % 10 == 0) {
                std::cout << '\n'; 
            }
        }
    }
    std::cout << '\n';

    return 0;
}
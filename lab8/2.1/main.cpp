#include <iostream>

const int MAXVAL = 10'000'000;

enum InitializationType {
    KeyboardInput = 1,
    RandomGeneration = 2
};

int main() {
    srand(time(0));
    long long n;
    std::cout << "Enter the length of the sequence (n <= 10^12): ";
    std::cin >> n;

    bool* present = new bool[MAXVAL + 1]();

    int choice;
    std::cout << "Choose initialization method:\n1. Keyboard input\n2. Random generation\n";
    std::cin >> choice;

    if (choice != KeyboardInput && choice != RandomGeneration) {
        std::cerr << "Invalid choice! Please restart the program and choose 1 or 2.\n";
        delete[] present;
        return 1;
    }
    if (choice == KeyboardInput)
    {
        std::cout << "Enter " << n << " natural numbers (each <= 10^7):\n";
    }
    for (long long i = 0; i < n; ++i) {
        int number;
        if (choice == KeyboardInput) {
            std::cin >> number;
            if (number <= 0 || number > MAXVAL) {
                std::cerr << "Number out of range! Please enter a number between 1 and " << MAXVAL << ".\n";
                --i;
                continue;
            }
        } else {
            number = rand() % MAXVAL + 1;
        }

        present[number] = true;
    }

    std::cout << "Missing numbers (up to " << MAXVAL << "):" << '\n';
    for (int i = 1; i <= MAXVAL; i++) {
        if (!present[i]) {
            std::cout << i << " ";
            if (i % 10 == 0) {
                std::cout << '\n'; 
            }
        }
    }
    std::cout << '\n';

    delete[] present;

    return 0;
}

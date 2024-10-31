#include <fstream>
#include <iostream>

bool isEven(int num) {
    return num % 2 == 0;
}

int main() {
    std::ifstream input;
    std::ofstream output;
    input.open("input.txt");
    output.open("output.txt");
    if (!input.is_open() || !output.is_open()) {
        std::cerr << "Error opening file.\n";
        return 1;
    }
    int count = 0;

    int num;
    while (input >> num) {
        if (isEven(num)) {
            count++;
        } else {
            count--;
        }
    }
    if (count) {
        std::cerr << "The number of even and odd numbers is not equal.\n";
    }
    input.clear(); 
    input.seekg(0, input.beg);
    if (!(input >> num)) {
        std::cerr << "File is empty or invalid data.\n";
        return 1;
    }
    output << num << '\n';
    bool isPrevEven = isEven(num);
    while (input >> num) {
        if (isEven(num) != isPrevEven) {
            output << num << '\n';
        }
        isPrevEven = isEven(num);
    }
    input.close();
    output.close();
    std::cout << "File processed successfully.\n";

    return 0;
}
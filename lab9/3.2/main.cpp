#include <fstream>
#include <iostream>

bool isEven(int num) {
    return num % 2 == 0;
}

int main() {
    std::ifstream input;
    std::ofstream output;
    input.open("input.dat", std::ios_base::binary);
    output.open("output.dat", std::ios_base::binary);
    if (!input.is_open() || !output.is_open()) {
        std::cerr << "Error opening file.\n";
        return 1;
    }
    int count = 0;

    int num;
    while (input.read(reinterpret_cast<char*>(&num), sizeof(num))) {
        if (isEven(num)) {
            count++;
        } else {
            count--;
        }
    }
    if (count != 0) {
        std::cerr << "Warning: The number of even and odd numbers is not equal.\n";
    }
    input.clear();
    input.seekg(0, input.beg);
    if (!input.read(reinterpret_cast<char*>(&num), sizeof(num))) {
        std::cerr << "File is empty or invalid data.\n";
        return 1;
    }
    output.write(reinterpret_cast<char*>(&num), sizeof(num));
    bool isPrevEven = isEven(num);
    while (input.read(reinterpret_cast<char*>(&num), sizeof(num))) {
        if (isEven(num) != isPrevEven) {
            output.write(reinterpret_cast<char*>(&num), sizeof(num));
        }
        isPrevEven = isEven(num);
    }

    input.close();
    output.close();
    
    std::ifstream binaryInput("output.dat", std::ios_base::binary);
    std::ofstream textOutput("output.txt");

    if (!binaryInput.is_open() || !textOutput.is_open()) {
        std::cerr << "Error opening output.dat or output.txt.\n";
        return 1;
    }

    while (binaryInput.read(reinterpret_cast<char*>(&num), sizeof(num))) {
        textOutput << num << ' ';
    }

    
    std::cout << "File processed successfully.\n";

    return 0;
}
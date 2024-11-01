#include <fstream>
#include <iostream>
#include <cstring>
#include <string>

const int STRING_SIZE = 100;

struct {
    char name[STRING_SIZE];
    int age;
    char gender[STRING_SIZE];
    int year;
    double mark;
} Student;

int main() {
    std::ifstream input;
    std::ofstream output;
    input.open("input.txt");
    output.open("output.txt");
    if (!input.is_open() || !output.is_open()) {
        std::cerr << "Error opening file.\n";
        return 1;
    }
    char data[STRING_SIZE];
    if (!(getline(input, data))) {
        std::cerr << "File is empty or invalid data.\n";
        return 1;
    }
    


    return 0;
}
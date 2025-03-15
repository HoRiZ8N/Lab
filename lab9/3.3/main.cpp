#include <fstream>
#include <iostream>
#include <string>

struct Student {
    char name[50];
    int age;
    char gender[10];
    int year;
    double mark;
};

void print(const Student& student, std::ofstream& output) {
    output.write(reinterpret_cast<const char*>(&student), sizeof(student));
}

void displayFileContent(const std::string& filename) {
    std::ifstream input(filename, std::ios::binary);
    if (!input.is_open()) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return;
    }

    Student student;
    while (input.read(reinterpret_cast<char*>(&student), sizeof(student))) {
        std::cout << student.name << " " << student.age << " "
                  << student.gender << " " << student.year << " "
                  << student.mark << std::endl;
    }

    input.close();
}

void processFiles(std::ifstream& input, std::ofstream& output, const char FirstChar, const int Course) {
    Student student;
    while (input.read(reinterpret_cast<char*>(&student), sizeof(student))) {
        if (student.name[0] == FirstChar && student.year == Course) {
            print(student, output);
        }
    }
}


int main() {
    std::ifstream input("input.dat", std::ios::binary);
    std::ofstream output("output.dat", std::ios::binary);

    if (!input.is_open() || !output.is_open()) {
        std::cerr << "Error opening file.\n";
        return 1;
    }
    
    processFiles(input, output, 'A', 1);
    displayFileContent("input.dat");
    displayFileContent("output.dat");

    input.close();
    output.close();

    return 0;
}


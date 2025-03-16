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

void processFiles(std::ifstream& input, std::ofstream& output, char FirstChar, int Course) {
    Student student;
    while (input.read(reinterpret_cast<char*>(&student), sizeof(student))) {
        if (student.name[0] == FirstChar && student.year == Course) {
            output.write(reinterpret_cast<const char*>(&student), sizeof(student));
        }
    }
}

void displayFileContent(const std::string& filename) {
    std::ifstream input(filename, std::ios::binary);

    if (!input.is_open()) {
        std::cerr << "Error opening file: " << filename << '\n';
        return;
    }

    Student student;
    std::cout << "Content of " << filename << ":\n";
    while (input.read(reinterpret_cast<char*>(&student), sizeof(student))) {
        std::cout << student.name << ' '
                  << student.age << ' '
                  << student.gender << ' '
                  << student.year << ' '
                  << student.mark << '\n';
    }

    std::cout << '\n';
    input.close();
}

void createInputFile(const std::string& filename) {
    std::ofstream file(filename, std::ios::binary);

    if (!file.is_open()) {
        std::cerr << "Error opening file for writing: " << filename << '\n';
        return;
    }

    Student students[] = {
        {"Alice", 20, "Female", 2, 4.5}, 
        {"Andrew", 22, "Male", 1, 3.8}, 
        {"Bob", 21, "Male", 2, 4.2},
        {"Anna", 19, "Female", 1, 4.7}, 
        {"Charlie", 23, "Male", 3, 3.9},
        {"Diana", 20, "Female", 1, 4.8}
    };

    for (const auto& student : students) {
        file.write(reinterpret_cast<const char*>(&student), sizeof(student));
    }

    file.close();
}

int main() {
    const std::string inputFile = "input.dat";
    const std::string outputFile = "output.dat";

    createInputFile(inputFile);

    std::ifstream input(inputFile, std::ios::binary);
    std::ofstream output(outputFile, std::ios::binary);

    if (!input.is_open() || !output.is_open()) {
        std::cerr << "Error opening files.\n";
        return 1;
    }

    processFiles(input, output, 'A', 1);
    input.close();
    output.close();

    displayFileContent(inputFile);
    displayFileContent(outputFile);

    return 0;
}

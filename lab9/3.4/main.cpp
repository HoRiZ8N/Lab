#include <fstream>
#include <iostream>
#include <string>

struct Student {
    std::string name;
    int age;
    std::string gender;
    int year;
    double mark;
};

void print(const Student& student, std::ofstream& output) {
    output << student.name << " " << student.age << " " 
           << student.gender << " " << student.year << " " 
           << student.mark << std::endl;
}

void displayFileContent(const std::string& filename) {
    std::ifstream input(filename);

    if (!input.is_open()) {
        std::cerr << "Error opening file: " << filename << '\n';
        return;
    }

    Student student;
    std::cout << "Content of " << filename << ":\n";
    while (input >> student.name >> student.age >> student.gender >> student.year >> student.mark) {
        std::cout << student.name << " "
                  << student.age << " "
                  << student.gender << " "
                  << student.year << " "
                  << student.mark << "\n";
    }

    std::cout << std::endl;
    input.close();
}

void processFiles(std::ifstream& input, std::ofstream& output, const char FirstChar, const int Course) {
    Student student;
    while (input >> student.name >> student.age >> student.gender >> student.year >> student.mark) {
        if (student.name[0] == FirstChar && student.year == Course) {
            print(student, output);
        }
    }
}

int main() {
    const std::string inputFile = "input.txt";
    const std::string outputFile = "output.txt";

    std::ifstream input(inputFile);
    std::ofstream output(outputFile);

    if (!input.is_open() || !output.is_open()) {
        std::cerr << "Error opening file.\n";
        return 1;
    }
    
    processFiles(input, output, 'A', 1);
    
    displayFileContent(inputFile);
    displayFileContent(outputFile);

    input.close();
    output.close();

    return 0;
}

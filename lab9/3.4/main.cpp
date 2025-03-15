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
        std::cerr << "Error opening file: " << filename << std::endl;
        return;
    }

    Student student;
    while (input >> student.name >> student.age >> student.gender >> student.year >> student.mark) {
        std::cout << student.name << " " << student.age << " "
                  << student.gender << " " << student.year << " "
                  << student.mark << std::endl;
    }
    std::cout << std::endl;
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
    std::ifstream input("input.txt");
    std::ofstream output("output.txt");

    if (!input.is_open() || !output.is_open()) {
        std::cerr << "Error opening file.\n";
        return 1;
    }
    
    processFiles(input, output, 'A', 1);
    
    displayFileContent("input.txt");
    displayFileContent("output.txt");

    input.close();
    output.close();

    return 0;
}

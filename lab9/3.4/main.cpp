#include <fstream>
#include <iostream>
#include <string>

struct Student {
    std::string name;
    int age;
    std::string gender;
    int year;
    double mark;

    void print(std::ostream &os) const {
        os << name << ' ' << age << ' ' << gender << ' ' << year << ' ' << mark << '\n';
    }
};

int main() {
    const char FirstChar = 'A';
    const int Course = 1;

    std::ifstream input("input.txt");
    std::ofstream output("output.txt");

    if (!input.is_open() || !output.is_open()) {
        std::cerr << "Error opening file.\n";
        return 1;
    }

    std::string data;
    Student student;


    while (input >> student.name >> student.age >> student.gender >> student.year >> student.mark) {
        if (student.name[0] == FirstChar && student.year == Course)
        {
            student.print(output);  
        }
    }

    return 0;
}

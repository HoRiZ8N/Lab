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

    void writeToBinary(std::ofstream &out) const {
        size_t nameLen = name.size();
        out.write(reinterpret_cast<const char*>(&nameLen), sizeof(nameLen));
        out.write(name.c_str(), nameLen);

        out.write(reinterpret_cast<const char*>(&age), sizeof(age));

        size_t genderLen = gender.size();
        out.write(reinterpret_cast<const char*>(&genderLen), sizeof(genderLen));
        out.write(gender.c_str(), genderLen);

        out.write(reinterpret_cast<const char*>(&year), sizeof(year));
        out.write(reinterpret_cast<const char*>(&mark), sizeof(mark));
    }

    void readFromBinary(std::ifstream &in) {
        size_t nameLen;
        in.read(reinterpret_cast<char*>(&nameLen), sizeof(nameLen));
        name.resize(nameLen);
        in.read(&name[0], nameLen);

        in.read(reinterpret_cast<char*>(&age), sizeof(age));

        size_t genderLen;
        in.read(reinterpret_cast<char*>(&genderLen), sizeof(genderLen));
        gender.resize(genderLen);
        in.read(&gender[0], genderLen);

        in.read(reinterpret_cast<char*>(&year), sizeof(year));
        in.read(reinterpret_cast<char*>(&mark), sizeof(mark));
    }
};

int main() {
    const char FirstChar = 'A';
    const int Course = 1;

    std::ifstream input("input.dat", std::ios::binary);
    std::ofstream output("output.dat", std::ios::binary);

    if (!input.is_open() || !output.is_open()) {
        std::cerr << "Error opening file.\n";
        return 1;
    }

    Student student;

    while (input.peek() != EOF) {
        student.readFromBinary(input);
        if (student.name[0] == FirstChar && student.year == Course) {
            student.writeToBinary(output);
        }
    }

    return 0;
}

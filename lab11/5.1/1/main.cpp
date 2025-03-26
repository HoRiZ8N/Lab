#include <iostream>
#include <string>

void removeSingleCharacters(std::string& text) {
    int charOcc[256]{};

    for (char ch : text) {
        charOcc[static_cast<unsigned char>(ch)]++;
    }

    std::string result;
    for (char ch : text) {
        if (charOcc[static_cast<unsigned char>(ch)] > 1) {
            result += ch;
        }
    }

    text = result;
}

int main() {
    std::string inputText;
    std::cout << "Enter text: ";
    std::getline(std::cin, inputText);

    removeSingleCharacters(inputText);
    std::cout << "Result: " << inputText << std::endl;

    return 0;
}

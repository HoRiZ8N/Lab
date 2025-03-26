#include <iostream>
#include <string>
#include <vector>
#include <cassert>

bool isEvenLength(const std::string& word) {
    return word.length() % 2 == 0;
}

bool isSymmetrical(const std::string& word) {
    size_t len = word.length();
    for (size_t i = 0; i < len / 2; ++i) {
        if (word[i] != word[len - i - 1]) {
            return false;
        }
    }
    return true;
}

std::vector<std::string> splitIntoWords(const std::string& text, const std::string& delimiters) {
    std::vector<std::string> words;
    size_t start = 0, end = 0;
    while ((end = text.find_first_of(delimiters, start)) != std::string::npos) {
        if (end > start) {
            words.push_back(text.substr(start, end - start));
        }
        start = end + 1;
    }
    if (start < text.size()) {
        words.push_back(text.substr(start));
    }
    return words;
}

std::string processText(const std::string& text) {
    const std::string delimiters = " .,:;!?-()";
    std::vector<std::string> words = splitIntoWords(text, delimiters);
    std::string result;

    for (const std::string& word : words) {
        if (isEvenLength(word) && !isSymmetrical(word)) {
            if (!result.empty()) {
                result += " "; 
            }
            result += word;
        }
    }

    return result;
}

int main() {
    std::string inputText;
    std::cout << "Enter text: ";
    std::getline(std::cin, inputText);

    std::string result = processText(inputText);
    std::cout << "Asymmetrical words with even length: " << result << std::endl;
    
    return 0;
}

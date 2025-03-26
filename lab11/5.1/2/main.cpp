#include <iostream>
#include <string>
#include <cmath>

std::string binaryToDecimal(const std::string& binary) {
    double decimal = 0.0;
    int pointPosition = binary.find('.');
    std::string decimalString;

    // Если точки нет, обрабатываем как целое число
    if (pointPosition == std::string::npos) {
        pointPosition = binary.size();
    }

    // Обработка целой части
    for (int i = 0; i < pointPosition; ++i) {
        if (binary[i] == '1') {
            decimal += pow(2, pointPosition - i - 1);
        }
    }

    // Обработка дробной части
    for (int i = pointPosition + 1; i < binary.size(); ++i) {
        if (binary[i] == '1') {
            decimal += pow(2, - (i - pointPosition));
        }
    }

    decimalString = std::to_string(decimal);

    return decimalString;
}

int main() {
    std::string binaryNumber;
    std::cout << "Enter binary number: ";
    std::cin >> binaryNumber;

    std::string decimalResult = binaryToDecimal(binaryNumber);
    std::cout << "Decimal represintation: " << decimalResult << std::endl;

    return 0;
}

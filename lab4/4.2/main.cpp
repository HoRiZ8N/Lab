#include <iostream>
#include <cmath>
#include <cstring>
#include <iomanip>

const int SIZE = 1000;

int binaryToDecimalIntegerPart(char* binaryIntPart) {
    int decimal = 0;
    int len = strlen(binaryIntPart);
    
    for (int i = 0; i < len; ++i) {
        if (binaryIntPart[i] == '1') {
            decimal += pow(2, len - 1 - i);
        }
    }
    
    return decimal;
}

double binaryToDecimalFloatPart(char* binaryFracPart) {
    double decimal = 0.0;
    int len = strlen(binaryFracPart);
    
    for (int i = 0; i < len; ++i) {
        if (binaryFracPart[i] == '1') {
            decimal += pow(2, -(i + 1));
        }
    }
    
    return decimal;
}

int findDotPos(char* s) {
    for (int i = 0; i < SIZE; i++)
    {
        if (s[i] == '.')
        {
            return i;
        }
    }
    return -1;
}

int main() {
    char binaryNumber[SIZE];
    std::cout << "Enter binary float number: ";
    std::cin.getline(binaryNumber, SIZE);

    int pointPosition = findDotPos(binaryNumber);
    char binaryIntPart[SIZE];
    char binaryFloatPart[SIZE];

    for (int i = 0; i < pointPosition; i++) {
        binaryIntPart[i] = binaryNumber[i];
    }

    int count = 0;
    for (int i = pointPosition + 1; i < SIZE; i++, count++) {
        binaryFloatPart[count] = binaryNumber[i];
    }

    double decimalNumber = binaryToDecimalFloatPart(binaryFloatPart) + binaryToDecimalIntegerPart(binaryIntPart);

    std::cout << std::fixed << std::setprecision(10) << "Decimal representation: " << decimalNumber << '\n';

    return 0;
}

#include <iostream>
#include <cmath>

int countDigits(int power) {
    return (int)(power * log10(2)) + 1;
}

int getDigitAtPosition(long long number, int position) {
    int numDigits = (int)log10(number) + 1;
    return (number / (long long)pow(10, numDigits - position)) % 10;
}

int main() {
    int k;
    std::cout << "Enter a number k: ";
    std::cin >> k;

    int power = 0; 
    long long totalDigits = 0;  

    while (true) {
        int numDigits = countDigits(power); 
        if (totalDigits + numDigits >= k) {
            long long number = (long long)pow(2, power);
            int digit = getDigitAtPosition(number, k - totalDigits);
            std::cout << "k-th number: " << digit << '\n';
            break;
        }
        totalDigits += numDigits;
        power++;
    }

    return 0;
}

#include <iostream>
#include "RationalFraction.h"

int main() {
    try {
        // Создание объектов
        RationalFraction frac1(3, 4);
        RationalFraction frac2(2, 3);

        // Проверка операторов
        RationalFraction sum = frac1 + frac2;
        RationalFraction diff = frac1 - frac2;
        RationalFraction prod = frac1 * frac2;
        RationalFraction quot = frac1 / frac2;

        // Вывод результатов
        std::cout << "Fraction 1: ";
        frac1.print();
        std::cout << "\nFraction 2: ";
        frac2.print();
        std::cout << "\n\nSum: ";
        sum.print();
        std::cout << "\nDifference: ";
        diff.print();
        std::cout << "\nProduct: ";
        prod.print();
        std::cout << "\nQuotient: ";
        quot.print();
        std::cout << "\n";

        // Проверка сравнений
        std::cout << "\nFraction 1 == Fraction 2: " << (frac1 == frac2) << "\n";
        std::cout << "Fraction 1 < Fraction 2: " << (frac1 < frac2) << "\n";
        std::cout << "Fraction 1 <= Fraction 2: " << (frac1 <= frac2) << "\n";
        std::cout << "Fraction 1 > Fraction 2: " << (frac1 > frac2) << "\n";
        std::cout << "Fraction 1 >= Fraction 2: " << (frac1 >= frac2) << "\n";

        // Проверка сеттеров
        frac1.setNumerator(5);
        frac1.setDenominator(6);
        std::cout << "\nUpdated Fraction 1: ";
        frac1.print();
        std::cout << "\n";

    } catch (const std::exception &ex) {
        std::cerr << "Error: " << ex.what() << "\n";
    }

    return 0;
}

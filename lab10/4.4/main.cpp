#include "RationalFraction.h"
#include <iostream>

int main()
{
    RationalFraction num1(14, 3), num2(7, 3), num3;
    std::cout << "Num1: ";
    num1.print();
    std::cout << "\nNum2: ";
    num2.print();

    num3 = num1 * num2;
    std::cout << "\nProduct of num1 and num2: ";
    num3.print();

    num3 = num1 / num2;
    std::cout << "\nDivision of num1 and num2: ";
    num3.print();

    
    num1.setNumerator(5);
    num1.setDenominator(15);
    std::cout << "\nNew num1 value: ";
    num1.print();
    num1.reduce();
    std::cout << "\nReduced num1: ";
    num1.print();

    std::cout << "\nCompare num1 and num2: ";
    if (num1 == num2)
    {
        std::cout << "num1 == num2";
    } 
    else if (num1 < num2)
    {
        std::cout << "num1 < num2";
    }
    else if(num1 > num2)
    {
        std::cout << "num1 > num2";
    }

    return 0;
}
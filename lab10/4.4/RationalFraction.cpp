#include "RationalFraction.h"
#include <numeric>
#include <iostream>

RationalFraction::RationalFraction(int num, int denom) : numerator(num), denominator(denom) {
    if (denominator == 0) {
        throw std::invalid_argument("Denominator cannot be zero");
    }
    reduce();
}

RationalFraction::RationalFraction() : numerator(0), denominator(1) {}

bool RationalFraction::operator==(const RationalFraction &other) const {
    return numerator == other.numerator && denominator == other.denominator;
}

RationalFraction RationalFraction::operator+(const RationalFraction &other) const {
    int num = numerator * other.denominator + other.numerator * denominator;
    int den = denominator * other.denominator;
    return RationalFraction(num, den);
}

RationalFraction RationalFraction::operator-(const RationalFraction &other) const {
    int num = numerator * other.denominator - other.numerator * denominator;
    int den = denominator * other.denominator;
    return RationalFraction(num, den);
}

RationalFraction RationalFraction::operator*(const RationalFraction &other) const {
    return RationalFraction(numerator * other.numerator, denominator * other.denominator);
}

RationalFraction RationalFraction::operator/(const RationalFraction &other) const {
    if (other.numerator == 0) {
        throw std::invalid_argument("Cannot divide by zero");
    }
    return RationalFraction(numerator * other.denominator, denominator * other.numerator);
}

bool RationalFraction::operator<(const RationalFraction &other) const {
    return (numerator * other.denominator) < (denominator * other.numerator);
}

bool RationalFraction::operator<=(const RationalFraction &other) const {
    return (numerator * other.denominator) <= (denominator * other.numerator);
}

bool RationalFraction::operator>(const RationalFraction &other) const {
    return (numerator * other.denominator) > (denominator * other.numerator);
}

bool RationalFraction::operator>=(const RationalFraction &other) const {
    return (numerator * other.denominator) >= (denominator * other.numerator);
}

void RationalFraction::print() const {
    std::cout << numerator << "/" << denominator;
}   

void RationalFraction::reduce() {
    int gcd = std::gcd(numerator, denominator);
    numerator /= gcd;
    denominator /= gcd;
    if (denominator < 0) {
        numerator = -numerator;
        denominator = -denominator;
    }
}

int RationalFraction::getNumerator() const
{
    return numerator;
}

int RationalFraction::getDenomerator() const
{
    return denominator;
}

void RationalFraction::setNumerator(int num)
{
    numerator = num;
}

void RationalFraction::setDenominator(int num) {
    if (num == 0) {
        throw std::invalid_argument("Denominator cannot be zero");
    }
    denominator = num;
    reduce(); 
}

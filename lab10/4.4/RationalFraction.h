#pragma once

class RationalFraction
{
public:
    RationalFraction(int num, int denom);
    RationalFraction();
    
    bool operator==(const RationalFraction &other) const;
    RationalFraction operator+(const RationalFraction &other) const;
    RationalFraction operator-(const RationalFraction &other) const;
    RationalFraction operator*(const RationalFraction &other) const;
    RationalFraction operator/(const RationalFraction &other) const;
    bool operator<(const RationalFraction &other) const;
    bool operator<=(const RationalFraction &other) const;
    bool operator>(const RationalFraction &other) const;
    bool operator>=(const RationalFraction &other) const;

    void print() const;
    void reduce();
    int getNumerator() const;
    int getDenomerator() const;
    void setNumerator(int num);
    void setDenominator(int num);

private:
    int numerator;
    int denominator;
};
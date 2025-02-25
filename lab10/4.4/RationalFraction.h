#pragma once

class RationalFraction
{
public:
    RationalFraction(int num, int denom);
    RationalFraction();
    ~RationalFraction();
    RationalFraction(const RationalFraction &other);
    RationalFraction(RationalFraction &&move) noexcept;

    RationalFraction &operator=(const RationalFraction &other);
    RationalFraction &operator=(RationalFraction &&other) noexcept;
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
    int getNumerator();
    int getDenomerator();
    void setNumerator(int num);
    void setDenominator(int num);

private:
    int numerator;
    int denominator;
};
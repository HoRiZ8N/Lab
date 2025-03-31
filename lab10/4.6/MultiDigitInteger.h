#pragma once

#include <cstdint>
#include <iostream>
#include <stdexcept>
#include <string>
#include <sstream>

class MultiDigitInteger {
protected:
    const int base;
    size_t digits;
    uint8_t* data; 

public:
    MultiDigitInteger(size_t digits = 0, int base = 10);
    MultiDigitInteger(const MultiDigitInteger& other);
    MultiDigitInteger(MultiDigitInteger&& other);
    ~MultiDigitInteger();

    MultiDigitInteger& operator=(const MultiDigitInteger& other);
    MultiDigitInteger& operator=(MultiDigitInteger&& other);

    MultiDigitInteger operator+(const MultiDigitInteger& other) const;
    MultiDigitInteger operator-(const MultiDigitInteger& other) const;
    MultiDigitInteger operator*(const MultiDigitInteger& other) const;
    MultiDigitInteger operator/(const MultiDigitInteger& other) const;
    MultiDigitInteger operator%(const MultiDigitInteger& other) const;

    bool operator==(const MultiDigitInteger& other) const;
    bool operator!=(const MultiDigitInteger& other) const;
    bool operator<(const MultiDigitInteger& other) const;
    bool operator>(const MultiDigitInteger& other) const;
    bool operator<=(const MultiDigitInteger& other) const;
    bool operator>=(const MultiDigitInteger& other) const;

    MultiDigitInteger operator<<(size_t n) const;
    MultiDigitInteger operator>>(size_t n) const; 

    uint8_t& operator[](size_t index);
    const uint8_t& operator[](size_t index) const;

    friend std::istream& operator>>(std::istream& is, MultiDigitInteger& num);
    friend std::ostream& operator<<(std::ostream& os, const MultiDigitInteger& num);

    MultiDigitInteger normalize() const; 
    std::string toString() const; 
    bool isZero() const;

    size_t getDigits() const { return digits; }
    int getBase() const { return base; }

    static uint8_t charToValue(char c, int base);
    static char valueToChar(uint8_t value, int base);
    
};

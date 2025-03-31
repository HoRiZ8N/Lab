#include "MultiDigitInteger.h"
#include <algorithm>

MultiDigitInteger::MultiDigitInteger(size_t digits, int base) 
    : base(base), digits(digits), data(new uint8_t[digits]()) {}

MultiDigitInteger::MultiDigitInteger(const MultiDigitInteger& other) 
    : base(other.base), digits(other.digits), data(new uint8_t[other.digits]) {
    std::copy(other.data, other.data + digits, data);
}

MultiDigitInteger::MultiDigitInteger(MultiDigitInteger&& other) 
    : base(other.base), digits(other.digits), data(other.data) {
    other.data = nullptr;
    other.digits = 0;
}

MultiDigitInteger::~MultiDigitInteger() {
    delete[] data;
}

MultiDigitInteger& MultiDigitInteger::operator=(const MultiDigitInteger& other) {
    if (this != &other) {
        if (base != other.base) throw std::invalid_argument("Base mismatch");
        if (digits != other.digits) {
            delete[] data;
            digits = other.digits;
            data = new uint8_t[digits];
        }
        std::copy(other.data, other.data + digits, data);
    }
    return *this;
}

MultiDigitInteger& MultiDigitInteger::operator=(MultiDigitInteger&& other) {
    if (this != &other) {
        if (base != other.base) throw std::invalid_argument("Base mismatch");
        delete[] data;
        digits = other.digits;
        data = other.data;
        other.data = nullptr;
        other.digits = 0;
    }
    return *this;
}

uint8_t& MultiDigitInteger::operator[](size_t index) {
    if (index >= digits) throw std::out_of_range("Index out of range");
    return data[index];
}

const uint8_t& MultiDigitInteger::operator[](size_t index) const {
    if (index >= digits) throw std::out_of_range("Index out of range");
    return data[index];
}

uint8_t MultiDigitInteger::charToValue(char c, int base) {
    if (base < 2 || base > 36) throw std::invalid_argument("Invalid base");
    uint8_t value;
    if (c >= '0' && c <= '9') value = c - '0';
    else if (c >= 'A' && c <= 'Z') value = 10 + c - 'A';
    else if (c >= 'a' && c <= 'z') value = 10 + c - 'a';
    else throw std::invalid_argument("Invalid character");
    if (value >= base) throw std::invalid_argument("Digit exceeds base");
    return value;
}

char MultiDigitInteger::valueToChar(uint8_t value, int base) {
    if (value >= base) throw std::invalid_argument("Value exceeds base");
    if (value < 10) return '0' + value;
    return 'A' + value - 10;
}

std::istream& operator>>(std::istream& is, MultiDigitInteger& num) {
    std::string input;
    is >> input;
    size_t len = input.size();

    try {
        for (size_t i = 0; i < len && i < num.digits; ++i) {
            char c = input[len - 1 - i];
            num[i] = MultiDigitInteger::charToValue(c, num.base);
        }
    } catch (const std::invalid_argument& e) {
        is.setstate(std::ios::failbit);
    }

    return is;
}

bool MultiDigitInteger::operator!=(const MultiDigitInteger& other) const {
    return !(*this == other);
}

bool MultiDigitInteger::operator>(const MultiDigitInteger& other) const {
    return other < *this;
}

bool MultiDigitInteger::operator<=(const MultiDigitInteger& other) const {
    return !(*this > other);
}

bool MultiDigitInteger::operator>=(const MultiDigitInteger& other) const {
    return !(*this < other);
}

std::ostream& operator<<(std::ostream& os, const MultiDigitInteger& num) {
    bool leadingZeros = true;
    for (int i = num.digits - 1; i >= 0; --i) {
        uint8_t digit = num[i];
        if (digit != 0 || !leadingZeros) {
            os << MultiDigitInteger::valueToChar(digit, num.base);
            leadingZeros = false;
        }
    }
    if (leadingZeros) os << '0';
    return os;
}

MultiDigitInteger MultiDigitInteger::operator+(const MultiDigitInteger& other) const {
    if (base != other.base) throw std::invalid_argument("Bases mismatch");
    
    size_t maxDigits = std::max(digits, other.digits) + 1;
    MultiDigitInteger result(maxDigits, base);
    uint8_t carry = 0;
    
    for (size_t i = 0; i < maxDigits; ++i) {
        uint8_t sum = carry;
        if (i < digits) sum += data[i];
        if (i < other.digits) sum += other.data[i];
        
        result[i] = sum % base;
        carry = sum / base;
    }
    
    return result.normalize();
}

MultiDigitInteger MultiDigitInteger::operator-(const MultiDigitInteger& other) const {
    if (base != other.base) throw std::invalid_argument("Bases mismatch");
    if (*this < other) throw std::invalid_argument("Negative result");
    
    MultiDigitInteger result(*this);
    uint8_t borrow = 0;
    
    for (size_t i = 0; i < digits; ++i) {
        int sub = result[i] - borrow;
        if (i < other.digits) sub -= other.data[i];
        
        if (sub < 0) {
            sub += base;
            borrow = 1;
        } else {
            borrow = 0;
        }
        result[i] = sub;
    }
    
    return result.normalize();
}

MultiDigitInteger MultiDigitInteger::operator*(const MultiDigitInteger& other) const {
    if (base != other.base) throw std::invalid_argument("Bases mismatch");
    
    MultiDigitInteger result(digits + other.digits, base);
    
    for (size_t i = 0; i < digits; ++i) {
        uint8_t carry = 0;
        for (size_t j = 0; j < other.digits; ++j) {
            uint8_t product = data[i] * other.data[j] + result[i + j] + carry;
            result[i + j] = product % base;
            carry = product / base;
        }
        if (carry) result[i + other.digits] += carry;
    }
    
    return result.normalize();
}

bool MultiDigitInteger::operator==(const MultiDigitInteger& other) const {
    if (base != other.base || digits != other.digits) return false;
    for (size_t i = 0; i < digits; ++i) {
        if (data[i] != other.data[i]) return false;
    }
    return true;
}

bool MultiDigitInteger::operator<(const MultiDigitInteger& other) const {
    if (base != other.base) throw std::invalid_argument("Bases mismatch");
    if (digits != other.digits) return digits < other.digits;
    
    for (int i = digits - 1; i >= 0; --i) {
        if (data[i] != other.data[i]) {
            return data[i] < other.data[i];
        }
    }
    return false;
}

MultiDigitInteger MultiDigitInteger::operator<<(size_t n) const {
    MultiDigitInteger result(digits + n, base);
    for (size_t i = 0; i < digits; ++i) {
        result[i + n] = data[i]; 
    }
    return result.normalize();
}

MultiDigitInteger MultiDigitInteger::operator>>(size_t n) const {
    if (n >= digits) return MultiDigitInteger(0, base);
    MultiDigitInteger result(digits - n, base);
    for (size_t i = 0; i < result.digits; ++i) {
        result[i] = data[i + n]; 
    }
    return result.normalize();
}


MultiDigitInteger MultiDigitInteger::normalize() const {
    size_t new_digits = digits;
    while (new_digits > 0 && data[new_digits - 1] == 0) {
        new_digits--;
    }
    if (new_digits == 0) new_digits = 1;
    
    MultiDigitInteger result(new_digits, base);
    std::copy(data, data + new_digits, result.data);
    return result;
}

bool MultiDigitInteger::isZero() const
{
    return std::all_of(data, data + digits, [](uint8_t d) { return d == 0; });
}

MultiDigitInteger MultiDigitInteger::operator/(const MultiDigitInteger& divisor) const {
    if (divisor.isZero()) throw std::invalid_argument("Division by zero");
    if (base != divisor.base) throw std::invalid_argument("Base mismatch");

    MultiDigitInteger quotient(1, base);  // Начальное частное (0)
    MultiDigitInteger remainder = this->normalize();
    MultiDigitInteger denom = divisor.normalize();

    if (remainder < denom) return quotient;  // Немедленный возврат 0
    if (remainder == denom) {                // Немедленный возврат 1
        MultiDigitInteger one(1, base);
        one[0] = 1;
        return one;
    }

    // Основной алгоритм деления
    int shift_diff = remainder.digits - denom.digits;
    while (shift_diff >= 0) {
        // Создаём сдвинутый делитель
        MultiDigitInteger shifted = denom << shift_diff;
        
        // Вычитаем пока возможно
        while (shifted <= remainder) {
            remainder = remainder - shifted;
            // Добавляем единицу в соответствующий разряд частного
            MultiDigitInteger add(shift_diff + 1, base);
            add[shift_diff] = 1;
            quotient = quotient + add;
        }
        
        shift_diff--;
    }

    return quotient.normalize();
}

MultiDigitInteger MultiDigitInteger::operator%(const MultiDigitInteger& divisor) const {
    return *this - (*this / divisor) * divisor;
}

std::string MultiDigitInteger::toString() const {
    if (isZero()) {
        return "0";
    }

    std::string result;
    for (int i = digits - 1; i >= 0; --i) {
        result += valueToChar(data[i], base);
    }
    return result;
}
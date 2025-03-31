#include "MultiDigitInteger.h"
#include <iostream>
#include <sstream>
#include <cstdlib>

size_t tests_passed = 0;
size_t tests_failed = 0;

#define TEST(name) std::cout << "\n[TEST] " << #name << "\n";
#define CHECK(cond) if (cond) { tests_passed++; std::cout << "✓ OK\n"; } \
    else { tests_failed++; std::cout << "✗ FAIL\n"; }

void test_default_constructor() {
    TEST(Default Constructor);
    MultiDigitInteger num(5, 10);
    CHECK(num.getDigits() == 5);
    CHECK(num.getBase() == 10);
    for(size_t i = 0; i < 5; ++i) {
        CHECK(num[i] == 0);
    }
}

void test_copy_constructor() {
    TEST(Copy Constructor);
    MultiDigitInteger num1(3, 16);
    num1[0] = 0xA; num1[1] = 0xF; num1[2] = 0x1;
    MultiDigitInteger num2(num1);
    
    CHECK(num2.getDigits() == 3);
    CHECK(num2.getBase() == 16);
    CHECK(num2[0] == 0xA);
    CHECK(num2[1] == 0xF);
    CHECK(num2[2] == 0x1);
}

void test_assignment_operator() {
    TEST(Assignment Operator);
    MultiDigitInteger num1(4, 10);
    num1[0] = 5; num1[1] = 2; num1[2] = 9; num1[3] = 7;
    
    MultiDigitInteger num2(2, 10);
    num2 = num1;
    
    CHECK(num2.getDigits() == 4);
    CHECK(num2[0] == 5);
    CHECK(num2[3] == 7);
}

void test_move_operations() {
    TEST(Move Operations);
    MultiDigitInteger num1(3, 2);
    num1[0] = 1; num1[1] = 0; num1[2] = 1;
    MultiDigitInteger num2(std::move(num1));
    
    CHECK(num2.getDigits() == 3);
    CHECK(num2[0] == 1);
    CHECK(num1.getDigits() == 0);
}

void test_index_operator() {
    TEST(Index Operator);
    MultiDigitInteger num(3, 10);
    num[0] = 5;
    num[1] = 9;
    
    CHECK(num[0] == 5);
    CHECK(num[1] == 9);
    
    try {
        num[3];
        CHECK(false);
    } catch(const std::out_of_range&) {
        CHECK(true);
    }
}

void test_io_operations() {
    TEST(IO Operations);
    {
        MultiDigitInteger num(4, 10);
        std::istringstream iss("9275");
        iss >> num;
        
        CHECK(num[0] == 5);
        CHECK(num[1] == 7);
        CHECK(num[2] == 2);
        CHECK(num[3] == 9);
        
        std::ostringstream oss;
        oss << num;
        CHECK(oss.str() == "9275");
    }
    
    {
        MultiDigitInteger num(3, 16);
        std::istringstream iss("AF1");
        iss >> num;
        
        CHECK(num[0] == 0x1);
        CHECK(num[1] == 0xF);
        CHECK(num[2] == 0xA);
        
        std::ostringstream oss;
        oss << num;
        CHECK(oss.str() == "AF1");
    }
}

void test_invalid_input() {
    TEST(Invalid Input);
    MultiDigitInteger num(3, 10);
    std::istringstream iss("12G34");
    iss >> num;
    CHECK(iss.fail());
}

void test_addition() {
    TEST(Addition);
    MultiDigitInteger a(3, 10);
    a[0] = 3; a[1] = 2; a[2] = 1; // 123
    
    MultiDigitInteger b(2, 10);
    b[0] = 7; b[1] = 4;          // 47
    
    MultiDigitInteger c = a + b; // 170
    c.normalize();
    
    CHECK(c.getDigits() == 3);
    CHECK(c[0] == 0);
    CHECK(c[1] == 7);
    CHECK(c[2] == 1);
}

void test_subtraction() {
    TEST(Subtraction);
    MultiDigitInteger a(3, 10);
    a[0] = 5; a[1] = 2; a[2] = 1; // 125
    
    MultiDigitInteger b(2, 10);
    b[0] = 7; b[1] = 3;          // 37
    
    MultiDigitInteger c = a - b; // 88
    c.normalize();
    
    CHECK(c.getDigits() == 2);
    CHECK(c[0] == 8);
    CHECK(c[1] == 8);
}

void test_multiplication() {
    TEST(Multiplication);
    MultiDigitInteger a(2, 10);
    a[0] = 5; a[1] = 2; // 25
    
    MultiDigitInteger b(1, 10);
    b[0] = 4;           // 4
    
    MultiDigitInteger c = a * b; // 100
    c.normalize();
    
    CHECK(c.getDigits() == 3);
    CHECK(c[0] == 0);
    CHECK(c[1] == 0);
    CHECK(c[2] == 1);
}

void test_comparisons() {
    TEST(Comparisons);
    MultiDigitInteger a(3, 10);
    a[0] = 5; a[1] = 2; a[2] = 1; // 125
    
    MultiDigitInteger b(2, 10);
    b[0] = 7; b[1] = 3;           // 37
    
    MultiDigitInteger c(3, 10);
    c[0] = 5; c[1] = 2; c[2] = 1; // 125
    
    CHECK(a == c);
    CHECK(a != b);
    CHECK(a > b);
    CHECK(b < a);
    CHECK(a >= c);
    CHECK(b <= a);
}

void test_shifts() {
    TEST(Bitwise Shifts);
    
    {
        MultiDigitInteger a(3, 10);
        a[0] = 3; a[1] = 2; a[2] = 1; 
        
        MultiDigitInteger b = a << 2;
        CHECK(b.getDigits() == 5);
        CHECK(b[0] == 0);
        CHECK(b[1] == 0);
        CHECK(b[2] == 3);
        CHECK(b[3] == 2);
        CHECK(b[4] == 1); 
    }
    
    {
        MultiDigitInteger a(5, 10);
        a[0] = 0; a[1] = 0; a[2] = 3; a[3] = 2; a[4] = 1;
        
        MultiDigitInteger b = a >> 2; 
        CHECK(b.getDigits() == 3);
        CHECK(b[0] == 3);
        CHECK(b[1] == 2);
        CHECK(b[2] == 1);
    }
}

void test_division() {
    TEST(Division);
    {
        // 1234 / 17 = 72
        MultiDigitInteger a(4, 10);
        a[0] = 5; a[1] = 5; a[2] = 5; a[3] = 5; // 5555
        
        MultiDigitInteger b(2, 10);
        b[0] = 3; b[1] = 3; // 33
        
        MultiDigitInteger c = a / b;
        CHECK(c.getDigits() == 3);
        CHECK(c[0] == 8); // 168
        CHECK(c[1] == 6);
        CHECK(c[2] == 1);
    }
    
    {
        // 100 / 5 = 20
        MultiDigitInteger a(3, 10);
        a[0] = 0; a[1] = 0; a[2] = 1; // [0,0,1] → 100
        
        MultiDigitInteger b(1, 10);
        b[0] = 5; // [5] → 5
        
        MultiDigitInteger c = a / b;
        CHECK(c.getDigits() == 2);
        CHECK(c[0] == 0); // 20 → [0,2]
        CHECK(c[1] == 2);
    }
}

void test_modulus() {
    TEST(Modulus);
    MultiDigitInteger a(4, 10);
    a[0] = 4; a[1] = 3; a[2] = 2; a[3] = 1; // 1234
    
    MultiDigitInteger b(2, 10);
    b[0] = 7; b[1] = 1; // 17
    
    MultiDigitInteger c = a % b; // 10
    c.normalize();
    
    CHECK(c.getDigits() == 2);
    CHECK(c[0] == 0);
    CHECK(c[1] == 1);
}

void test_utilities() {
    TEST(Utilities);

    // Тесты для normalize()
    {
        MultiDigitInteger a(5, 10);
        a[0] = 3;  a[1] = 2; a[2] = 1;  a[3] = 0; a[4] = 0; 
        
        MultiDigitInteger b = a.normalize();
        CHECK(b.getDigits() == 3);
        CHECK(b[0] == 3); 
        CHECK(b[1] == 2); 
        CHECK(b[2] == 1);
    }

    {
        // Нормализация нуля
        MultiDigitInteger a(5, 10);
        a[0] = 0; a[1] = 0; a[2] = 0;
        
        MultiDigitInteger b = a.normalize();
        CHECK(b.getDigits() == 1);
        CHECK(b[0] == 0);
    }

    // Тесты для isZero()
    {
        MultiDigitInteger zero(3, 10);
        CHECK(zero.isZero());
    }

    {
        MultiDigitInteger nonZero(3, 10);
        nonZero[0] = 0; nonZero[1] = 5;
        CHECK(!nonZero.isZero());
    }

    // Тесты для toString()
    {
        MultiDigitInteger num(3, 10);
        num[0] = 3; 
        num[1] = 2;
        num[2] = 1;
        CHECK(num.toString() == "123");
    }

    {
        MultiDigitInteger hexNum(2, 16);
        hexNum[0] = 0xF;
        hexNum[1] = 0xA;
        CHECK(hexNum.toString() == "AF");
    }

    {
        MultiDigitInteger zero(1, 10);
        CHECK(zero.toString() == "0");
    }

    // Тесты для charToValue() и valueToChar()
    {
        CHECK(MultiDigitInteger::charToValue('5', 10) == 5);
        CHECK(MultiDigitInteger::charToValue('A', 16) == 10);
        CHECK(MultiDigitInteger::charToValue('z', 36) == 35);
        
        bool exceptionThrown = false;
        try {
            MultiDigitInteger::charToValue('G', 10);
        } catch (const std::invalid_argument&) {
            exceptionThrown = true;
        }
        CHECK(exceptionThrown);
    }

    {
        CHECK(MultiDigitInteger::valueToChar(9, 10) == '9');
        CHECK(MultiDigitInteger::valueToChar(15, 16) == 'F');
        CHECK(MultiDigitInteger::valueToChar(20, 36) == 'K');
        
        bool exceptionThrown = false;
        try {
            MultiDigitInteger::valueToChar(16, 10);
        } catch (const std::invalid_argument&) {
            exceptionThrown = true;
        }
        CHECK(exceptionThrown);
    }
}

void test_errors() {
    TEST(Error Handling);
    {
        MultiDigitInteger a(2, 10);
        MultiDigitInteger b(0, 10);
        bool caught = false;
        try { auto c = a / b; } 
        catch(const std::invalid_argument&) { caught = true; }
        CHECK(caught);
    }
    
    {
        MultiDigitInteger a(2, 10);
        MultiDigitInteger b(2, 16);
        bool caught = false;
        try { auto c = a + b; } 
        catch(const std::invalid_argument&) { caught = true; }
        CHECK(caught);
    }
}

int main() {
    test_default_constructor();
    test_copy_constructor();
    test_assignment_operator();
    test_move_operations();
    test_index_operator();
    test_io_operations();
    test_invalid_input();
    test_addition();
    test_subtraction();
    test_multiplication();
    test_comparisons();
    test_shifts();
    test_division();
    test_modulus();
    test_utilities();
    test_errors();

    std::cout << "\n=== Test Results ==="
              << "\nPassed: " << tests_passed
              << "\nFailed: " << tests_failed
              << "\nTotal:  " << (tests_passed + tests_failed)
              << "\n====================" << std::endl;

    return tests_failed ? EXIT_FAILURE : EXIT_SUCCESS;
}
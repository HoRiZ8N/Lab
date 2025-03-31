#include "RationalFraction.h"
#include <iostream>
#include <sstream>
#include <cstdlib>

size_t tests_passed = 0;
size_t tests_failed = 0;

#define TEST(name) std::cout << "\n[TEST] " << #name << "\n";
#define CHECK(cond) if (cond) { tests_passed++; std::cout << "✓ OK\n"; } \
    else { tests_failed++; std::cout << "✗ FAIL\n"; }

void test_constructors() {
    TEST(Constructors)
    {
        RationalFraction rf1;
        CHECK(rf1.getNumerator() == 0)
        CHECK(rf1.getDenominator() == 1)
    }
    
    {
        RationalFraction rf2(3, 4);
        CHECK(rf2.getNumerator() == 3)
        CHECK(rf2.getDenominator() == 4)
    }
    
    {
        RationalFraction rf3(-5, 2);
        CHECK(rf3.getNumerator() == -5)
        CHECK(rf3.getDenominator() == 2)
    }
}

void test_arithmetic_operations() {
    TEST(Arithmetic Operations)
    RationalFraction a(3, 4);
    RationalFraction b(2, 3);
    
    {
        RationalFraction sum = a + b;
        CHECK(sum.getNumerator() == 17)
        CHECK(sum.getDenominator() == 12)
    }
    
    {
        RationalFraction diff = a - b;
        CHECK(diff.getNumerator() == 1)
        CHECK(diff.getDenominator() == 12)
    }
    
    {
        RationalFraction prod = a * b;
        CHECK(prod.getNumerator() == 1)
        CHECK(prod.getDenominator() == 2)
    }
    
    {
        RationalFraction quot = a / b;
        CHECK(quot.getNumerator() == 9)
        CHECK(quot.getDenominator() == 8)
    }
}

void test_comparisons() {
    TEST(Comparisons)
    RationalFraction a(3, 4);
    RationalFraction b(2, 3);
    RationalFraction c(6, 8);
    
    CHECK(a == c)
    CHECK(a > b)
    CHECK(b < a)
    CHECK(a >= c)
    CHECK(b <= a)
}

void test_setters() {
    TEST(Setters)
    RationalFraction rf;
    rf.setNumerator(5);
    rf.setDenominator(6);
    
    CHECK(rf.getNumerator() == 5)
    CHECK(rf.getDenominator() == 6)
}

void test_normalization() {
    TEST(Normalization)
    {
        RationalFraction rf(6, 8);
        rf.normalize();
        CHECK(rf.getNumerator() == 3)
        CHECK(rf.getDenominator() == 4)
    }
    
    {
        RationalFraction rf(-9, 12);
        rf.normalize();
        CHECK(rf.getNumerator() == -3)
        CHECK(rf.getDenominator() == 4)
    }
    
    {
        RationalFraction rf(0, 5);
        rf.normalize();
        CHECK(rf.getNumerator() == 0)
        CHECK(rf.getDenominator() == 1)
    }
}

void test_errors() {
    TEST(Error Handling)
    {
        bool caught = false;
        try {
            RationalFraction rf(1, 0);
        } catch(const std::invalid_argument&) {
            caught = true;
        }
        CHECK(caught)
    }
    
    {
        RationalFraction rf(3, 4);
        bool caught = false;
        try {
            rf.setDenominator(0);
        } catch(const std::invalid_argument&) {
            caught = true;
        }
        CHECK(caught)
    }
    
    {
        RationalFraction a(3, 4);
        RationalFraction b(0, 1);
        bool caught = false;
        try {
            auto c = a / b;
        } catch(const std::invalid_argument&) {
            caught = true;
        }
        CHECK(caught)
    }
}

int main() {
    test_constructors();
    test_arithmetic_operations();
    test_comparisons();
    test_setters();
    test_normalization();
    test_errors();

    std::cout << "\n=== Test Results ==="
              << "\nPassed: " << tests_passed
              << "\nFailed: " << tests_failed
              << "\nTotal:  " << (tests_passed + tests_failed)
              << "\n====================" << std::endl;

    return tests_failed ? EXIT_FAILURE : EXIT_SUCCESS;
}
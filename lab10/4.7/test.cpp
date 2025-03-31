#include <iostream>
#include <sstream>
#include <cstdlib>
#include "Matrix.h"


size_t tests_passed = 0;
size_t tests_failed = 0;

#define TEST(name) std::cout << "\n[TEST] " << #name << "\n";
#define CHECK(cond) if (cond) { tests_passed++; std::cout << "✓ OK\n"; } \
    else { tests_failed++; std::cout << "✗ FAIL\n"; }

void test_constructors() {
    TEST(Constructors);
    {
        Matrix<int> m1;
        CHECK(m1.Rows() == 0);
        CHECK(m1.Cols() == 0);
    }
    
    {
        Matrix<int> m2(3, 4, 5);
        CHECK(m2.Rows() == 3);
        CHECK(m2.Cols() == 4);
        CHECK(m2[0][0] == 5);
        CHECK(m2[2][3] == 5);
    }
    
    {
        Matrix<int> m3(2, 2, 7);
        Matrix<int> m4(m3);
        CHECK(m4.Rows() == 2);
        CHECK(m4.Cols() == 2);
        CHECK(m4[1][1] == 7);
    }
    
    {
        Matrix<int> m5(Matrix<int>(1, 1, 9));
        CHECK(m5.Rows() == 1);
        CHECK(m5.Cols() == 1);
        CHECK(m5[0][0] == 9);
    }
}

void test_assignment() {
    TEST(Assignment Operators);
    Matrix<int> m1(2, 3, 10);
    Matrix<int> m2;
    m2 = m1;
    
    CHECK(m2.Rows() == 2);
    CHECK(m2.Cols() == 3);
    CHECK(m2[1][2] == 10);
    
    Matrix<int> m3;
    m3 = Matrix<int>(3, 2, 5);
    CHECK(m3.Rows() == 3);
    CHECK(m3.Cols() == 2);
    CHECK(m3[2][1] == 5);
}

void test_element_access() {
    TEST(Element Access);
    Matrix<int> m(3, 3, 0);
    m[0][0] = 1;
    m[1][1] = 2;
    m[2][2] = 3;
    
    CHECK(m[0][0] == 1);
    CHECK(m[1][1] == 2);
    CHECK(m[2][2] == 3);
    
    try {
        m[3][0];
        CHECK(false);
    } catch(const std::out_of_range&) {
        CHECK(true);
    }
}

void test_resize() {
    TEST(Resize);
    Matrix<int> m(2, 2, 5);
    m.Resize(3, 4, 0);
    
    CHECK(m.Rows() == 3);
    CHECK(m.Cols() == 4);
    CHECK(m[0][0] == 5);
    CHECK(m[2][3] == 0);
    
    m.Resize(1, 1, 9);
    CHECK(m.Rows() == 1);
    CHECK(m.Cols() == 1);
    CHECK(m[0][0] == 5);
}



void test_move_operations() {
    TEST(Move Operations);
    Matrix<int> m1(2, 2, 5);
    Matrix<int> m2(std::move(m1));
    
    CHECK(m2.Rows() == 2);
    CHECK(m1.Rows() == 0);
    CHECK(m1.GetName().empty());
    
    Matrix<int> m3;
    m3 = std::move(m2);
    CHECK(m3.Rows() == 2);
    CHECK(m2.Rows() == 0);
}

void test_edge_cases() {
    TEST(Edge Cases);
    {
        Matrix<int> m(0, 0, 0);
        CHECK(m.Rows() == 0);
        CHECK(m.Cols() == 0);
    }
    
    {
        Matrix<int> m(1, 1000, 42);
        CHECK(m[0][999] == 42);
    }
    
    {
        Matrix<int> m1(5, 5, 3);
        Matrix<int> m2 = m1;
        m1.Resize(0, 0, 0);
        CHECK(m2.Rows() == 5);
    }
}

int main() {
    test_constructors();
    test_assignment();
    test_element_access();
    test_resize();
    test_move_operations();
    test_edge_cases();

    std::cout << "\n=== Test Results ==="
              << "\nPassed: " << tests_passed
              << "\nFailed: " << tests_failed
              << "\nTotal:  " << (tests_passed + tests_failed)
              << "\n====================" << std::endl;

    return tests_failed ? EXIT_FAILURE : EXIT_SUCCESS;
}
#include <iostream>
#include <sstream>
#include <cstdlib>
#include "BinaryTree.h"

size_t tests_passed = 0;
size_t tests_failed = 0;

#define TEST(name) std::cout << "\n[TEST] " << #name << "\n";
#define CHECK(cond) if (cond) { tests_passed++; std::cout << "✓ OK\n"; } \
    else { tests_failed++; std::cout << "✗ FAIL\n"; }

void test_default_constructor() {
    TEST(Default Constructor);
    BinaryTree<int> tree;
    CHECK(true);
}

void test_constructor_with_value() {
    TEST(Constructor with Value);
    BinaryTree<int> tree(42);
    CHECK(tree.contains(42));
}

void test_copy_constructor() {
    TEST(Copy Constructor);
    BinaryTree<int> tree1;
    tree1.insert(5);
    tree1.insert(3);
    tree1.insert(7);
    
    BinaryTree<int> tree2(tree1);
    
    CHECK(tree2.contains(5));
    CHECK(tree2.contains(3));
    CHECK(tree2.contains(7));
}

void test_assignment_operator() {
    TEST(Assignment Operator);
    BinaryTree<int> tree1;
    tree1.insert(10);
    tree1.insert(5);
    tree1.insert(15);
    
    BinaryTree<int> tree2;
    tree2 = tree1;
    
    CHECK(tree2.contains(10));
    CHECK(tree2.contains(5));
    CHECK(tree2.contains(15));
}

void test_move_operations() {
    TEST(Move Operations);
    BinaryTree<int> tree1;
    tree1.insert(8);
    tree1.insert(4);
    tree1.insert(12);
    
    BinaryTree<int> tree2(std::move(tree1));
    
    CHECK(tree2.contains(8));
    CHECK(tree2.contains(4));
    CHECK(tree2.contains(12));
    CHECK(!tree1.contains(8));
}

void test_insert_and_contains() {
    TEST(Insert and Contains);
    BinaryTree<int> tree;
    tree.insert(50);
    tree.insert(30);
    tree.insert(70);
    tree.insert(20);
    tree.insert(40);
    
    CHECK(tree.contains(50));
    CHECK(tree.contains(30));
    CHECK(tree.contains(70));
    CHECK(tree.contains(20));
    CHECK(tree.contains(40));
    CHECK(!tree.contains(99));
}

void test_remove_leaf() {
    TEST(Remove Leaf);
    BinaryTree<int> tree;
    tree.insert(50);
    tree.insert(30);
    tree.insert(70);
    tree.insert(20);
    
    CHECK(tree.removeLeaf(20));
    CHECK(!tree.contains(20));
    CHECK(!tree.removeLeaf(50)); 
    CHECK(!tree.removeLeaf(99));
}

void test_delete_min() {
    TEST(Delete Min);
    BinaryTree<int> tree;
    tree.insert(50);
    tree.insert(30);
    tree.insert(70);
    tree.insert(20);
    tree.insert(40);
    
    tree.deleteMin();
    CHECK(!tree.contains(20));
    CHECK(tree.contains(30));
    CHECK(tree.contains(40));
    CHECK(tree.contains(50));
    CHECK(tree.contains(70));
}

void test_clear() {
    TEST(Clear);
    BinaryTree<int> tree;
    tree.insert(10);
    tree.insert(5);
    tree.insert(15);
    
    tree.clear();
    CHECK(!tree.contains(10));
    CHECK(!tree.contains(5));
    CHECK(!tree.contains(15));
}

void test_print() {
    TEST(Print);
    BinaryTree<int> tree;
    tree.insert(4);
    tree.insert(2);
    tree.insert(6);
    tree.insert(1);
    tree.insert(3);
    tree.insert(5);
    tree.insert(7);
    
    std::ostringstream oss;
    std::streambuf* oldCout = std::cout.rdbuf(oss.rdbuf());
    tree.print();
    std::cout.rdbuf(oldCout);
    
    std::string output = oss.str();
    CHECK(output.find("1 2 3 4 5 6 7") != std::string::npos);
}

void test_init_first_element() {
    TEST(Init First Element);
    BinaryTree<int> tree;
    tree.initFirstElement(100);
    CHECK(tree.contains(100));
    
    tree.initFirstElement(200);
    CHECK(!tree.contains(200));
}

int main() {
    test_default_constructor();
    test_constructor_with_value();
    test_copy_constructor();
    test_assignment_operator();
    test_move_operations();
    test_insert_and_contains();
    test_remove_leaf();
    test_delete_min();
    test_clear();
    test_print();
    test_init_first_element();

    std::cout << "\n=== Test Results ==="
              << "\nPassed: " << tests_passed
              << "\nFailed: " << tests_failed
              << "\nTotal:  " << (tests_passed + tests_failed)
              << "\n====================" << std::endl;

    return tests_failed ? EXIT_FAILURE : EXIT_SUCCESS;
}
#include <iostream>
#include "BinaryTree.h"

int main() {
    BinaryTree<int> tree;
    std::cout << "Enter the number of elements: ";
    int size;
    std::cin >> size;

    if (size <= 0) {
        std::cout << "No elements to insert.\n";
        return 0;
    }

    std::cout << "Enter " << size << " elements: ";
    for (int i = 0; i < size; i++) {
        int val;
        std::cin >> val;
        tree.insert(val);
    }
    
    std::cout << "Tree in increasing order:\n";
    tree.print();
    std::cout << '\n';
    tree.deleteMin();
    std::cout << "Tree without minimal value element:\n";
    tree.print();
    std::cout << '\n';
    tree.clear();

    return 0;
}
#include <iostream>
#include "LinkedList.h"

int main()
{
    try
    {
        // Creating a LinkedList instance
        LinkedList<int> list;

        std::cout << "Initial size: " << list.Size() << std::endl;

        // Testing PushBack
        std::cout << "\nAdding elements...\n";
        list.PushBack(10);
        list.PushBack(20);
        list.PushBack(30);
        list.PushBack(40);

        std::cout << "List after adding elements: ";
        std::cout << list << std::endl;

        // Testing Size
        std::cout << "Current size of the list: " << list.Size() << std::endl;

        // Testing Push at specific index
        std::cout << "\nInserting 25 at index 2...\n";
        list.Push(25, 2);
        std::cout << "List after inserting: ";
        std::cout << list << std::endl;

        // Testing Search by index
        std::cout << "\nSearching for element at index 3...\n";
        int value = list.Search(3);
        std::cout << "Element at index 3: " << value << std::endl;

        // Testing GetIndex
        std::cout << "\nFinding index of element with value 25...\n";
        size_t index = list.GetIndex(25);
        std::cout << "Index of element 25: " << index << std::endl;

        // Testing Pop (removal by index)
        std::cout << "\nRemoving element at index 2...\n";
        list.Pop(2);
        std::cout << "List after removal: ";
        std::cout << list << std::endl;

        // Testing PopBack (removal of last element)
        std::cout << "\nRemoving last element...\n";
        list.PopBack();
        std::cout << "List after removing last element: ";
        std::cout << list << std::endl;

        // Testing Clear
        std::cout << "\nClearing the list...\n";
        list.Clear();
        std::cout << "List after clearing: ";
        std::cout << list << std::endl;
        std::cout << "Final size: " << list.Size() << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}

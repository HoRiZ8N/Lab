#include <iostream>
#include "DoubleLinkedList.h"

int main()
{
    try
    {
        // Создание списка
        DoubleLinkedList<int> list;
        std::cout << "Initial list size: " << list.Size() << std::endl;

        // Тестирование Insert
        std::cout << "\nInserting elements...\n";
        list.Insert(10);
        list.Insert(20);
        list.Insert(30);
        list.Insert(40);
        list.Insert(50);

        std::cout << "List after insertion: ";
        list.Print();

        // Тестирование Size
        std::cout << "List size: " << list.Size() << std::endl;

        // Тестирование оператора []
        std::cout << "\nAccessing element by index...\n";
        std::cout << "Element at index 3: " << list[3] << std::endl;
        
        // Тестирование Remove
        std::cout << "\nRemoving element 30...\n";
        list.Remove(30);
        std::cout << "List after removal: ";
        list.Print();

        // Тестирование Find
        std::cout << "\nFinding element 20...\n";
        size_t index = list.Find(20);
        std::cout << "Element 20 found at index: " << index << std::endl;

        // Тестирование Clear
        std::cout << "\nClearing the list...\n";
        list.Clear();
        std::cout << "List after clearing: ";
        list.Print();
    }
    catch (const std::exception& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}

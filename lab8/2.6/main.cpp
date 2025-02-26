#include <iostream>
#include "DoubleLinkedList.h"

int main()
{
    int n;
    std::cout << "Enter n: ";
    std::cin >> n;

    DoubleLinkedList list;
    std::cout << "Enter " << n << " real numbers:\n";
    for (int i = 0; i < n; i++)
    {
        double num;
        std::cin >> num;
        list.append(num);
    }

    double result = list.computeExpression();
    std::cout << "Result: " << result << std::endl;

    return 0;
}

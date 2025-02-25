#include "DoubleLinkedList.h"

template <typename T>
T CalculateExpression(const DoubleLinkedList<T> &list)
{
    unsigned int size = list.Size();
    if (size < 2)
        return 0;

    T result = 0;
    for (unsigned int i = 0; i < size - 1; ++i)
    {
        T a = list[i];
        T b = list[i + 1];
        T c = list[size - 2 - i];

        result += a + b + (size - i) * c;
    }

    return result;
}

int main()
{
    int n;
    std::cout << "Enter n: ";
    std::cin >> n;

    DoubleLinkedList<double> list;
    std::cout << "Enter " << n << " real numbers:\n";
    for (int i = 0; i < n; i++)
    {
        double num;
        std::cin >> num;
        list.Insert(num);
    }

    double result = CalculateExpression(list);
    std::cout << "Result: " << result << std::endl;

    return 0;
}

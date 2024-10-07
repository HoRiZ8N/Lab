#include <iostream>

int main()
{
    char n;

    setlocale(LC_ALL, "rus");

    std::cout << "Введите символ: ";
    std::cin >> n;
    std::cout << int(n);

    std::cout << "\n0-ой бит: " << (n & 1) << '\n';
    std::cout << "3-ой бит: " << ((n >> 3) & 1) << '\n';
    std::cout << "6-ой бит: " << ((n >> 7) & 1) << "\n\n";

    n = n ^ 8;
    n = n ^ 64;

    std::cout << "Символ с инвертированными 3м и 6м битами: " << n << " " << int(n);

    return 0;
}
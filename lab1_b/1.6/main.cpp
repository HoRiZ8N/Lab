#include <iostream>

int main()
{
    char n;

    setlocale(LC_ALL, "rus");

    std::cout << "������� ������: ";
    std::cin >> n;
    std::cout << int(n);

    std::cout << "\n0-�� ���: " << (n & 1) << '\n';
    std::cout << "3-�� ���: " << ((n >> 3) & 1) << '\n';
    std::cout << "6-�� ���: " << ((n >> 7) & 1) << "\n\n";

    n = n ^ 8;
    n = n ^ 64;

    std::cout << "������ � ���������������� 3� � 6� ������: " << n << " " << int(n);

    return 0;
}
#include <iostream>
#include <cmath>

int main() {
    setlocale(LC_ALL, "rus");
    
    int x1, x2, y1, y2;
    
    std::cout << "������� ��������� � �������� ������� �����: ";
    std::cin >> x1 >> y1 >> x2 >> y2;
    if ((abs(x1 - x2) == abs(y1 - y2)) || (x1 == x2) || (y1 == y2)) {
        std::cout << "����� ������� � �������� ������� �� ���� ���";
    } else {
        std::cout << "������ ������� � �������� ������� �� ���� ���\n������� � �������� ������� �� 2 ���� �����:\n������ ���: "
         << x2 << ' ' << y1 << "\n������ ���: " << x2 << ' ' << y2;
    }

    return 0;
}
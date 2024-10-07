#include <iostream>
#include <cmath>

int main() {
    setlocale(LC_ALL, "rus");
    double x, y, r1, r2;
    std::cout << "Введите числа x, y, r1, r2: ";
    std::cin >> x >> y >> r1 >> r2;

    ((x <= 0 && y >= 0 && hypot(x, y) <= r2) || (x >= 0 && y <= 0 && hypot(x, y) <= r1 && hypot(x, y) >= r2)) == (true) ?
    (std::cout << "\nТочка принадлежит заданной обасти") : (std::cout << "\nТочка не принадлежит заданной обасти");

    return 0;
}
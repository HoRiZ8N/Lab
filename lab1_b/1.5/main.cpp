#include <iostream>

bool func(double x1, double y1, double x2, double y2, double x3, double y3) {
    return y1 > ((x1 - x2) * (y3 - y2) / (x3 - x2) + y2);
}

int main() {
    setlocale(LC_ALL, "Rus");

    double a, b, c, d, e, f, g, h;
    std::cout << "Введите координаты четырех точек: \n\n";
    std::cin >> a >> b >> c >> d >> e >> f >> g >> h;

    if (func(a, b, e, f, g, h) == func(c, d, e, f, g, h))
    {
        std::cout << "\nТочки лежат в одной полуплоскости";
    } else {
        std::cout << "\nТочки лежат в разных полуплоскостях";
    }
    

    return 0;
}
#include <iostream>
#include <cmath>


int main() {
    setlocale(LC_ALL, "rus");

    int s, t;
    double x;

    std::cout << "Введите числа s, t, x: ";
    std::cin >> s >> t >> x;

    if (pow(x, t) <= 0 || (x + s * log(pow(x, t)) <= 0)) {
        std::cout << "\nФункция не определена";
    } else {
        std::cout << '\n' << pow(M_E, (0.5 * x)) / sqrt(x + s * log(pow(x, t)));
    }

    return 0;
}
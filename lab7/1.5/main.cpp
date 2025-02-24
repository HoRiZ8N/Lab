#include <iostream>
#include <iomanip>
#include "integral.h"

int main() {
    double s1 = 0.0, s2 = 2.0, delta_s = 0.5;
    double t1 = 2.0, t2 = 5.0, delta_t = 1.0;
    double a = -1.0, b = 1.0;
    double epsilon = 1e-6;

    std::cout << std::fixed << std::setprecision(6);
    std::cout << "  +-----------+----------+----------+------+" << std::endl;
    std::cout << "  |    s      |    t     |   val    | iter |" << std::endl;
    std::cout << "  +-----------+----------+----------+------+" << std::endl;

    for (double s = s1; s <= s2; s += delta_s) {
        for (double t = t1; t <= t2; t += delta_t) {
            int k_iter;
            double integral = leftRectangleMethod(a, b, s, t, epsilon, k_iter, testFunc);

            std::cout << "  | " << s << "  | " << t << " | " << std::setw(8) <<  integral
                << " | " << std::setw(4) <<k_iter << " |" << std::endl;
        }
    }

    std::cout << "  +-----------+----------+----------+------+" << std::endl;

    return 0;
}

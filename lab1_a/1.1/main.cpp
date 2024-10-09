#include <iostream>
#include <cmath>


int main() {
    double x;
    std::cin >> x;
    if (x == 0 || (sin(M_PI * x * x) + sin(x) + log(x * x) + (x * x) + pow(M_E, cos(x))) == 0)
    {
        std::cout << "Function is undefined";
    } else {
        std::cout << ((sin(M_PI * x * x) + log(x * x)) / (sin(M_PI * x * x) + sin(x) + log(x * x) + (x * x) + pow(M_E, cos(x))));
    }

    return 0;
}
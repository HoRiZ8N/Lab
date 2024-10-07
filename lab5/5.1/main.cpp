#include <iostream>
#include <iomanip>

long double abs(long double n) {
    if(n < 0) {
        return (-1 * n);
    } else {
        return n;
    }
}

long double fact(size_t n) {
    long double product = 1;
    for (int i = 1; i <= n; i++)
    {
        product *= i;
    }
    return product;
}

long double pow(long double n, int p) {
    long double prod = 1; 
    for (int i = 0; i < p; i++)
    {
        prod *= n;
    }
    return prod;
}

long double param(size_t k, double x) {
    return (pow(-1, k) * pow(x, 4 * k + 1) / (4 * k + 1) / fact(2 * k));
}

int main() {
    long double x;
    std::cout << "Enter a number x, 0 < x <= 1: ";
    std::cin >> x;

    size_t k = 1;
    long double result = 0;
    long double pr = param(k, x);
    while (abs(pr) > 0.000001)
    {
        pr = param(k, x);
        result += pr;
        k++;
    }
    
    std::cout << "\nThe resul of the sum is: ";
    std::cout << std::fixed << std::setprecision(6) << result << ' ' << k;

    return 0;
}
#include <iostream>

void func(double &a, double &b) {
    double tmp; 
    (a > b) ? (std::swap(a, b)) : (std::swap(a, a));
}

int main() {
    setlocale(LC_ALL, "rus");

    double x1, x2, x3, x4;

    std::cout << "¬ведите 4 координаты точек: \n";
    std::cin >> x1 >> x2 >> x3 >> x4;

    func(x1, x2); 
    func(x3, x4); 
    func(x1, x3); 
    func(x2, x4); 
    func(x2, x3); 
    
    std::cout << '\n' << x1 << ' ' << x2 << ' ' << x3 << ' ' << x4;

    return 0;
}
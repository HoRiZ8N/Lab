#include <iostream>

int main() {
    int n;
    std::cin >> n;
    n /= 100;
    int h =  n % 10;
    std::cout << h;

    return 0;
}
#include <iostream>

int fact(int num) {
    int prod = 1;
    for (int i = 2; i <= num; i++)
    {
        prod *= i;
    }
    return prod;
}

void fact(int num, int &res) {
    int prod = 1;
    for (int i = 2; i <= num; i++)
    {
        prod *= i;
    }
    res = prod;
}

void fact(int num, int* res) {
    int prod = 1;
    for (int i = 2; i <= num; i++)
    {
        prod *= i;
    }
    *res = prod; 
}

int main() {
    int n = 2;
    while (fact(n) < fact(n + 1))
    {
        n++;
    }
    std::cout << n - 1;

    return 0;
}
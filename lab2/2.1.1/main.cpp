#include <iostream>
#include <cmath>

int intSize(int n) {
    int size = 0;
    if (!n)
    {
        return 1;
    }
    
    while (n)
    {
        n /= 10;
        size++;
    }
    
    return size;
}

int main()
{

    long long n;

    std::cout << "Enter a number: ";
    std::cin >> n;
    long long tmpn = n;


    int k = intSize(n);
    long long new_n = 0;
    int size = k; 
    for (int i = 0; i < size; i++)  //123456->654321
    {
        new_n += (n % 10) * std::pow(10, k-1);
        k--;
        n /= 10;
    }

    (new_n == tmpn) ? (std::cout << "Your num is a polyndrome") : (std::cout << "Your num isn't a polyndrome");

    return 0;
}
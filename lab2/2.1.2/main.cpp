#include <iostream>
#include <string>

int main() {

    int n, k, sum1 = 0, sum2 = 0;
    double num;

    std::cout << "Enter a float number: ";
    std::cin >> num;

    num -= (int)num;

    std::cout << "\nEnter n, k: ";
    std::cin >> n >> k;
    
    for (int i = 0; i < n; i++) //sum for first n numbers
    {
        num *= 10;
        sum1 += (int)num;
        num -= (int)num;
    }

    for (int i = 0; i < k; i++) // sum for next k numbers
    {
        num *= 10;
        sum2 += (int)num;
        num -= (int)num;
    }

    (sum1 == sum2) ? (std::cout << "Equal") : (std::cout << "Not Equal");

    return 0;
}
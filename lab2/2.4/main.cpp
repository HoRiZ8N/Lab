#include <iostream>

int main() {
    int d, maximum = 2, count = 2, n, curr, prev;
    std::cout << "Enter amount of numbers: ";
    std::cin >> n;
    std::cout << "\nEnter " << n << " numbers: ";


    if (n == 0)
    {
        std::cout << 0;
        return 0;
    } else if (n == 1){
        std::cin >> prev;
        std::cout << 1;
        return 0;
    } else if (n == 2) {
        std::cin >> prev >> curr;
        std::cout << 2;
        return 0;
    }
    


    std::cin >> prev >> curr;
    d = curr - prev;
    for (int i = 2; i < n; i++)
    {
        prev = curr;
        std::cin >> curr;
        if (curr - prev == d) {
            count++;
        } else {
            maximum = std::max(count, maximum);
            count = 1;
        }
        d = curr - prev;
    }

    maximum = std::max(count, maximum);

    std::cout << "\nMaximum arithmetic progression size is: " << maximum;

    return 0;
}
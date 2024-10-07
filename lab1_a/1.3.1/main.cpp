#include <iostream>

int main() {
    int n, k;
    std::cin >> n >> k;
    bool ans = ((n % 2 == 0 && k % 2 == 0) || (n % 2 == 1 && k % 2 == 1)) ? true : false;
    std::cout << ans;

    return 0;
}
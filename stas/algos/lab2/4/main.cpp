#include <iostream>
#include <vector>

int main() {
    int n, m;
    std::cout << "Enter your number of substances and added substances" << std::endl;
    std::cin >> n >> m;

    if (n < 1 || n > 300) {
        std::cerr << "Error: number of substances 'n' must be between 1 and 300." << std::endl;
        return 1;
    }
    if (m < 1 || m > 1000) {
        std::cerr << "Error: number of added substances 'm' must be between 1 and 1000." << std::endl;
        return 1;
    }

    std::vector<std::vector<int>> matrix(n, std::vector<int>(n));

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
        std::cin >> matrix[i][j];

            std::vector<int> sequence(m);
    for (int i = 0; i < m; ++i) {
        std::cin >> sequence[i];
        sequence[i]--;
    }

    std::vector<int> tube; // стек пробирки

    for (int x : sequence) {
        while (!tube.empty()) {
            int top = tube.back();
            int result = matrix[top][x];
            if (result == top) break;
            tube.pop_back();
            x = result - 1;
        }
        tube.push_back(x);
    }

    for (int i = tube.size() - 1; i >= 0; i--) {
        std::cout << tube[i] + 1;
        if (i > 0) std::cout << " ";
    }
    std::cout << std::endl;

    return 0;
}

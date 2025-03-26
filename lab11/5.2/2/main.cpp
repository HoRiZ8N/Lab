#include <iostream>
#include <vector>

std::vector<double> multiplyMatrixVector(const std::vector<std::vector<double>>& A, const std::vector<double>& b) {
    size_t n = A.size();
    std::vector<double> result(n, 0.0);

    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < n; ++j) {
            result[i] += A[i][j] * b[j];
        }
    }

    return result;
}

int main() {
    size_t n;
    std::cout << "Enter matrix size: ";
    std::cin >> n;

    // Ввод матрицы A
    std::vector<std::vector<double>> A(n, std::vector<double>(n));
    std::cout << "Enter matrix A:" << std::endl;
    for (int i = 0; i < n; ++i) {
        for (size_t j = 0; j < n; ++j) {
            std::cin >> A[i][j];
        }
    }

    // Ввод вектора b
    std::vector<double> b(n);
    std::cout << "Enter vector b:" << std::endl;
    for (int i = 0; i < n; ++i) {
        std::cin >> b[i];
    }

    std::vector<double> c = multiplyMatrixVector(A, multiplyMatrixVector(A, b));

    // Вывод результата
    std::cout << "Result:" << std::endl;
    for (double value : c) {
        std::cout << value << " ";
    }
    std::cout << std::endl;

    return 0;
}

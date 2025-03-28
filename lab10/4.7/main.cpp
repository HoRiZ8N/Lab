#include <iostream>
#include "Matrix.h"

MyVector<double> multiplyMatrixVector(const Matrix<double>& A, const MyVector<double>& b) {
    if (A.Rows() != A.Cols()) {
        throw std::invalid_argument("Matrix must be square!");
    }
    const size_t n = A.Rows();
    
    MyVector<double> result(n, 0.0);

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

    try {
        Matrix<double> A(n, n);
        std::cout << "Enter matrix A:" << std::endl;
        for (size_t i = 0; i < n; ++i) {
            for (size_t j = 0; j < n; ++j) {
                std::cin >> A[i][j];
            }
        }

        MyVector<double> b(n);
        std::cout << "Enter vector b:" << std::endl;
        for (size_t i = 0; i < n; ++i) {
            std::cin >> b[i];
        }

        MyVector<double> result = multiplyMatrixVector(A, multiplyMatrixVector(A, b));

        std::cout << "Result:" << std::endl;
        for (size_t i = 0; i < result.Size(); ++i) {
            std::cout << result[i] << " ";
        }
        std::cout << std::endl;

    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
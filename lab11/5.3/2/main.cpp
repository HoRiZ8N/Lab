#include <iostream>
#include <list>

std::list<double> inputNumbers(int n) {
    std::list<double> numbers;
    std::cout << "Enter " << n << " real numbers:\n";
    for (int i = 0; i < n; i++) {
        double num;
        std::cin >> num;
        numbers.push_back(num);
    }
    return numbers;
}

double computeExpression(const std::list<double>& numbers) {
    int size = numbers.size();
    if (size < 2)
        return 0.0;

    double result = 0.0;
    auto frontIt = numbers.begin();
    auto backIt = --numbers.end();

    for (int i = 0; i < size - 1; ++i) {
        double a = *frontIt;
        double b = *std::next(frontIt);
        double c = *std::prev(backIt);

        result += a + b + (size - i) * c;

        ++frontIt;
        --backIt;
    }

    return result;
}

int main() {
    int n;
    std::cout << "Enter n: ";
    std::cin >> n;

    std::list<double> numbers = inputNumbers(n);

    double result = computeExpression(numbers);
    std::cout << "Result: " << result << std::endl;

    return 0;
}

#include <iostream>
#include <algorithm>

bool canAllGirlsDate(int* boys, int M, int* girls, int N) {
    std::sort(boys, boys + M);
    std::sort(girls, girls + N);

    int boyIndex = 0;
    int girlIndex = 0;
    int pairs = 0;

    while (boyIndex < M && girlIndex < N) {
        if (boys[boyIndex] > girls[girlIndex]) {
            // Нашли подходящую пару
            pairs++;
            boyIndex++;
            girlIndex++;
        } else {
            // Парень слишком низкий, пробуем следующего
            boyIndex++;
        }
    }

    return pairs == N;
}

int main() {
    setlocale(LC_ALL, "rus");
    int inputMethod;
    std::cout << "Выберите способ ввода (1 - случайный, 2 - ручной): ";
    std::cin >> inputMethod;

    int M, N;
    int* boys;
    int* girls;

    if (inputMethod == 1) {
        // Генерация случайных данных
        std::cout << "Введите количество парней M и девушек N: ";
        std::cin >> M >> N;

        boys = new int[M];
        girls = new int[N];

        for (int i = 0; i < M; i++) {
            boys[i] = 150 + rand() % 51;
        }
        for (int i = 0; i < N; i++) {
            girls[i] = 150 + rand() % 51;
        }

        std::cout << "Рост парней: ";
        for (int i = 0; i < M; i++) {
            std::cout << boys[i] << " ";
        }
        std::cout << "\nРост девушек: ";
        for (int i = 0; i < N; i++) {
            std::cout << girls[i] << " ";
        }
        std::cout << std::endl;
    } else {
        std::cout << "Введите количество парней M: ";
        std::cin >> M;
        boys = new int[M];
        std::cout << "Введите рост каждого из " << M << " парней (150-200): ";
        for (int i = 0; i < M; i++) {
            std::cin >> boys[i];
        }

        std::cout << "Введите количество девушек N: ";
        std::cin >> N;
        girls = new int[N];
        std::cout << "Введите рост каждой из " << N << " девушек (150-200): ";
        for (int i = 0; i < N; i++) {
            std::cin >> girls[i];
        }
    }

    bool result = canAllGirlsDate(boys, M, girls, N);
    std::cout << (result ? "YES" : "NO") << std::endl;

    delete[] boys;
    delete[] girls;

    return 0;
}

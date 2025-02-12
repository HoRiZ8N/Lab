#include <iostream>
#include <algorithm>

template <typename T>
void mergeSort(T* a, unsigned int start, unsigned int end) {
    if (end - start < 2)
        return;
    
    if (end - start == 2) {
        if (a[start] > a[start + 1])
            std::swap(a[start], a[start + 1]);
        return;
    }
    
    unsigned int mid = start + (end - start) / 2;
    mergeSort(a, start, mid);
    mergeSort(a, mid, end);

    // Временный массив для хранения результатов слияния
    T* temp = new int[end - start];
    unsigned int b1 = start;
    unsigned int e1 = mid;
    unsigned int b2 = mid;
    unsigned int idx = 0;

    // Слияние двух отсортированных частей
    while (b1 < e1 && b2 < end) {
        if (a[b1] <= a[b2]) {
            temp[idx++] = a[b1++];
        } else {
            temp[idx++] = a[b2++];
        }
    }

    // Копируем оставшиеся элементы
    while (b1 < e1) {
        temp[idx++] = a[b1++];
    }
    while (b2 < end) {
        temp[idx++] = a[b2++];
    }

    // Копируем обратно во входной массив
    for (unsigned int i = 0; i < end - start; ++i) {
        a[start + i] = temp[i];
    }

    delete[] temp;
}

enum FillType {
    keyboard,
    random
};

int main() {
    FillType fillType = FillType::random;
    const int MAX_NUM = 100;
    unsigned int size;

    std::cout << "Enter array size: ";
    std::cin >> size;

    int* a = new int[size];
    switch (fillType) {
    case FillType::random:
        srand(time(0));
        for (int i = 0; i < size; i++) {
            a[i] = rand() % MAX_NUM;
        }
        std::cout << "Array before sorting: ";
        for (unsigned int i = 0; i < size; ++i) {
            std::cout << a[i] << ' ';
        }
        std::cout << '\n';
        break;
    
    case FillType::keyboard:
        std::cout << "Enter array elements: ";
        for (unsigned int i = 0; i < size; ++i) {
            std::cin >> a[i];
        }
        break;

    default:
        return 1;
    }

    mergeSort(a, 0, size);

    std::cout << "Array after sorting: ";
    for (unsigned int i = 0; i < size; ++i) {
        std::cout << a[i] << ' ';
    }
    std::cout << '\n';

    delete[] a;
    return 0;
}

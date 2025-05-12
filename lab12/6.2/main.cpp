#include "DynamicArray.h"

int main() {
    // Создание объектов
    DynamicArray arr;
    arr.add(new Star("Sun", 5778, 1.0));
    arr.add(new Planet("Earth", 288, true, true));
    arr.add(new Asteroid("Ceres", {1.5, 0, 0}, {0, 0.5, 0}, 950));

    // Вывод
    std::cout << "Original array:\n";
    arr.print();

    // Копирование
    DynamicArray arr2 = arr;
    std::cout << "\nCopied array:\n";
    arr2.print();

    // Перемещение
    DynamicArray arr3 = std::move(arr);
    std::cout << "\nMoved array:\n";
    arr3.print();
    std::cout << "\nOriginal array after move (size): " << arr.getSize() << "\n";

    // Удаление элемента
    arr3.remove(0);
    std::cout << "\nArray after removal:\n";
    arr3.print();

    return 0;
}
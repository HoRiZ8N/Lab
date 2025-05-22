#include <iostream>
#include <vector>
#pragma once
using namespace std;

// Функция меняет элементы местами
void swap(int *a, int *b) {
  int temp = *b;
  *b = *a;
  *a = temp;
}

// Функция сортирует
void heapify(vector<int> &hT, int i) {
  int size = hT.size();

  // Находим самое большое значение среди
  // корневого, правого и левого дочернего элемента
  int largest = i;
  int l = 2 * i + 1;
  int r = 2 * i + 2;
  if (l < size && hT[l] > hT[largest])
    largest = l;
  if (r < size && hT[r] > hT[largest])
    largest = r;

  // Меняем местами и продолжаем сортировку,
  // если значение корневого элемента не самое большое
  if (largest != i) {
    swap(&hT[i], &hT[largest]);
    heapify(hT, largest);
  }
}

// Функция вставляет элемент
void insert(vector<int> &hT, int newNum) {
  int size = hT.size();
  if (size == 0) {
    hT.push_back(newNum);
  } else {
    hT.push_back(newNum);
    for (int i = size / 2 - 1; i >= 0; i--) {
      heapify(hT, i);
    }
  }
}

// Функция удаляет элемент
void deleteNode(vector<int> &hT, int num) {
  int size = hT.size();
  int i;
  for (i = 0; i < size; i++) {
    if (num == hT[i])
      break;
  }
  swap(&hT[i], &hT[size - 1]);

  hT.pop_back();
  for (int i = size / 2 - 1; i >= 0; i--) {
    heapify(hT, i);
  }
}

// Выводим дерево в консоль
void printArray(vector<int> &hT) {
  for (int i = 0; i < hT.size(); ++i)
    cout << hT[i] << " ";
  cout << "\n";
}

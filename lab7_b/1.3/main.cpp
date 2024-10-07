#include <iostream>
#include <algorithm>

const int SIZE = 50;
const int k = 228;
int* array = new int[SIZE];
int* newArray = new int[SIZE];
void printArray(int* arr) {
    for (int i = 0; i < SIZE; i++) {
        std::cout << arr[i] << ' ';
    }
    std::cout << "\n\n";
}

void enterArray(int* arr) {
    for (int i = 0; i < SIZE; i++)
    {
        std::cin >> arr[i];
    }
}

void randomArray(int* arr) {
    for (int i = 0; i < SIZE; i++) {
        arr[i] = rand() % 100;
    }
    
}

void copyArray(int* arrToCopy, int* arrFromCopying) {
    for (int i = 0; i < SIZE; i++) {
        arrToCopy[i] = arrFromCopying[i];
    }
}

int* findMax(int* newarr, int* arr) {
    int* maxValPtr = nullptr;
    for (int i = 0; i < SIZE - 2; i++) {
        if (newarr[i] == newarr[i + 1] && newarr[i] != newarr[i + 2]) {
            maxValPtr = newarr + i;
            break;
        }
    }
    if (newarr[SIZE - 2] == newarr[SIZE - 1] && maxValPtr == nullptr) {
        maxValPtr = &(newarr[SIZE - 2]);
    }
    if (maxValPtr == nullptr) {
        maxValPtr = newarr;
    }
    
    if (maxValPtr != nullptr) {
        for (int i = 0; i < SIZE; i++) {
            if (*maxValPtr == arr[i]) {
                maxValPtr = arr + i;
                break;
            }
        }
    }
     
    return maxValPtr;
}

enum enterType{
    keyboard = 1,
    random = 2
};

enum enterType type = random;

int main() {
    srand(time(0));
    switch (type) {
    case 1:
        enterArray(array);
        break;
    case 2:
        randomArray(array);
        break;
    default:
        return 1;
    }
    copyArray(newArray, array);
    std::sort(newArray, newArray + SIZE, 
    [](int a, int b){
        return a > b;
    });
    int* maxVal = findMax(newArray, array);
    delete[] newArray;
    printArray(array);
    *maxVal = k;
    printArray(array);
    delete[] array;

    return 0;
}
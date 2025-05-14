#include "../6.2/DynamicArray.h"

int main() {
    DynamicArray arr;
    arr.load("data.txt");
    arr.save("data.txt");
    return 0;
}
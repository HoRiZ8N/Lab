#include "DynamicArray.h"

void DynamicArray::resize() {
    capacity = (capacity == 0) ? 1 : capacity * 2;
    SpaceEntity** newData = new SpaceEntity*[capacity];
    for (size_t i = 0; i < size; ++i) {
        newData[i] = data[i]->clone();
    }
    delete[] data;
    data = newData;
}

DynamicArray::DynamicArray(const DynamicArray& other) : 
    data(new SpaceEntity*[other.capacity]), 
    size(other.size), 
    capacity(other.capacity) 
{
    for (size_t i = 0; i < size; ++i) {
        data[i] = other.data[i]->clone();
    }
}

DynamicArray::DynamicArray(DynamicArray&& other) : 
    data(other.data), 
    size(other.size), 
    capacity(other.capacity) 
{
    other.data = nullptr;
    other.size = other.capacity = 0;
}

DynamicArray& DynamicArray::operator=(const DynamicArray& other) {
    if (this != &other) {
        for (size_t i = 0; i < size; ++i) {
            delete data[i];
        }
        if (capacity < other.size) {
            delete[] data;
            capacity = other.size;
            data = new SpaceEntity*[capacity];
        }
        size = other.size;
        for (size_t i = 0; i < size; ++i) {
            data[i] = other.data[i]->clone();
        }
    }
    return *this;
}

DynamicArray& DynamicArray::operator=(DynamicArray&& other) {
    if (this != &other) {
        clear();
        data = other.data;
        size = other.size;
        capacity = other.capacity;
        other.data = nullptr;
        other.size = other.capacity = 0;
    }
    return *this;
}

DynamicArray::~DynamicArray() {
    clear();
}

void DynamicArray::add(const SpaceEntity* entity) {
    if (size >= capacity) resize();
    data[size++] = entity->clone();
}

void DynamicArray::remove(size_t index) {
    if (index >= size) throw std::out_of_range("Index out of range");
    delete data[index];
    for (size_t i = index; i < size - 1; ++i) {
        data[i] = data[i + 1];
    }
    --size;
}

void DynamicArray::print() const {
    for (size_t i = 0; i < size; ++i) {
        data[i]->Print(std::cout);
        std::cout << "\n";
    }
}

void DynamicArray::clear() {
    for (size_t i = 0; i < size; ++i) {
        delete data[i];
    }
    delete[] data;
    data = nullptr;
    size = capacity = 0;
}
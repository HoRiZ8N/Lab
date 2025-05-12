#pragma once

#include <iostream>
#include <stdexcept>
#include "../6.1/header.h"

class DynamicArray {
private:
    SpaceEntity** data = nullptr;
    size_t size = 0;
    size_t capacity = 0;
    void resize();

public:
    DynamicArray() = default;
    DynamicArray(const DynamicArray& other);
    DynamicArray(DynamicArray&& other);
    DynamicArray& operator=(const DynamicArray& other);
    DynamicArray& operator=(DynamicArray&& other);
    ~DynamicArray();

    void add(const SpaceEntity* entity);
    void remove(size_t index);
    void print() const;
    void clear();
    size_t getSize() const { return size; }
};

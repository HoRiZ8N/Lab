#pragma once

#include <iostream>
#include <ostream>
#include <istream>

template <typename T>
class MyVector
{
public:
    MyVector(); // default constructor
    MyVector(size_t capacity); // parameterized constructor
    MyVector(const MyVector &other); // copy constructor
    MyVector(MyVector &&move) noexcept; // move constructor
    MyVector &operator=(const MyVector &other); // copy assignment operator
    MyVector &operator=(MyVector &&other) noexcept; // move assignment operator
    ~MyVector(); // destructor

    void PushBack(T data);
    T &operator[](size_t index);
    const T &operator[](size_t index) const;

    friend std::ostream &operator<<(std::ostream &os, const MyVector &vector);
    friend std::istream &operator>>(std::istream &is, MyVector<T> &vector);

    size_t Size() const;
    size_t Capacity() const;

private:
    void ReAlloc(size_t newCapacity);

    T *m_Data = nullptr;
    size_t m_Size = 0;
    size_t m_Capacity = 0;
};
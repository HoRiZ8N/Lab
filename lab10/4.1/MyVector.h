#pragma once

#include <iostream>
#include <ostream>
#include <istream>
#include <stdexcept>

template <typename T>
class MyVector
{
public:
    MyVector(); 
    MyVector(size_t size, const T& initialValue);
    MyVector(size_t capacity); 
    MyVector(const MyVector &other);
    MyVector(MyVector &&move); 
    MyVector &operator=(const MyVector &other);
    MyVector &operator=(MyVector &&other); 
    ~MyVector();

    void PushBack(T data);
    T &operator[](size_t index);
    const T &operator[](size_t index) const;

    template <typename U>
    friend std::ostream &operator<<(std::ostream &os, const MyVector<U> &vector);

    template <typename U>
    friend std::istream &operator>>(std::istream &is, MyVector<U> &vector);

    size_t Size() const;
    size_t Capacity() const;
    void Resize(size_t newSize, const T& value = T());

private:
    void ReAlloc(size_t newCapacity);

    T *m_Data = nullptr;
    size_t m_Size = 0;
    size_t m_Capacity = 0;
};

template <typename T>
MyVector<T>::MyVector(size_t size, const T& initialValue) {
    ReAlloc(size);
    for (size_t i = 0; i < size; ++i) {
        m_Data[i] = initialValue;
    }
    m_Size = size;
}

template <typename T>
MyVector<T>::MyVector()
{
    ReAlloc(4);
}

template <typename T>
MyVector<T>::MyVector(size_t capacity)
{
    ReAlloc(capacity);
}

template <typename T>
MyVector<T>::MyVector(const MyVector &other)
    : m_Size(other.m_Size), m_Capacity(other.m_Capacity)
{
    m_Data = new T[m_Capacity];
    for (size_t i = 0; i < m_Size; i++)
    {
        m_Data[i] = other.m_Data[i];
    }
}

template <typename T>
MyVector<T>::MyVector(MyVector &&move)
    : m_Data(move.m_Data), m_Size(move.m_Size), m_Capacity(move.m_Capacity)
{
    move.m_Data = nullptr;
    move.m_Size = 0;
    move.m_Capacity = 0;
}

template <typename T>
MyVector<T> &MyVector<T>::operator=(const MyVector &other)
{
    if (this != &other)
    {
        delete[] m_Data;

        m_Size = other.m_Size;
        m_Capacity = other.m_Capacity;
        m_Data = new T[m_Capacity];
        for (size_t i = 0; i < m_Size; ++i)
        {
            m_Data[i] = other.m_Data[i];
        }
    }
    return *this;
}

template <typename T>
MyVector<T> &MyVector<T>::operator=(MyVector &&other)
{
    if (this != &other)
    {
        delete[] m_Data;

        m_Data = other.m_Data;
        m_Size = other.m_Size;
        m_Capacity = other.m_Capacity;

        other.m_Data = nullptr;
        other.m_Size = 0;
        other.m_Capacity = 0;
    }
    return *this;
}

template <typename T>
MyVector<T>::~MyVector()
{
    delete[] m_Data;
}

template <typename T>
void MyVector<T>::PushBack(T data)
{
    if (m_Capacity <= m_Size)
    {
        ReAlloc(m_Capacity * 2);
    }
    m_Data[m_Size++] = data;
}

template <typename T>
T &MyVector<T>::operator[](size_t index)
{
    if (index >= m_Capacity)
    {
        throw std::out_of_range("Index out of range");
    }
    return m_Data[index];
}

template <typename T>
const T &MyVector<T>::operator[](size_t index) const
{
    if (index >= m_Capacity)
    {
        throw std::out_of_range("Index out of range");
    }
    return m_Data[index];
}

template <typename T>
std::ostream &operator<<(std::ostream &os, const MyVector<T> &vector)
{
    for (size_t i = 0; i < vector.m_Size; i++)
    {
        os << vector.m_Data[i] << " ";
    }
    return os;
}

template <typename T>
std::istream &operator>>(std::istream &is, MyVector<T> &vector)
{
    T value;
    while (is >> value)
    {
        vector.PushBack(value);
    }
    return is;
}

template <typename T>
size_t MyVector<T>::Size() const
{
    return m_Size;
}

template <typename T>
size_t MyVector<T>::Capacity() const
{
    return m_Capacity;
}

template <typename T>
void MyVector<T>::ReAlloc(size_t newCapacity)
{
    T *newBlock = new T[newCapacity];
    for (size_t i = 0; i < m_Size; i++)
    {
        newBlock[i] = m_Data[i];
    }
    delete[] m_Data;
    m_Data = newBlock;
    m_Capacity = newCapacity;
}

template <typename T>
void MyVector<T>::Resize(size_t newSize, const T& value) 
{
    if (newSize > m_Capacity) {
        ReAlloc(newSize);
    }
    for (size_t i = m_Size; i < newSize; ++i) {
        m_Data[i] = value;
    }
    m_Size = newSize;
}



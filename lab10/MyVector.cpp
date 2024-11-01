#include "MyVector.h"

// Default constructor
template <typename T>
MyVector<T>::MyVector()
{
    ReAlloc(4);
}

// Parameterized constructor
template <typename T>
MyVector<T>::MyVector(size_t capacity)
{
    ReAlloc(capacity);
}

// Copy constructor
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

// Move constructor
template <typename T>
MyVector<T>::MyVector(MyVector &&move) noexcept
    : m_Data(move.m_Data), m_Size(move.m_Size), m_Capacity(move.m_Capacity)
{
    move.m_Data = nullptr;
    move.m_Size = 0;
    move.m_Capacity = 0;
}

// Copy assignment operator
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

// Move assignment operator
template <typename T>
MyVector<T> &MyVector<T>::operator=(MyVector &&other) noexcept
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

// Destructor
template <typename T>
MyVector<T>::~MyVector()
{
    delete[] m_Data;
}

// PushBack method
template <typename T>
void MyVector<T>::PushBack(T data)
{
    if (m_Capacity <= m_Size)
    {
        ReAlloc(m_Capacity * 2);
    }
    m_Data[m_Size++] = data;
}

// Indexing operator
template <typename T>
T &MyVector<T>::operator[](size_t index)
{
    if (index >= m_Size)
    {
        throw std::out_of_range("Index out of range");
    }
    return m_Data[index];
}

// Const indexing operator
template <typename T>
const T &MyVector<T>::operator[](size_t index) const
{
    if (index >= m_Size)
    {
        throw std::out_of_range("Index out of range");
    }
    return m_Data[index];
}

// Output operator
template <typename T>
std::ostream &operator<<(std::ostream &os, const MyVector<T> &vector)
{
    os << "{";
    for (size_t i = 0; i < vector.m_Size; i++)
    {
        os << vector.m_Data[i];
        if (i < vector.m_Size - 1)
        {
            os << ", ";
        }
    }
    os << "}";
    return os;
}

// Input operator
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

// Size method
template <typename T>
size_t MyVector<T>::Size() const
{
    return m_Size;
}

// Capacity method
template <typename T>
size_t MyVector<T>::Capacity() const
{
    return m_Capacity;
}

// ReAlloc method
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

#pragma once 
#include <iostream>

template <typename T>
class DoubleLinkedList
{
public:
    DoubleLinkedList();
    DoubleLinkedList(T data); 
    DoubleLinkedList(const DoubleLinkedList &other); 
    DoubleLinkedList(DoubleLinkedList &&move) noexcept; 
    ~DoubleLinkedList();
    DoubleLinkedList &operator=(const DoubleLinkedList &other); 
    DoubleLinkedList &operator=(DoubleLinkedList &&other) noexcept; 

    T& operator[](unsigned int index);
    const T& operator[](unsigned int index) const;

    void Insert(T data); 
    void Remove(T data);
    void Print() const;
    void Clear(); 
    T* Find(const T& key) const;
    int Size() const;  

private:
    struct Node
    {
        Node* m_next;
        Node* m_prev;
        T m_data;

        Node() : m_next(nullptr), m_prev(nullptr) {}
        Node(T myData) : m_next(nullptr), m_prev(nullptr), m_data(myData) {}
    };

    Node* head;
    Node* tail;
    unsigned int size;
};

template <typename T>
DoubleLinkedList<T>::DoubleLinkedList() : head(nullptr), tail(nullptr), size(0) {}

template <typename T>
DoubleLinkedList<T>::DoubleLinkedList(T data) : head(new Node(data)), tail(head), size(1) {}

template <typename T>
DoubleLinkedList<T>::DoubleLinkedList(const DoubleLinkedList &other) : head(nullptr), tail(nullptr)
{
    if (other.head == nullptr) return;

    head = new Node(other.head->m_data);
    tail = head;
    size = other.size;
    Node* current = head;
    Node* otherCurrent = other.head->m_next;

    while (otherCurrent != nullptr)
    {
        current->m_next = new Node(otherCurrent->m_data);
        current->m_next->m_prev = current;
        current = current->m_next;
        otherCurrent = otherCurrent->m_next;
    }
    tail = current;
}

template <typename T>
DoubleLinkedList<T>::DoubleLinkedList(DoubleLinkedList &&move) noexcept : head(move.head), tail(move.tail)
{
    move.head = nullptr;
    move.tail = nullptr;
}

template <typename T>
DoubleLinkedList<T>::~DoubleLinkedList()
{
    Clear();
}

template <typename T>
DoubleLinkedList<T> &DoubleLinkedList<T>::operator=(const DoubleLinkedList &other)
{
    if (this != &other) // Check for self-assignment
    {
        Clear(); // Clean up current list
        if (other.head == nullptr) return *this; // Handle empty list

        head = new Node(other.head->m_data);
        tail = head;
        Node* current = head;
        Node* otherCurrent = other.head->m_next;

        while (otherCurrent != nullptr)
        {
            current->m_next = new Node(otherCurrent->m_data);
            current->m_next->m_prev = current;
            current = current->m_next;
            otherCurrent = otherCurrent->m_next;
        }
        tail = current; // Update tail
    }
    return *this;
}

template <typename T>
DoubleLinkedList<T> &DoubleLinkedList<T>::operator=(DoubleLinkedList &&other) noexcept
{
    if (this != &other) // Check for self-assignment
    {
        Clear(); // Clean up current list
        head = other.head;
        tail = other.tail;
        other.head = nullptr;
        other.tail = nullptr;
    }
    return *this;
}

template <typename T>
void DoubleLinkedList<T>::Insert(T data)
{
    Node* newNode = new Node(data);
    if (head == nullptr)
    {
        head = newNode;
        tail = newNode;
        size++;
    }
    else
    {
        tail->m_next = newNode;
        newNode->m_prev = tail;
        tail = newNode;
        size++;
    }
}

template <typename T>
void DoubleLinkedList<T>::Remove(T data)
{
    Node* current = head;
    while (current != nullptr)
    {
        if (current->m_data == data)
        {
            if (current->m_prev) current->m_prev->m_next = current->m_next;
            if (current->m_next) current->m_next->m_prev = current->m_prev;
            if (current == head) head = current->m_next;
            if (current == tail) tail = current->m_prev;
            delete current;
            --size;
            return;
        }
        current = current->m_next;
    }
}


template <typename T>
void DoubleLinkedList<T>::Print() const
{
    Node* current = head;
    while (current != nullptr)
    {
        std::cout << current->m_data << " ";
        current = current->m_next;
    }
    std::cout << std::endl;
}

template <typename T>
void DoubleLinkedList<T>::Clear()
{
    Node* current = head;
    while (current != nullptr)
    {
        Node* nextNode = current->m_next;
        delete current;
        current = nextNode;
    }
    head = nullptr;
    tail = nullptr;
    size = 0;
}

template <typename T>
T* DoubleLinkedList<T>::Find(const T& key) const
{
    Node* current = head;
    while (current != nullptr)
    {
        if (current->m_data == key)
        {
            return &current->m_data;
        }
        current = current->m_next;
    }
    return nullptr;
}

template <typename T>
int DoubleLinkedList<T>::Size() const
{
    return size;
}

template <typename T>
T& DoubleLinkedList<T>::operator[](unsigned int index)
{
    if (index >= size)
    {
        throw std::out_of_range("Index out of range");
    }

    Node* current = head;
    for (unsigned int i = 0; i < index; ++i)
    {
        current = current->m_next;
    }

    return current->m_data;
}

template <typename T>
const T& DoubleLinkedList<T>::operator[](unsigned int index) const
{
    if (index >= size)
    {
        throw std::out_of_range("Index out of range");
    }

    Node* current = head;
    for (unsigned int i = 0; i < index; ++i)
    {
        current = current->m_next;
    }

    return current->m_data;
}


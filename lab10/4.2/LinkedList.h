#pragma once
#include <iostream>
#include <ostream>
#include <istream>

template <typename T>
class LinkedList
{
public:
    LinkedList(); // default constructor
    LinkedList(T data); // constructor with initial data
    LinkedList(const LinkedList &other); // copy constructor
    LinkedList(LinkedList &&move) noexcept; // move constructor
    ~LinkedList(); // destructor
    LinkedList &operator=(const LinkedList &other); // copy assignment operator
    LinkedList &operator=(LinkedList &&other) noexcept; // move assignment operator
    void PushBack(T data); // add an element to the end
    void Push(T data, size_t index);
    T Search(size_t index); // Search an element by index
    void Pop(size_t index); // delete an element by index
    void PopBack(); // delete last
    size_t Size(); // get the size of the list

    friend std::ostream &operator<<(std::ostream &os, const LinkedList &list) {
        typename LinkedList<T>::Node* current = list.head;
        while (current != nullptr) {
            os << current->m_data;
            if (current->m_next != nullptr) {
                os << " ";
            }
            current = current->m_next;
        }
        os << " ";
        return os;
    }
    friend std::istream &operator>>(std::istream &is, LinkedList<T> &list) {
        T value;
        list.Clear();
        while (is >> value) {
            list.PushBack(value);
        }
        return is;
    }

private:
    struct Node
    {
        Node* m_next;
        T m_data;

        Node() : m_next(nullptr) {}
        Node(T myData) : m_next(nullptr), m_data(myData) {}
    };

    Node* head;

    void Clear();
};

template <typename T>
LinkedList<T>::LinkedList() : head(nullptr) {}

template <typename T>
LinkedList<T>::LinkedList(T data)
{
    head = new Node(data);
}

template <typename T>
LinkedList<T>::LinkedList(const LinkedList &other) : head(nullptr)
{
    if (other.head == nullptr) return;

    head = new Node(other.head->m_data);
    Node* current = head;
    Node* otherCurrent = other.head->m_next;

    while (otherCurrent != nullptr)
    {
        current->m_next = new Node(otherCurrent->m_data);
        current = current->m_next;
        otherCurrent = otherCurrent->m_next;
    }
}

template <typename T>
LinkedList<T>::LinkedList(LinkedList &&move) noexcept : head(move.head)
{
    move.head = nullptr;
}

template <typename T>
LinkedList<T>::~LinkedList()
{
    Clear();
}


template <typename T>
LinkedList<T> &LinkedList<T>::operator=(const LinkedList &other)
{
    if (this == &other) return *this;

    Clear();

    if (other.head == nullptr) return *this;

    head = new Node(other.head->m_data);
    Node* current = head;
    Node* otherCurrent = other.head->m_next;

    while (otherCurrent != nullptr)
    {
        current->m_next = new Node(otherCurrent->m_data);
        current = current->m_next;
        otherCurrent = otherCurrent->m_next;
    }

    return *this;
}

template <typename T>
LinkedList<T>& LinkedList<T>::operator=(LinkedList&& other) noexcept
{
    Clear(); 
    head = other.head; 
    other.head = nullptr; 

    return *this;
}

template <typename T>
void LinkedList<T>::PushBack(T data)
{
    if (head == nullptr)
    {
        head = new Node(data);
    }
    else
    {
        Node* temp = head;
        while (temp->m_next != nullptr)
        {
            temp = temp->m_next;
        }
        temp->m_next = new Node(data);
    }
}

template <typename T>
void LinkedList<T>::Push(T data, size_t index)
{
    if (index > this->Size())
    {
        throw std::out_of_range("Index out of range");
    }

    Node* newNode = new Node(data);

    if (index == 0)
    {
        newNode->m_next = head;
        head = newNode;
        return;
    }

    Node* current = head;
    for (size_t i = 0; i < index - 1; ++i)
    {
        current = current->m_next;
    }

    newNode->m_next = current->m_next;
    current->m_next = newNode;
}

template <typename T>
T LinkedList<T>::Search(size_t index)
{
    if (index >= this->Size())
    {
        throw std::out_of_range("Index out of range");
    }

    Node* current = head;
    for (size_t i = 0; i < index; ++i)
    {
        current = current->m_next;
    }

    return current->m_data;
}

template <typename T>
void LinkedList<T>::Pop(size_t index)
{
    if (head == nullptr || index >= this->Size())
    {
        throw std::out_of_range("Index out of range");
    }

    if (index == 0)
    {
        Node* temp = head;
        head = head->m_next;
        delete temp;
        return;
    }

    Node* current = head;
    for (size_t i = 0; i < index - 1; ++i)
    {
        current = current->m_next;
    }

    Node* toDelete = current->m_next;
    current->m_next = toDelete->m_next;
    delete toDelete;
}

template <typename T>
void LinkedList<T>::PopBack()
{
    if (head == nullptr)
    {
        return;
    }

    if (head->m_next == nullptr)
    {
        delete head;
        head = nullptr;
        return;
    }

    Node* current = head;
    while (current->m_next->m_next != nullptr)
    {
        current = current->m_next;
    }

    delete current->m_next;
    current->m_next = nullptr;
}

template <typename T>
size_t LinkedList<T>::Size()
{
    size_t size = 0;
    Node* temp = head;
    while (temp != nullptr)
    {
        size++;
        temp = temp->m_next;
    }
    return size;
}

template <typename T>
void LinkedList<T>::Clear()
{
    Node* current = head;
    while (current != nullptr)
    {
        Node* next = current->m_next;
        delete current;
        current = next;
    }
    head = nullptr;
}

#pragma once
#include <stdexcept>

class DoubleLinkedList
{
private:
    struct Node
    {
        double value;
        Node *prev;
        Node *next;

        Node(double val) : value(val), prev(nullptr), next(nullptr) {}
    };

    Node *head;
    Node *tail;
    int size;

public:
    DoubleLinkedList();
    ~DoubleLinkedList();

    void append(double value);
    double computeExpression();
    double getValueAt(int index) const;
};

double DoubleLinkedList::computeExpression()
{
    if (size < 2)
        return 0.0;

    double result = 0.0;

    for (int i = 0; i < size - 1; ++i)
    {
        double a = getValueAt(i);
        double b = getValueAt(i + 1);
        double c = getValueAt(size - 2 - i);

        result += a + b + (size - i) * c;
    }

    return result;
}

double DoubleLinkedList::getValueAt(int index) const
{
    if (index < 0 || index >= size)
    {
        throw std::out_of_range("Index out of range");
    }

    Node *current = head;
    for (int i = 0; i < index; ++i)
    {
        current = current->next;
    }

    return current->value;
}

void DoubleLinkedList::append(double value)
{
    Node *newNode = new Node(value);
    if (!head)
    {
        head = tail = newNode;
    }
    else
    {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
    size++;
}

DoubleLinkedList::DoubleLinkedList() : head(nullptr), tail(nullptr), size(0) {}

DoubleLinkedList::~DoubleLinkedList()
{
    Node *current = head;
    while (current)
    {
        Node *nextNode = current->next;
        delete current;
        current = nextNode;
    }
}
#pragma once

template <typename T>
class LinkedList
{
    T *values;
    int *next;
    int size;
    int head;
    int free;

public:
    LinkedList(int size);
    ~LinkedList();

    void add(T value);
    void insert(T value, int position);
    void remove(int position);
    void print();
    int find(T value);
    int listSize();
    LinkedList<T> formListWithTwoOccurrences();
};

template <typename T>
LinkedList<T>::LinkedList(int size)
{
    this->size = size;
    values = new T[size];
    next = new int[size];
    for (int i = 0; i < size; ++i)
    {
        next[i] = i + 1;
    }
    next[size - 1] = -1;
    head = -1;
    free = 0;
}

template <typename T>
LinkedList<T>::~LinkedList()
{
    delete[] values;
    delete[] next;
    values = nullptr;
    next = nullptr;
}

template <typename T>
void LinkedList<T>::add(T value)
{
    if (free == -1)
    {
        std::cout << "[No free space to add element]\n";
        return;
    }
    int newElement = free;
    free = next[free];
    values[newElement] = value;
    next[newElement] = head;
    head = newElement;
}

template <typename T>
void LinkedList<T>::insert(T value, int position)
{
    if (free == -1)
    {
        return;
    }
    int newElement = free;
    free = next[free];
    values[newElement] = value;

    if (position == 0)
    {
        next[newElement] = head;
        head = newElement;
        return;
    }

    int current = head;
    for (int i = 0; i < position - 1; ++i)
    {
        if (current == -1)
        {
            return;
        }
        current = next[current];
    }

    next[newElement] = next[current];
    next[current] = newElement;
}

template <typename T>
void LinkedList<T>::remove(int position)
{
    if (head == -1)
    {
        std::cout << "[List is empty.]\n";
        return;
    }

    if (position < 0 || position >= listSize())
    {
        std::cout << "[Invalid position.]\n";
        return;
    }

    if (position == 0)
    {
        int temp = head;
        head = next[head];
        next[temp] = free;
        free = temp;
        return;
    }

    int current = head;
    for (int i = 0; i < position - 1; ++i)
    {
        current = next[current];
    }

    int temp = next[current];
    next[current] = next[temp];
    next[temp] = free;
    free = temp;
}

template <typename T>
int LinkedList<T>::find(T value)
{
    int current = head;
    int position = 0;
    while (current != -1)
    {
        if (values[current] == value)
        {
            return position;
        }
        current = next[current];
        position++;
    }
    return -1;
}

template <typename T>
void LinkedList<T>::print()
{
    int current = head;
    while (current != -1)
    {
        std::cout << values[current] << " ";
        current = next[current];
    }
    std::cout << "\n";
}

template <typename T>
int LinkedList<T>::listSize()
{
    int current = head;
    int count = 0;
    while (current != -1)
    {
        count++;
        current = next[current];
    }
    return count;
}

template <typename T>
LinkedList<T> LinkedList<T>::formListWithTwoOccurrences()
{
    LinkedList<T> result(size);
    T *toRemove = new T[size];
    int toRemoveCount = 0;
    int current = head;

    while (current != -1)
    {
        T value = values[current];
        int occurrences = 0;
        int temp = head;
        while (temp != -1)
        {
            if (values[temp] == value)
            {
                occurrences++;
            }
            temp = next[temp];
        }
        if (occurrences == 2 && result.find(value) == -1)
        {
            result.add(value);
            toRemove[toRemoveCount++] = value;
        }
        current = next[current];
    }

    for (int i = 0; i < toRemoveCount; ++i)
    {
        T value = toRemove[i];
        int pos = find(value);
        while (pos != -1)
        {
            remove(pos);
            pos = find(value);
        }
    }

    delete[] toRemove;
    return result;
}

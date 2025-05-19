#pragma once
#include <iostream>

template <typename T>
class LinkedList {
private:
    struct Node {
        T* data;
        Node* next;
        Node(T* obj) : data(obj), next(nullptr) {}
        ~Node() { delete data; }
    };

    Node* head;

    void copyFrom(const LinkedList& other) {
        Node* current = other.head;
        while (current) {
            add(current->data->clone());
            current = current->next;
        }
    }

    void clear() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

public:
    LinkedList() : head(nullptr) {}
    ~LinkedList() { clear(); }
    LinkedList(const LinkedList& other) : head(nullptr) { copyFrom(other); }
    LinkedList(LinkedList&& other) : head(other.head) { other.head = nullptr; }
    
    LinkedList& operator=(const LinkedList& other) {
        if (this != &other) {
            clear();
            copyFrom(other);
        }
        return *this;
    }

    LinkedList& operator=(LinkedList&& other) noexcept {
        if (this != &other) {
            clear();
            head = other.head;
            other.head = nullptr;
        }
        return *this;
    }

    void add(T* obj) {
        Node* newNode = new Node(obj);
        newNode->next = head;
        head = newNode;
    }

    void remove(const T* obj) {
        Node** current = &head;
        while (*current) {
            if ((*current)->data == obj) {
                Node* temp = *current;
                *current = temp->next;
                delete temp;
                break;
            }
            current = &(*current)->next;
        }
    }

    void print(std::ostream& os = std::cout) const {
        Node* current = head;
        while (current) {
            current->data->print(os);
            os << "\n";
            current = current->next;
        }
    }

    LinkedList clone() const {
        LinkedList copy;
        Node* current = head;
        while (current) {
            copy.add(current->data->clone());
            current = current->next;
        }
        return copy;
    }
};
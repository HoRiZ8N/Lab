#include <iostream>

struct Node {
    char symb;
    Node* next;
    Node() {
        next = nullptr;
    }
};

void freeList(Node* head) {
    Node* current = head;
    Node* nextNode;

    while (current != nullptr) {
        nextNode = current->next;
        delete current;
        current = nextNode; 
    }
}

void printNodeVal(Node* head) {
    Node* curr = head;
    while (curr->next != nullptr) {
        curr = curr->next;
        std::cout << curr->symb << ' ';
    }  
    std::cout << '\n';
}

int main() {
    int size;
    int numOfSymbols[256] = {};
    Node* head = new Node;
    Node* curr = head;

    std::cout << "Enter array size: ";
    std::cin >> size; 
    std::cout << "\nEnter " << size << " symbols: ";

    for (int i = 0; i < size; i++) {
        Node* newNode = new Node;
        char s;
        std::cin >> s;
        curr->next = newNode;
        newNode->symb = s;
        numOfSymbols[s]++;
        curr = curr->next;
    }

    std::cout << "Values:\n";
    printNodeVal(head);

    Node* newHead = new Node;
    Node* newCurr = newHead;
    curr = head;
    
    for (int i = 0; i < size; i++) {
        if (numOfSymbols[int(curr->next->symb)] == 2) {
            numOfSymbols[int(curr->next->symb)] = 0;
            Node* newNode = new Node;
            newCurr->next = newNode;
            newNode->symb = curr->next->symb;
            newCurr = newCurr->next;
        }
        curr = curr->next;
    }
    
    std::cout << "\nSymbols that appear exactly twice:\n";
    printNodeVal(newHead);

    freeList(head);
    freeList(newHead);

    return 0;
}
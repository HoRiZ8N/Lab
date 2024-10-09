#include <iostream>
#include <algorithm>
#include <cstring>
#include <fstream>

const int STRING_SIZE = 100;

struct Node {
    char birthDate[STRING_SIZE];
    char fullName[STRING_SIZE];
    int year;
    float mark;
    Node* next;
    Node(const char* FullName, const char* BirthDate, int Year, float Mark) {
        strcpy(birthDate, BirthDate);
        strcpy(fullName, FullName);
        year = Year;
        mark = Mark;
        next = nullptr;
    }
    Node() {
        next = nullptr;
    }
};

void addNode(Node* head, const char* FullName, const char* BirtDate, int Year, float Mark) {
    Node* curr = head;
    Node* newNode = new Node(FullName, BirtDate, Year, Mark);
    if (head->next == nullptr) {
        head->next = newNode; 
        return;
    }
    while (curr->next != nullptr && strcmp(curr->next->fullName, newNode->fullName) < 0) {
        curr = curr->next;
    }  
    newNode->next = curr->next;
    curr->next = newNode;
}

void printNames(Node* head) {
    Node* curr = head;
    while (curr->next != nullptr) {
        curr = curr->next;
        std::cout << curr->fullName << '\n';
    }  
    std::cout << '\n';
}

void freeList(Node* head) {
    Node* current = head;
    Node* nextNode;

    while (current != nullptr) {
        nextNode = current->next;
        delete current;
        current = nextNode; 
    }
}

void removeNode(Node* head, Node* toRemove) {
    Node* curr = head;
    while (curr->next != toRemove) {
        curr->next = curr->next->next;
    }
}

int main() {
    std::ifstream fin;
    fin.open("input.txt");
    Node* head = new Node;
    int size;
    fin >> size;
    for (int i = 0; i < size; i++) {
        char birthdate[STRING_SIZE], fullname[STRING_SIZE] = "", name[STRING_SIZE], surname[STRING_SIZE], secondsurname[STRING_SIZE];
        int year;
        float mark;
        fin >> surname >> name >> secondsurname >> birthdate >> year >> mark;
        strcpy(fullname, surname);
        strcat(fullname, " ");
        strcat(fullname, name);
        strcat(fullname, " ");
        strcat(fullname, secondsurname);
        strcat(fullname, " ");
        addNode(head, fullname, birthdate, year, mark);
    }
    printNames(head);
    char letter;
    fin >> letter;
    Node* newHead = new Node;
    Node* curr = head;
    while (curr != nullptr) {
        if (curr->fullName[0] == letter) {
            addNode(newHead, curr->fullName, curr->birthDate, curr->year, curr->mark);
            removeNode(head, curr);
        }
        curr = curr->next;
    }
    printNames(newHead);

    freeList(head);
    freeList(newHead);
    fin.close();
    return 0;
}
#include <iostream>
#include <cstring>
#include <fstream>

const int STRING_SIZE = 100;

struct Student
{
    char fullName[STRING_SIZE];
    char birthDate[STRING_SIZE];
    int year;
    float mark;
    Student(const char *FullName, const char *BirthDate, int Year, float Mark)
    {
        strcpy(fullName, FullName);
        strcpy(birthDate, BirthDate);
        year = Year;
        mark = Mark;
    }
    Student() {}
};

struct Node
{
    Student data;
    Node *next;
    Node(const Student &student) : data(student), next(nullptr) {}
    Node() : next(nullptr) {}
};

void addNode(Node *head, const Student &student)
{
    Node *curr = head;
    Node *newNode = new Node(student);

    if (head->next == nullptr)
    {
        head->next = newNode;
        return;
    }
    
    while (curr->next != nullptr && strcmp(curr->next->data.fullName, newNode->data.fullName) < 0)
    {
        curr = curr->next;
    }
    
    newNode->next = curr->next;
    curr->next = newNode;
}

void printNames(Node *head)
{
    Node *curr = head;
    while (curr->next != nullptr)
    {
        curr = curr->next;
        std::cout << curr->data.fullName << '\n';
    }
    std::cout << '\n';
}

void deleteList(Node *head)
{
    Node *current = head;
    Node *nextNode;

    while (current != nullptr)
    {
        nextNode = current->next;
        delete current;
        current = nextNode;
    }
}

void removeNode(Node *head, Node *toRemove)
{
    Node *curr = head;
    while (curr != nullptr && curr->next != toRemove)
    {
        curr = curr->next;
    }
    
    if (curr != nullptr && curr->next == toRemove)
    {
        Node *temp = curr->next;
        curr->next = curr->next->next;
        delete temp;
    }
}

int main()
{
    std::ifstream fin("input.txt");

    Node *head = new Node;
    int size;
    fin >> size;

    for (int i = 0; i < size; i++)
    {
        char birthDate[STRING_SIZE], fullName[STRING_SIZE] = "", name[STRING_SIZE] = "", 
            surname[STRING_SIZE] = "", secondSurname[STRING_SIZE] = "";
        int year;
        float mark;
        fin >> surname >> name >> secondSurname >> birthDate >> year >> mark;
        
        strcat(fullName, surname);
        strcat(fullName, " ");
        strcat(fullName, name);
        strcat(fullName, " ");
        strcat(fullName, secondSurname);
        
        Student student(fullName, birthDate, year, mark);
        addNode(head, student);
    }

    std::cout << "Initial list:\n"; 
    printNames(head);

    char letter;
    fin >> letter;
    Node *newHead = new Node;
    Node *curr = head->next; 

    while (curr != nullptr)
    {
        if (tolower(curr->data.fullName[0]) == tolower(letter))
        {
            addNode(newHead, curr->data);
            removeNode(head, curr);
        }
        curr = curr->next;
    }

    std::cout << "Updated list:\n";
    printNames(head);
    std::cout << "New list:\n";
    printNames(newHead);

    deleteList(head);
    deleteList(newHead);
    fin.close();

    return 0;
}

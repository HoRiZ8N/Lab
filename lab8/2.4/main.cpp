#include <iostream>
#include <ctime>

enum InitializationType
{
    KeyboardInput = 1,
    RandomGeneration = 2
};

struct Node
{
    char symb;
    Node *next;
    Node(char symbol = '\0') : symb(symbol), next(nullptr) {}
};

void addNode(Node *&head, char symbol)
{
    Node *newNode = new Node(symbol);
    if (!head)
    {
        head = newNode;
    }
    else
    {
        Node *curr = head;
        while (curr->next != nullptr)
        {
            curr = curr->next;
        }
        curr->next = newNode;
    }
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

void printNodeVal(Node *head)
{
    Node *curr = head;
    while (curr != nullptr)
    {
        std::cout << curr->symb << ' ';
        curr = curr->next;
    }
    std::cout << '\n';
}

int main()
{
    int size;
    int numOfSymbols[256] = {0};
    Node *head = nullptr;

    std::cout << "Enter array size: ";
    std::cin >> size;
    std::cout << "Choose initialization method:\n"
              << InitializationType::KeyboardInput << ": Keyboard\n"
              << InitializationType::RandomGeneration << ": Random generation\n";
    int choice;
    std::cin >> choice;
    InitializationType initType = static_cast<InitializationType>(choice);

    switch (initType)
    {
    case InitializationType::RandomGeneration:
        srand(static_cast<unsigned int>(time(0)));
        for (int i = 0; i < size; i++)
        {
            char s = rand() % 94 + 33; // Limiting to printable characters
            addNode(head, s);
            numOfSymbols[static_cast<int>(s)]++;
        }
        break;

    case InitializationType::KeyboardInput:
        std::cout << "Enter " << size << " characters:\n";
        for (int i = 0; i < size; i++)
        {
            char s;
            std::cin >> s;
            addNode(head, s);
            numOfSymbols[static_cast<int>(s)]++;
        }
        break;

    default:
        std::cerr << "Invalid initialization method.\n";
        return 1;
    }

    std::cout << "Values:\n";
    printNodeVal(head);

    Node *newHead = nullptr;
    Node *curr = head;

    while (curr != nullptr)
    {
        if (numOfSymbols[static_cast<int>(curr->symb)] == 2)
        {
            numOfSymbols[static_cast<int>(curr->symb)] = 0;
            addNode(newHead, curr->symb);
        }
        curr = curr->next;
    }

    std::cout << "\nSymbols that appear exactly twice:\n";
    printNodeVal(newHead);

    deleteList(head);
    deleteList(newHead);

    return 0;
}

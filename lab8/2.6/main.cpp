#include <iostream>

class DoublyLinkedList
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
    int size = 0;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr), size(0) {}

    void append(double value)
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

    double computeExpression()
    {
        if (size < 2)
            return 0.0;

        double result = 0.0;
        Node *current = head;
        Node *tailNode = tail;

        int i = 0;
        while (current && tailNode && current != tailNode)
        {
            result += current->value + (size - i) * tailNode->value;
            current = current->next;
            tailNode = tailNode->prev;
            i++;
        }

        return result;
    }

    ~DoublyLinkedList()
    {
        Node *current = head;
        while (current)
        {
            Node *nextNode = current->next;
            delete current;
            current = nextNode;
        }
    }
};

int main()
{
    int n;
    std::cout << "Enter n: ";
    std::cin >> n;

    DoublyLinkedList list;
    std::cout << "Enter " << n << " real numbers:\n";
    for (int i = 0; i < n; i++)
    {
        double num;
        std::cin >> num;
        list.append(num);
    }

    double result = list.computeExpression();
    std::cout << "Result: " << result << std::endl;

    return 0;
}

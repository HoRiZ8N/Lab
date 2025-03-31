#include <iostream>
#include <utility>

template <typename T>
class BinaryTree {
private:
    struct Node {
        T data;
        Node* left;
        Node* right;

        Node(const T& value);
    };

    Node* root;

    void clear(Node* node);
    Node* copy(Node* node);
    void printInOrder(Node* node) const;

public:
    BinaryTree();
    BinaryTree(const T& value);
    ~BinaryTree();
    BinaryTree(const BinaryTree& other);
    BinaryTree(BinaryTree&& other);
    BinaryTree& operator=(const BinaryTree& other);
    BinaryTree& operator=(BinaryTree&& other);

    void initFirstElement(const T& value);
    void insert(const T& value);
    bool removeLeaf(const T& value);
    bool contains(const T& value) const;
    void print() const;
    void clear();
    void deleteMin();
};

template <typename T>
BinaryTree<T>::Node::Node(const T& value) 
    : data(value), left(nullptr), right(nullptr) {}

template <typename T>
BinaryTree<T>::BinaryTree() : root(nullptr) {}

template <typename T>
BinaryTree<T>::BinaryTree(const T& value) : root(new Node(value)) {}

template <typename T>
BinaryTree<T>::~BinaryTree() {
    clear();
}

template <typename T>
BinaryTree<T>::BinaryTree(const BinaryTree& other) {
    root = copy(other.root);
}

template <typename T>
BinaryTree<T>::BinaryTree(BinaryTree&& other) 
    : root(other.root) {
    other.root = nullptr;
}

template <typename T>
BinaryTree<T>& BinaryTree<T>::operator=(const BinaryTree& other) {
    if (this != &other) {
        clear();
        root = copy(other.root);
    }
    return *this;
}

template <typename T>
BinaryTree<T>& BinaryTree<T>::operator=(BinaryTree&& other) {
    if (this != &other) {
        clear();
        root = other.root;
        other.root = nullptr;
    }
    return *this;
}

template <typename T>
void BinaryTree<T>::initFirstElement(const T& value) {
    if (!root) {
        root = new Node(value);
    }
}

template <typename T>
void BinaryTree<T>::insert(const T& value) {
    Node** current = &root;
    while (*current) {
        if (value < (*current)->data) {
            current = &(*current)->left;
        } else {
            current = &(*current)->right;
        }
    }
    *current = new Node(value);
}

template <typename T>
bool BinaryTree<T>::removeLeaf(const T& value) {
    Node* parent = nullptr;
    Node* current = root;
    bool isLeftChild = false;

    while (current && current->data != value) {
        parent = current;
        if (value < current->data) {
            current = current->left;
            isLeftChild = true;
        } else {
            current = current->right;
            isLeftChild = false;
        }
    }

    if (!current || current->left || current->right) {
        return false;
    }

    if (!parent) {
        delete root;
        root = nullptr;
    } else {
        if (isLeftChild) {
            delete parent->left;
            parent->left = nullptr;
        } else {
            delete parent->right;
            parent->right = nullptr;
        }
    }
    return true;
}

template <typename T>
bool BinaryTree<T>::contains(const T& value) const {
    Node* current = root;
    while (current) {
        if (current->data == value) return true;
        current = (value < current->data) ? current->left : current->right;
    }
    return false;
}

template <typename T>
void BinaryTree<T>::print() const {
    printInOrder(root);
    std::cout << std::endl;
}

template <typename T>
void BinaryTree<T>::clear() {
    clear(root);
    root = nullptr;
}

template <typename T>
void BinaryTree<T>::deleteMin() {
    if (!root) return;
    Node** current = &root;
    while ((*current)->left) {
        current = &(*current)->left;
    }
    Node* temp = *current;
    *current = temp->right;
    delete temp; 
}

template <typename T>
void BinaryTree<T>::clear(Node* node) {
    if (node) {
        clear(node->left);
        clear(node->right);
        delete node;
    }
}

template <typename T>
typename BinaryTree<T>::Node* BinaryTree<T>::copy(Node* node) {
    if (!node) return nullptr;
    Node* newNode = new Node(node->data);
    newNode->left = copy(node->left);
    newNode->right = copy(node->right);
    return newNode;
}

template <typename T>
void BinaryTree<T>::printInOrder(Node* node) const {
    if (node) {
        printInOrder(node->left);
        std::cout << node->data << " ";
        printInOrder(node->right);
    }
}
#include <iostream>

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val = 0) : data(val), left(nullptr), right(nullptr) {}
};

void PrintTree(TreeNode* root) {
    if (root != nullptr) {
        PrintTree(root->left);
        std::cout << root->data << " ";
        PrintTree(root->right);
    }
}

TreeNode* InsertTreeNode(int val, TreeNode* root) {
    if (root == nullptr) {
        return new TreeNode(val);
    } else if (val <= root->data) {
        root->left = InsertTreeNode(val, root->left);
    } else {
        root->right = InsertTreeNode(val, root->right);
    }
    return root;
}

void ClearTree(TreeNode* root) {
    if (root != nullptr) {
        ClearTree(root->left);
        ClearTree(root->right);
        delete root;
    }
}

void DeleteMinimalValueTreeNode(TreeNode*& root) {
    if (root == nullptr) {
        return;
    }
    if (root->left == nullptr) {
        TreeNode* temp = root;
        root = root->right; 
        delete temp;
    } else {
        TreeNode* parent = root;
        TreeNode* minNode = root->left;
        while (minNode->left != nullptr) {
            parent = minNode;
            minNode = minNode->left;
        }

        parent->left = minNode->right;
        delete minNode; 
    }
}

int main() {
    TreeNode* root = nullptr;
    std::cout << "Enter the number of elements: ";
    int size;
    std::cin >> size;

    if (size <= 0) {
        std::cout << "No elements to insert.\n";
        return 0;
    }

    std::cout << "Enter " << size << " elements: ";
    for (int i = 0; i < size; i++) {
        int val;
        std::cin >> val;
        root = InsertTreeNode(val, root);
    }
    
    std::cout << "Tree in increasing order:\n";
    PrintTree(root);
    std::cout << '\n';
    DeleteMinimalValueTreeNode(root);
    std::cout << "Tree without minimal value element: ";
    PrintTree(root);
    std::cout << '\n';
    ClearTree(root);

    return 0;
}

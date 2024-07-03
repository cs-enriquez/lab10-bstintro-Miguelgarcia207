#include <iostream>

using namespace std;

// Implement the node class we will need for our Binary Search Tree
class Node {
    public:
        int key;
        Node* left;
        Node* right;

        // Write a constructor for the Node
        Node(int value) : key(value), left(nullptr), right(nullptr) {}
};

// Function to insert a new node in the BST
Node* insertNode(Node* root, int key) {
    if (root == nullptr) {
        return new Node(key);
    }
    if (key < root->key) {
        root->left = insertNode(root->left, key);
    } else {
        root->right = insertNode(root->right, key);
    }
    return root;
}

// Use this function to create a Binary Search Tree (BST) tree with the following values
// {13, 0, 7, 6, 21, 15, -2, 12, 99, 18, 19, -1}
Node* createTree() {
    Node* root = nullptr;
    int values[] = {13, 0, 7, 6, 21, 15, -2, 12, 99, 18, 19, -1};
    for (int value : values) {
        root = insertNode(root, value);
    }
    return root;
}

// Write a function that will search the BST for a target value
bool searchTree(int target, Node* root) {
    if (root == nullptr) {
        return false;
    }
    if (root->key == target) {
        return true;
    }
    if (target < root->key) {
        return searchTree(target, root->left);
    } else {
        return searchTree(target, root->right);
    }
}

// Write a function that will return the total number of Nodes in the tree
int treeSize(Node* root) {
    if (root == nullptr) {
        return 0;
    }
    return 1 + treeSize(root->left) + treeSize(root->right);
}

// BONUS! Write a function that will determine the height of the tree
int treeHeight(Node* root) {
    if (root == nullptr) {
        return -1;
    }
    int leftHeight = treeHeight(root->left);
    int rightHeight = treeHeight(root->right);
    return 1 + max(leftHeight, rightHeight);
}

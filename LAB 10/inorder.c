#include <stdio.h>
#include <stdlib.h>

// Structure of a Binary Tree Node
struct Node {
    int data;
    struct Node *left, *right;
};

// Function to print inorder traversal
void printInorder(struct Node* node) {
    if (node == NULL)
        return;

    // First recur on left subtree
    printInorder(node->left);

    // Now deal with the node
    printf("%d ", node->data);

    // Then recur on right subtree
    printInorder(node->right);
}

// Function to create a new node
struct Node* newNode(int v) {
    struct Node* node = 
      (struct Node*)malloc(sizeof(struct Node));
    node->data = v;
    node->left = node->right = NULL;
    return node;
}

int main() {
    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->right = newNode(6);

    printInorder(root);

    return 0;
}
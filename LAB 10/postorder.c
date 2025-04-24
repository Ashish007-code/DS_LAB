#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};


void printPostorder(struct Node* node)
{
    if (node == NULL)
        return;

  
    printPostorder(node->left);
 
    printPostorder(node->right);

    printf("%d ", node->data);
}

int main()
{
    struct Node* root = (struct Node*)malloc(sizeof(struct Node));
    root->data = 1;
    root->left = (struct Node*)malloc(sizeof(struct Node));
    root->left->data = 2;
    root->right = (struct Node*)malloc(sizeof(struct Node));
    root->right->data = 3;
    root->left->left = (struct Node*)malloc(sizeof(struct Node));
    root->left->left->data = 4;
    root->left->right = (struct Node*)malloc(sizeof(struct Node));
    root->left->right->data = 5;
    root->right->right = (struct Node*)malloc(sizeof(struct Node));
    root->right->right->data = 6;

    printPostorder(root);

    return 0;
}

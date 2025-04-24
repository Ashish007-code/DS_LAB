#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *newNode(int data)
{
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}


int count = 0;
int ans = -1;

void inorder(struct Node *root, int k)
{
    if (root == NULL || count >= k)
        return;

    inorder(root->left, k);

    count++;
    if (count == k)
    {
        ans = root->data;
        return;
    }

    inorder(root->right, k);
}

int findKthSmallest(struct Node *root, int k)
{
    count = 0;
    ans = -1;
    inorder(root, k);
    return ans;
}

struct Node *insert(struct Node *root, int val)
{
    if (root == NULL)
        return newNode(val);
    if (val < root->data)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);
    return root;
}

int main()
{
    struct Node *root = NULL;
    root = insert(root, 5);
    root = insert(root, 3);
    root = insert(root, 7);
    root = insert(root, 2);
    root = insert(root, 4);
    root = insert(root, 6);
    root = insert(root, 8);

    int k = 3;
    printf("%d smallest element: %d\n", k, findKthSmallest(root, k));

    return 0;
}

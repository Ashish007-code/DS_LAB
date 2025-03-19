#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
    struct node *prev;
};

struct node *head = NULL;  // Initialize head to NULL globally

void display() {
    printf("Linked list elements:\n");
    struct node *temp1 = head;
    
    if (temp1 == NULL) {
        printf("List is empty.\n");
        return;
    }
    
    while (temp1 != NULL) {
        printf("%d ", temp1->data);
        temp1 = temp1->next;
    }
    printf("\n");
}

void create() {
    int choice = 1;
    struct node *temp, *newnode;
    struct node *tail = NULL; // Track the last node

    while (choice) {
        newnode = (struct node*)malloc(sizeof(struct node));
        if (newnode == NULL) {
            printf("Memory allocation failed\n");
            return;
        }

        printf("Enter data: ");
        scanf("%d", &newnode->data);

        newnode->prev = NULL;
        newnode->next = NULL;

        if (head == NULL) {
            head = tail = newnode; // First node
        } else {
            tail->next = newnode;  // Link the previous last node to newnode
            newnode->prev = tail;  // Link newnode to previous last node
            tail = newnode;        // Move tail to the new last node
        }

        printf("Do you want to continue? (1 for Yes, 0 for No): ");
        scanf("%d", &choice);
    }
}

int main() {
    create();
    display();
    return 0;
}
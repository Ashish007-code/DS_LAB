
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next, *prev;
};

struct node *head = NULL;

void insert_beg(int val) {
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = val;
    newnode->next = head;
    newnode->prev = NULL;
    if (head != NULL) head->prev = newnode;
    head = newnode;
}

void insert_end(int val) {
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = val;
    newnode->next = NULL;
    if (head == NULL) {
        newnode->prev = NULL;
        head = newnode;
        return;
    }
    struct node *temp = head;
    while (temp->next != NULL) temp = temp->next;
    temp->next = newnode;
    newnode->prev = temp;
}

void insert_pos(int val, int pos) {
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = val;
    if (pos == 1) {
        insert_beg(val);
        return;
    }
    struct node *temp = head;
    for (int i = 1; i < pos - 1 && temp != NULL; i++)
        temp = temp->next;
    if (temp == NULL) {
        printf("Invalid position\n");
        free(newnode);
        return;
    }
    newnode->next = temp->next;
    newnode->prev = temp;
    if (temp->next != NULL) temp->next->prev = newnode;
    temp->next = newnode;
}

void display() {
    struct node *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int choice, val, pos;
    while (1) {
        printf("\n1.Insert at Beginning\n2.Insert at End\n3.Insert at Position\n4.Display\n5.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: printf("Enter value: "); scanf("%d", &val); insert_beg(val); break;
            case 2: printf("Enter value: "); scanf("%d", &val); insert_end(val); break;
            case 3: printf("Enter value and position: "); scanf("%d %d", &val, &pos); insert_pos(val, pos); break;
            case 4: display(); break;
            case 5: exit(0);
            default: printf("Invalid choice\n");
        }
    }
    return 0;
}

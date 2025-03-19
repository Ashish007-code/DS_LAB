
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next, *prev;
};

struct node *head = NULL;

void delete_beg() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct node *temp = head;
    head = head->next;
    if (head != NULL) head->prev = NULL;
    free(temp);
}

void delete_end() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct node *temp = head;
    if (head->next == NULL) {
        free(head);
        head = NULL;
        return;
    }
    while (temp->next != NULL) temp = temp->next;
    temp->prev->next = NULL;
    free(temp);
}

void delete_pos(int pos) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    if (pos == 1) {
        delete_beg();
        return;
    }
    struct node *temp = head;
    for (int i = 1; temp != NULL && i < pos; i++)
        temp = temp->next;
    if (temp == NULL) {
        printf("Invalid position\n");
        return;
    }
    if (temp->next != NULL) temp->next->prev = temp->prev;
    if (temp->prev != NULL) temp->prev->next = temp->next;
    free(temp);
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
    int choice, pos, val;
    struct node *newnode;
    
    while (1) {
        printf("\n1.Insert at End\n2.Delete at Beginning\n3.Delete at End\n4.Delete at Position\n5.Display\n6.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1: 
                newnode = (struct node*)malloc(sizeof(struct node));
                printf("Enter value: ");
                scanf("%d", &val);
                newnode->data = val;
                newnode->next = NULL;
                if (head == NULL) {
                    newnode->prev = NULL;
                    head = newnode;
                } else {
                    struct node *temp = head;
                    while (temp->next != NULL) temp = temp->next;
                    temp->next = newnode;
                    newnode->prev = temp;
                }
                break;
            case 2: delete_beg(); break;
            case 3: delete_end(); break;
            case 4: printf("Enter position: "); scanf("%d", &pos); delete_pos(pos); break;
            case 5: display(); break;
            case 6: exit(0);
            default: printf("Invalid choice\n");
        }
    }
    return 0;
}

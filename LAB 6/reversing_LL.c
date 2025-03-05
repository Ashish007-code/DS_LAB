#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};
struct node *head;

void reverse(){
    struct node *prevn,*currentn,*nextn,*temp;
    prevn=0;
    currentn=nextn=head;
    while(nextn!=0) {
        nextn=nextn->next;
        currentn->next=prevn;
        prevn=currentn;
        currentn=nextn;
 
    }
    head=prevn;
    printf("Reversed linked list is\n ");
    temp = head;
    while (temp != NULL) {
        printf("%d->", temp->data); // Added space for clarity
        temp = temp->next;
    }
    printf("NULL");
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }

}

int main() {
    int choice = 1;
    struct node  *newnode, *temp;
    
    head = NULL;

    while (choice) {
        newnode = (struct node*)malloc(sizeof(struct node));
        if (newnode == NULL) {
            printf("Memory allocation failed.\n");
            return 1; // Exit if malloc fails
        }

        printf("Enter data: ");
        scanf("%d", &newnode->data);
        newnode->next = NULL;

        if (head == NULL) {
            head = temp = newnode;
        } else {
            temp->next = newnode;
            temp = newnode;
        }

        printf("Do you want to continue? (1 for Yes, 0 for No): ");
        scanf("%d", &choice);
    }

    printf("Linked List Elements:\n ");
    temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data); 
        temp = temp->next;
    }
    reverse();
    

   free(temp);
       return 0; 
    }
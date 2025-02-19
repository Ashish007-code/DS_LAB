#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

void delatpos(struct node *head){
    int i=1;
    int pos;
    printf("Enter position");
    scanf("%d",&pos);
    struct node *temp,*prev;
   prev= temp =head;

    while(i<pos){
        prev=temp;
        temp=temp->next;
        
        i++;
    }
    prev->next=temp->next;
    printf("Linked List Elements:\n ");
    temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data); 
        temp = temp->next;
    }
    free(temp);

}

void delatbeg (struct node *head)
{
 struct node *temp;
 temp=head;
 head=head->next;

 printf("Linked List Elements: ");
    temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data); 
        temp = temp->next;
    }
    
    free(temp);

}

void delatend(struct node *head){
    struct node *temp,*prev;
    temp =head;
    while(temp->next !=0){
        prev=temp;
        temp=temp->next;
    }
    free(temp);
    prev->next=0;
    printf("Linked List Elements:\n ");
    temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data); // Added space for clarity
        temp = temp->next;
    }


}

int main() {
    int choice = 1;
    struct node *head, *newnode, *temp;
    
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
      int ans;
   free(temp);
   printf("\n");

    printf("Do you want to delete a node at beginning? (Enter 1)  At end? (Enter 2) At specific position? (Enter 3)\n");
    scanf("%d",&ans);

    if(ans==1){
        delatbeg(head);
    }
     else if(ans==2){
        delatend(head);
    }
    else if(ans==3){
        delatpos(head);
    }
       return 0; 
    }
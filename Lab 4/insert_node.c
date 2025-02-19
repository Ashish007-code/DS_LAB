#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

void atanypos(struct node *head){

    int pos,i=1;
    printf("Enter the postion after which the node shoulld be inserted:\n");
    scanf("%d",&pos);

    struct node  *newnode, *temp;
    temp=head;
    while(i<pos){
        temp=temp->next;
        i++;
    }
    newnode = (struct node*)malloc(sizeof(struct node));
    printf("Enter data:");
    scanf("%d",&newnode->data);
    newnode->next=temp->next;
    temp->next=newnode;

    printf("Linked List Elements: \n");
    temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data); // Added space for clarity
        temp = temp->next;
    }
    free(temp);


}

 void atend(struct node *head){

    struct node  *newnode, *temp;
    newnode = (struct node*)malloc(sizeof(struct node));
    printf("Enter data");
    scanf("%d",&newnode->data);
    newnode->next=NULL;
    temp=head;
    while(temp->next!=0){
        temp= temp->next;
    }
    temp->next=newnode;

    printf("Linked List Elements: ");
    temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data); // Added space for clarity
        temp = temp->next;
    }
    free(temp);

}
 
struct node * atbeginning(struct node *head)
{
    struct node  *newnode, *temp;
    newnode = (struct node*)malloc(sizeof(struct node));
    printf("Enter data");
    scanf("%d",&newnode->data);
    newnode->next = head;
    head = newnode;

    printf("Linked List Elements: ");
    temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data); // Added space for clarity
        temp = temp->next;
    }

   free(temp);
   return head;
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

   free(temp);
   int ans,ans1,pos,ans2;
    
    printf("Do you want to insert a node at beginning?( 0 or 1)");
    scanf("%d",&ans);
    if(ans==1){
        head= atbeginning(head);
    }

    printf("Do you want to insert a node at end?");
    scanf("%d",&ans1);
     if(ans1=1 && ans){
        atend(head);
     }
       

        printf("Do you want to insert a node at a specific position?");
     scanf("%d",&ans2);

     if(ans2=1){
        atanypos(head);
     }
       
     
    
        return 0; 
       
}
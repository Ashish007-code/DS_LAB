# include <stdio.h>
# include <stdlib.h>
struct node {
    int data;
    struct node *next;
};
int main() {
    int choice1 = 1;
    struct node *head1, *newnode1, *temp1;
    
    head1 = NULL;

    printf("Entries for first link list");
    printf("\n");

    while (choice1) {
        newnode1 = (struct node*)malloc(sizeof(struct node));
        if (newnode1 == NULL) {
            printf("Memory allocation failed.\n");
            return 1; 
        }

        printf("Enter data: ");
        scanf("%d", &newnode1->data);
        newnode1->next = NULL;

        if (head1 == NULL) {
            head1 = temp1 = newnode1;
        } else {
            temp1->next = newnode1;
            temp1 = newnode1;
        }

        printf("Do you want to continue? (1 for Yes, 0 for No): ");
        scanf("%d", &choice1);

    }

    printf("Linked List one  Elements: ");
    temp1 = head1;
    while (temp1!= NULL) {
        printf("%d ", temp1->data); 
        temp1 = temp1->next;
    }
    free(temp1);

     printf("\n");
     printf("Entries for second link list");

    int choice2 = 1;
    struct node *head2, *newnode2, *temp2;
    
    head2 = NULL;

    while (choice2) {
        newnode2 = (struct node*)malloc(sizeof(struct node));
        if (newnode2 == NULL) {
            printf("Memory allocation failed.\n");
            return 1; 
        }

        printf("Enter data: ");
        scanf("%d", &newnode2->data);
        newnode2->next = NULL;

        if (head2 == NULL) {
            head2 = temp2 = newnode2;
        } else {
            temp2->next = newnode2;
            temp2 = newnode2;
        }

        printf("Do you want to continue? (1 for Yes, 0 for No): ");
        scanf("%d", &choice2);

    }

    printf("Linked List two Elements:");
    temp2 = head2;
    while (temp2!= NULL) {
        printf("%d ", temp2->data); 
        temp2 = temp2->next;
    }

    free(temp2);
    printf("\n");


    struct node *temp;
    temp=head1;
    while(temp->next !=NULL){
        temp=temp->next;
    }
    temp->next=head2;

    temp=head1;
    printf("Concatinated list is:");

     while(temp!=0){
        printf("%d",temp->data);
        temp=temp->next;
     }
     free(temp);
     free(head2);


}
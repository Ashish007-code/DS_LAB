#include <stdlib.h>
#include <stdio.h>


struct node {
    int data;
    struct node *next;
};
struct node *head;

void del_at_pos(int n)
{
    struct node *temp = head;
    struct node *prev = NULL;
    for (int i = 0; i < n; i++)
    {
        prev = temp;
        temp = temp->next;
    }
    prev->next = temp->next;
    printf("Linked List Elements: ");
    temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data); 
        temp = temp->next;
    }
   
    free(temp);
}


int main() {
    int choice = 1;
    int count=0;
    struct node *newnode, *temp;
    
    head = NULL;

    while (choice) {
        newnode = (struct node*)malloc(sizeof(struct node));
        if (newnode == NULL) {
            printf("Memory allocation failed.\n");
            return 1;
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
        count++;
    }

    printf("Linked List Elements: ");
    temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data); 
        temp = temp->next;
    }
   

  temp=head;
       
    

int A[100] = {0};

    int c = 0;

    while (temp != NULL)
    {
        A[temp->data]++;
        if (A[temp->data] > 1)
        {
            del_at_pos(count);
        }
        c++;
        temp = temp->next;
    }
    return 0;
}
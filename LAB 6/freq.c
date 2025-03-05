#include <stdlib.h>
#include <stdio.h>


struct node {
    int data;
    struct node *next;
};

int main() {
    int choice = 1;
    int count=0;
    struct node *head, *newnode, *temp;
    
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
    printf("%d\n",count);

int freq[100] = {0};
temp = head;
while (temp != NULL)
{
    freq[temp->data]++;
    temp = temp->next;
}

for (int i = 0; i < 100; i++)
{
    if (freq[i] != 0)
    {
        printf("%d occurs %d times\n", i, freq[i]);
    }
}
}
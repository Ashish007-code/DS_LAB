#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    char name[50];
    int age, number;
    struct node *next;
} Patient;

Patient *front = NULL, *rear = NULL;
int count = 0;

void enqueue(char name[], int age)
{
    Patient *p = (Patient *)malloc(sizeof(Patient));
    strcpy(p->name, name);
    p->age = age;
    p->number = ++count;
    p->next = NULL;

    if (!front)
        front = rear = p;
    else
        rear->next = p, rear = p;
}

void dequeue()
{
    if (!front)
        return;

    Patient *temp = front;
    front = front->next;
    free(temp);
    count--;

    for (Patient *t = front; t; t = t->next)
        t->number--;
    if (!front)
        rear = NULL;
}

void display()
{
    for (Patient *t = front; t; t = t->next)
        printf("%s | %d | %d\n", t->name, t->age, t->number);
}

int main()
{

    enqueue("Ramesh", 16);
    enqueue("harsh", 18);
    enqueue("karan", 23);
    enqueue("shyam", 20);

    printf("Name | Age | Number\n");
    display();

    dequeue();
    dequeue();

    enqueue("deepak", 19);
    dequeue();
    dequeue();

    enqueue("Utkarsh", 19);

    printf("\nName | Age | Number\n");
    display();

    return 0;
}

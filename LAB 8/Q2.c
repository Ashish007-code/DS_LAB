#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node* top=NULL;

void push()
{
    int n;
    printf("Enter Data");
    scanf("%d",&n);

    struct node * newnode ;
    newnode =(struct node*)malloc(sizeof(struct node));

    newnode->data=n;
    newnode->next=0;

    if(top==NULL){
        top=newnode;
    }
    else
    {
       newnode->next=top;
       top=newnode;
    }

}
void pop(){
    struct node* temp ;
    temp=top;
    top=top->next;
    free(temp);
}

void display(){
    struct node *temp;
    temp=top;
    while(temp!=0){
        printf("%d",temp->data);
        temp=temp->next;
    }
}

int main() {
    push();
    push();
    push();
    push();

    pop();
    display();
    }
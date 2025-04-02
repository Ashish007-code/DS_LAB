# include <stdio.h>
#include <stdlib.h>

int stack[7];
int top=-1;
int n=50;
void display(){
    while(top>=0){
        printf("%d",stack[top]);
        top--;
    }
}

void push(){
  int data;
  printf("Enter Data:\n");
  scanf("%d",&data);
 if(top==n-1){
    printf("Overflow stack is full");
 }
 else
 {
    top+=1;
    stack[top]=data;
 }

}
void pop(){
    int data;
    
    if(top==-1){
        printf("Underflow stack is empty");
    }

    else{
      data= stack[top];
      printf("%d",data);
      top--;

    }

}
void main(){
    
    //pushing into stack
   
    
    push();
    push();
    push();
    pop();
    display();


}
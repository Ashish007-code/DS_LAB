#include <stdio.h>
#include <string.h>
#define MAX 100

char stack[MAX];
int top = -1;

void push(char c) {
    stack[++top] = c;
}

char pop() {
    return (top == -1) ? '\0' : stack[top--];
}

int isBalanced(char expr[]) {
    for (int i = 0; expr[i] != '\0'; i++) {
        if (expr[i] == '(' || expr[i] == '{' || expr[i] == '[') {
            push(expr[i]);
        } else if (expr[i] == ')' && pop() != '(') {
            return 0;
        } else if (expr[i] == '}' && pop() != '{') {
            return 0;
        } else if (expr[i] == ']' && pop() != '[') {
            return 0;
        }
    }
    return top == -1;
}

int main() {
    char expr[MAX];
    printf("Enter an expression: ");
    scanf("%s", expr);
    printf(isBalanced(expr) ? "Balanced\n" : "Not Balanced\n");
    return 0;
}

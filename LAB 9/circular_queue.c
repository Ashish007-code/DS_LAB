#include <stdio.h>
#define SIZE 10

int circularQueue[SIZE];
int frontIndex = -1, rearIndex = -1;

void enqueue(int value) {
    if ((rearIndex + 1) % SIZE == frontIndex) {
        printf("Queue Overflow - Cannot enqueue %d\n", value);
        return;
    }
    if (frontIndex == -1 && rearIndex == -1) {
        frontIndex = rearIndex = 0;
    } else {
        rearIndex = (rearIndex + 1) % SIZE;
    }
    circularQueue[rearIndex] = value;
}

void dequeue() {
    if (frontIndex == -1 && rearIndex == -1) {
        return;
    }
    if (frontIndex == rearIndex) {
        frontIndex = rearIndex = -1;
    } else {
        frontIndex = (frontIndex + 1) % SIZE;
    }
}

void showQueue() {
    if (frontIndex == -1 && rearIndex == -1) {
        return;
    }
    int i = frontIndex;
    while (1) {
        printf("%d ", circularQueue[i]);
        if (i == rearIndex) break;
        i = (i + 1) % SIZE;
    }
    printf("\n");
}

int main() {
    int n, value;
    printf("Enter number of elements to insert (1-10): ");
    scanf("%d", &n);
    
    printf("Enter values: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        enqueue(value);
    }

    printf("\nQueue: ");
    showQueue();

    int d;
    printf("\nNumber of elements to remove: ");
    scanf("%d", &d);
    for (int i = 0; i < d; i++) {
        dequeue();
    }

    printf("After Dequeue: ");
    showQueue();

    int e;
    printf("\nNumber of elements to add: ");
    scanf("%d", &e);
    printf("Enter values: ");
    for (int i = 0; i < e; i++) {
        scanf("%d", &value);
        enqueue(value);
    }

    showQueue();
    return 0;
}

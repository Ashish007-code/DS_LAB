#include <stdio.h>

#define MAX 100

int main()
{
    int stream[] = {1, 2, 3, 2, 1, 4, 5};
    int n = sizeof(stream) / sizeof(stream[0]);

    int freq[10] = {0};      // To count frequency of digits 0-9
    int queue[MAX];          // Acts like a queue
    int front = 0, rear = 0; // Queue pointers

    for (int i = 0; i < n; i++)
    {
        int num = stream[i];
        freq[num]++;

        // Enqueue the current number
        queue[rear++] = num;

        // Remove repeating numbers from front
        while (front < rear && freq[queue[front]] > 1)
        {
            front++;
        }

        // Print result
        if (front < rear)
            printf("First non-repeating after %d: %d\n", num, queue[front]);
        else
            printf("First non-repeating after %d: -1\n", num);
    }

    return 0;
}

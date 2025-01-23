#include <stdio.h>

int main() {
    int n, i;

    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d elements: ", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Right shift the array
    int last = arr[n - 1]; // Store the last element
    for (i = n - 1; i > 0; i--) {
        arr[i] = arr[i - 1]; // Shift elements to the right
    }
    arr[0] = last; // Place the last element at the start

    // Print the shifted array
    printf("Array after right shift: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
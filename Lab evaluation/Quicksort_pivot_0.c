#include <stdio.h>

int partition(int arr[], int low, int high) {
    int pivot = arr[low];  
    int i = low + 1;
    int j = high;

    while (i <= j) {
        while (i <= high && arr[i] <= pivot)  
            i++;
        while (arr[j] > pivot) 
            j--;
        
        if (i < j) {  
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

   
    arr[low] = arr[j];
    arr[j] = pivot;

    return j;  
}


void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pivotIndex = partition(arr, low, high);
        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}


void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}


int main() {
    int arr[] = {10, 7, 8, 9, 1, 5};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    printArray(arr, size);

    quickSort(arr, 0, size - 1);

    printf("Sorted array: ");
    printArray(arr, size);
    return 0;
}
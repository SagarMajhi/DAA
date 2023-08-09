#include <stdio.h>

void heapify(int array[], int n, int rootIndex) {
    int largest = rootIndex;
    int leftChild = 2 * rootIndex + 1;
    int rightChild = 2 * rootIndex + 2;

    if (leftChild < n && array[leftChild] > array[largest])
        largest = leftChild;

    if (rightChild < n && array[rightChild] > array[largest])
        largest = rightChild;

    if (largest != rootIndex) {
        int temp = array[rootIndex];
        array[rootIndex] = array[largest];
        array[largest] = temp;

        heapify(array, n, largest);
    }
}

void heapSort(int array[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(array, n, i);

    for (int i = n - 1; i > 0; i--) {
        int temp = array[0];
        array[0] = array[i];
        array[i] = temp;

        heapify(array, i, 0);
    }
}

void printArray(int array[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", array[i]);
    printf("\n");
}

int main() {
    int array[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(array) / sizeof(array[0]);

    printf("Original array: \n");
    printArray(array, n);

    heapSort(array, n);

    printf("Sorted array: \n");
    printArray(array, n);

    return 0;
}

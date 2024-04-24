#include <stdio.h>

void insertionSort(int *arr, int length);
void selectionSort(int *arr, int length);

int main() {
    int array[] = {10, 3, 5, 3, 6, 2, 5, 5, 8};
    int length = sizeof(array) / sizeof(array[0]);

    int choice;
    printf("Enter 1 to use Insertion Sort\n");
    printf("Enter 2 to use Selection Sort\n");
    printf("Your choice: ");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            insertionSort(array, length);
            break;
        case 2:
            selectionSort(array, length);
            break;
        default:
            printf("Invalid choice!\n");
            return 1;
    }

    printf("Sorted array: ");
    for (int i = 0; i < length; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    return 0;
}

void insertionSort(int *arr, int length) {
    for (int i = 1; i < length; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void selectionSort(int *arr, int length) {
    for (int i = 0; i < length - 1; i++) {
        int min_index = i;
        for (int j = i + 1; j < length; j++) {
            if (arr[j] < arr[min_index]) {
                min_index = j;
            }
        }
        int temp = arr[min_index];
        arr[min_index] = arr[i];
        arr[i] = temp;
    }
}

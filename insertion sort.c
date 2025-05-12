#include <stdio.h>

void insertionSort(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];          
        j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];  
            j = j - 1;
        }
        arr[j + 1] = key;  
    }
}

void printArray(int arr[], int n)  
 {
 	int i;
    for ( i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main()
 {
    int arr[] = {100,1000,101,100011,1023,67};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    printArray(arr, n);

    insertionSort(arr, n);

    printf("Sorted array: ");
    printArray(arr, n);
   return 0;

}

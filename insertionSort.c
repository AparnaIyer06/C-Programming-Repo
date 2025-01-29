#include <stdio.h>

// Insertion Sort
void insertionSort(int arr[], int size) {
    int i, key, j, k;
    for (i = 1; i < size; i++) {
        key = arr[i];
        printf("i=%d key=%d\n", i, key);
        j = i - 1;

        while (j >= 0 && arr[j] > key) {
        	printf("j=%d, arr[j]=%d\n", j, arr[j]);
            arr[j + 1] = arr[j];
            j = j - 1;
        	printf("intermediate: ");
	    	for (k = 0; k < size; k++)
	        	printf("%d ", arr[k]);
	        printf("\n");
        }

        arr[j + 1] = key;
        printf("final: ");
    	for (k = 0; k < size; k++)
        	printf("%d ", arr[k]);
        printf("\n");
    }
}

int main() {
	int arr[] = {1, 2, 3, 5, 4};
	int size = sizeof(arr) / sizeof(int);
	
    int i;
    printf("\nArray before sorting: ");
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
    
	insertionSort(arr, size);
	
    printf("\nArray after sorting: ");
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
        
    return 0;
}

#include <stdio.h>

// Function to merge two sorted subarrays into a single sorted subarray
void merge(int arr[], int left, int mid, int right, int* comparisons) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[n1], R[n2], i, j;

    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    i = 0, j = 0;
	int k = left;

    while (i < n1 && j < n2) {
        // Compare elements while merging
        (*comparisons)++;
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements, if any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Optimized Merge Sort function with comparison count
void mergeSort(int arr[], int left, int right, int* comparisons) {
    if (left >= right)
        return;

    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid, comparisons);
    mergeSort(arr, mid + 1, right, comparisons);

    // Check if the two subarrays are already sorted
    if (arr[mid] <= arr[mid + 1]) {
        return;
    }

    merge(arr, left, mid, right, comparisons);
}

int main() {
    int i, n;
    int comparisons = 0;

    printf("Enter the size of the array (maximum size: 100): ");
    scanf("%d", &n);

    if (n <= 0 || n > 100) {
        printf("Invalid array size.\n");
        return 1;
    }

    int arr[100];

    printf("Enter the elements of the array:\n");
    for (i = 0; i < n; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    printf("\nArray before sorting: ");
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);

    mergeSort(arr, 0, n - 1, &comparisons);

    printf("\nArray after sorting: ");
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);

    printf("\nTotal comparisons: %d\n", comparisons);

    return 0;
}


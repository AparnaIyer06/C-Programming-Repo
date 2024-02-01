// Find the smallest positive integer missing from an unsorted array

#include <stdio.h>
#include <stdlib.h>

// Function for accepting arr and size, return missing positive interger else return the next positive integer after the maximum element in the array

int findMissingInteger(int arr[], int size) {
	//Find the minimum positive number
	int min = 999;
	int i; 
	for(i=0; i<size; i++) {
		if(arr[i] > 0 && arr[i] < min) {
			min = arr[i];
		}
	}
	
	// Find the maximum positive number
	int max = -999;
	for(i=0; i<size; i++) {
		if(arr[i] > max) {
			max = arr[i];
		}
	}
	
	// Create a temporary array of size max and initialize it with 0s
	int temp[max];
	for(i=0; i<max; i++)
		temp[i] = 0;

	// Read the non-negative number from array and go to temp to mark its position as -1
	for(i=0; i<size; i++) {
		if(arr[i] > 0 )
			temp[arr[i]] = -1;
	}

	// Check the first zero from index min to max and return its position 
	for(i=min; i<max; i++) {
		if(temp[i] == 0) {
			return i;
		}
	}
	return -1; // return the next positive integer after the maximum element in the array
}

int main() {
	int arr1[] = {-2, 1, 3, 4, 6, 2};
	int size1 = sizeof(arr1) / sizeof(int);
	int arr2[]={-1,0,1,2,3,4};
	
	
	
	int i, max;
	
	for(i=0; i<size1; i++) {
		if(arr[i] > max) {
			max = arr[i];
		}
	}
	
	int missing = findMissingInteger(arr1, size1);

	if(missing == -1)
		printf("No positive integer is missing. The next positive integer after the maximum element in the array is: %d", max + 1);
	else
		printf("The smallest positive missing integer is: %d\n", missing);
	
	return 0;
}

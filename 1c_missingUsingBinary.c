#include<stdio.h>

int missingUsingBinary(int arr[], int size) {
	int left = 0, right = size - 1, mid;
	
	// Search for the first positive value in the array
	while(arr[left] <= 0)
		left++;
	
	while(left < right) {
		mid = (left + right) / 2;
		
		// If the difference between the mid and first locations is less than the difference between the mid and first values, then the missing integer is on the left side of the array
		if(mid - left < arr[mid] - arr[left])
			right = mid;
		// If the difference between the mid and first locations is same as the difference between the mid and first values, it is on the right side
		else if(mid - left == arr[mid] - arr[left])
			left = mid;
		
		// Continue the binary search until the left and right indices meet
		if(left + 1 == right) {
			if(arr[left] + 1 == arr[right])
				// Return -1 to indicate that no number is missing
				return -1;
			else
				// The smallest missing positive integer will be arr[left] + 1 if arr[left] + 1 < arr[right]
				return(arr[left] + 1);
		}
	}

	return -1;
}

int main() {
  int arr[] = {-2, -5, 0, 1, 2, 4, 5};
  int size = sizeof(arr) / sizeof(int);
  int missing = missingUsingBinary(arr, size);
  
	if(missing == -1)
		printf("No positive number is missing");
   else
		printf("Missing positive number is %d", missing);

	return 0;
}

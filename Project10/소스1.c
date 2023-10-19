#include <stdio.h>
#include <stdlib.h>
// Function to determine the maximum value in the given array
int getMax(int arr[], int n) {
	int mx = arr[0]; // Start by assuming the first element is the maximum
	for (int i = 1; i < n; i++) // Loop through all other elements
		if (arr[i] > mx) // If current element is greater than the current max
			mx = arr[i]; // Update the max value
	return mx; // Return the maximum value found
}
// A counting sort function that sorts based on individual digit values represented by exp
void countSort(int arr[], int n, int exp) {
	int* output = (int*)malloc(n * sizeof(int)); // Allocate memory for the output array
	int i, count[10] = { 0 }; // Initialize a count array to track frequencies of digits
	for (i = 0; i < n; i++) // Populate the count array with frequencies of the current digit of all numbers
		count[(arr[i] / exp) % 10]++;
	for (i = 1; i < 10; i++) // Modify the count array so each index will show the cumulative frequency
		count[i] += count[i - 1];
	for (i = n - 1; i >= 0; i--) { // Place numbers in the output array according to their current digit value
		output[count[(arr[i] / exp) % 10] - 1] = arr[i];
		count[(arr[i] / exp) % 10]--;
	}
	for (i = 0; i < n; i++) // Copy the sorted numbers from the output array back to the original array
		arr[i] = output[i];
	free(output); // Free the memory allocated for the output array
}
// Utility function to print the array
void print(int arr[], int n) {
	for (int i = 0; i < n; i++) // Loop through each element in the array
		printf("%d ", arr[i]); // Print the current element
	printf("\n");
}
// Radix Sort function
void radixsort(int arr[], int n) {
	int m = getMax(arr, n); // Determine the maximum number in the array to know the number of digits
	// Do counting sort for every digit
	for (int exp = 1; m / exp > 0; exp *= 10) { // The variable 'exp' helps in extracting individual digits from a number
		countSort(arr, n, exp);

	}
}

// Main function
int main() {
	int arr[] = { 543, 986, 217, 765, 329 }; // Sample array to be sorted
	int n = sizeof(arr) / sizeof(arr[0]); // Determine the number of elements in the array
	radixsort(arr, n); // Call the radix sort function to sort the array
	print(arr, n); // Print the sorted array
	return 0;
}
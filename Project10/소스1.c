#include <stdio.h> // Include the standard I/O library for C
// Define a function to find the minimum of two integers
int min(int a, int b) {
	return (a < b) ? a : b; // Return the smaller of the two integers
}
// Function to calculate the minimum time to assemble the product
int productAssembly(int a[2][5], int t[2][4], int e[2], int x[2]) {
	int f1[5], f2[5]; // Declare arrays to store times for two production lines
	// Time taken to reach the first station on line 1
	f1[0] = e[0] + a[0][0];
	// Time taken to reach the first station on line 2
	f2[0] = e[1] + a[1][0];
	// Iterate over each station, starting from the second
	for (int j = 1; j < 5; j++) {
		// Calculate time for current station on line 1
		f1[j] = min(f1[j - 1] + a[0][j], f2[j - 1] + t[1][j - 1] + a[0][j]);
		// Calculate time for current station on line 2
		f2[j] = min(f2[j - 1] + a[1][j], f1[j - 1] + t[0][j - 1] + a[1][j]);
	}
	// Return the minimum time considering the exit times from both lines
	return min(f1[4] + x[0], f2[4] + x[1]);
}
// The main function where execution begins
int main() {
	// Define and initialize arrays for assembly times, transition times, entry times, and exit times
	int a[2][5] = { {8, 10, 4, 5, 9}, {9, 6, 7, 5, 6} };
	int t[2][4] = { {2, 3, 1, 3}, {2, 1, 2, 2} };
	int e[2] = { 3, 5 };
	int x[2] = { 2, 1 };
	// Print the minimum time calculated by the productAssembly function
	printf("Optimal Time for completing the product is: %d\n",
		productAssembly(a, t, e, x));
	return 0; // Return 0 to indicate successful completion
}
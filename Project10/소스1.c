#include <stdio.h>
#include <stdlib.h>
void countsort(int arr[], int n) { //count sort function start
	int max = 0; //input array's maximum element -> count array's size
	for (int i = 0; i < n; i++) 
		if (arr[i] > max)
			max = arr[i];    //finding maximum element in input array
	int* count_arr = (int*)malloc((max + 1) * sizeof(int)); // dynamically allocate count array size:max+1
	if (count_arr == NULL) {
		perror("Memory allocation failed");
		exit(1); // Exits program with an error code
	}
	for (int i = 0; i <= max; i++)
		count_arr[i] = 0;   //count array's element reset to 0
	for (int i = 0; i < n; i++)
		count_arr[arr[i]]++; //Make the number of each element in the input array a count array	
	int* output_arr = (int*)malloc(sizeof(int)*n);
	int op_idx = 0; //  This keeps track of the next position to insert a number into outputArray

	for (int i = 0; i <= max; i++) {    //To rearrange each element of the input element
		while (count_arr[i] > 0) {     //Place input array'element as many as in the count array to output array
			output_arr[op_idx] = i;    
			op_idx++;
			count_arr[i]--;
		}
	}
	for (int i = 0; i < n; i++)
		printf("%d ", output_arr[i]); //print output array
	free(count_arr);  //releasing memory
	free(output_arr);  //releasing memory
}
int main()
{
	// Declaring and initializing the input array
	int inputArray[] = { 4, 3, 12, 1, 5, 5, 3, 9 };
	// Calculating the number of elements in inputArray
	int N = sizeof(inputArray) / sizeof(inputArray[0]);
	// Calling countSort to sort the numbers in inputArray and print them
	countsort(inputArray, N);
	return 0; // Returning 0 indicates successful execution of the program
}
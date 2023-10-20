#include<stdio.h>
#include<stdlib.h>
int get_max(int arr[],int n) {
	int max, i;
	max = arr[0];
	for (i = 1; i < n; i++)
		if (arr[i] > max)
			max = arr[i];
	return max;
}
void count_sort(int arr[], int n, int exp) { 
	int *output;
	output = (int*)malloc(n * sizeof(int));
	int i,count[10] = { 0 };
	for (i = 0; i < n; i++)
		count[arr[i] / exp % 10]++;
	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	for (i = n - 1; i >= 0; i--) {
		output[count[arr[i] / exp % 10] - 1] = arr[i];
		count[arr[i] / exp % 10]--;
	}
	for (i = 0; i < n; i++)
		arr[i] = output[i];
	free(output);
}
void radix_sort(int arr[], int n) {
	int max = get_max(arr, n);
	for (int exp = 1; max / exp > 0; exp *= 10)
		count_sort(arr, n, exp);
}
int main() {
	int key,i,j,temp,max;
	int n = 5;
	int arr[5] = {1,7,2,6,9 };
	
	radix_sort(arr, n);

	
	for (i = 0; i < n; i++)
		printf("%d ", arr[i]);
		
}

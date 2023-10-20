#include<stdio.h>
#include<stdlib.h>

int main() {
	int key,i,j,temp,max;
	int n = 5;
	int arr[5] = {1,7,2,6,9 };
	max = arr[0];
	for (i = 0; i < n; i++)
		if (max < arr[i])
			max = arr[i];
	int *count;
	count = (int*)malloc((max+1) * sizeof(int));
	for (i = 0; i <= max; i++)
		count[i] = 0;
	for (i = 0; i < n; i++)
		count[arr[i]]++;

	int *output, output_idx=0;
	output = (int*)malloc(n * sizeof(int));
	for (i = 0; i <= max; i++) {
		while (count[i] > 0) {
			output[output_idx] = i;
			output_idx++;
			count[i]--;
		}
	}


	
	for (i = 0; i < n; i++)
		printf("%d ", output[i]);
		
}

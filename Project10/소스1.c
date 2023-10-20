#include<stdio.h>
#include<stdlib.h>
void merge(int arr[], int l,int m,int r) {
	int a1, a2,i,j,k; 
	a1 = m - l + 1;
	a2 = r - m;
	int *L1, *R1;
	L1 = (int*)malloc(a1 * sizeof(int));
	R1 = (int*)malloc(a2 * sizeof(int));
	for (i = 0; i < a1; i++) 
		L1[i] = arr[i + l];
	for (j = 0; j < a2; j++)
		R1[j] = arr[m + 1 + j];
	i = 0, j = 0,k = l;
	while (i < a1 && j < a2) {
		if (L1[i] <= R1[j]) {
			arr[k] = L1[i];
			i++;
		}
		else  {
			arr[k] = R1[j];
			j++;
		}
		k++;
	}
	while (i < a1) {
		arr[k] = L1[i];
		i++,k++;
	}
	while (j < a2) {
		arr[k] = R1[j];
		j++, k++;
	}
}
void merge_sort(int arr[], int l, int r) {
	int m;
	if (l < r) {
		m = l + (r-l)/2; 
		merge_sort(arr, l, m);
		merge_sort(arr, m + 1, r);
		merge(arr, l, m, r);
	}
}
int main() {
	int key,i,j,temp,min_idx;
	int n = 5;
	int arr[5] = {1,7,2,6,9 };

	merge_sort(arr, 0, n-1);


	
	for (i = 0; i < n; i++)
		printf("%d ", arr[i]);
		
}

#include <stdio.h>
int main() {
	int n, i, left, right, mid;
	double *a, key;

	printf("Enter Array Size : ");
	scanf("%d", &n);

	a = (double*)malloc(n * sizeof(double)); 

	printf("Enter %d numbers in sorted order: ", n);
	for (i = 0; i < n; i++)
		scanf("%lf", &a[i]);

	left = 0, right = n - 1, mid = (left + right) / 2;
	printf("Enter search Key: ");
	scanf("%lf", &key);

	while (left <= right) {
		if (key < a[mid])
			right = mid - 1;
		else if (key > a[mid])
			left = mid + 1;
		else {
			printf("Found at Location %d\n", mid);
			break;
		}
		mid = (left + right) / 2;
	}
	if (left>right) 
		printf("Not Found\n");
	return 0;
}
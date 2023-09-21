#include <stdio.h>
int main()
{
	int a[100], n, i, j, position, swap, min_idx, temp, res;
	printf("Enter Number of Elements n :");
	scanf("%d", &n);
	printf("Enter %d Numbers n: \n", n);
	for (i = 0; i < n; i++)
		scanf("%d", &a[i]);
	
	for (i = 0; i < n - 1; i++) {
		min_idx = i;
		for (j = i + 1; j < n; j++) {
			if (a[j] < a[min_idx]) {
				min_idx = j;
			}
		}
		temp = a[min_idx];
		a[min_idx] = a[i];
		a[i] = temp;
	}
	printf("Sorted Array:\n");
	for (i = 0; i < n; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");

	printf("minimum: %d\n", a[0]);
	printf("maximum: %d\n", a[n - 1]);
	return 0;
}
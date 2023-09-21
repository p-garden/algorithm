#include <stdio.h>
int main() {
	int n, i, j, temp,*a;
	printf("Enter Array Size: ");
	scanf("%d", &n);
	a = (int*)malloc(n * sizeof(int));
	printf("Input: number [%d]: ", n);
	for (i = 0; i < n; i++)
		scanf("%d", &a[i]);


	for (i = 0; i < n; i++) {
		for (j = 0; j < n - 1; j++) {
			if (a[j] < a[j + 1]) {
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}
	printf("Output: \n");
	for (i = 0; i < n; i++) {
		printf("%d: %d\n",i, a[i]);
	}
	printf("largest element: %d\n", a[0]);
	printf("smallest element: %d\n", a[n-1]);
	free(a);
	return 0;
}
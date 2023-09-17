#include <stdio.h>
int main() {
	int i, n, key;
	int a[100];
	printf("Enter Array length(up to 100): ");
	scanf("%d", &n);
	if (n > 100) {
		printf("Array size exceeds limit of 100\n");
		return 1;
	}
	printf("Enter %d array elements:\n", n);
	for (i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	printf("Enter search key: ");
	scanf("%d", &key);
	for (i = 0; i < n; i++) {
		if (a[i] == key) {
			printf("key's  position: %d\n", i);
			break;
		}
		if (i == n - 1)
			printf("Not Found\n");
	}
	return 0;
}
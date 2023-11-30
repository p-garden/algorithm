#include <stdio.h>
// Global variables
int n = 5; // Number of items
int p[10] = { 3, 3, 2, 5, 1 }; // Array storing weights of items
int w[10] = { 10, 15, 10, 12, 8 }; // Array storing values of items
int W = 10; // Maximum weight capacity of the knapsack
int main() {
	int cur_w; // Current weight of the knapsack
	float tot_v = 0; // Total value of items in the knapsack, initialized to 0
	int i, maxi; // Loop counters and index of the current item
	int used[10]; // Array to track whether an item is used
	// Initialize the used array to 0 for all items
	for (i = 0; i < n; ++i)
		used[i] = 0; //사용한 적이 있는지 없음:0 있음:1
	cur_w = W; // Set current weight to the knapsack's capacity
	// Main loop to add items to the knapsack
	while (cur_w > 0) {
		maxi = -1; // Reset the index of the chosen item
		// Find the item with the best value-to-weight ratio that hasn't been used
		for (i = 0; i < n; ++i)
			if ((used[i] == 0) && ((maxi == -1) || ((float)w[i] / p[i] > (float)w[maxi] / p[maxi]))) //사용한적 없고 (for문 처음이거나 or 무게당 가치가 best보다 큰경우) -> 결국은 무게당 가치 젤 높은거 찾기
				maxi = i;
		used[maxi] = 1; // Mark the chosen item as used
		cur_w = cur_w - p[maxi]; // Reduce current weight by the weight of the chosen item
		tot_v = tot_v + w[maxi]; // Add the value of the chosen item to the total value
		// Print information about the added item
		if (cur_w >= 0)
			printf("Added object %d (%d, %d) completely in the bag. Space left: %d.\n", maxi + 1, w[maxi], p[maxi], cur_w);
		else {
			// If only part of the item was added due to weight constraints
			printf("Added %d%% (%d, %d) of object %d in the bag.\n", (int)((1 + (float)cur_w / p[maxi]) * 100), w[maxi], p[maxi], maxi + 1); //무게가 넘치는 경우 마지막 추가될 무게의 몇%만이 포함됨
			tot_v = tot_v - w[maxi]; // Remove the value of the entire item
			tot_v = tot_v + (1 + (float)cur_w / p[maxi]) * w[maxi]; // Add the value of the part of the item / 43+ ((1+-4.0/5) * 12)
		}
	}
	// Print the final total value of items in the knapsack
	printf("Filled the bag with objects worth %.2f.\n", tot_v);
	return 0;
}
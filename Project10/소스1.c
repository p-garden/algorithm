#include <stdio.h>
int a, b, u, v, n, i, j, ne = 1; // Declare variables
int visited[10] = { 0 }, min, mincost = 0, cost[10][10]; // Declare arrays and1initialize variables
int main(){
	printf("\nEnter the number of nodes: ");
	scanf("%d", &n); // Take input for the number of nodes
	printf("\nEnter the adjacency matrix:\n");
	for (i = 1; i <= n; i++)
		for (j = 1; j <= n; j++)
		{
			scanf("%d", &cost[i][j]); // Take input for the adjacency matrix
			if (cost[i][j] == 0)
				cost[i][j] = 999; // If the cost is 0, set it to a large value (999)
		}
	visited[1] = 1; // Mark the first node as visited
	printf("\n");
	while (ne < n)
	{
		min = 999;
		for (i = 1; i <= n; i++)
			for (j = 1; j <= n; j++)
				if (cost[i][j] < min)
					if (visited[i] != 0)
					{
						min = cost[i][j];
						a = u = i;
						b = v = j; // Update minimum cost and corresponding nodes
					}
		if (visited[u] == 0 || visited[v] == 0){
			printf("\nEdge %d: (%d %d) cost: %d", ne++, a, b, min); // Print the1selected edge and cost
				mincost += min; // Update the total minimum cost
			visited[b] = 1; // Mark the new node as visited
		}
		cost[a][b] = cost[b][a] = 999; // Remove the edge from consideration
	}
	printf("\nMinimum cost = %d\n", mincost); // Print the minimum cost
	return 0;
}
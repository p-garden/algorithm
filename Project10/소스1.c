#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
// Declaring global variables
int i, j, k, a, b, u, v, n, ne = 1;
int min, mincost = 0, cost[9][9], parent[9];
// Function declarations
int find(int);
int uni(int, int);
// Main function
int main()
{
	// Printing a message to indicate Kruskal's Algorithm implementation
	printf("\n\tImplementation of Kruskal's Algorithm\n");
	// Taking input for the number of vertices
	printf("\nEnter the no. of vertices:");
	scanf("%d", &n);
	// Taking input for the cost adjacency matrix
	printf("\nEnter the cost adjacency matrix:\n");
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
		{
			// Reading the cost and replacing 0 with a large value (999 in this case)
			scanf("%d", &cost[i][j]);
			if (cost[i][j] == 0)
				cost[i][j] = 999;
		}
	}
	// Printing the edges of the Minimum Cost Spanning Tree
	printf("The edges of Minimum Cost Spanning Tree are\n");
	// Loop until all vertices are included in the MST
	while (ne < n)
	{
		// Finding the minimum cost edge in the adjacency matrix
		for (i = 1, min = 999; i <= n; i++) {
			for (j = 1; j <= n; j++) {
				if (cost[i][j] < min) {
					min = cost[i][j];
					a = u = i;
					b = v = j;
				}
			}
		}
		// Finding the parent of the vertices using the find function
		u = find(u);
		v = find(v); //아직 부모 설정 안되어있음 자기 자신을 함숫값으로 받음
		// Checking if adding the edge creates a cycle
		if (uni(u, v)) //v의 부모로 u를 넣음 이때 rerurn값은 1/ 두 변수가 같으면 return:0
		{
			// Printing the selected edge and updating the minimum cost
			printf("%d edge (%d,%d) =%d\n", ne++, a, b, min);
			mincost += min;
		}
		// Marking the edge as processed by setting its cost to a large value
		cost[a][b] = cost[b][a] = 999;
	}
	// Printing the minimum cost of the Minimum Cost Spanning Tree
	printf("\n\tMinimum cost = %d\n", mincost);
	// Waiting for a key press before closing the console window
	getch();
}
// Function to find the parent of a vertex in a set
int find(int i)
{
	while (parent[i])
		i = parent[i];
	return i;
}
// Function to perform union operation of two sets
int uni(int i, int j)
{
	if (i != j)
	{
		// Setting the parent of the second set to the first set
		parent[j] = i;
		return 1;
	}
	return 0;
}
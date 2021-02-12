/*
    Time Complexity: O(ElogV)
*/

#include <stdio.h>
#define INF 9999

void prim(int n, int graph[n][n]) {
    int mst[n], cost = 0, num_edges = 0, row, col, min;
    for (int i = 0; i < n; i++)
        mst[i] = 0;
    mst[0] = 1;

    printf("\nEdge :  Weight");
    while (num_edges < n-1) {
        min = INF;
        row = 0;
        col = 0;

        for (int i = 0; i < n; i++) {
            if (mst[i]) {
                for (int j = 0; j < n; j++) {
                    if (graph[i][j] && !mst[j]) {
                        if (graph[i][j] < min) {
                            min = graph[i][j];
                            row = i;
                            col = j;
                        }
                    }
                }
            }
        }
        printf("\n%d - %d: %d", row, col, graph[row][col]);
        cost += graph[row][col];
        mst[col] = 1;
        num_edges++;
    }
    printf("\nThe cost of the Minimum Spanning Tree: %d", cost);
}

int main() {
	int n;
	printf("Enter the number of vertices: ");
	scanf("%d",&n);

    int graph[n][n];
	printf("\nEnter the adjacency matrix:\n");
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			scanf("%d", &graph[i][j]);

	prim(n, graph);

	return 0;
}






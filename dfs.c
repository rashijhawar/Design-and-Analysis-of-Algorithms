#include <stdio.h>
#define N 50

int visited[N] = {0};

int dfs(int n, int node, int graph[n][n]) {
    if (!visited[node]) {
        printf("%d ", node);
        visited[node] = 1;

        for (int i = 0; i < n; i++)
            if (graph[node][i])
                dfs(n, i, graph);
    }

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

    int start;
    printf("\nEnter the starting vertex: ");
	scanf("%d",&start);

	printf("\nDFS Traversal: ");
	dfs(n, start, graph);

	return 0;
}


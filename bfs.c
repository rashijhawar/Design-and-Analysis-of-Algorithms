#include <stdio.h>
#define N 50

int visited[N] = { 0 }, queue[N] = { 0 };
int front = 0, rear = -1;

int bfs(int n, int start, int graph[n][n]) {
    printf("\nBFS Traversal: ");
    visited[start] = 1;
    rear++;
    queue[rear] = start;

    int node;
    while (front <= rear) {
        node = queue[front];
        printf("%d ", queue[front]);
        front++;

        for (int i = 0; i < n; i++)
            if (graph[node][i] && !visited[i]) {
                visited[i] = 1;
                rear++;
                queue[rear] = i;
            }
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

	bfs(n, start, graph);

	return 0;
}

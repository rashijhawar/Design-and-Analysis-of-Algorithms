#include <stdio.h>

int nearest_neighbor(int source, int n, int graph[n][n], int visited[n]) {
    int min = 9999, min_index = -1;
    for (int j = 0; j < n; j++)
        if (source != j && !visited[j])
            if (graph[source][j] < min) {
                min = graph[source][j];
                min_index = j;
            }
    return min_index;
}

void tsp(int n, int graph[n][n], int source) {
    int visited[n], cost = 0;

    for (int i = 0; i < n; i++)
        visited[i] = 0;
    visited[source] = 1;

    printf("%d -> ", source);

    int next = source, k = 0, curr;
    while (k < n-1) {
        curr = next;
        next = nearest_neighbor(curr, n, graph, visited);
        visited[next] = 1;
        cost += graph[curr][next];
        printf("%d -> ", next);
        k++;
    }
    printf("%d", source);
    cost += graph[next][source];

    printf("\n\nCost of travelling: %d\n", cost);

}

int main() {
	int n;
	printf("Enter the number of cities: ");
	scanf("%d",&n);

    int graph[n][n];
	printf("\nEnter the adjacency matrix:\n");
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			scanf("%d", &graph[i][j]);

    int source;
	printf("\nEnter the source city: ");
	scanf("%d",&source);

	tsp(n, graph, source);

	return 0;
}

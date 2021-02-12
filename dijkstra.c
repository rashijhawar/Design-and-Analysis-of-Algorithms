#include <stdio.h>
#define INF 9999

void dijkstra(int n, int source, int graph[n][n]) {
    int cost[n][n], visited[n], distance[n];
    int min_distance, min_distance_index;
    int original_source = source;

    for (int i = 0; i < n; i++) {
        distance[i] = INF;
        visited[i] = 0;
    }
    distance[source] = 0;

    for (int k = 0; k < n-1; k++) {
        min_distance = INF;
        for (int l = 0; l < n; l++)
            if (distance[l] < min_distance && !visited[l]) {
                min_distance = distance[l];
                min_distance_index = l;
            }
        source = min_distance_index;
        visited[min_distance_index] = 1;

        for (int i = 0; i < n; i++)
            if (!visited[i] && graph[source][i] && distance[source] != INF && distance[source] + graph[source][i] < distance[i])
                distance[i] = distance[source] + graph[source][i];
     }

    for (int i = 0; i < n; i++)
        printf("\nDistance from Node %d to Node %d: %d", original_source, i, distance[i]);
}

int main() {
    int n;
    printf("Enter the number of nodes: ");
	scanf("%d",&n);

	int graph[n][n];
    printf("\nEnter the adjacency matrix:\n");
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			scanf("%d", &graph[i][j]);

    int source;
    printf("Enter the source node: ");
	scanf("%d",&source);

    dijkstra(n, source, graph);

  return 0;
}

#include <stdio.h>

int isSafe(int n, int v, int graph[n][n], int color[n], int c) {
    for (int i = 0; i < n; i++)
        if (graph[v][i] && c == color[i])
            return 0;
    return 1;
}

int colorGraph(int n, int m, int graph[n][n], int color[n], int v) {
    if (v == n)
        return 1;

    for (int i = 1; i <= m; i++) {
        if (isSafe(n, v, graph, color, i)) {
            color[v] = i;

            if (colorGraph(n, m, graph, color, v + 1))
                return 1;

            color[v] = 0;
        }
    }

    return 0;
}

int main() {
    int n, m;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    int graph[n][n];
    printf("\nEnter the adjacency matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);

    printf("\nEnter the number of colors: ");
    scanf("%d", &m);

    int color[n];
    for (int i = 0; i < n; i++)
        color[i] = 0;

    if (colorGraph(n, m, graph, color, 0)) {
        for (int i = 0; i < n; i++)
            printf("\nVertex %d : Color %d", i, color[i]);
    } else
        printf("\nThere exists no solution for the given graph.");

    return 0;
}

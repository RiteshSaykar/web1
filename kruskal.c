#include <stdio.h>

int p[10];

int parent(int x) {
    while (x != p[x]) {
        x = p[x];
    }
    return x;
}

void kruskal(int graph[10][10], int n) {
    int u, v;
    for (int i = 0; i < n; i++) {
        p[i] = i;
    }
    int ne = 0;
    int sum = 0;
    while (ne < n - 1) {
        int min = 999;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (graph[i][j] < min) {
                    min = graph[i][j];
                    u = i;
                    v = j;
                }
            }
        }
        if (parent(u) != parent(v)) {
            printf("Connect %d -----> %d = %d\n", u, v, graph[u][v]);
            sum += graph[u][v];
            p[parent(v)] = parent(u);
            ne++;
        }
        graph[u][v] = 999;
        graph[v][u] = 999;
    }
    printf("MST cost = %d\n", sum);
}

int main() {
    int graph[10][10], n;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    printf("\nEnter the weighted graph:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }
    printf("\n-----------Minimum Spanning Tree-----------\n");
    kruskal(graph, n);

    return 0;
}

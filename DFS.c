#include <stdio.h>

#define MAX 5

int visited[MAX] = {0};

void dfs(int graph[MAX][MAX], int node) {
    int i;
    visited[node] = 1;
    printf("%d ", node + 1);

    for (i = 0; i < MAX; i++) {
        if (graph[node][i] == 1 && !visited[i]) {
            dfs(graph, i);
        }
    }
}

int main() {
    int graph[MAX][MAX] = {
        {0, 1, 1, 0, 0},
        {1, 0, 0, 1, 0},
        {1, 0, 0, 0, 1},
        {0, 1, 0, 0, 1},
        {0, 0, 1, 1, 0}
    };

    dfs(graph, 0);
    return 0;
}

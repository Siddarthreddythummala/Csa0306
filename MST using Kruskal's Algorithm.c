#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct Edge {
    int src, dest, weight;
};

int parent[MAX];

int find(int i) {
    if (parent[i] == i)
        return i;
    return find(parent[i]);
}

void unionSet(int u, int v) {
    int u_root = find(u);
    int v_root = find(v);
    parent[u_root] = v_root;
}

int compare(const void* a, const void* b) {
    struct Edge* e1 = (struct Edge*)a;
    struct Edge* e2 = (struct Edge*)b;
    return e1->weight - e2->weight;
}

void kruskal(struct Edge edges[], int V, int E) {
    int i, count = 0;
    int totalWeight = 0;

    for (i = 0; i < V; i++)
        parent[i] = i;

    qsort(edges, E, sizeof(edges[0]), compare);

    printf("Edge \tWeight\n");

    for (i = 0; i < E && count < V - 1; i++) {
        int u = find(edges[i].src);
        int v = find(edges[i].dest);

        if (u != v) {
            printf("%d - %d\t%d\n", edges[i].src, edges[i].dest, edges[i].weight);
            totalWeight += edges[i].weight;
            unionSet(u, v);
            count++;
        }
    }

    printf("Total weight of MST: %d\n", totalWeight);
}

int main() {
    int V = 4;
    int E = 5;

    struct Edge edges[] = {
        {0, 1, 10},
        {0, 2, 6},
        {0, 3, 5},
        {1, 3, 15},
        {2, 3, 4}
    };

    kruskal(edges, V, E);
    return 0;
}

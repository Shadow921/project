#include <stdio.h>
#include <stdlib.h>

#define MAXNODES 10
#define INF 9999

typedef struct {
    int u, v, cost;
} edge;

int fnFindParent(int v, int parent[]) {
    while (parent[v] != v)
        v = parent[v];
    return v;
}

void fnUnion_ij(int i, int j, int parent[]) {
    if (i < j)
        parent[j] = i;
    else
        parent[i] = j;
}

void fnInputGraph(int m, edge e[]) {
    int i, j, k, cost;
    for (k = 0; k < m; k++) {
        printf("Enter edge and cost in the form u v w: ");
        scanf("%d %d %d", &i, &j, &cost);
        e[k].u = i;
        e[k].v = j;
        e[k].cost = cost;
    }
}

int fnGetMinEdge(edge e[], int n) {
    int i, small = INF, pos = -1;
    for (i = 0; i < n; i++) {
        if (e[i].cost < small) {
            small = e[i].cost;
            pos = i;
        }
    }
    return pos;
}

void fnKruskal(int n, edge e[], int m) {
    int i, j, count = 0, k = 0, sum = 0, u, v, pos;
    int parent[MAXNODES];
    int t[MAXNODES][2];

    for (i = 0; i < n; i++)
        parent[i] = i;

    while (count != n - 1) {
        pos = fnGetMinEdge(e, m);
        if (pos == -1)
            break;

        u = e[pos].u;
        v = e[pos].v;

        i = fnFindParent(u, parent);
        j = fnFindParent(v, parent);

        if (i != j) {
            t[k][0] = u;
            t[k][1] = v;
            k++;
            count++;
            sum += e[pos].cost;
            fnUnion_ij(i, j, parent);
        }

        e[pos].cost = INF;
    }

    if (count == n - 1) {
        printf("\nSpanning tree exists\n");
        printf("The Spanning tree is shown below:\n");
        for (i = 0; i < n - 1; i++)
            printf("%d - %d\n", t[i][0], t[i][1]);
        printf("Cost of the spanning tree: %d\n", sum);
    } else {
        printf("\nThe spanning tree does not exist\n");
    }
}

int main() {
    int n, m;
    edge e[2 * MAXNODES];

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    printf("Enter the number of edges: ");
    scanf("%d", &m);

    fnInputGraph(m, e);
    fnKruskal(n, e, m);

    return 0;
}

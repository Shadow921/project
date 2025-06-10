#include <stdio.h>
#include <stdlib.h>

#define MAXNODES 10
#define INF 9999

void fnPrims(int n, int cost[MAXNODES][MAXNODES]);
void fnGetMatrix(int n, int a[MAXNODES][MAXNODES]);

int main() {
    int a[MAXNODES][MAXNODES];
    int n;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    fnGetMatrix(n, a);
    fnPrims(n, a);

    return 0;
}

void fnPrims(int n, int cost[MAXNODES][MAXNODES]) {
    int i, j, u, v, min;
    int sum, k, t[MAXNODES][2], p[MAXNODES], d[MAXNODES], s[MAXNODES];
    int source, count;

    min = INF;
    source = 0;

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (cost[i][j] != 0 && cost[i][j] <= min) {
                min = cost[i][j];
                source = i;
            }
        }
    }

    for (i = 0; i < n; i++) {
        d[i] = cost[source][i];
        s[i] = 0;
        p[i] = source;
    }

    s[source] = 1;
    sum = 0;
    k = 0;
    count = 0;

    while (count != n - 1) {
        min = INF;
        u = -1;

        for (j = 0; j < n; j++) {
            if (s[j] == 0 && d[j] < min) {
                min = d[j];
                u = j;
            }
        }

        if (u == -1) break;

        t[k][0] = u;
        t[k][1] = p[u];
        k++;
        count++;
        sum += cost[u][p[u]];
        s[u] = 1;

        for (v = 0; v < n; v++) {
            if (s[v] == 0 && cost[u][v] < d[v]) {
                d[v] = cost[u][v];
                p[v] = u;
            }
        }
    }

    if (sum >= INF)
        printf("\nSpanning tree does not exist\n");
    else {
        printf("\nThe spanning tree exists. Minimum cost spanning tree edges are:\n");
        for (i = 0; i < k; i++)
            printf("%d - %d\n", t[i][1], t[i][0]);

        printf("\nThe cost of the minimum cost spanning tree is %d\n", sum);
    }
}

void fnGetMatrix(int n, int a[MAXNODES][MAXNODES]) {
    int i, j;
    printf("Enter the Cost Adjacency Matrix:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &a[i][j]);
}

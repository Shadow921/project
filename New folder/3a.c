#include <stdio.h>
#define INF 999

int min(int a, int b) {
    return (a < b) ? a : b;
}

void floyd(int p[][10], int n) {
    int i, j, k;
    for (k = 0; k < n; k++)
        for (i = 0; i < n; i++)
            for (j = 0; j < n; j++)
                p[i][j] = min(p[i][j], p[i][k] + p[k][j]);
}

int main() {
    int a[10][10], n, i, j;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix (use %d for INF):\n", INF);
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &a[i][j]);

    floyd(a, n);

    printf("\nShortest path matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++)
            printf("%3d ", a[i][j]);
        printf("\n");
    }

    return 0;
}

//3b
#include <stdio.h>

void warshall(int p[][10], int n)
{
    int i, j, k;
    for (k = 0; k < n; k++)
        for (i = 0; i < n; i++)
            for (j = 0; j < n; j++)
                p[i][j] = p[i][j] || (p[i][k] && p[k][j]);
}

int main()
{
    int a[10][10], n, i, j;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &a[i][j]);

    warshall(a, n);

    printf("Transitive closure (Path matrix):\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
            printf("%d ", a[i][j]);
        printf("\n");
    }

    return 0;
}

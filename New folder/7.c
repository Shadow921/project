#include <stdio.h>
#define MAX 50

int p[MAX], w[MAX];
double x[MAX];           // Use double since we deal with fractions
double maxprofit;
int n, m, i;

void greedyKnapsack(int n, int w[], int p[], int m) {
    double ratio[MAX];

    // Calculate profit-to-weight ratio
    for (i = 0; i < n; i++) {
        ratio[i] = (double)p[i] / w[i];
    }

    // Sort items based on ratio in descending order
    for (i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (ratio[i] < ratio[j]) {
                double temp = ratio[i];
                ratio[i] = ratio[j];
                ratio[j] = temp;

                int temp2 = w[i];
                w[i] = w[j];
                w[j] = temp2;

                temp2 = p[i];
                p[i] = p[j];
                p[j] = temp2;
            }
        }
    }

    int currentWeight = 0;
    maxprofit = 0.0;

    // Select items greedily
    for (i = 0; i < n; i++) {
        if (currentWeight + w[i] <= m) {
            x[i] = 1.0;
            currentWeight += w[i];
            maxprofit += p[i];
        } else {
            x[i] = (double)(m - currentWeight) / w[i];
            maxprofit += x[i] * p[i];
            break;  // Knapsack is full
        }
    }

    printf("\nOptimal profit using Greedy Method: %.2f\n", maxprofit);
    printf("Solution vector (fractions of items taken):\n");
    for (i = 0; i < n; i++)
        printf("%.2f\t", x[i]);
    printf("\n");
}

int main() {
    printf("Enter the number of objects: ");
    scanf("%d", &n);

    printf("Enter the weights of the objects:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &w[i]);

    printf("Enter the profits of the objects:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &p[i]);

    printf("Enter the maximum capacity of knapsack: ");
    scanf("%d", &m);

    greedyKnapsack(n, w, p, m);

    return 0;
}

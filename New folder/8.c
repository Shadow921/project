#include <stdio.h> 
int subset(int n, int d, int values[]); 
int main() { 
int n, d, i, values[10]; 
printf("Enter the number of elements: "); 
scanf("%d", &n); 
printf("Enter the values of the elements (in ascending order):\n"); 
for(i = 1; i <= n; i++) 
scanf("%d", &values[i]); 
printf("Enter the sum value: "); 
scanf("%d", &d); 
if (!subset(n, d, values)) 
printf("\nThe problem instance doesn't have any solution.\n"); 
else 
printf("\nThe above-mentioned sets are the required solution to the given instance.\n"); 
return 0; 
} 
int subset(int n, int d, int values[]) { 
int sum, k, i, included[10]; 
static int foundSoln = 0; 
static int count = 0; 
for(i = 1; i <= n; i++) 
        included[i] = 0; 
 
    sum = 0; 
    k = 1; 
    included[k] = 1; 
 
    while(1) { 
        if (k <= n && included[k] == 1) { 
            if (sum + values[k] == d) { 
                foundSoln = 1; 
                ++count; 
                printf("SOLUTION #%d IS\n{ ", count); 
                for(i = 1; i <= n; i++) { 
                    if (included[i] == 1) 
                        printf("%d ", values[i]); 
                } 
                printf("}\n\n"); 
                included[k] = 0; 
            } else if (sum + values[k] < d) { 
                sum += values[k]; 
            } else { 
                included[k] = 0; 
            } 
        } else { 
            k--; 
            while (k > 0 && included[k] == 0) 
                k--; 
 
            if (k == 0) 
                break; 
 
included[k] = 0; 
sum -= values[k]; 
} 
k = k + 1; 
included[k] = 1; 
} 
return foundSoln; 
} 

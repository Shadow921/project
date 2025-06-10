#include <stdio.h> 
#include <stdlib.h> 
#include <sys/time.h> 
#include <time.h> 
 
#define MAX 500000 
 
void fnGenRandInput(int [], int); 
void fnDispArray(int [], int); 
void fnSelectionSort(int [], int); 
 
int main() 
{ 
    FILE *fp; 
    struct timeval tv; 
    double dStart, dEnd; 
    int iaArr[MAX], iNum, i, iChoice; 
 
    while (1) 
    { 
        printf("\n1. Plot the Graph\n2. Selection Sort\n3. Exit\n"); 
        printf("Enter your choice: "); 
        scanf("%d", &iChoice); 
 
        switch (iChoice) 
        { 
            case 1: 
                fp = fopen("SelectionPlot.dat", "w"); 
                if (fp == NULL) 
                { 
                    perror("Failed to open file"); 
                    exit(1); 
                } 
                for (i = 100; i <= 20000; i += 100) 
                { 
                    fnGenRandInput(iaArr, i); 
 
                    gettimeofday(&tv, NULL); 
                    dStart = tv.tv_sec + (tv.tv_usec / 1000000.0); 
 
                    fnSelectionSort(iaArr, i); 
 
                    gettimeofday(&tv, NULL); 
                    dEnd = tv.tv_sec + (tv.tv_usec / 1000000.0); 
 
                    fprintf(fp, "%d\t%lf\n", i, dEnd - dStart); 
                } 
                fclose(fp); 
                printf("\nData file generated and saved as 'SelectionPlot.dat'.\nUse a plotting utility to view 
the graph.\n"); 
                break; 
 
            case 2: 
                printf("\nEnter the number of elements to sort: "); 
                scanf("%d", &iNum); 
 
                printf("\nUnsorted Array:\n"); 
                fnGenRandInput(iaArr, iNum); 
                fnDispArray(iaArr, iNum); 
 
                fnSelectionSort(iaArr, iNum); 
 
                printf("\nSorted Array:\n"); 
                fnDispArray(iaArr, iNum); 
                break; 
 
            case 3: 
                exit(0); 
 
            default: 
                printf("Invalid choice! Please try again.\n"); 
        } 
    } 
 
    return 0; 
} 
 
void fnGenRandInput(int X[], int n) 
{ 
    int i; 
    srand(time(NULL)); 
    for (i = 0; i < n; i++) 
    { 
        X[i] = rand() % 10000; 
    } 
} 
 
void fnDispArray(int X[], int n) 
{ 
    int i; 
    for (i = 0; i < n; i++) 
    { 
        printf("%5d\n", X[i]); 
    } 
} 
 
void fnSelectionSort(int X[], int n) 
{ 
    int i, j, iMin, iTemp; 
    for (i = 0; i < n - 1; i++) 
    { 
        iMin = i; 
        for (j = i + 1; j < n; j++) 
        { 
            if (X[j] < X[iMin]) 
                iMin = j; 
        } 
        // Swap 
        iTemp = X[i]; 
        X[i] = X[iMin]; 
        X[iMin] = iTemp; 
    } 
} 

 
 
 
 
 
 
 
set terminal png font arial 
set title "Time Complexity for Selection Sort" 
set autoscale 
set xlabel "Size of Input" 
set ylabel "Sorting Time (seconds)" 
set grid 
set output "SelectionPlot.png" 
plot "SelectionPlot.dat" title 'Selection Sort' with lines 







 
void fnGenRandInput(int [], int); void fnDispArray( int [], int); 
int fnPartition(int [], int , int); void fnQuickSort(int [], int , int); void fnSwap(int*, int*); 
 
void fnSwap(int *a, int *b) 
{ 
int t = *a; *a = *b; *b = t; 
}
int fnPartition(int a[], int l, int r) 
{ 
int i,j; int p; 
p = a[l]; 
i = l; 
j = r+1; do 
{ 
do { i++; } while (a[i] < p); 
do { j--; } while (a[j] > p); 
fnSwap(&a[i], &a[j]); 
}while (i<j); 
fnSwap(&a[i], &a[j]); 
fnSwap(&a[l], &a[j]); return j; 
} 
void fnQuickSort(int a[], int l, int r) 
{ 
int s; 
if (l < r) 
{ 
s = fnPartition(a, l, r); fnQuickSort(a, l, s-1); fnQuickSort(a, s+1, r); 
} }

void fnMerge(int [], int ,int ,int);  
void fnMergeSort(int [], int , int); 
#include <stdio.h>

void fnMerge(int a[], int low, int mid, int high) 
{ 
    int i = low, j = mid + 1, k = low;
    int b[500000];

    while(i <= mid && j <= high) 
    { 
        if(a[i] < a[j]) 
            b[k++] = a[i++]; 
        else 
            b[k++] = a[j++]; 
    } 

    while(i <= mid) 
        b[k++] = a[i++]; 

    while(j <= high) 
        b[k++] = a[j++]; 

    for(i = low; i < k; i++) 
        a[i] = b[i]; 
} 

void fnMergeSort(int a[], int low, int high) 
{ 
    if(low < high) 
    { 
        int mid = (low + high) / 2;
        fnMergeSort(a, low, mid); 
        fnMergeSort(a, mid + 1, high); 
        fnMerge(a, low, mid, high); 
    } 
} 



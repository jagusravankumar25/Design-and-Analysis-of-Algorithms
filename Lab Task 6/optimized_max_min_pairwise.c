#include <stdio.h>

/*
 * Optimized linear-time max/min using pairwise comparison.
 * Comparisons: at most 3n/2 - 2 for even n.
 */
void findMaxMin(const int a[], int n, int *min, int *max) {
    int i;

    if (n % 2 == 0) {
        if (a[0] < a[1]) {
            *min = a[0];
            *max = a[1];
        } else {
            *min = a[1];
            *max = a[0];
        }
        i = 2;
    } else {
        *min = *max = a[0];
        i = 1;
    }

    while (i + 1 < n) {
        int localMin, localMax;

        if (a[i] < a[i + 1]) {
            localMin = a[i];
            localMax = a[i + 1];
        } else {
            localMin = a[i + 1];
            localMax = a[i];
        }

        if (localMin < *min)
            *min = localMin;
        if (localMax > *max)
            *max = localMax;

        i += 2;
    }
}

int main(void) {
    int n;

    printf("Enter number of elements: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid number of elements.\n");
        return 1;
    }

    int a[n];

    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    int min, max;
    findMaxMin(a, n, &min, &max);

    printf("Minimum = %d\n", min);
    printf("Maximum = %d\n", max);

    return 0;
}

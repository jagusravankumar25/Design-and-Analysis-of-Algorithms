#include <stdio.h>
#include <limits.h>

/*
 * Optimized maximum-subarray solution using Kadane's algorithm.
 * Time: O(n), Space: O(1)
 */
long long maxSubarraySum(const int a[], int n) {
    long long bestEndingHere = a[0];
    long long bestSoFar = a[0];

    for (int i = 1; i < n; i++) {
        if (bestEndingHere + a[i] < a[i])
            bestEndingHere = a[i];
        else
            bestEndingHere += a[i];

        if (bestEndingHere > bestSoFar)
            bestSoFar = bestEndingHere;
    }

    return bestSoFar;
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

    printf("Maximum subarray sum = %lld\n", maxSubarraySum(a, n));

    return 0;
}

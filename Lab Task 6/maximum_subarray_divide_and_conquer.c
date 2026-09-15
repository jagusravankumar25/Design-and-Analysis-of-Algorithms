#include <stdio.h>
#include <limits.h>

long long max3(long long a, long long b, long long c) {
    long long m = (a > b) ? a : b;
    return (m > c) ? m : c;
}

long long maxCrossingSum(int a[], int low, int mid, int high) {
    long long leftSum = LLONG_MIN;
    long long sum = 0;

    for (int i = mid; i >= low; i--) {
        sum += a[i];
        if (sum > leftSum) {
            leftSum = sum;
        }
    }

    long long rightSum = LLONG_MIN;
    sum = 0;

    for (int i = mid + 1; i <= high; i++) {
        sum += a[i];
        if (sum > rightSum) {
            rightSum = sum;
        }
    }

    return leftSum + rightSum;
}

long long maxSubarraySum(int a[], int low, int high) {
    if (low == high) {
        return a[low];
    }

    int mid = low + (high - low) / 2;

    long long left = maxSubarraySum(a, low, mid);
    long long right = maxSubarraySum(a, mid + 1, high);
    long long crossing = maxCrossingSum(a, low, mid, high);

    return max3(left, right, crossing);
}

int main(void) {
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Number of elements must be positive.\n");
        return 1;
    }

    int a[n];

    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    printf("Maximum subarray sum = %lld\n",
           maxSubarraySum(a, 0, n - 1));

    return 0;
}

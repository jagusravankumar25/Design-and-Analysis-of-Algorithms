#include <stdio.h>

void findMaxMin(int a[], int low, int high, int *min, int *max) {
    if (low == high) {
        *min = *max = a[low];
        return;
    }

    if (high == low + 1) {
        if (a[low] < a[high]) {
            *min = a[low];
            *max = a[high];
        } else {
            *min = a[high];
            *max = a[low];
        }
        return;
    }

    int mid = low + (high - low) / 2;
    int min1, max1, min2, max2;

    findMaxMin(a, low, mid, &min1, &max1);
    findMaxMin(a, mid + 1, high, &min2, &max2);

    *min = (min1 < min2) ? min1 : min2;
    *max = (max1 > max2) ? max1 : max2;
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

    int min, max;
    findMaxMin(a, 0, n - 1, &min, &max);

    printf("Minimum = %d\n", min);
    printf("Maximum = %d\n", max);

    return 0;
}

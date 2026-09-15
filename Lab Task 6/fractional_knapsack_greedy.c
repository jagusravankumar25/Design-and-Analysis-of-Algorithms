#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int weight;
    int value;
    double ratio;
} Item;

int compare(const void *a, const void *b) {
    const Item *x = (const Item *)a;
    const Item *y = (const Item *)b;

    if (x->ratio < y->ratio) {
        return 1;
    }
    if (x->ratio > y->ratio) {
        return -1;
    }
    return 0;
}

int main(void) {
    int n, capacity;

    printf("Enter number of items: ");
    scanf("%d", &n);

    printf("Enter knapsack capacity: ");
    scanf("%d", &capacity);

    if (n <= 0 || capacity < 0) {
        printf("Invalid input.\n");
        return 1;
    }

    Item items[n];

    printf("Enter weight and value for each item:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &items[i].weight, &items[i].value);

        if (items[i].weight <= 0) {
            printf("Weight must be positive.\n");
            return 1;
        }

        items[i].ratio = (double)items[i].value / items[i].weight;
    }

    // Greedy choice: take items in decreasing value/weight ratio.
    qsort(items, n, sizeof(Item), compare);

    int remaining = capacity;
    double maxValue = 0.0;

    for (int i = 0; i < n && remaining > 0; i++) {
        if (items[i].weight <= remaining) {
            remaining -= items[i].weight;
            maxValue += items[i].value;
        } else {
            double fraction = (double)remaining / items[i].weight;
            maxValue += items[i].value * fraction;
            remaining = 0;
        }
    }

    printf("Maximum value = %.2f\n", maxValue);

    return 0;
}

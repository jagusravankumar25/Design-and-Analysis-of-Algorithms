#include <stdio.h>

int main() {
    int arr[] = {7, 2, 9, 1, 5};
    int n = 5;
    int k = 3;

    // Sort the array                               // similar to selection sorting algorithm 
    
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {

            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    printf("Kth smallest element = %d\n", arr[k - 1]);

    return 0;
}

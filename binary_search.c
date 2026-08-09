#include <stdio.h>

int main()
{
    int n, key;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter elements in sorted order:\n");
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Enter element to search: ");
    scanf("%d", &key);

    int low = 0;
    int high = n - 1;

    while(low <= high)
    {
        int mid = (low + high) / 2;

        if(arr[mid] == key)
        {
            printf("Element found at index %d", mid);
            return 0;
        }
        else if(key < arr[mid])
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    printf("Element not found");

    return 0;
}
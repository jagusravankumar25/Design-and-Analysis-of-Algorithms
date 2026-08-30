#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 100

struct Node {
    int key;
    struct Node *next;
};

struct Node *hashTable[TABLE_SIZE] = {NULL};

int hashFunction(int key)
{
    int h = key % TABLE_SIZE;
    if (h < 0)
        h += TABLE_SIZE;
    return h;
}

void insert(int key)
{
    int index = hashFunction(key);
    struct Node *newNode = malloc(sizeof(struct Node));
    newNode->key = key;
    newNode->next = hashTable[index];
    hashTable[index] = newNode;
}

int search(int key)
{
    int index = hashFunction(key);
    struct Node *temp = hashTable[index];
    while (temp != NULL)
    {
        if (temp->key == key)
            return 1;
        temp = temp->next;
    }
    return 0;
}

void findPair(int arr[], int n, int target)
{
    int found = 0;

    for (int i = 0; i < n; i++)
    {
        int need = target - arr[i];

        if (search(need))
        {
            printf("Pair found: %d + %d = %d\n", need, arr[i], target);
            found = 1;
        }
        insert(arr[i]);
    }

    if (!found)
        printf("No pair found with sum %d\n", target);
}

int main()
{
    int arr[] = {10, 15, 3, 7, 2, 8};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 17;

    printf("Array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    printf("Target sum: %d\n", target);
    findPair(arr, n, target);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 100

struct Node {
    int key;
    int count;
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
    struct Node *temp = hashTable[index];

    while (temp != NULL)
    {
        if (temp->key == key)
        {
            temp->count++;
            return;
        }
        temp = temp->next;
    }

    struct Node *newNode = malloc(sizeof(struct Node));
    newNode->key = key;
    newNode->count = 1;
    newNode->next = hashTable[index];
    hashTable[index] = newNode;
}

void display()
{
    printf("Element -> Frequency\n");
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        struct Node *temp = hashTable[i];
        while (temp != NULL)
        {
            printf("%d -> %d\n", temp->key, temp->count);
            temp = temp->next;
        }
    }
}

int main()
{
    int arr[] = {4, 2, 5, 2, 4, 4, 8, 5, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    for (int i = 0; i < n; i++)
        insert(arr[i]);

    display();

    return 0;
}

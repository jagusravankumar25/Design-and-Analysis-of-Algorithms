#include <stdio.h>
#include <stdbool.h>

#define SIZE 10

int table[SIZE];
bool occupied[SIZE] = {false};

int hashFunction(int key)
{
    return key % SIZE;
}

void insert(int key)
{
    int index = hashFunction(key);
    int i = 0;

    while (i < SIZE)
    {
        int pos = (index + i * i) % SIZE;
        if (!occupied[pos])
        {
            table[pos] = key;
            occupied[pos] = true;
            return;
        }
        i++;
    }
    printf("Hash table is full, cannot insert %d\n", key);
}

int search(int key)
{
    int index = hashFunction(key);
    int i = 0;

    while (i < SIZE)
    {
        int pos = (index + i * i) % SIZE;
        if (occupied[pos] && table[pos] == key)
            return pos;
        i++;
    }
    return -1;
}

void display()
{
    for (int i = 0; i < SIZE; i++)
    {
        if (occupied[i])
            printf("%d -> %d\n", i, table[i]);
        else
            printf("%d -> empty\n", i);
    }
}

int main()
{
    int keys[] = {23, 34, 14, 15, 45, 67};
    int n = sizeof(keys) / sizeof(keys[0]);

    for (int i = 0; i < n; i++)
        insert(keys[i]);

    printf("Hash Table using Quadratic Probing:\n");
    display();

    int key = 45;
    int pos = search(key);
    if (pos != -1)
        printf("Key %d found at index %d\n", key, pos);
    else
        printf("Key %d not found\n", key);

    return 0;
}

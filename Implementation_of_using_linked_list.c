#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *front = NULL;
struct Node *rear = NULL;

void enqueue(int value)
{
    struct Node *newNode = malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->next = NULL;

    if (rear == NULL)
    {
        front = rear = newNode;
    }
    else
    {
        rear->next = newNode;
        rear = newNode;
    }
}

void dequeue()
{
    if (front == NULL)
    {
        printf("Queue Underflow\n");
        return;
    }

    struct Node *temp = front;

    printf("Deleted: %d\n", front->data);

    front = front->next;

    if (front == NULL)
        rear = NULL;

    free(temp);
}

void peek()
{
    if (front == NULL)
    {
        printf("Queue is empty\n");
        return;
    }

    printf("Front: %d\n", front->data);
}

void display()
{
    struct Node *temp = front;

    if (front == NULL)
    {
        printf("Queue is empty\n");
        return;
    }

    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    printf("\n");
}

int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);

    display();

    peek();

    dequeue();

    display();

    return 0;
}

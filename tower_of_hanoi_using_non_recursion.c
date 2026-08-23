#include <stdio.h>
#include <math.h>

void hanoi(int n)
{
    int total = (int)pow(2, n) - 1;
    char source = 'A', auxiliary = 'B', destination = 'C';

    if (n % 2 == 0)
    {
        char temp = auxiliary;
        auxiliary = destination;
        destination = temp;
    }

    for (int i = 1; i <= total; i++)
    {
        int disk = 1;
        int x = i;

        while (x % 2 == 0)
        {
            x = x / 2;
            disk++;
        }

        if (disk % 2 == 1)
        {
            if (i % 3 == 1)
                printf("Move disk %d from %c to %c\n", disk, source, destination);
            else if (i % 3 == 2)
                printf("Move disk %d from %c to %c\n", disk, destination, auxiliary);
            else
                printf("Move disk %d from %c to %c\n", disk, auxiliary, source);
        }
        else
        {
            if (i % 3 == 1)
                printf("Move disk %d from %c to %c\n", disk, source, auxiliary);
            else if (i % 3 == 2)
                printf("Move disk %d from %c to %c\n", disk, auxiliary, destination);
            else
                printf("Move disk %d from %c to %c\n", disk, destination, source);
        }
    }
}

int main()
{
    int n;
    scanf("%d", &n);

    hanoi(n);

    return 0;
}

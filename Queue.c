#include <stdio.h>
#define MAX 5

int front = -1, rear = -1;
int queue[MAX];

void enqueue(int item)
{
    if (rear == MAX - 1)
    {
        printf("Overflow\n");
        return;
    }

    if (front == -1)
        front = 0;

    rear++;
    queue[rear] = item;
    printf("Value entered = %d\n", item);
}

void dequeue()
{
    if (front == -1)
    {
        printf("Underflow\n");
        return;
    }

    printf("Deleted element %d\n", queue[front]);
    front++;

    // Reset pointers once all elements have been removed
    if (front > rear)
    {
        front = -1;
        rear = -1;
    }
}

void display()
{
    if (front == -1)
    {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue elements: ");
    for (int i = front; i <= rear; i++)
    {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int main()
{
    int x, choice;

    while (1)
    {
        printf("\n--- Queue Menu ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter choice: ");

        if (scanf("%d", &choice) != 1)
        {
            printf("Invalid input. Exiting.\n");
            return 1;
        }

        switch (choice)
        {
            case 1:
                printf("Enter value: ");
                scanf("%d", &x);
                enqueue(x);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                display();
                break;

            case 4:
                return 0;

            default:
                printf("Invalid Choice\n");
        }
    }

    return 0;
}

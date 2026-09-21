#include <stdio.h>
#define MAX 5

int deque[MAX];
int front = -1, rear = -1;

void insertFront(int x) {
    if (front == 0) {
        printf("Deque Overflow!\n");
        return;
    }

    if (front == -1) {
        front = rear = 0;
    } else {
        front--;
    }

    deque[front] = x;
}

void insertRear(int x) {
    if (rear == MAX - 1) {
        printf("Deque Overflow!\n");
        return;
    }

    if (front == -1) {
        front = rear = 0;
    } else {
        rear++;
    }

    deque[rear] = x;
}

void deleteFront() {
    if (front == -1) {
        printf("Deque Underflow!\n");
        return;
    }

    printf("%d deleted from front\n", deque[front]);

    if (front == rear) {
        front = rear = -1;
    } else {
        front++;
    }
}

void deleteRear() {
    if (front == -1) {
        printf("Deque Underflow!\n");
        return;
    }

    printf("%d deleted from rear\n", deque[rear]);

    if (front == rear) {
        front = rear = -1;
    } else {
        rear--;
    }
}

void display() {
    if (front == -1) {
        printf("Deque is empty\n");
        return;
    }

    printf("Deque: ");
    for (int i = front; i <= rear; i++) {
        printf("%d ", deque[i]);
    }
    printf("\n");
}

int main() {
    int choice, value;

    while (1) {
        printf("\n--- DEQUE ---\n");
        printf("1. Insert Front\n");
        printf("2. Insert Rear\n");
        printf("3. Delete Front\n");
        printf("4. Delete Rear\n");
        printf("5. Display\n");
        printf("6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                insertFront(value);
                break;

            case 2:
                printf("Enter value: ");
                scanf("%d", &value);
                insertRear(value);
                break;

            case 3:
                deleteFront();
                break;

            case 4:
                deleteRear();
                break;

            case 5:
                display();
                break;

            case 6:
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }
}

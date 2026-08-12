#include <stdio.h>
#define MAX 5

int deque[MAX];
int front = -1, rear = -1;

// Insert at rear
void insertRear(int x) {
    if((front == 0 && rear == MAX-1) || (rear+1)%MAX == front) {
        printf("Deque Overflow!\n");
    } else {
        if(front == -1) front = rear = 0;
        else rear = (rear+1) % MAX;
        deque[rear] = x;
        printf("%d inserted at rear\n", x);
    }
}

// Insert at front
void insertFront(int x) {
    if((front == 0 && rear == MAX-1) || (rear+1)%MAX == front) {
        printf("Deque Overflow!\n");
    } else {
        if(front == -1) front = rear = 0;
        else front = (front-1+MAX) % MAX;
        deque[front] = x;
        printf("%d inserted at front\n", x);
    }
}

// Delete from front
void deleteFront() {
    if(front == -1) {
        printf("Deque Underflow!\n");
    } else {
        printf("%d deleted from front\n", deque[front]);
        if(front == rear) front = rear = -1;
        else front = (front+1) % MAX;
    }
}

// Delete from rear
void deleteRear() {
    if(front == -1) {
        printf("Deque Underflow!\n");
    } else {
        printf("%d deleted from rear\n", deque[rear]);
        if(front == rear) front = rear = -1;
        else rear = (rear-1+MAX) % MAX;
    }
}

// Display deque
void display() {
    if(front == -1) {
        printf("Deque is empty\n");
    } else {
        printf("Deque elements: ");
        int i = front;
        while(1) {
            printf("%d ", deque[i]);
            if(i == rear) break;
            i = (i+1) % MAX;
        }
        printf("\n");
    }
}

int main() {
    int choice, value;
    while(1) {
        printf("\n--- Deque Menu ---\n");
        printf("1. Insert Front\n2. Insert Rear\n3. Delete Front\n4. Delete Rear\n5. Display\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
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

#include <stdio.h>

#define MAX 5

int queue[MAX];
int front = -1;
int rear = -1;

void insert() {
    int item;
    if ((front == 0 && rear == MAX - 1) || (front == rear + 1)) {
        printf("Queue is overflow\n");
        return;
    } else {
        if (front == -1) {
            front = 0;
            rear = 0;
        } else {
            if (rear == MAX - 1) {
                rear = 0;
            } else {
                rear = rear + 1;
            }
        }
        printf("\nEnter element to be inserted: ");
        scanf("%d", &item);
        queue[rear] = item;
        printf("\nElement inserted successfully\n");
    }
}

void deletion() {
    if (front == -1) {
        printf("Queue Underflow\n");
        return;
    }
    printf("\nElement deleted from queue is: %d\n", queue[front]);
    if (front == rear) {
        front = -1;
        rear = -1;
    } else {
        if (front == MAX - 1) {
            front = 0;
        } else {
            front = front + 1;
        }
    }
}

void display() {
    if (front == -1) {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue elements: ");
    if (rear >= front) {
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
    } else {
        for (int i = front; i < MAX; i++) {
            printf("%d ", queue[i]);
        }
        for (int i = 0; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
    }
    printf("\n");
}

int main() {
    int choice;
    do {
        printf("\n1. Insert");
        printf("\n2. Delete");
        printf("\n3. Display");
        printf("\n4. Quit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            insert();
            break;
        case 2:
            deletion();
            break;
        case 3:
            display();
            break;
        case 4:
            break;
        default:
            printf("\nInvalid choice\n");
        }
    } while (choice != 4);

    return 0;
}

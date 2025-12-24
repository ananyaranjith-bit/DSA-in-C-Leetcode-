#include <stdio.h>
#define MAX 5
int cq[MAX];
int front = -1, rear = -1;

void insert() {
    int item;
    if ((rear + 1) % MAX == front) {
        printf("Queue Overflow! Circular Queue is full.\n");
        return;
    }

    if (front == -1) {   // first insertion
        front = 0;
        rear = 0;
    } else {
        rear = (rear + 1) % MAX;
    }

    printf("Enter element to insert: ");
    scanf("%d", &item);
    cq[rear] = item;
    printf("Element inserted successfully.\n");
}

void delete() {
    if (front == -1) {
        printf("Queue Underflow! Circular Queue is empty.\n");
        return;
    }

    printf("Deleted element: %d\n", cq[front]);

    if (front == rear) {   // only one element
        front = -1;
        rear = -1;
    } else {
        front = (front + 1) % MAX;
    }
}

void display() {
    int i;

    if (front == -1) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Circular Queue elements:\n");
    i = front;
    while (1) {
        printf("%d ", cq[i]);
        if (i == rear)
            break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

int main() {
    int choice;

    do {
        printf("\n CIRCULAR QUEUE MENU \n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: insert(); break;
            case 2: delete(); break;
            case 3: display(); break;
            case 4: printf("Exiting program.\n"); break;
            default: printf("Invalid choice!\n");
        }
    } while (choice != 4);

    return 0;
}


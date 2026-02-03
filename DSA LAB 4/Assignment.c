#include <stdio.h>
#define SIZE 10

int pq[SIZE];
int rear = -1;

int isFull() {
    return (rear == SIZE - 1);
}
int isEmpty() {
    return (rear == -1);
}

void enqueue(int value) {
    if (isFull()) {
        printf("Priority Queue is Full\n");
        return;
    }
    int i;
    for (i = rear; i >= 0 && pq[i] < value; i--) {
        pq[i + 1] = pq[i];
    }
    pq[i + 1] = value;
    rear++;
    printf("%d inserted\n", value);
}

void dequeue() {
    if (isEmpty()) {
        printf("Priority Queue is Empty\n");
        return;
    }
    printf("%d removed\n", pq[0]);
    for (int i = 0; i < rear; i++) {
        pq[i] = pq[i + 1];
    }
    rear--;
}

void display() {
    if (isEmpty()) {
        printf("Priority Queue is Empty\n");
        return;
    }
    printf("Priority Queue: ");
    for (int i = 0; i <= rear; i++) {
        printf("%d ", pq[i]);
    }
    printf("\n");
}

int main() {
    int choice, value;
    do {
        printf("\n--- Priority Queue Menu ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
        }
    } while(choice != 4);
    return 0;
}

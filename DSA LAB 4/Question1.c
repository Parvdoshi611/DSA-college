#include <stdio.h>
#define SIZE 5
int queue[SIZE];
int front = -1, rear = -1;
int isFull() {
if ((front == 0 && rear == SIZE - 1) || (front == rear +
1))
return 1;
return 0;
}
int isEmpty() {
if (front == -1)
return 1;
return 0;
}
void enqueue(int value) {
if (isFull()) {
printf("Queue is Full\n");
return;
}
if (front == -1)
front = 0;
rear = (rear + 1) % SIZE;
queue[rear] = value;
printf("%d inserted into queue\n", value);
}
void dequeue() {
if (isEmpty()) {
printf("Queue is Empty\n");
return;
}
printf("%d removed from queue\n", queue[front]);
if (front == rear) {
front = rear = -1;
} else {
front = (front + 1) % SIZE;
}
}
void Front() {
if (isEmpty())
printf("Queue is Empty\n");
else
printf("Front element: %d\n", queue[front]);
}
void Rear() {
if (isEmpty())
printf("Queue is Empty\n");
else
printf("Rear element: %d\n", queue[rear]);
}
int main() {
int choice, value;
do {
printf("\n--- Circular Queue Menu ---\n");
printf("1. Enqueue\n");
printf("2. Dequeue\n");
printf("3. Front\n");
printf("4. Rear\n");
printf("5. Exit\n");
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
Front();
break;
case 4:
Rear();
break;
}
} while(choice != 5);
return 0;
}
#include <stdio.h>
#define MAX 10 
int dq[MAX];
int front = -1, rear = -1;

int isEmpty() {
    return (front == -1);
}

int isFull() {
    return ((front == 0 && rear == MAX - 1) || (front == rear + 
	1));
}

void enqueueFront(int x) {
    if (isFull()) {
        printf("Deque FULL. Cannot enqueueFront(%d)\n", x);
        return;
    }
    if (isEmpty()) {
        front = rear = 0;
    } 
    else if (front == 0) {
        front = MAX - 1;
    } 
    else {
        front--;
    }

    dq[front] = x;
}

void enqueueRear(int x) {
    if (isFull()) {
        printf("Deque FULL. Cannot enqueueRear(%d)\n", x);
        return;
    }
    if (isEmpty()) {
        front = rear = 0;
    } 
    else if (rear == MAX - 1) {
        rear = 0;
    } 
    else {
        rear++;
    }
    dq[rear] = x;
}

int dequeueFront() {
    int x;
    if (isEmpty()) {
        printf("Deque EMPTY. Cannot dequeueFront()\n");
        return -1;
    }
    x = dq[front];
    if (front == rear) {
        front = rear = -1;
    } 
    else if (front == MAX - 1) {
        front = 0;
    } 
    else {
        front++;
    }
    return x;
}

int dequeueRear() {
    int x;
    if (isEmpty()) {
        printf("Deque EMPTY. Cannot dequeueRear()\n");
        return -1;
    }
    x = dq[rear];
    if (front == rear) {
        front = rear = -1;
    } 
    else if (rear == 0) {
        rear = MAX - 1;
    } 
    else {
        rear--;
    }
    return x;
}

int getFront() {
    if (isEmpty()) {
        printf("Deque EMPTY. getFront() not possible\n");
        return -1;
    }
    return dq[front];
}

int getRear() {
    if (isEmpty()) {
        printf("Deque EMPTY. getRear() not possible\n");
        return -1;
    }
    return dq[rear];
}

void display() {
    if (isEmpty()) {
        printf("Deque: [empty]\n");
        return;
    }
    printf("Deque: ");
    int i = front;
    while (1) {
        printf("%d ", dq[i]);
        if (i == rear)
            break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

int main() {
    int ch, val, ans;

    while (1) {
        printf("\n--- DEQUE MENU (MAX=%d) ---\n", MAX);
        printf("1. enqueueFront\n");
        printf("2. enqueueRear\n");
        printf("3. dequeueFront\n");
        printf("4. dequeueRear\n");
        printf("5. getFront\n");
        printf("6. getRear\n");
        printf("7. isEmpty\n");
        printf("8. isFull\n");
        printf("9. display\n");
        printf("0. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &val);
                enqueueFront(val);
                break;
            case 2:
                printf("Enter value: ");
                scanf("%d", &val);
                enqueueRear(val);
                break;
            case 3:
                ans = dequeueFront();
                if (ans != -1)
                    printf("dequeueFront -> %d\n", ans);
                break;
            case 4:
                ans = dequeueRear();
                if (ans != -1)
                    printf("dequeueRear -> %d\n", ans);
                break;
            case 5:
                ans = getFront();
                if (ans != -1)
                    printf("Front -> %d\n", ans);
                break;
            case 6:
                ans = getRear();
                if (ans != -1)
                    printf("Rear -> %d\n", ans);
                break;
            case 7:
                printf("isEmpty -> %s\n", isEmpty() ? "YES" : 
			   "NO");
                break;
            case 8:
                printf("isFull -> %s\n", isFull() ? "YES" : 
			   "NO");
                break;
            case 9:
                display();
                break;
            case 0:
                printf("Exit.\n");
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    }
}

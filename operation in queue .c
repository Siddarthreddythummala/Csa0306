#include <stdio.h>
#define SIZE 5

int queue[SIZE];
int front = -1, rear = -1;

void enqueue(int value) {
    if (rear == SIZE - 1)
        printf("Queue is full\n");
    else {
        if (front == -1)
            front = 0;
        rear++;
        queue[rear] = value;
    }
}

void dequeue() {
    if (front == -1 || front > rear)
        printf("Queue is empty\n");
    else {
        printf("Deleted %d\n", queue[front]);
        front++;
    }
}

void display() {
	int i;
    if (front == -1 || front > rear)
        printf("Queue is empty\n");
    else {
        printf("Queue: ");
        for ( i = front; i <= rear; i++)
            printf("%d ", queue[i]);
        printf("\n");
    }
}
int main() {
    enqueue(50);
    enqueue(60);
    enqueue(70);
    display();        

    dequeue();        
    display();        

    enqueue(100);
    enqueue(50);
    enqueue(11);      
    display();        

    return 0;
}

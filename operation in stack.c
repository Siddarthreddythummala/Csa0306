#include <stdio.h>
#define SIZE 100

int stack[SIZE];
int top = -1;

void push() {
    int value;
    if (top == SIZE - 1) {
        printf("Stack is full \n");
    } else {
        printf("Enter value to push: ");
        scanf("%d", &value);
        stack[++top] = value;
        printf("%d pushed to stack\n", value);
    }
}

void pop() {
    if (top == -1) {
        printf("Stack is empty (Underflow)\n");
    } else {
        printf("%d popped from stack\n", stack[top--]);
    }
}

void peek() {
    if (top == -1) {
        printf("Stack is empty\n");
    } else {
        printf("Top element is %d\n", stack[top]);
    }
}


void display() {
	int i;
    if (top == -1) {
        printf("Stack is empty\n");
    } else {
        printf("Stack elements (top to bottom):\n");
        for ( i = top; i >= 0; i--) {
            printf("%d\n", stack[i]);
        }
    }
}

int main() {
    int choice;
    while (4)
	 {
        printf("\n---- Stack Menu ----\n");
        printf("1. Push\n2. Pop\n3. Peek\n4. Display\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: push();
			 break;	
            case 2: pop();
			 break;
            case 3: peek();
			 break;
            case 4: display(); 
			
			break;
            case 5: return 0;
            default: printf("no\n");
        }
    }
    return 0;
}

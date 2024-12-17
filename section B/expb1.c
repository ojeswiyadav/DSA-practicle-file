#include <stdio.h>
#define MAX 10 // Maximum size of the stack

int stack[MAX]; // Array to store stack elements
int top = -1;   // Index of the top element, initially -1 (empty)

// Function to push an element onto the stack
void push(int val) {
    if (top == MAX - 1) {
        printf("Stack Overflow! Cannot push %d\n\n", val);
    } else {
        top++;
        stack[top] = val;
        printf("Pushed %d onto the stack\n\n", val);
    }
}

// Function to pop an element from the stack
void pop() {
    if (top == -1) {
        printf("Stack Underflow! Stack is empty\n\n");
    } else {
        int val = stack[top];
        top--;
        printf("Popped %d from the stack\n\n", val);
    }
}

// Function to print the elements of the stack
void display() {
    if (top == -1) {
        printf("Stack is empty\n\n");
    } else {
        printf("Stack elements (top to bottom): ");
        for (int i = top; i >= 0; i--) {
            printf("%d ", stack[i]);
        }
        printf("\n\n");
    }
}

// Main function
int main() {
    int choice, val;

    while (1) {
        printf("1. Push onto Stack\n");
        printf("2. Pop from Stack\n");
        printf("3. Display Stack\n");
        printf("0. Exit\n\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &val);
                push(val);
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 0:
                printf("Thanks for using the program\n\n");
                return 0;
            default:
                printf("Invalid choice! Try again.\n\n");
        }
    }
    return 0;
}

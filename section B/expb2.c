#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node
typedef struct Node {
    int value;
    struct Node* next;
} Node;

Node* top = NULL; // Pointer to the top of the stack

// Function to add an element to the stack
void push(int val) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation failed. Overflow!\n\n");
        return;
    }
    newNode->value = val;
    newNode->next = top;
    top = newNode;
    printf("Added %d to the stack\n\n", val);
}

// Function to remove an element from the stack
void pop() {
    if (top == NULL) {
        printf("Stack Underflow! Stack is empty\n\n");
        return;
    }
    Node* temp = top;
    int val = temp->value;
    top = top->next;
    free(temp);
    printf("Removed %d from the stack\n\n", val);
}

// Function to display the stack
void display() {
    if (top == NULL) {
        printf("Stack is empty\n\n");
        return;
    }
    Node* temp = top;
    printf("Stack elements: ");
    while (temp != NULL) {
        printf("%d ", temp->value);
        temp = temp->next;
    }
    printf("\n\n");
}

// Main function
int main() {
    int choice, val;

    while (1) {
        printf("1. Add to Stack\n");
        printf("2. Remove from Stack\n");
        printf("3. Display Stack\n");
        printf("0. Exit\n\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to add: ");
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
                printf("Exiting program. Thank you!\n\n");
                return 0;
            default:
                printf("Invalid choice! Try again.\n\n");
        }
    }
    return 0;
}

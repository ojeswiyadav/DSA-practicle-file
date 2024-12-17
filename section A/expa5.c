#include <stdio.h>
#include <stdlib.h>

// Define the structure for a doubly linked list node
typedef struct Node {
    int value;
    struct Node* prev;
    struct Node* next;
} Node;

Node* HEAD = NULL;

// Function to insert a value at the end of the circular doubly linked list
void insert(int val) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation failed. OVERFLOW!\n\n");
        return;
    }
    newNode->value = val;
    newNode->prev = NULL;
    newNode->next = NULL;

    if (HEAD == NULL) {
        // If the list is empty
        HEAD = newNode;
        newNode->next = HEAD;
        newNode->prev = HEAD;
    } else {
        // Traverse to the last node
        Node* last = HEAD->prev;

        last->next = newNode;
        newNode->prev = last;
        newNode->next = HEAD;
        HEAD->prev = newNode;
    }
    printf("Insertion successful\n\n");
}

// Function to delete a value from the front of the circular doubly linked list
void deleteFront() {
    if (HEAD == NULL) {
        printf("List is empty. UNDERFLOW!\n\n");
        return;
    }

    Node* temp = HEAD;
    int deletedValue = temp->value;

    if (HEAD->next == HEAD) {
        // If there is only one node
        HEAD = NULL;
    } else {
        // Update the head and adjust pointers
        Node* last = HEAD->prev;
        HEAD = HEAD->next;
        HEAD->prev = last;
        last->next = HEAD;
    }

    free(temp);
    printf("Deletion successful. Deleted value = %d\n\n", deletedValue);
}

// Function to print the circular doubly linked list forward
void printListForward() {
    if (HEAD == NULL) {
        printf("List is empty.\n\n");
        return;
    }

    Node* temp = HEAD;
    printf("HEAD -> ");
    do {
        printf("%d -> ", temp->value);
        temp = temp->next;
    } while (temp != HEAD);
    printf("HEAD\n\n");
}

// Function to print the circular doubly linked list backward
void printListBackward() {
    if (HEAD == NULL) {
        printf("List is empty.\n\n");
        return;
    }

    Node* temp = HEAD->prev;
    printf("TAIL -> ");
    do {
        printf("%d -> ", temp->value);
        temp = temp->prev;
    } while (temp != HEAD->prev);
    printf("HEAD\n\n");
}

// Main function
int main() {
    int choice, val;

    while (1) {
        printf("1. Insert into Circular Doubly Linked List\n");
        printf("2. Delete from Circular Doubly Linked List\n");
        printf("3. Print Circular Doubly Linked List (Forward)\n");
        printf("4. Print Circular Doubly Linked List (Backward)\n");
        printf("0. Exit\n\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &val);
                insert(val);
                break;
            case 2:
                deleteFront();
                break;
            case 3:
                printListForward();
                break;
            case 4:
                printListBackward();
                break;
            case 0:
                printf("Thanks for using our program\n\n");
                return 0;
            default:
                printf("Incorrect choice\n\n");
        }
    }
    return 0;
}

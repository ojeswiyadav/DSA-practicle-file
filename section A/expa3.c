#include <stdio.h>
#include <stdlib.h>

// Define the structure for a doubly linked list node
typedef struct Node {
    int value;
    struct Node* prev;
    struct Node* next;
} Node;

Node* HEAD = NULL;

// Function to insert a value at the end of the doubly linked list
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
    } else {
        // Traverse to the end of the list
        Node* temp = HEAD;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
    printf("Insertion successful\n\n");
}

// Function to delete a value from the front of the doubly linked list
void deleteFront() {
    if (HEAD == NULL) {
        printf("List is empty. UNDERFLOW!\n\n");
        return;
    }
    Node* temp = HEAD;
    int deletedValue = temp->value;

    if (HEAD->next == NULL) {
        // If there is only one node
        HEAD = NULL;
    } else {
        HEAD = HEAD->next;
        HEAD->prev = NULL;
    }
    free(temp);
    printf("Deletion successful. Deleted value = %d\n\n", deletedValue);
}

// Function to print the doubly linked list forward
void printListForward() {
    if (HEAD == NULL) {
        printf("List is empty.\n\n");
        return;
    }
    Node* temp = HEAD;
    printf("HEAD -> ");
    while (temp != NULL) {
        printf("%d -> ", temp->value);
        temp = temp->next;
    }
    printf("NULL\n\n");
}

// Function to print the doubly linked list backward
void printListBackward() {
    if (HEAD == NULL) {
        printf("List is empty.\n\n");
        return;
    }
    Node* temp = HEAD;

    // Traverse to the last node
    while (temp->next != NULL) {
        temp = temp->next;
    }

    printf("TAIL -> ");
    while (temp != NULL) {
        printf("%d -> ", temp->value);
        temp = temp->prev;
    }
    printf("HEAD\n\n");
}

// Main function
int main() {
    int choice, val;

    while (1) {
        printf("1. Insert into Doubly Linked List\n");
        printf("2. Delete from Doubly Linked List\n");
        printf("3. Print Doubly Linked List (Forward)\n");
        printf("4. Print Doubly Linked List (Backward)\n");
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

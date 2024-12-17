#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node
typedef struct Node {
    int value;
    struct Node* next;
} Node;

Node* HEAD = NULL;

// Function to insert a value at the end of the linked list
void insert(int val) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation failed. OVERFLOW!\n\n");
        return;
    }
    newNode->value = val;
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
    }
    printf("Insertion successful\n\n");
}

// Function to delete a value from the front of the linked list
void deleteFront() {
    if (HEAD == NULL) {
        printf("List is empty. UNDERFLOW!\n\n");
        return;
    }
    Node* temp = HEAD;
    int deletedValue = temp->value;
    HEAD = HEAD->next;
    free(temp);
    printf("Deletion successful. Deleted value = %d\n\n", deletedValue);
}

// Function to print the linked list
void printList() {
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

// Main function
int main() {
    int choice, val;

    while (1) {
        printf("1. Insert into Linked List\n");
        printf("2. Delete from Linked List\n");
        printf("3. Print Linked List\n");
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
                printList();
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

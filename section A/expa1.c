#include <stdio.h>

#define MAX 10

typedef struct Node {
    int value;
    int next;
} Node;

Node LIST[MAX];
int HEAD = -1;
int freeIndex = 0;

// Function to find the next free index
int getFreeIndex() {
    if (freeIndex < MAX)
        return freeIndex++;
    else
        return -1; // No space left
}

// Insert a value at the end of the list
void insert(int val) {
    int newIndex = getFreeIndex();
    if (newIndex == -1) {
        printf("List is full. OVERFLOW!\n\n");
        return;
    }
    LIST[newIndex].value = val;
    LIST[newIndex].next = -1;

    if (HEAD == -1) {
        // If list is empty
        HEAD = newIndex;
    } else {
        // Traverse to the end of the list
        int temp = HEAD;
        while (LIST[temp].next != -1) {
            temp = LIST[temp].next;
        }
        LIST[temp].next = newIndex;
    }
    printf("Insertion successful\n\n");
}

// Delete a value from the front of the list
void deleteFront() {
    if (HEAD == -1) {
        printf("List is empty. UNDERFLOW!\n\n");
        return;
    }
    int deletedValue = LIST[HEAD].value;
    HEAD = LIST[HEAD].next;
    printf("Deletion successful. Deleted value = %d\n\n", deletedValue);
}

// Print the list
void printList() {
    if (HEAD == -1) {
        printf("List is empty.\n\n");
        return;
    }
    int temp = HEAD;
    printf("HEAD -> ");
    while (temp != -1) {
        printf("%d -> ", LIST[temp].value);
        temp = LIST[temp].next;
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

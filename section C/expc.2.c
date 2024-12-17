#include <stdio.h>
#include <stdlib.h>

// Node structure for the queue
struct Node
{
    int data;
    struct Node *next;
};

// Function prototypes
void insert(struct Node **front, struct Node **rear, int value);
void delete(struct Node **front, struct Node **rear);
void printQueue(struct Node *front);

// Main function
int main()
{
    int choice, value;
    struct Node *front = NULL;
    struct Node *rear = NULL;

    while (1)
    {
        printf("1. Insert in Queue\n");
        printf("2. Delete in Queue\n");
        printf("3. Print Queue\n");
        printf("0. Exit\n\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value to insert: ");
            scanf("%d", &value);
            insert(&front, &rear, value);
            printf("Insertion successful\n\n");
            break;
        case 2:
            delete (&front, &rear);
            break;
        case 3:
            printQueue(front);
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

// Function to insert an element in the queue
void insert(struct Node **front, struct Node **rear, int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (!newNode)
    {
        printf("Memory allocation failed. Insertion unsuccessful.\n\n");
        return;
    }
    newNode->data = value;
    newNode->next = NULL;

    if (*rear == NULL)
    {
        *front = *rear = newNode; // Queue was empty
    }
    else
    {
        (*rear)->next = newNode;
        *rear = newNode;
    }
}

// Function to delete an element from the queue
void delete(struct Node **front, struct Node **rear)
{
    if (*front == NULL)
    {
        printf("QUEUE is empty. UNDERFLOW!!\n\n");
        return;
    }

    struct Node *temp = *front;
    printf("Deletion Successful. Deleted value = %d\n\n", temp->data);

    *front = (*front)->next;
    if (*front == NULL)
    {
        *rear = NULL; // Queue is empty after deletion
    }
    free(temp);
}

// Function to print the queue
void printQueue(struct Node *front)
{
    if (front == NULL)
    {
        printf("QUEUE is empty.\n\n");
        return;
    }

    printf("FRONT->");
    while (front != NULL)
    {
        printf("%d -> ", front->data);
        front = front->next;
    }
    printf("REAR\n\n");
}

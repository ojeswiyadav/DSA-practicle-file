#include <stdio.h>
#define SIZE 5 // Maximum size of the circular queue

// Function prototypes
void insert(int queue[], int *front, int *rear, int value);
void delete(int queue[], int *front, int *rear);
void printQueue(int queue[], int front, int rear);

int main()
{
    int queue[SIZE];
    int front = -1, rear = -1, choice, value;

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
            insert(queue, &front, &rear, value);
            break;
        case 2:
            delete (queue, &front, &rear);
            break;
        case 3:
            printQueue(queue, front, rear);
            break;
        case 0:
            printf("Thanks for using our program\n");
            return 0;
        default:
            printf("Incorrect choice\n\n");
        }
    }
    return 0;
}

// Function to insert an element in the circular queue
void insert(int queue[], int *front, int *rear, int value)
{
    if ((*front == 0 && *rear == SIZE - 1) || (*rear + 1 == *front))
    {
        printf("OVERFLOW!! QUEUE is full\n\n");
        return;
    }

    if (*front == -1)
    { // Queue is initially empty
        *front = *rear = 0;
    }
    else
    {
        *rear = (*rear + 1) % SIZE; // Increment rear in circular manner
    }

    queue[*rear] = value;
    printf("Insertion successful\n\n");
}

// Function to delete an element from the circular queue
void delete(int queue[], int *front, int *rear)
{
    if (*front == -1)
    { // Queue is empty
        printf("QUEUE is empty. UNDERFLOW!!\n\n");
        return;
    }

    printf("Deletion Successful. Deleted value = %d\n\n", queue[*front]);

    if (*front == *rear)
    { // Queue has only one element
        *front = *rear = -1;
    }
    else
    {
        *front = (*front + 1) % SIZE; // Increment front in circular manner
    }
}

// Function to print the circular queue
void printQueue(int queue[], int front, int rear)
{
    if (front == -1)
    {
        printf("QUEUE is empty.\n\n");
        return;
    }

    printf("FRONT->");
    int i = front;
    while (1)
    {
        printf("%d -> ", queue[i]);
        if (i == rear)
            break;
        i = (i + 1) % SIZE; // Move to the next index in circular manner
    }
    printf("REAR\n\n");
}

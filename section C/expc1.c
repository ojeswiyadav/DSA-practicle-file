#include <stdio.h>
int main()
{
    int choice;
    int QUEUE[10];
    int FRONT, REAR, val, i;
    FRONT = -1;
    REAR = -1;
    while (choice != 0)
    {
        printf("1. Insert in Queue\n");
        printf("2. Delete in Queue\n");
        printf("3. Print Queue\n");
        printf("0. Exit\n\n");
        printf("Enter choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            if (REAR == 9)
            {
                printf("OVERFLOW!! QUEUE is full\n\n");
            }
            else
            {
                if (FRONT == -1 && REAR == -1)
                {
                    FRONT = 0;
                    REAR = 0;
                }
                else
                {
                    REAR++;
                }
                printf("Enter value to insert : ");
                scanf("%d", &val);
                QUEUE[REAR] = val;
                printf("Insertion successful\n\n");
            }
            break;
        case 2:
            if (FRONT == -1)
            {
                printf("QUEUE is empty. UNDERFLOW!!\n\n");
            }
            else
            {
                printf("Deletion Successful. Deleted value = %d\n\n", QUEUE[FRONT]);
                if (FRONT == REAR)
                {
                    FRONT = -1;
                    REAR = -1;
                }
                else
                {
                    FRONT++;
                }
            }
            break;
        case 3:
            printf("FRONT->");
            for (i = FRONT; i <= REAR; i++)
            {
                printf("%d -> ", QUEUE[i]);
            }
            printf("REAR\n\n");
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

#include <stdio.h>
#include <stdlib.h>

// Structure for a BST node
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

// Function to create a new node
struct Node *createNode(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a value into the BST
struct Node *insert(struct Node *root, int value)
{
    if (root == NULL)
        return createNode(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);

    return root;
}

// Function for In-order traversal (Left, Root, Right)
void inOrder(struct Node *root)
{
    if (root != NULL)
    {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

// Function for Pre-order traversal (Root, Left, Right)
void preOrder(struct Node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

// Function for Post-order traversal (Left, Right, Root)
void postOrder(struct Node *root)
{
    if (root != NULL)
    {
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ", root->data);
    }
}

int main()
{
    struct Node *root = NULL;
    int choice, value;

    while (1)
    {
        printf("\n1. Insert\n2. In-order Traversal\n3. Pre-order Traversal\n4. Post-order Traversal\n0. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        if (choice == 1)
        { // Insert
            printf("Enter value to insert: ");
            scanf("%d", &value);
            root = insert(root, value);
            printf("Inserted %d\n", value);
        }
        else if (choice == 2)
        { // In-order Traversal
            printf("In-order Traversal: ");
            inOrder(root);
            printf("\n");
        }
        else if (choice == 3)
        { // Pre-order Traversal
            printf("Pre-order Traversal: ");
            preOrder(root);
            printf("\n");
        }
        else if (choice == 4)
        { // Post-order Traversal
            printf("Post-order Traversal: ");
            postOrder(root);
            printf("\n");
        }
        else if (choice == 0)
        {
            printf("Exiting program. Thank you!\n");
            break;
        }
        else
        {
            printf("Invalid choice!\n");
        }
    }

    return 0; // Explicit return for program termination
}

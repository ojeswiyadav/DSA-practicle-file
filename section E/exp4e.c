#include <stdio.h>
#include <string.h>

// Function to implement Linear Search for strings
int linearSearch(char arr[][50], int n, char target[])
{
    for (int i = 0; i < n; i++)
    {
        if (strcmp(arr[i], target) == 0)
        {             // Compare strings
            return i; // Return the index if found
        }
    }
    return -1; // Return -1 if not found
}

int main()
{
    int n;
    char target[50];

    // Input the number of strings
    printf("Enter the number of strings: ");
    scanf("%d", &n);

    char arr[n][50]; // Array to store strings

    // Input strings into the array
    printf("Enter %d strings:\n", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%s", arr[i]);
    }

    // Input the target string to search
    printf("Enter the string to search: ");
    scanf("%s", target);

    // Perform Linear Search
    int result = linearSearch(arr, n, target);

    // Print the result
    if (result != -1)
        printf("String found at index %d (0-based indexing).\n", result);
    else
        printf("String not found in the array.\n");

    return 0; // Explicit return for program termination
}

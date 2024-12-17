#include <stdio.h>
#include <string.h>

// Function to implement Binary Search for strings
int binarySearch(char arr[][50], int n, char target[])
{
    int low = 0, high = n - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        // Compare target with the middle element
        int res = strcmp(arr[mid], target);

        if (res == 0) // Target found
            return mid;

        if (res > 0) // Target is smaller, search the left half
            high = mid - 1;

        else // Target is larger, search the right half
            low = mid + 1;
    }

    // Target not found
    return -1;
}

int main()
{
    int n;
    char target[50];

    // Input size of the array
    printf("Enter the number of strings: ");
    scanf("%d", &n);

    char arr[n][50]; // Array to store strings

    // Input array elements (assume sorted)
    printf("Enter %d strings in sorted order:\n", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%s", arr[i]);
    }

    // Input the target string to search
    printf("Enter the string to search: ");
    scanf("%s", target);

    // Perform Binary Search
    int result = binarySearch(arr, n, target);

    // Print the result
    if (result != -1)
        printf("String found at index %d (0-based indexing).\n", result);
    else
        printf("String not found in the array.\n");

    return 0; // Explicit return for program termination
}

#include <stdio.h>

// Function to implement Binary Search
int binarySearch(int arr[], int n, int target) {
    int low = 0, high = n - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        // Check if the target is at mid
        if (arr[mid] == target)
            return mid;

        // If target is smaller, ignore the right half
        if (arr[mid] > target)
            high = mid - 1;

        // If target is larger, ignore the left half
        else
            low = mid + 1;
    }

    // Target not found
    return -1;
}

int main() {
    int n, target;

    // Input size of the array
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];

    // Input array elements (assume sorted)
    printf("Enter %d elements in sorted order:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Input the target element to search
    printf("Enter the element to search: ");
    scanf("%d", &target);

    // Perform Binary Search
    int result = binarySearch(arr, n, target);

    // Print the result
    if (result != -1)
        printf("Element found at index %d (0-based indexing).\n", result);
    else
        printf("Element not found in the array.\n");

    return 0; // Explicit return for program termination
}

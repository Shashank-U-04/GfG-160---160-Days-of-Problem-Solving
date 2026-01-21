// Time Complexity: O(n)
// Space Complexity: O(1)

#include <limits.h>

int getSecondLargest(int *arr, int n) {
    int largest = INT_MIN;
    int secondLargest = INT_MIN;

    for (int i = 0; i < n; i++) {
        if (arr[i] > largest) {
            secondLargest = largest;
            largest = arr[i];
        }
        else if (arr[i] > secondLargest && arr[i] != largest) {
            secondLargest = arr[i];
        }
    }

    // If second largest doesn't exist
    if (secondLargest == INT_MIN)
        return -1;

    return secondLargest;
}

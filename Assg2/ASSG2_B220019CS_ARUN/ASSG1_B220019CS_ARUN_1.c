#include <stdio.h>

int kthMissingElement(int arr[], int n, int k) {
    int left = 0;
    int right = n - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        // Calculate the number of missing elements before arr[mid]
        int missingBeforeMid = arr[mid] - (mid + 1);

        // If the k-th missing element is before or at arr[mid]
        if (missingBeforeMid >= k) {
            right = mid - 1; // Move to the left side
        } else {
            left = mid + 1; // Move to the right side
        }
    }

    // Calculate the k-th missing element
    int kthMissing = left + k;

    // Check if the k-th missing element is within the bounds of the array
    if (kthMissing > arr[n - 1]) {
        return -1; // k-th missing element is not present
    }

    return kthMissing;
}

int main() {
    int n, k;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the array elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the value of k: ");
    scanf("%d", &k);

    int kthMissing = kthMissingElement(arr, n, k);

    if (kthMissing == -1) {
        printf("The k-th missing element is not present.\n");
    } else {
        printf("The k-th missing element is: %d\n", kthMissing);
    }

    return 0;
}

#include <stdio.h>

int partition(int arr[], char charArray[], int l, int r) {
    int pivot = arr[r];
    int i = (l - 1);

    for (int j = l; j <= r - 1; j++) {
        if (arr[j] >= pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;

            char tempChar = charArray[i];
            charArray[i] = charArray[j];
            charArray[j] = tempChar;
        }
    }

    int temp = arr[i + 1];
    arr[i + 1] = arr[r];
    arr[r] = temp;

    char tempChar = charArray[i + 1];
    charArray[i + 1] = charArray[r];
    charArray[r] = tempChar;

    return (i + 1);
}

void quickSort(int arr[], char charArray[], int l, int r) {
    if (l < r) {
        int pi = partition(arr, charArray, l, r);

        quickSort(arr, charArray, l, pi - 1);
        quickSort(arr, charArray, pi + 1, r);
    }
}

int main() {
    int n;
    scanf("%d", &n);
    char charArray[n];
    int asciiArray[n];

    for (int i = 0; i < n; i++) {
        scanf(" %c", &charArray[i]); 
        asciiArray[i] = (int)charArray[i];
    }
    quickSort(asciiArray, charArray, 0, n - 1);
    for (int i = 0; i < n; i++) {
        printf("%c ", charArray[i]);
    }

    return 1;
}

#include<stdio.h>

void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

void sort(int arr[], int n, int e) {
    int i, j, temp;

    for (i = 0; i < n - 1 && e > 0; i++) {
        temp = i;
        for (j = i + 1; j < n; j++) {
            if ((i % 2 == 0 && arr[j] < arr[temp]) || (i % 2 != 0 && arr[j] > arr[temp])) {
                temp = j;
            }
        }

        if (temp != i) {
            swap(&arr[temp], &arr[i]);
            e--; // 
        }
    }
}

int main() {
    int n, i, e;
    scanf("%d", &n);
    int arr[n];

    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    scanf("%d", &e);

    sort(arr, n, e);

    for (i = 0; i < n - 1; i++) {
        printf("%d ", arr[i]);
    }
    printf("%d\n", arr[i]);

    return 1;
}

#include <stdio.h>

void maxHeapify(int arr[], int n, int i) 
{
    int max = i;
    int l = 2 * i+1;
    int r = 2 * i+2;

    if (l < n && arr[l] > arr[max])
        max = l;

    if (r < n && arr[r] > arr[max])
        max = r;

    if (max != i) {

        int temp = arr[i];
        arr[i] = arr[max];
        arr[max] = temp;

        maxHeapify(arr, n, max);
    }
}

void heapSort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        maxHeapify(arr, n, i);
    for (int i = n - 1; i > 0; i--) {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        maxHeapify(arr, i, 0);
    }
}

int main()
{
    int n, i;
    scanf("%d",&n);
    int arr[n];

    for ( i = 0; i < n; i++)
    {
        scanf("%d",&arr[i]);
    }
    
    heapSort(arr, n);

    for ( i = n-1; i >0; i--)
        printf("%d ", arr[i]);
    printf("%d",arr[0]);

    return 1;
}
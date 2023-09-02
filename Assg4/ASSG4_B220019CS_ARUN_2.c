#include <stdio.h>

void countingSort(int arr[], int n, int pos) 
{
    int output[n];
    int max = arr[0];

    for (int i = 1; i < n; i++) {
        if (arr[i] > max)
            max = arr[i];
    }

    int count[max + 1];

    for (int i = 0; i <= max; ++i)
        count[i] = 0;

    for (int i = 0; i < n; i++)
        count[(arr[i] / pos) % 10]++;

    for (int i = 1; i <= max; i++)
        count[i] += count[i - 1];

    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / pos) % 10] - 1] = arr[i];
        count[(arr[i] / pos) % 10]--;
    }

    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}

int main()
{   
    int n, i;
    scanf("%d", &n);
    int arr[n];

    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    
    int max = arr[0];
    
    for (i = 1; i < n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }

    int pos = 1;

    while (max / pos > 0)
    {
        countingSort(arr, n, pos);
        pos *= 10;
    }
    
    for ( i= 0; i < n-1; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("%d", arr[i]);
    
    return 1;
}

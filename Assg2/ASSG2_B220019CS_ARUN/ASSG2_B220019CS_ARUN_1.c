#include<stdio.h>

int getK(int arr[], int n, int k)
     {
    int mid, min, max, missCount, kTh = -1;
    min = 0;
    max = n - 1;

    while (min <= max) 
    {
        mid = (min + max) / 2;
        missCount = arr[mid] - mid - 1;
        
        if (missCount >= k) 
        {
            
            kTh = arr[mid] - (missCount - k + 1);
            max = mid - 1; 
        } 
        else
         {
            min = mid + 1; 
        }
    }   

    return kTh;
}

int main() 
{
    int n, k;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) 
    {
        scanf("%d", &arr[i]);
    }

    scanf("%d", &k);

    int ans = getK(arr, n, k);
    printf("%d", ans);

    return 1; 
}

#include<stdio.h>

getK(int arr[],int n,int k)
{
    int mid, min, max;
    min=0,max=n-1,count=0;

    while(min<=max)
    {
        mid= min + (max-min)/2;
        count= arr[mid] - arr[min] - (mid - min);
        if (count >= k) 
        {
            min = mid - 1;
        } 
        else 
        {
            k = k- count;
            min = mid + 1;
        }
    }   
    
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
    printf("%d\n", ans);

    return 1;
}


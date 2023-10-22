#include <stdio.h>

void heapify(int arr[],int n,int i)
{
    int min = i;

    int l = i*2+1;
    int r = i*2+2;

    if(arr[l]>arr[min] && l < n)
    {
        min = l;
    }

    if(arr[r]>arr[min] && r < n)
    {
        min = r;
    } 

    if(min!=i)
    {
        int t = arr[min];
        arr[min] = arr[i];
        arr[i] = t;

        heapify(arr,n,min);
    }
}

int extractMax(int arr[], int n)
{
    int max = arr[0];

    int t = arr[0];
    arr[0]=arr[n-1];
    arr[n-1]=t;

    n--;
    heapify(arr,n,0);
    return max;
}

void main()
{
    int arr[] = {1,2,3,4,5,6,7,8};
    int n = 8;
    int max = extractMax(arr,n);

    printf("%d",max);
}
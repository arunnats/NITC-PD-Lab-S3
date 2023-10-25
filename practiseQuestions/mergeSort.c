#include <stdio.h>

void heapify(int arr[],int n,int i)
{
    int max = i;

    int l = i*2+1;
    int r = i*2+2;

    if(arr[l]>arr[max] && l < n)
    {
        max = l;
    }

    if(arr[r]>arr[max] && r < n)
    {
        max = r;
    } 

    if(max!=i)
    {
        int t = arr[max];
        arr[max] = arr[i];
        arr[i] = t;

        heapify(arr,n,max);
    }
}

void merge(int arr[], int n)
{
    for (int i = n/2 -1;i>=0;i--)
    {
        heapify(arr,n,i);
    }

    for (int i = n-1; i >= 0; i--)
    {
        int t = arr[0];
        arr[0] = arr[i];
        arr[i] = t;

        heapify(arr,i,0);
    }
    
}

int main()
{
    int arr[]={10,7,8,9,1,5};
    int n=6; 
    merge(arr,n);

    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
    return 1;
}



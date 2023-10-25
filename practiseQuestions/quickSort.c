#include <stdio.h>

int partition(int arr[],int l, int r)
{
    int pivot = arr[r];

    int i=(l-1);

    for (int j = l;j<r;j++) 
    {
        if(arr[j]<pivot)
        {
            i++;
            int t = arr[i];  
            arr[i] = arr[j];  
            arr[j] = t;  
        }
    }

    int t = arr[r];
    arr[r]=arr[i+1];
    arr[i+1] = t;

    return (i+1);
}

void sort(int arr[],int l,int r)
{
    if(l<r)
    {
        int pivot = partition(arr,l,r);
    
    sort(arr,l,(pivot-1));
    sort(arr,(pivot+1),r);

    }
}

int main()
{
    int arr[]={10,7,8,9,1,5};
    int n=6; 
    sort(arr,0,n-1);

    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
    return 1;
}
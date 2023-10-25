#include <stdio.h>

void main()
{
    int arr[5], i, j;
    for(i=0;i<5;i++)
    {
        scanf("%d",&arr[i]);
    }
    int min,temp;
    for(i=0;i<n,i++)
    {
        min=i;
        for(j=i+1;j<n;j++)
        if(arr[min]>arr[j])
            min=j;
    }

    if(min!=i)
    {
        arr[i]=temp;
        arr[i]=arr[min];
        arr[min]=temp;
    }

    for(i=0;i<n;i++)
    {
        for ( i = 0; i < n; i++)
        {
            printf("%d",arr[i]);
        }
        
    }

}
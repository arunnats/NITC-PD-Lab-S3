#include <stdio.h>

int main()
{
    int n, i;
    scanf("%d",&n);
    int arr[n];
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }   
    int key,j;
    for ( i = 1; i < n; i++)
    {
        key=arr[i];
        j=i-1;

        while (j>=0 && arr[j]>key)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1]=key;
    }

    for ( i = n-1; i > 0 ; i--)
    {
        printf("%d ",arr[i]);
    }
    printf("%d",arr[i]);
    
    return 1;
    
}

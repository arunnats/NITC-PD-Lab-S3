#include <stdio.h>

int main()
{
    // n = no o fitems 
    int n, i;
    scanf("%d",&n);
    float arr[n];
    for(i=0;i<n;i++)
    {
        scanf("%f",&arr[i]);
    }   
    int new;
    scanf("%d",&new);
    int days;
    scanf("%d",&days);
    int j;
    float key;
    int count=0;
    for ( i = n-new; i < n; i++)
    {
        key=arr[i];
        j=i-1;

        while (j>=0 && arr[j]>key)
        {
            arr[j+1] = arr[j];
            j--;
        }
        count++;
        arr[j+1]=key;
        if (count==days)
        {
            break;
        }
    }

    for ( i = 0; i <n-1 ; i++)
    {
        printf("%0.2f ",arr[i]);
    }
    printf("%0.2f",arr[i]);
    return 1;
}
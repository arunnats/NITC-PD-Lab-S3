#include<stdio.h>

int linear(int arr[],int key, int n)
{
    int i=0;
    for(i=0;i<n;i++)
    {
        if(arr[i]==key)
        {
            return i;  
        }
    }
    return -1;
}

int main()
{
    int n, key, i;
    scanf("%d",&n);
    int arr[n];
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }

    scanf("%d",&key);

    int ans = linear(arr, key, n);

    printf("%d", ans);
    return 1;
}

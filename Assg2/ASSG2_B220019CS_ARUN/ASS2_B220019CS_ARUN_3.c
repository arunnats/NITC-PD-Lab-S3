#include <stdio.h>

int main() 
    {
    int n, i;
    scanf("%d", &n);
    int arr[n];
    for (i = 0; i < n; i++) 
    {
        scanf("%d", &arr[i]);
    }
    int min, max, mean;
    min = 0;
    max = n - 1;

    while (min < max) 
    {
        mean = min + (max - min) / 2;
        if (arr[mean] > arr[mean + 1])
         {
            max = mean; 
        } 
        else
        {
            min = mean + 1; 
        }
    }

    printf("%d", arr[min]);

    return 1; 
}

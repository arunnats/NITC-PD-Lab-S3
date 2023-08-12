#include <stdio.h>

int main() 
{
    int n, m;
    scanf("%d %d", &n, &m);
    int arr[m];
    int maxTime = 0;
    for (int i = 0; i < m; i++) 
    {
        scanf("%d", &arr[i]);
        if (arr[i] > maxTime) 
        {
            maxTime = arr[i];
        }
    }
    int min = maxTime;
    int max = 0;
    for (int i = 0; i < m; i++) 
    {
        max += arr[i]; 
    }
    while (min <= max)
     {
        int mid = (min + max) / 2;
        int totalnNeeded = 0;
        int currentDayTime = 0;
        for (int i = 0; i < m; i++)
        {
            if (currentDayTime + arr[i] <= mid)
            {
                currentDayTime += arr[i];
            } 
            else
            {
                totalnNeeded++;
                currentDayTime = arr[i];
            }
        }

        totalnNeeded++; 

        if (totalnNeeded <= n) 
        {
            max = mid - 1;
        } 
        else
        {
            min = mid + 1;
        }
    }

    printf("%d", min);

    return 1;
}

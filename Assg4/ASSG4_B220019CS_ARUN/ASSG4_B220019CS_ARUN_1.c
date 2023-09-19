#include <stdio.h>

#define MAX 1000

void bucketSort(float arr[], int n) {
    int buckets[MAX][MAX];
    int bucketSize[MAX] = {0}; 
    int i,j;
    for (i = 0; i < n; i++) {
        int index = (int)(arr[i] * 100); 
        buckets[index][bucketSize[index]] = i; 
        bucketSize[index]++;
    }
    for (i = 0; i < MAX; i++) {
        if (bucketSize[i] > 1) {
            for (j = 1; j < bucketSize[i]; j++) {
                int keyIndex = buckets[i][j];
                float key = arr[keyIndex];
                int k = j - 1;
                while (k >= 0 && arr[buckets[i][k]] > key) {
                    buckets[i][k + 1] = buckets[i][k];
                    k--;
                }
                buckets[i][k + 1] = keyIndex;
            }
        }
    }
    float sortedArr[MAX];
    int k = 0;
    for (i = 0; i < MAX; i++) {
        for (j = 0; j < bucketSize[i]; j++) {
            int index = buckets[i][j];
            sortedArr[k++] = arr[index];
        }
    }
    for (i = 0; i < n; i++) {
        arr[i] = sortedArr[i];
    }
}

int main() {
    int n,i;
    scanf("%d", &n);
    float arr[MAX];

    for (i = 0; i < n; i++) {
        scanf("%f", &arr[i]);
    }

    bucketSort(arr, n);
    for (i = 0; i < n-1; i++) {
        printf("%.2f ", arr[i]);
    }
    printf("%.2f", arr[i]);


    return 1;
}

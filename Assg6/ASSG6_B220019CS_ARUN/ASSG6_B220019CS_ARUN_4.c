#include <stdio.h>
#define MAX_SIZE 1000

struct Queue 
{
    int data[MAX_SIZE];
    int head;
    int tail;
};

void enqueue(struct Queue* q, int x) 
{
    q->data[q->tail] = x;
    q->tail++;
}

int dequeue(struct Queue* q) 
{
    int x = q->data[q->head];
    q->head++;
    return x;
}

int isEmpty(struct Queue* q) 
{
    return (q->head == q->tail);
}

int size(struct Queue* q) 
{
    return (q->tail - q->head);
}

void reverse(struct Queue* q, int k, int n) 
{
    int temp[k];

    for (int i = 0; i < k; i++) 
    {
        temp[i] = dequeue(q);
    }
    for (int i = (k - 1); i >= 0; i--) 
    {
        enqueue(q, temp[i]);
    }
    for (int i = k; i < n; i++) 
    {
        enqueue(q, dequeue(q));
    }
}

int main() 
{
    int n, k;
    scanf("%d %d", &n, &k);

    struct Queue q;
    q.head = q.tail = 0;
    
    for (int i = 0; i < n; i++) 
    {
        int x;
        scanf("%d", &x);
        enqueue(&q, x);
    }

    reverse(&q, k, n);

    int tempArr[n];

    for (int i = 0; i < n; i++) 
    {
        tempArr[i] = dequeue(&q);
    }

    for (int i = 0; i < n - 1; i++)
     {
        printf("%d ", tempArr[i]);
    }
    printf("%d", tempArr[n - 1]);

    return 1;
}

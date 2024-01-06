#include <stdio.h>
#include <string.h>
#define MAX 100001

struct Queue
{
    char arr[MAX][21];
    int head;
    int tail;
};

int queue_full(struct Queue *q, int n)
{
    int next = (q->tail + 1) % n;
    if (next = = q->head)
    {
        return -1;
    }
    else
    {
        return 1;
    }
}

int queue_empty(struct Queue *q)
{
    if (q->head == q->tail)
    {
        return -1;
    }
    else
    {
        return 1;
    }
}

int enqueue(struct Queue *q, char s[21], int n)
{
    if (queue_full(q, n) == -1)
    {
        printf("-1\n");
    }
    else
    {
        strcpy(q->arr[q->tail], s); 
        q->tail = (q->tail + 1) % n;
    }
    
}

int dequeue(struct Queue *q)
{
    if (queue_empty(q) == -1)
    {
        printf("-1\n");
    }
    else
    {
        printf("%s\n", q->arr[q->head]);
        q->head = (q->head + 1) % MAX;
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    struct Queue q;
    q.head = q.tail = 0;

    char choice;
    char input[21];

    do
    {
        scanf(" %c", &choice);

        if (choice == 'i')
        {
            scanf(" %[^\n]", input);
            enqueue(&q, input, n);
        }
        else if (choice == 'd')
        {
            dequeue(&q);
        }
        else if (choice == 'f')
        {
            int isFull = queue_full(&q, n);
            printf("%d\n", isFull);
        }
        else if (choice == 'e')
        {
            int isEmpty = queue_empty(&q);
            printf("%d\n", isEmpty);
        }
        else if (choice == 't')
        {
            break;
        }
    } while (1);

    return 1;
}

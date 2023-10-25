#include <stdio.h>

void push(int S[], int *top, int x)
{
    (*top)++;
    S[*top] = x;
     
}

int pop(int S[], int *top) 
{
    int temp = S[*top];
    S[*top] = ' '; 
    (*top)--;
    return temp;
}

int empty(int top)
{
    if (top==-1)
        return 1;
    else
        return 0;
}

void findNext(int S[], int n, int result[])
{
    int stack[n];
    int top=-1;

    for (int i = 0; i < n; i++)
    {
        while(empty(top)!=1 && S[i]>S[stack[top]])
        {
            int topIndex = pop(stack,&top);
            result[topIndex] = S[i];
        }
        push(stack,&top,i);
    }
    while (empty(top)!=1)
    {
        int topIndex = pop(stack, &top);
        result[topIndex] = -1;
    }
    
    
}

int main() 
    {
    int n;
    scanf("%d", &n);
    int i;
    int s[n];
    for (i = 0; i < n; i++) 
    {
        scanf("%d", &s[i]);
    }

    int result[n];

    findNext(s, n, result);

    for (i = 0; i < n-1; i++) 
    {
        printf("%d ", result[i]);
    }
    printf("%d",result[i]);

    return 1;
}


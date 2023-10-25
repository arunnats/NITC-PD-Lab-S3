
#include <stdio.h>

struct Stack {
    char A[10001]; 
    int top; 
};

int stack_empty(struct Stack *s) 
{
    if (s->top == -1)
        return -1; 
    else
        return 1; 
}

int stack_full(struct Stack *s, int n) 
{
    if (s->top == n - 1)
        return -1;
    else
        return 1; 
}

void push(struct Stack *s, int n, char c) 
{
    if (stack_full(s, n) != -1) 
    {
        s->top++;
        s->A[s->top] = c;
    } 
    else 
    {
        printf("-1\n"); 
    }
}

char pop(struct Stack *s) 
{
    if (stack_empty(s) != -1) 
    {
        char temp = s->A[s->top];
        s->top--;
        return temp;
    } 
    else 
    {
        printf("-1\n"); 
        return -1;
    }
}

char peek(struct Stack *s) 
{
    return s->A[s->top];
}

int main() 
{
    int n;
    scanf("%d", &n);
    struct Stack S;
    S.top = -1;

    char choice, input;

    do {
        scanf(" %c", &choice);

        if (choice == 'i') 
        {
            scanf(" %c", &input);
            push(&S, n, input);
        } else if (choice == 'd') 
        {
            char temp = pop(&S);
            if (temp != -1) 
            {
                printf("%c\n", temp);
            }
        } else if (choice == 'p') 
        {
            if (stack_empty(&S) != -1) 
            {
                printf("%c\n", peek(&S));
            } else {
                printf("-1\n"); 
            }
        } else if (choice == 't') 
        {
            break;
        }
    } while (1);

    return 1;
}

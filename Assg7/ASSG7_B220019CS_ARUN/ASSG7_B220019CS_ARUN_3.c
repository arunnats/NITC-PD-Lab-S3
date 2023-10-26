#include <stdio.h>
#include <stdlib.h>
#include <string.h>  
#define MAX 100

struct Stack
{
    int data[MAX];
    int top;
};

void initializeStack(struct Stack *stack)
{
    stack->top = -1;
}

void push(struct Stack *stack, int value)
{
    stack->data[++stack->top] = value;
}

int pop(struct Stack *stack)
{
    return stack->data[stack->top--];
}

int peek(struct Stack *stack)
{
    return stack->data[stack->top];
}

int main()
{
    char postFix[MAX];
    int ans;
    int len = 0;
    scanf(" %[^\n]s", postFix);
    len = strlen(postFix);  

    struct Stack stack;
    initializeStack(&stack);
    int flag = 0;
    int temp = 0;

    for (int i = 0; i < len; i++)
    {
        if (postFix[i] == ' ')
        {
            continue;
        }
        if (postFix[i] == '+' || postFix[i] == '-' || postFix[i] == '/' || postFix[i] == '*')
        {
            if (stack.top < 1)
            {
                flag = 1;
                break;
            }
            int b = pop(&stack);
            int a = pop(&stack);
            if (postFix[i] == '+')
            {
                temp = a + b;
            }
            if (postFix[i] == '-')
            {
                temp = a - b;
            }
            if (postFix[i] == '*')
            {
                temp = a * b;
            }
            if (postFix[i] == '/')
            {
                if (b == 0)
                {
                    flag = 1;
                    break;
                }
                temp = a / b;
            }
            push(&stack, temp);
        }
        else
        {
            int converted = 0;
            while (i < len && postFix[i] >= '0' && postFix[i] <= '9')
            {
                converted = converted * 10 + (postFix[i] - '0');
                i++;
            }
            i--; 
            push(&stack, converted);
        }
    }

    if (stack.top != 0 || flag == 1)
    {
        printf("-1");
    }
    else
    {
        printf("%d", temp);
    }
    return 1;
}

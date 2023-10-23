#include <stdio.h>
#include <stdlib.h>
#define MAX 100

struct Stack 
{
    char data[MAX];
    int top;
};

void initializeStack(struct Stack *stack) 
{
    stack->top = -1;
}

void push(struct Stack *stack, char value) 
{
    stack->data[++stack->top] = value;
}

char pop(struct Stack *stack) 
{
    return stack->data[stack->top--];
}

char peek(struct Stack *stack) 
{
    return stack->data[stack->top];
}

int main() 
{
    char postFix[MAX];
    int ans;
    int len = 0;
    scanf(" %[^\n]s", postFix);
    for (int i = 0; postFix[i] != 0; i++) 
    {
        len++;
    }

    struct Stack stack;
    initializeStack(&stack);

    int j = 0;
    int temp;
    for (int i = 0; i < len; i++) 
    {
        if(postFix[i] == ' ')
        {
            continue;
        }
        if (postFix[i] == '+' || postFix[i] == '-' || postFix[i] == '/' || postFix[i] == '*') 
        {
        int b = pop(&stack);
        int a = pop(&stack);   
            if(postFix[i] == '+')
            {
                temp = a+b;
            }
            if(postFix[i] == '-')
            {
                temp = a-b;
            }
            if(postFix[i] == '*')
            {
                temp = a*b;
            }
            if(postFix[i] == '/')
            {
                temp = a/b;
            }
            push(&stack, temp);
        } 
        else 
        {
            int converted = postFix[i] - '0';
            push(&stack, converted);
        }
    }


    printf("%d", temp);
    return 1;
}

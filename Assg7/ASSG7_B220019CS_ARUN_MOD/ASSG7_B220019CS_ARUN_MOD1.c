#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

struct Stack 
{
    char data[10001];
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

int precedence(char operator) 
{
    if (operator == '%' || operator == '#')
        return 10;
    if (operator == '+' || operator == '-')
        return 9;
    if (operator == '*' || operator == '/')
        return 7;
     if (operator == '^')
        return 6;
    return 0;
}

int main() 
{
    int len =0;
    char inFix[MAX];
    int count = 0;
    struct Stack stack;
    initializeStack(&stack);

    scanf(" %[^\n]s", inFix);

    // while (inFix[len] =! '\0' && inFix[len+1]!='\0')
    // {
    //     len++;
    // }
    // len--;
    // printf("%d",len);
    // int size = (len + len - 1);
    len = strlen(inFix);
    char postFix[len];
    for (int i = 0; i < len; i++) 
    {
        char ch = inFix[i];
        if (ch == ' ') 
        {
            continue;
        } 
        else if (ch == '+' || ch == '-' || ch == '/' || ch == '*' || ch == '%' || ch == '^') 
        {
            while (stack.top >= 0 && precedence(peek(&stack)) >= precedence(ch)) 
            {
                postFix[count] = pop(&stack);
                count++;
                postFix[count] = ' ';
                count++;
            }
            push(&stack, ch);
        } 
        else if (ch == '(') 
        {
            push(&stack, ch);
        } 
        else if (ch == ')') 
        {
            while (stack.top >= 0 && peek(&stack) != '(') 
            {
                postFix[count] = pop(&stack);
                count++;
                postFix[count] = ' ';
                count++;
            }
            if (stack.top >= 0 && peek(&stack) == '(') 
            {
                pop(&stack);
            }
        } 
        else 
        {
            postFix[count] = ch;
            count++;
            postFix[count] = ' ';
            count++;
        }
    }

    while (stack.top >= 0) 
    {
        postFix[count] = pop(&stack);
        count++;
        postFix[count] = ' ';
        count++;
    }

    postFix[count-1] = '\b';
    postFix[count-1] = '\0'; 
    printf("%s\n", postFix);

    return 1;
}

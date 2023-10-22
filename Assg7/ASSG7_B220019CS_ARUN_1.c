#include <stdio.h>
#include <stdlib.h>

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
    if (operator == '+' || operator == '-')
        return 1;
    if (operator == '*' || operator == '/' || operator == '%')
        return 2;
    if (operator == '^')
        return 3;
    return 0;
}

int main() 
{
    int len;
    scanf("%d", &len);

    int size = (len + len - 1);

    char inFix[size];
    char postFix[size];

    int count = 0;

    struct Stack stack;
    initializeStack(&stack);

    scanf(" %[^\n]s", inFix);

    for (int i = 0; i < (len + len - 1); i++) 
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

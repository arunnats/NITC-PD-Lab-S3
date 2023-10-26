#include <stdio.h>
#include <string.h>

#define MAX 1000

struct Stack 
{
    char data[MAX][MAX];
    int top;
};

void push(struct Stack *stack, const char *str) 
{
    if (stack->top < MAX) 
    {
        strcpy(stack->data[stack->top], str);
        stack->top++;
    }
}

void pop(struct Stack *stack, char *str) 
{
    if (stack->top > 0) 
    {
        stack->top--;
        strcpy(str, stack->data[stack->top]);
    }
}

void concatenateStrings(char *result, const char *str1, char operator, const char *str2) 
{
    int i = 0;
    for (; str1[i] != '\0'; i++)
    {
        result[i] = str1[i];
    }
    result[i++] = operator;
    for (int j = 0; str2[j] != '\0'; j++) 
    {
        result[i + j] = str2[j];
    }
    result[i + strlen(str2)] = '\0';
}

int main() 
{
    char postfix[100];
    scanf("%s", postfix);

    struct Stack stack;
    stack.top = 0;

    int length = strlen(postfix);

    for (int i = 0; i < length; i++) 
    {
        char currentChar[2] = {postfix[i], '\0'};
        if (postfix[i] == '+' || postfix[i] == '-' || postfix[i] == '*' || postfix[i] == '/') 
        {
            char operand1[MAX], operand2[MAX];
            pop(&stack, operand1);
            pop(&stack, operand2);

            char newExpression[MAX];
            if (i == length - 1) 
            {
                concatenateStrings(newExpression, operand2, postfix[i], operand1);
            } 
            else 
            {
                newExpression[0] = '(';
                concatenateStrings(newExpression + 1, operand2, postfix[i], operand1);
                int len = strlen(newExpression);
                newExpression[len] = ')';
                newExpression[len + 1] = '\0';
            }

            push(&stack, newExpression);
        } 
        else 
        {
            push(&stack, currentChar);
        }
    }

    char infixExpression[MAX];
    pop(&stack, infixExpression);

    printf("%s\n", infixExpression);

    return 1;
}

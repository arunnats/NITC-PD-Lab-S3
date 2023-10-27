#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    if (operator == '*' || operator == '/')
        return 2;
    return 0;
}

int isOperator(char ch)
{
    return (ch == '+' || ch == '-' || ch == '/' || ch == '*' || ch == '%' || ch == '^');
}

int isDigit(char ch)
{
    return (ch >= '0' && ch <= '9');
}

int isDecimalPoint(char ch)
{
    return (ch == '.');
}

void convertToPostfix(const char *infix, char *postfix) {
    struct Stack stack;
    initializeStack(&stack);
    int count = 0;

    for (int i = 0; i < strlen(infix); i++) {
        char ch = infix[i];
        if (ch == ' ')
            continue;

        if (isDigit(ch) || (ch == '.' && isDigit(infix[i + 1]))) { // Operand (including multi-digit and decimal numbers)
            while (i < strlen(infix) && (isDigit(infix[i]) || (infix[i] == '.' && isDigit(infix[i + 1])))) {
                postfix[count] = infix[i];
                count++;
                i++;
            }
            i--;
            postfix[count] = ' ';
            count++;
        } else if (isOperator(ch)) { // Operator
            while (stack.top >= 0 && precedence(peek(&stack)) >= precedence(ch)) {
                postfix[count] = pop(&stack);
                count++;
                postfix[count] = ' ';
                count++;
            }
            push(&stack, ch);
        } else if (ch == '(') { // Left parenthesis
            push(&stack, ch);
        } else if (ch == ')') { // Right parenthesis
            while (stack.top >= 0 && peek(&stack) != '(') {
                postfix[count] = pop(&stack);
                count++;
                postfix[count] = ' ';
                count++;
            }
            if (stack.top >= 0 && peek(&stack) == '(') {
                pop(&stack);
            }
        }
    }

    while (stack.top >= 0) {
        postfix[count] = pop(&stack);
        count++;
        postfix[count] = ' ';
        count++;
    }

    postfix[count - 1] = '\0';
}


void evaluatePostfix(char postFix[], float *result)
{
   
}

int main()
{
    char inFix[10001];
    char postFix[10001];
    float result = 0.0;
    int len = 0;

    scanf("%d", &len);
    scanf(" %[^\n]s", inFix);

    convertToPostfix(inFix, postFix);
    printf("%s\n", postFix);

    evaluatePostfix(postFix, &result);

    if (result < 0)
    {
        printf("N");
    }
    else
    {
        printf("%.2f", result);
    }

    return 0;
}
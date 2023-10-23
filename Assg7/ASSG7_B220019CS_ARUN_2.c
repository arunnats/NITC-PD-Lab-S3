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
  char inFix[MAX];
  int len = 0;
  scanf(" %[^\n]s", postFix);
  for (int i = 0; postFix[i] != 0; i++) 
  {
    len++;
  }

  struct Stack stack;
  initializeStack(&stack);

  int j = 0;
  for (int i = 0; i < len; i++) 
  {
    if (postFix[i] == '+' || postFix[i] == '-' || postFix[i] == '/' || postFix[i] == '*') 
    {
      char b = pop(&stack);
      char a = pop(&stack);
    }
    else
    {
      push(&stack, postFix[i]);
    }
  }

  inFix[j] = '\0';
  printf("%s", inFix);
return 1;
}

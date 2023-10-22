#include <stdio.h>
#include <stdlib.h>
#define MAX 100

struct Stack {
  char data[MAX];
  int top;
};

void initializeStack(struct Stack *stack) {
  stack->top = -1;
}

void push(struct Stack *stack, char value) {
  stack->data[++stack->top] = value;
}

char pop(struct Stack *stack) {
  return stack->data[stack->top--];
}

char peek(struct Stack *stack) {
  return stack->data[stack->top];
}

int main() {
  char postFix[MAX];
  char inFix[MAX];
  int len = 0;
  scanf(" %[^\n]s", postFix);
  for (int i = 0; postFix[i] != 0; i++) {
    len++;
  }

  struct Stack stack;
  initializeStack(&stack);

  int j = 0;
  for (int i = 0; i < len; i++) {
    if (postFix[i] == '+' || postFix[i] == '-' || postFix[i] == '/' || postFix[i] == '*') {
      char b = pop(&stack);
      char a = pop(&stack);

      // Check if the top two operators have the same precedence, if so,
      // associate from left to right, but not if the top operator is a left parenthesis.
      if (peek(&stack) == postFix[i] && peek(&stack) != '(') {
        inFix[j] = '('; j++;
        inFix[j] = a; j++;
        inFix[j] = postFix[i]; j++;
        inFix[j] = b; j++;
        inFix[j] = ')'; j++;
      } else {
        inFix[j] = a; j++;
        inFix[j] = postFix[i]; j++;
        inFix[j] = b; j++;
      }
    } else {
      push(&stack, postFix[i]);
    }
  }

  // Pop the remaining operators from the stack and push them to the infix expression,
  // but only if the top of the stack is not a left parenthesis.
  while (stack.top != -1) {
    if (inFix[j] != '(') {
      inFix[j] = pop(&stack);
      j++;
    } else {
      break;
    }
  }

  inFix[j] = '\0';
  printf("%s", inFix);
  return 0;
}

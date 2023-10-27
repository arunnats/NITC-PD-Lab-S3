#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

struct Stack {
  int data[MAX];
  int top;
};

void initializeStack(struct Stack *stack) {
  stack->top = -1;
}

void push(struct Stack *stack, int value) {
  stack->data[++stack->top] = value;
}

int pop(struct Stack *stack) {
  return stack->data[stack->top--];
}

int peek(struct Stack *stack) {
  return stack->data[stack->top];
}

int precedence(char operator) {
  switch (operator) {
    case '+':
    case '-':
      return 1;
    case '*':
    case '/':
      return 2;
    case '^':
      return 3;
    default:
      return 0;
  }
}

void infixToPostfix(char *infix, char *postfix) {
  struct Stack stack;
  initializeStack(&stack);

  int i = 0;
  int j = 0;

  while (infix[i] != '\0') {
    if (infix[i] >= '0' && infix[i] <= '9') {
      postfix[j] = infix[i];
      j++;
    } else if (infix[i] == '(') {
      push(&stack, infix[i]);
    } else if (infix[i] == ')') {
      while (peek(&stack) != '(') {
        postfix[j] = pop(&stack);
        j++;
      }

      pop(&stack);
    } else {
      while (stack.top != -1 && precedence(peek(&stack)) >= precedence(infix[i])) {
        postfix[j] = pop(&stack);
        j++;
      }

      push(&stack, infix[i]);
    }

    i++;
  }

  while (stack.top != -1) {
    postfix[j] = pop(&stack);
    j++;
  }

  postfix[j] = '\0';
}

int evaluatePostfix(char *postfix) {
  struct Stack stack;
  initializeStack(&stack);

  int i = 0;

  while (postfix[i] != '\0') {
    if (postfix[i] >= '0' && postfix[i] <= '9') {
      push(&stack, postfix[i] - '0');
    } else {
      int b = pop(&stack);
      int a = pop(&stack);

      switch (postfix[i]) {
        case '+':
          push(&stack, a + b);
          break;
        case '-':
          push(&stack, a - b);
          break;
        case '*':
          push(&stack, a * b);
          break;
        case '/':
          push(&stack, a / b);
          break;
      }
    }

    i++;
  }

  return pop(&stack);
}

int main() {
  char infix[MAX];
  char postfix[MAX];

  printf("Enter an infix expression: ");
  scanf("%s", infix);

  infixToPostfix(infix, postfix);

  printf("The postfix expression is: %s\n", postfix);

  int result = evaluatePostfix(postfix);

  printf("The result of the postfix expression is: %d\n", result);

  return 0;
}

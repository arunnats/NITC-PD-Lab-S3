#include <stdio.h>
#include <stdlib.h>
#include <math.h>
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

int precedence(char operator) 
{
    if (operator == '+' || operator == '-')
        return 1;
    if (operator == '*' || operator == '/')
        return 2;
    return 0;
}


// void infixToPostfix(char *infix, char *postfix) 
// {
//     struct Stack stack;
//     initializeStack(&stack);
//     int count = 0;

//     for (int i = 0; infix[i] != 0; i++) 
//     {
//         if (infix[i] == ' ') 
//         {
//             continue;
//         }

//         if (infix[i] >= '0' && infix[i] <= '9') 
//         {
//             while (infix[i] >= '0' && infix[i] <= '9') 
//             {
//                 postfix[count++] = infix[i];
//                 i++;
//             }

//             postfix[count++] = ' ';
//             i--;

void infixToPostfix(char *infix, char *postfix) {
  struct Stack stack;
  initializeStack(&stack);
  int count = 0;
  for (int i = 0; infix[i] != 0; i++) {
    if (infix[i] == ' ') {
      continue;
    }
    if (infix[i] >= '0' && infix[i] <= '9') {
      while (infix[i] >= '0' && infix[i] <= '9') {
        postfix[count++] = infix[i];
        i++;
      }
      i--;
      postfix[count++] = ' ';
    } else if (infix[i] == '+' || infix[i] == '-' || infix[i] == '*' || infix[i] == '/') {
      while (stack.top >= 0 && precedence(peek(&stack)) >= precedence(infix[i])) {
        postfix[count++] = pop(&stack);
        postfix[count++] = ' ';
      }
      push(&stack, infix[i]);
    } else if (infix[i] == '(') {
      push(&stack, infix[i]);
    } else if (infix[i] == ')') {
      while (infix[i] == ')' && stack.top >= 0 && peek(&stack) != '(') {
        postfix[count++] = pop(&stack);
        postfix[count++] = ' ';
      }
      if (stack.top >= 0 && peek(&stack) == '(') {
        pop(&stack);
      }
    }
  }
  while (stack.top >= 0) {
    postfix[count++] = pop(&stack);
    postfix[count++] = ' ';
  }
  postfix[count - 1] = '\0';
}

//         } 
//         else if (infix[i] == '+' || infix[i] == '-' || infix[i] == '*' || infix[i] == '/') 
//         {
//             while (stack.top >= 0 && precedence(peek(&stack)) >= precedence(infix[i])) 
//             {
//                 postfix[count++] = pop(&stack);
//                 postfix[count++] = ' ';
//             }
//             push(&stack, infix[i]);
//         } 
//         else if (infix[i] == '(') 
//         {
//             push(&stack, infix[i]);
//         } 
//         else if (infix[i] == ')') 
//         {
//             while (stack.top >= 0 && peek(&stack) != '(') 
//             {
//                 postfix[count++] = pop(&stack);
//                 postfix[count++] = ' ';
//             }
//             if (stack.top >= 0 && peek(&stack) == '(') 
//             {
//                 pop(&stack);
//             }
//         }
//     }

//     while (stack.top >= 0) 
//     {
//         postfix[count++] = pop(&stack);
//         postfix[count++] = ' ';
//     }
//     postfix[count - 1] = '\0';
// }

// double evaluatePostfix(char *postfix) 
// {
//     struct Stack stack;
//     initializeStack(&stack);
//     int len = 0;
//     for (int i = 0; postfix[i] != 0; i++) 
//     {
//         len++;
//     }

//     for (int i = 0; i < len; i++) 
//     {
//         if (postfix[i] == ' ') 
//         {
//             continue;
//         }
//         if (postfix[i] >= '0' && postfix[i] <= '9') 
//         {
//             double num = 0;
//             while (postfix[i] >= '0' && postfix[i] <= '9') 
//             {
//                 num = num * 10 + (postfix[i] - '0');
//                 i++;
//             }
//             i--;
//             push(&stack, num);
//         } 
//         else if (postfix[i] == '+' || postfix[i] == '-' || postfix[i] == '*' || postfix[i] == '/') 
//         {
//             double b = pop(&stack);
//             double a = pop(&stack);
//             double result = 0;
//             if (postfix[i] == '+') 
//             {
//                 result = a + b;
//             } else if (postfix[i] == '-') 
//             {
//                 result = a - b;
//             } else if (postfix[i] == '*') 
//             {
//                 result = a * b;
//             } else if (postfix[i] == '/') 
//             {
//                 if (b == 0) {
//                     return -1.0; // Division by zero
//                 }
//                 result = a / b;
//             }
//             push(&stack, result);
//         }
//     }
//     return pop(&stack);
// }

double evaluatePostfix(char *postfix) {
  struct Stack stack;
  initializeStack(&stack);
  int len = 0;
  for (int i = 0; postfix[i] != 0; i++) {
    len++;
  }
  for (int i = 0; i < len; i++) {
    if (postfix[i] == ' ') {
      continue;
    }
    if (postfix[i] >= '0' && postfix[i] <= '9') {
      double num = 0;
      while (postfix[i] >= '0' && postfix[i] <= '9') {
        num = num * 10 + (postfix[i] - '0');
        i++;
      }
      i--;
      push(&stack, num);
    } else if (postfix[i] == '+' || postfix[i] == '-' || postfix[i] == '*' || postfix[i] == '/') {
      double b = pop(&stack);
      double a = pop(&stack);
      double result = 0;
      if (postfix[i] == '+') {
        result = a + b;
      } else if (postfix[i] == '-') {
        result = a - b;
      } else if (postfix[i] == '*') {
        result = a * b;
      } else if (postfix[i] == '/') {
        if (fabs(b) < 1e-6) {
          return -1.0; // Division by a very small number
        }
        result = a / b;
      }
      push(&stack, result);
    }
  }
  return pop(&stack);
}

int main() 
{
    char infix[MAX];
    char postfix[MAX];

    scanf(" %[^\n]s", infix);

    infixToPostfix(infix, postfix);
    printf("%s\n", postfix);

    printf("%f\n", evaluatePostfix(postfix));

    return 0;


}

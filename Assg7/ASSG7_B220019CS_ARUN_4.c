#include <stdio.h>
#include <stdlib.h>
<<<<<<< HEAD
#include <string.h>

struct Stack
{
    char data[10001];
    int top;
};

void initializeStack(struct Stack *stack)
=======
#include <math.h>
#define MAX 100

struct Stack 
{
    char data[MAX];
    int top;
};

void initializeStack(struct Stack *stack) 
>>>>>>> 824cde11c63bad65fdee1b5491e88eee6cd351fc
{
    stack->top = -1;
}

<<<<<<< HEAD
void push(struct Stack *stack, char value)
=======
void push(struct Stack *stack, char value) 
>>>>>>> 824cde11c63bad65fdee1b5491e88eee6cd351fc
{
    stack->data[++stack->top] = value;
}

<<<<<<< HEAD
char pop(struct Stack *stack)
=======
char pop(struct Stack *stack) 
>>>>>>> 824cde11c63bad65fdee1b5491e88eee6cd351fc
{
    return stack->data[stack->top--];
}

<<<<<<< HEAD
char peek(struct Stack *stack)
=======
char peek(struct Stack *stack) 
>>>>>>> 824cde11c63bad65fdee1b5491e88eee6cd351fc
{
    return stack->data[stack->top];
}

<<<<<<< HEAD
int precedence(char operator)
=======
int precedence(char operator) 
>>>>>>> 824cde11c63bad65fdee1b5491e88eee6cd351fc
{
    if (operator == '+' || operator == '-')
        return 1;
    if (operator == '*' || operator == '/')
        return 2;
    return 0;
}

<<<<<<< HEAD
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
=======

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

    return 1;


}
>>>>>>> 824cde11c63bad65fdee1b5491e88eee6cd351fc

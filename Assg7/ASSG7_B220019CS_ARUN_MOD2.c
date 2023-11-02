#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

struct Stack 
{
    struct Node* data[10001];
    int top;
};

struct Node 
{
    char data;
    struct Node* left;
    struct Node* right;
};

int isEmpty(struct Stack* stack) 
{
    return stack->top == -1;
}

int isFull(struct Stack* stack) 
{
    return stack->top == MAX - 1;
}

struct Node* createNode(char x) 
{
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = x;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void initializeStack(struct Stack* stack) {
    stack->top = -1;
}

void push(struct Stack* stack, struct Node* node) 
{
    if (isFull(stack)) 
    {
        printf("Stack is full!\n");
        return;
    }

    stack->data[++stack->top] = node;
}

struct Node* pop(struct Stack* stack)
 {
    if (isEmpty(stack)) 
    {
        printf("Stack is empty!\n");
        return NULL;
    }

    return stack->data[stack->top--];
}

struct Node* peek(struct Stack* stack) 
{
    if (isEmpty(stack)) 
    {
        return NULL;
    }

    return stack->data[stack->top];
}

int isOperator(char ch) 
{
    if (ch == '+' || ch == '-' || ch == '%' || ch == '*' || ch == '/' || ch == '^') {
        return 1;
    } 
    else 
    {
        return 0;
    }
}

void printInorder(struct Node* node) 
{
    if (node == NULL) 
    {
        return;
    }

    printInorder(node->left);
    printf("%c", node->data);
    printInorder(node->right);
}

int main() {
    int len = 0;
    char postFix[MAX];
    scanf("%d",&len);
    scanf(" %[^\n]s", postFix);
    char inFix[len];
    struct Stack charStack;
    initializeStack(&charStack);

    for (int i = 0; i < len; i++) 
    {
        char ch = postFix[i];
        if (isOperator(ch)) {
            struct Node* b = pop(&charStack);
            struct Node* a = pop(&charStack);

            struct Node* parentNode = createNode(ch);
            parentNode->left = a;
            parentNode->right = b;

            push(&charStack, parentNode);
        } 
        else 
        {
            struct Node* charNode = createNode(ch);
            charNode->left = NULL;
            charNode->right = NULL;

            push(&charStack, charNode);
        }
    }

    struct Node* root = charStack.data[charStack.top];
    printInorder(root);

    return ;
}

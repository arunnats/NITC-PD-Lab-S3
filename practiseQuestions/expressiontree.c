#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_CAPACITY 10001

// Structure for a tree node
struct TreeNode {
    char data;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Structure for a character stack
struct CharStack {
    int top;
    char array[MAX_CAPACITY];
};

// Structure for a node stack
struct NodeStack {
    int top;
    struct TreeNode* array[MAX_CAPACITY];
};

// Function to initialize a character stack
struct CharStack* createCharStack() {
    struct CharStack* stack = (struct CharStack*)malloc(sizeof(struct CharStack));
    stack->top = -1;
    return stack;
}

// Function to check if a character stack is empty
int isCharStackEmpty(struct CharStack* stack) {
    return stack->top == -1;
}

// Function to push a character to the stack
void pushChar(struct CharStack* stack, char item) {
    stack->array[++stack->top] = item;
}

// Function to pop a character from the stack
char popChar(struct CharStack* stack) {
    if (!isCharStackEmpty(stack))
        return stack->array[stack->top--];
    return '$'; // Return a special character indicating an empty stack
}

// Function to get the top character from the stack without popping
char peekChar(struct CharStack* stack) {
    return stack->array[stack->top];
}

// Function to initialize a node stack
struct NodeStack* createNodeStack() {
    struct NodeStack* stack = (struct NodeStack*)malloc(sizeof(struct NodeStack));
    stack->top = -1;
    return stack;
}

// Function to check if a node stack is empty
int isNodeStackEmpty(struct NodeStack* stack) {
    return stack->top == -1;
}

// Function to push a node to the stack
void pushNode(struct NodeStack* stack, struct TreeNode* item) {
    stack->array[++stack->top] = item;
}

// Function to pop a node from the stack
struct TreeNode* popNode(struct NodeStack* stack) {
    if (!isNodeStackEmpty(stack))
        return stack->array[stack->top--];
    return NULL; // Return NULL indicating an empty stack
}

// Function to check if a character is an operand (digit)
int isOperand(char ch) {
    return (ch >= '0' && ch <= '9');
}

// Function to check the precedence of an operator
int precedence(char op) {
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0;
}

// Function to convert infix expression to postfix notation
void infixToPostfix(char infix[], char postfix[]) {
    struct CharStack* stack = createCharStack();
    int i, j;
    i = j = 0;

    while (infix[i] != '\0') {
        if (infix[i] == ' ') {
            i++;
        } else if (isOperand(infix[i])) {
            while (isOperand(infix[i])) {
                postfix[j++] = infix[i++];
            }
            postfix[j++] = ' '; // Add space after each operand
        } else if (infix[i] == '(') {
            pushChar(stack, infix[i++]);
        } else if (infix[i] == ')') {
            while (!isCharStackEmpty(stack) && peekChar(stack) != '(') {
                postfix[j++] = ' '; // Add space before each operator
                postfix[j++] = popChar(stack);
            }
            popChar(stack); // Pop '('
            i++;
        } else { // Operator
            while (!isCharStackEmpty(stack) && precedence(infix[i]) <= precedence(peekChar(stack))) {
                postfix[j++] = ' '; // Add space before each operator
                postfix[j++] = popChar(stack);
            }
            pushChar(stack, infix[i++]);
        }
    }

    // Pop remaining operators from stack
    while (!isCharStackEmpty(stack)) {
        postfix[j++] = ' '; // Add space before each operator
        postfix[j++] = popChar(stack);
    }

    postfix[j] = '\0'; // Null-terminate the postfix expression
}



// Function to create an expression tree from postfix notation
struct TreeNode* constructExpressionTree(char postfix[]) {
    struct NodeStack* stack = createNodeStack();
    int i;
    for (i = 0; postfix[i] != '\0'; i++) {
        if (isOperand(postfix[i])) {
            struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
            newNode->data = postfix[i];
            newNode->left = newNode->right = NULL;
            pushNode(stack, newNode);
        } else {
            struct TreeNode* op2 = popNode(stack);
            struct TreeNode* op1 = popNode(stack);
            struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
            newNode->data = postfix[i];
            newNode->left = op1;
            newNode->right = op2;
            pushNode(stack, newNode);
        }
    }
    return popNode(stack);
}

// Function to calculate the height of an expression tree
int height(struct TreeNode* root) {
    if (root == NULL)
        return 0;
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    return (leftHeight > rightHeight) ? leftHeight + 1 : rightHeight + 1;
}

// Function to find the minimum length from the root to any leaf in the expression tree
int minLengthToLeaf(struct TreeNode* root) {
    if (root == NULL)
        return 0;
    if (root->left == NULL && root->right == NULL)
        return 1;
    int leftHeight = minLengthToLeaf(root->left);
    int rightHeight = minLengthToLeaf(root->right);
    return 1 + ((leftHeight < rightHeight) ? leftHeight : rightHeight);
}

double evaluateExpression(struct TreeNode* root) {
    if (root == NULL)
        return 0;
    if (isOperand(root->data)) {
        return root->data - '0'; // Convert char to int
    }
    double leftValue = evaluateExpression(root->left);
    double rightValue = evaluateExpression(root->right);
    switch (root->data) {
        case '+':
            return leftValue + rightValue;
        case '-':
            return leftValue - rightValue;
        case '*':
            return leftValue * rightValue;
        case '/':
            if (rightValue != 0) {
                return leftValue / rightValue;
            } else {
                printf("N\n");
                exit(0);
            }
    }
    return 0; // Default return, should not be reached
}

int main() {
    char infix[MAX_CAPACITY];
    fgets(infix, sizeof(infix), stdin);

    // Convert infix to postfix
    char postfix[MAX_CAPACITY];
    infixToPostfix(infix, postfix);

    // Construct expression tree from postfix
    struct TreeNode* root = constructExpressionTree(postfix);

    // Print postorder traversal
    printf("%s\n", postfix);

    // Evaluate expression and display result
    double result = evaluateExpression(root);
    if (!isnan(result) && !isinf(result))
        printf("%.2lf\n", result);
    else
        printf("N\n");

    // Display height of the expression tree
    printf("%d\n", height(root));

    // Display minimum length from root to any leaf
    printf("%d\n", minLengthToLeaf(root));

    return 0;
}

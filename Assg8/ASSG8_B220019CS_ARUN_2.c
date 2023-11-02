#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    struct Node* parent;
};

struct Node* createNode(int x)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = x;
    newNode->parent = NULL;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void insertNode(struct Node** head, int k, struct Node* parentNode)
{
    if (*head == NULL)
    {
        *head = createNode(k);
        (*head)->parent = parentNode;
    }
    else if (k >= (*head)->data)
    {
        insertNode(&((*head)->left), k, *head);
    }
    else if (k < (*head)->data)
    {
        insertNode(&((*head)->right), k, *head);
    }
}

void printPreorder(struct Node* node)
{
    if (node == NULL)
        return;

    printf("%d ", node->data);
    printPreorder(node->left);
    printPreorder(node->right);
}

struct Node* findMin(struct Node* node)
{
    while (node && node->right)
        node = node->right;
    return node;
}

struct Node* findMax(struct Node* node)
{
    while (node && node->left)
        node = node->left;
    return node;
}

struct Node* findSuccessor(struct Node* node)
{
    if (node == NULL)
        return NULL;

    if (node->right)
    {
        return findMin(node->right);
    }

    struct Node* successor = NULL;
    struct Node* current = node->parent;

    while (current != NULL && node == current->right)
    {
        node = current;
        current = current->parent;
    }

    return current;
}


struct Node* findPredecessor(struct Node* node)
{
    if (node == NULL)
        return NULL;

    if (node->left)
        return findMax(node->left);

    struct Node* predecessor = NULL;
    struct Node* current = node->parent;

    while (current != NULL)
    {
        if (node == current->right)
        {
            node = current;
            current = current->parent;
        }
        else
        {
            predecessor = current;
            break;
        }
    }

    return predecessor;
}


struct Node* deleteNode(struct Node* root, int k)
{
    if (root == NULL)
    {
        printf("-1\n");
        return root;
    }

    if (k < root->data)
    {
        root->left = deleteNode(root->left, k);
    }
    else if (k > root->data)
    {
        root->right = deleteNode(root->right, k);
    }
    else
    {
        if (root->left == NULL)
        {
            struct Node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }

        struct Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }

    return root;
}

int main()
{
    struct Node* root = NULL;

    char choice;
    int k;

    do {
        scanf(" %c", &choice);

        if (choice == 'a')
        {
            scanf(" %d", &k);
            insertNode(&root, k, NULL);
        }
        else if (choice == 'd')
        {
            scanf(" %d", &k);
            struct Node* result = deleteNode(root, k);
        }
        else if (choice == 'c')
        {
            scanf(" %d", &k);
            struct Node* successor = findSuccessor(root);
            if (successor)
                printf("%d\n", successor->data);
            else
                printf("-1\n");
        }
        else if (choice == 'r')
        {
            scanf(" %d", &k);
            struct Node* predecessor = findPredecessor(root);
            if (predecessor)
                printf("%d\n", predecessor->data);
            else
                printf("-1\n");
        }
        else if (choice == 'p')
        {
            if (root)
            {
                printPreorder(root);
                printf("\n");
            }
            else
            {
                printf("-1\n");
            }
        }
        else if (choice == 'e')
        {
            break;
        }
    } while (1);

    return 1;
}

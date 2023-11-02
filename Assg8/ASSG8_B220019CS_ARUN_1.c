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
    return newNode; // Added return statement
}

void insertNode(struct Node** head, int k, struct Node* parentNode)
{
    if (*head == NULL)
    {
        *head = createNode(k);
        (*head)->parent = parentNode; // Set parent correctly
    }
    else if (k > (*head)->data)
    {
        insertNode(&((*head)->left), k, *head); // Fixed the recursion
    }
    else if (k <= (*head)->data)
    {
        insertNode(&((*head)->right), k, *head); // Fixed the recursion
    }
}

void findMax(struct Node* head)
{   
    if(head==NULL)
    {
        return;
    }
    while (head->left != NULL)
    {
        head = head->left;
    }
    printf("%d\n", head->data);
}

void findMin(struct Node* head)
{   
    if(head==NULL)
    {
        return;
    }
    while (head->right != NULL)
    {
        head = head->right;
    }
    printf("%d\n", head->data);
}

void printInorder(struct Node* node)
{
    if (node == NULL)
        return;

    printInorder(node->left);
    printf("%d ", node->data);
    printInorder(node->right);
}

void printPreorder(struct Node* node)
{
    if (node == NULL)
        return;

    printf("%d ", node->data);
    printPreorder(node->left);
    printPreorder(node->right);
}

void printPostorder(struct Node* node)
{
    if (node == NULL)
        return;

    printPostorder(node->left);
    printPostorder(node->right);
    printf("%d ", node->data);
}

struct Node* search(struct Node* root, int key)
{
    if (root == NULL || root->data == key)
        return root;
    if (root->data < key)
        return search(root->right, key);
    return search(root->left, key);
}

int main()
{
    struct Node* root = NULL;

    char choice;

    do {
        scanf(" %c", &choice);

        if (choice == 'a')
        {
            int x;
            scanf(" %d", &x);
            insertNode(&root, x, NULL);
        }
        else if (choice == 's')
        {   
            if(root!=NULL)
            {
                int k;
                scanf(" %d", &k);
                struct Node* result = search(root, k);
                if (result != NULL) 
                {
                    printf("F\n");
                } 
                else {
                    printf("N\n");
                }
            }
        }
        else if (choice == 'x')
        {
            findMax(root);

        }
        else if (choice == 'n')
        {
            findMin(root);
        }
        else if (choice == 'i')
        {
            if (root) 
            {
                printInorder(root);
                printf("\n");
            }
        }
        else if (choice == 'p')
        {
            if (root) 
            {
                printPreorder(root);
                printf("\n"); 
            }
        }
        else if (choice == 't')
        {
            if (root) 
            {
                printPostorder(root);
                printf("\n"); 
            }
        }
        else if (choice == 'e')
        {
            break;
        }
    } while (1);

    return 1;
}

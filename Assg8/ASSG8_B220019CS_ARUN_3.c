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
    else if (k > (*head)->data)
    {
        insertNode(&((*head)->right), k, *head);
    }
    else if (k <= (*head)->data)
    {
        insertNode(&((*head)->left), k, *head);
    }
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


void print(struct Node* root) {
    if (root == NULL) {
        printf("( )");
        return;
    }

    printf("( %d", root->data);
    print(root->left);
    print(root->right);
    printf(" )");
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
        else if (choice == 'p')
        {
            print(&root);
        }
        else if (choice == 'e')
        {
            break;
        }
    } while (1);

    return 1;
}

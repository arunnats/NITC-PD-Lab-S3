#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
    struct Node* p;
};

struct Node* createNode(int key) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = key;
    newNode->right = NULL;
    newNode->left = NULL;
    newNode->p = NULL;
    return newNode;
}

struct Node* insertNode(struct Node* head, int key, struct Node* p) {
    if (head == NULL) {
        struct Node* newNode = createNode(key);
        newNode->p = p; 
        return newNode;
    }

    if (head->data > key)
        head->left = insertNode(head->left, key, head);
    else
        head->right = insertNode(head->right, key, head);

    return head;
}

struct Node* findMax(struct Node* root) {
    while (root != NULL && root->right != NULL) {
        root = root->right;
    }
    return root;
}

struct Node* findMin(struct Node* root) {
    while (root != NULL && root->left != NULL) {
        root = root->left;
    }
    return root;
}

void inorderArray(struct Node* node, int arr[], int* len) {
    if (node == NULL)
        return;

    inorderArray(node->left, arr, len);
    arr[*len] = node->data;
    (*len)++;
    inorderArray(node->right, arr, len);
}

int findSuccessor(struct Node* root, int key) {
    int arr[100];
    int len = 0;
    int succ = -1; 

    inorderArray(root, arr, &len);

    for (int i = 0; i < len; i++) {
        if (key == arr[i]) {
            if (i == len - 1)
                succ = -1;
            else
                succ = arr[i + 1];
        }
    }

    return succ;
}

void preorderArray(struct Node* node, int arr[], int* len) {
    if (node == NULL)
        return;

    arr[*len] = node->data;
    (*len)++;
    preorderArray(node->left, arr, len);
    preorderArray(node->right, arr, len);
}

int findPred(struct Node* root, int key) {
    int arr[100];
    int len = 0;
    int succ = -1; 

    preorderArray(root, arr, &len);

    for (int i = 0; i < len; i++) {
        if (key == arr[i]) {
            if (i == 0)
                succ = -1;
            else
                succ = arr[i - 1];
        }
    }

    return succ;
}


void printInorder(struct Node* node) {
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

struct Node* search(struct Node* root, int key)
{
    if (root == NULL || root->data == key)
        return root;
    if (root->data < key)
        return search(root->right, key);
    return search(root->left, key);
}


struct Node* deleteNode(struct Node* root, int k, struct Node* tempRoot)
{
    if(root == NULL)
    {
        return root;
    }

    if(k>root->data)
    {
        root->right = deleteNode(root->right,k,tempRoot);
    }

    else if(k<root->data)
    {
        root->left = deleteNode(root->left,k,tempRoot);
    }

    else
    {
        if (root->left==NULL)
        {
            struct Node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right==NULL)
        {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }

        int succ = findSuccessor(root,k);
        struct Node* succNode = search(tempRoot,succ);

        root->right = deleteNode(tempRoot, succNode->data, tempRoot);
        int temp = succNode->data;
        root->data = temp;



        
    }

    return root;
}

void print(struct Node* root) {
    if (root == NULL) {
        printf("( )");
        return;
    }

    printf("( %d", root->data);

    if (root->left != NULL || root->right != NULL) {
        printf(" ");
        print(root->left);
        printf(" ");
        print(root->right);
    }

    printf(")");
}

int main() {
    struct Node* root = NULL;
    root = insertNode(root, 4, NULL);
    root = insertNode(root, 5, NULL);
    root = insertNode(root, 7, NULL);
    root = insertNode(root, 2, NULL);
    root = insertNode(root, 1, NULL);
    root = insertNode(root, 9, NULL);

    printInorder(root);
    int successor = findSuccessor(root, 7);
    printf("\nInorder successor of 7 is: %d\n", successor);

    printPreorder(root);    
    int pred = findPred(root, 7);
    printf("\nPreorder pred of 7 is: %d\n", pred);

    root = deleteNode(root,5,root);
    printInorder(root);
    printf("\n");
    print(root);
    printf("\n");
    root = insertNode(root, 3, NULL);
    root = insertNode(root, 5, NULL);
    root = insertNode(root, 9, NULL);
    root = insertNode(root, 10, NULL);
    root = insertNode(root, 11, NULL);
    print(root);
    return 0;
}

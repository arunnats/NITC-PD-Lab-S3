#include<stdio.h> 
#include<stdlib.h>

struct node{
    int n ;
    struct node *left ;
    struct node *right ;
};

typedef struct node node ;

node *createnode( int n ){
    node *newnode = ( node *)malloc( sizeof(node) );
    newnode->n = n ;
    newnode->right = NULL ;
    newnode->left = NULL ;
    return newnode ;
}

node *build( char *c , int n , int *a ){
    if( *a < n ){
        node *temp = NULL ;
        if( c[*a] != ')'){
                temp = createnode( c[*a] - '0');

                if( c[++(*a)] == '('){
                    *a = *a + 1;
                    temp->left = build( c , n , a );
                }
                else 
                    temp->left = createnode( c[*a] - '0' );
                
                if( c[++(*a)] == '('){
                    *a = *a + 1;
                    temp->right = build( c , n , a );
                }
                else 
                    temp->right = createnode( c[*a] - '0' );
                (*a)++;
        }
        return temp ;
    }
}

int extractNumber(char S[], int* index) {
    int data = 0;
    while (S[*index] >= '0' && S[*index] <= '9') {
        data = data * 10 + (S[*index] - '0');
        (*index)++;
    }
    return data;
}

struct Node* buildTree(char S[], int* index) {
    if (S[*index] == '(') {
        (*index)++; // Move to the next character

        // Extract the data
        int data = extractNumber(S, index);

        // Create a new node with the extracted data
        struct Node* newNode = createNode(data);

        // Recursively build left and right subtrees
        newNode->left = buildTree(S, index);
        newNode->right = buildTree(S, index);

        // Move to the closing parenthesis
        (*index)++;

        return newNode;
    }

    // If the current character is ')', move to the next character
    (*index)++;

    return NULL;
}

void inorder( node *root ){
    if( root != NULL ){
        inorder( root->left );
        printf( "%d " , root->n );
        inorder( root->right );
    }
}

int main( ){
    char S[103];
    fgets(S, sizeof(S), stdin);

    // Initialize the index to 0
    int index = 0;

    // Build the binary tree from Parenthesis Representation
    struct Node* root = buildTree(S, &index);
    inorder( root );
    //printf( "%d" , root->right->n );
}
#include<stdio.h>
#include<string.h> 
#include<stdlib.h>

struct node{
    char c ;
    struct node *left ;
    struct node *right ;
};

typedef struct node node ;

int operator( char c ) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^' || c == '%');
}

node *createnode( char c ){
    node *newnode ;
    newnode = ( node *)malloc( sizeof( node ));
    newnode->c = c ;
    newnode->left = NULL;
    newnode->right = NULL;

    return newnode ;
}

node *constructTree( char *exp , int n ){
    node *stack[100] , *newnode ;
    int top = -1 ;

    for( int i = 0 ; i < n ; i ++ ){
        if( !operator(exp[i]) ){
            newnode = createnode( exp[i] );
            stack[++top] = newnode ;
        }
        else{
            newnode = createnode( exp[i] );

            newnode->right = stack[top--];
            newnode->left = stack[top--];

            stack[++top] = newnode ;
        }
    }

    return stack[top] ;
}

void infix( node *root ){
    if( root != NULL ){
        infix( root->left);
        printf( "%c" , root->c );
        infix( root->right );
    }
}

int main( ){

    int n ; 
    scanf( "%d" , &n );
   
    char exp[n] , c ;
    scanf( "%c" , &c );
    int i = 0 ; 

    scanf( "%[^\n]s" , exp );

    node *root = NULL ;
    root = constructTree( exp , n );
    infix( root );

    return 1 ;
}
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

typedef struct node node;

void create_node(int k)
{
    node* newNode = (node*)malloc(sizeof(node));
    newNode->data=k;
    newNode->next=NULL;
    return newNode;
}

void list_insert_tail(node** L, int k)
{
    node* newNode = create_node(k);
    node* current=*L;
    if (current->next=NULL)
    {
        newNode=L;
    }
    
    while (current->next!=NULL)
    {
        current=current->next;
    }
    current->next=newNode;    
}

void list_insert_front(node** L, int k)
{
    node* newNode = create_node(k);
    newNode->next=*L;
    *L=newNode 
}

int list_search(node** L, int k)
{
    int pos=0;
    node* current = *L;
    while (current!=NULL)
    {
        if (current->data=k)
        {
            return pos;
        }
        current=current->next;
        pos++;
    }
    return -1;
}

int list_length(node** L)
{
    int len=0;
    node* current = *L;
    while (current!=NULL)
    {
        len++;
        current=current->next;
    }
    return len;
}

void list_insert_before(node** L,int x, int y)
{
    int pos = list_search(*L,y);
    if (pos=0)
    {
        
    }
    
}


int main() 
{

}
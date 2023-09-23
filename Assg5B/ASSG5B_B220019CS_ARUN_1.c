#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

typedef struct node node;

node* create_node(int k)
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
    if (current->next==NULL)
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
    *L=newNode; 
}

int list_pos(node** L, int k)
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

int list_search(node** L, int k)
{
    node* current = *L;
    while (current!=NULL)
    {
        if (current->data=k)
        {
            return 1;
        }
        current=current->next;

    }
    return -1;
}

void list_insert_before(node** L,int x, int y)
{
    int pos = list_pos(*L,y);
    if (pos=0)
    {
        list_insert_front(*L,x);
    }
    
    node* newnode=create_node(x);
    node* current = *L;
    node* prev = NULL;
    for(int i=0;i<pos;i++)
    {
        prev=current;
        current=current->next;
    }
    newnode=current->next;
    prev = newnode;
}

void list_insert_after(node** L,int x, int y)
{
    int pos = list_pos(*L,y);
    int len = list_length(*L);
    if (pos=len)
    {
        list_insert_tail(*L,x);
    }

    node* newnode=create_node(x);
    node* current = *L;
    node* prev = NULL;
    for(int i=0;i<=pos;i++)
    {
        prev=current;
        current=current->next;
    }
    newnode=current->next;
    prev = newnode;
    
}

int delete(node** L, int k)
{
    int pos=list_pos(*L,k);
    int len=list_length(*L);
    if (pos=-1)
    {
        return -1;
    }
    else if (pos=0)
    {
        list_delete_first(*L);    
    }
    else if (pos=len)
    {
        list_delete_last(*L);
    }
    else
    {
        node* currentNode =*L;
        node* prevNode = NULL;
        node* nextNode = currentNode->next;

        for(int i=0;i<pos;i++)
        {
            prevNode=currentNode;
            currentNode=currentNode->next;
            nextNode=currentNode->next;
        }
        free(prevNode->next);
        prevNode->next=nextNode;
        return k;
    }
}

int list_delete_first(node** L)
{
    node* currentNode=*L;
    currentNode=currentNode->next;
    int temp = currentNode->data;
    free(*L);
    *L=currentNode;
    return temp;
}

int list_delete_last(node** L)
{
    node* currentNode=*L;
    node* prevNode=NULL;
    while (currentNode->next!= NULL) 
    {
        prevNode=currentNode;
        currentNode=currentNode->next;
    }
    int temp = currentNode->data;
    free(currentNode);
    prevNode->next=NULL;
    return temp;
}

void list_reverse(node** L)
{
    node* currentNode = *L;
    node* prevNode = NULL;
    node* nextNode = *L;
    while (nextNode!= NULL) 
    {
        nextNode=nextNode->next;
        currentNode->next=prevNode;
        prevNode=currentNode;
        currentNode=nextNode;
    }
    *L=prevNode;
    display(*L);
}

void list_reverse_even(node** L)
{
    
}

void display(node* L) 
{
    node* current = L;
    while (current->next != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("%d", current->data);
}


int main() 
{

}
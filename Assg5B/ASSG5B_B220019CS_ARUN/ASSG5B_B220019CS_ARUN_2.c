#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node 
{
    int data;
    struct Node* next;
    struct Node* prev;
};

typedef struct Node Node;

Node* create_node(int k) 
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = k;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void list_insert_front(Node** L, int k) 
{
    Node* newNode = create_node(k);
    if (*L == NULL) 
    {
        *L = newNode;
    } else 
    {
        newNode->next = *L;
        (*L)->prev = newNode;
        *L = newNode;
    }
}

void list_insert_tail(Node** L, int k) 
{
    Node* newNode = create_node(k);
    if (*L == NULL) 
    {
        *L = newNode;
    } else 
    {
        Node* current = *L;
        while (current->next != NULL) 
        {
            current = current->next;
        }
        current->next = newNode;
        newNode->prev = current;
    }
}

void list_insert_after(Node** L, int x, int y) 
{
    Node* newNode = create_node(x);
    Node* current = *L;
    while (current != NULL && current->data != y) 
    {
        current = current->next;
    }
    if (current == NULL) 
    {
        free(newNode);
        return;
    }
    newNode->next = current->next;
    newNode->prev = current;
    if (current->next != NULL) 
    {
        current->next->prev = newNode;
    }
    current->next = newNode;
}

void list_insert_before(Node** L, int x, int y) 
{
    Node* newNode = create_node(x);
    Node* current = *L;
    while (current != NULL && current->data != y) 
    {
        current = current->next;
    }
    if (current == NULL) 
    {
        free(newNode);
        return;
    }
    newNode->next = current;
    newNode->prev = current->prev;
    if (current->prev != NULL) 
    {
        current->prev->next = newNode;
    }
    current->prev = newNode;
    if (*L == current) 
    {
        *L = newNode;
    }
}

int list_delete(Node** L, int k) 
{
    Node* current = *L;
    while (current != NULL && current->data != k) 
    {
        current = current->next;
    }
    if (current == NULL) 
    {
        return -1;
    }
    if (current->prev != NULL) 
    {
        current->prev->next = current->next;
    } else 
    {
        *L = current->next;
    }
    if (current->next != NULL) 
    {
        current->next->prev = current->prev;
    }
    int deletedData = current->data;
    free(current);
    return deletedData;
}

int list_delete_initial(Node** L) 
{
    if (*L == NULL) 
    {
        return -1;
    }
    Node* current = *L;
    *L = current->next;
    if (current->next != NULL) 
    {
        current->next->prev = NULL;
    }
    int deletedData = current->data;
    free(current);
    return deletedData;
}

int list_delete_last(Node** L) 
{
    if (*L == NULL)
    {
        return -1;
    }
    Node* current = *L;
    while (current->next != NULL) 
    {
        current = current->next;
    }
    if (current->prev != NULL) 
    {
        current->prev->next = NULL;
    } else 
    {
        *L = NULL;
    }
    int deletedData = current->data;
    free(current);
    return deletedData;
}

int list_search(Node* L, int k) 
{
    Node* current = L;
    while (current != NULL)
    {
        if (current->data == k) 
        {
            return 1;
        }
        current = current->next;
    }
    return -1;
}

void list_display(Node* L) 
{
    Node* current = L;
    while (current != NULL) 
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void list_reverse_negative(Node** L) 
{
    Node* current = *L;
    Node* prev = NULL;
    Node* negativeList = NULL;
    Node* negativeListTail = NULL;

    while (current != NULL)
    {
        Node* temp = current->next;

        if (current->data < 0)
        {
            current->next = negativeList;
            current->prev = temp;

            if (temp != NULL)
                temp->prev = current;

            negativeList = current;
            if (negativeListTail == NULL)
                negativeListTail = current;
        }
        else
        {
            prev = current;
        }

        current = temp;
    }

    if (negativeListTail != NULL)
        negativeListTail->next = prev;
    
    if (prev != NULL)
        prev->prev = negativeListTail;

    *L = negativeList;
}

int main() 
{
    Node* L = NULL;
    char choice[3];
    int x, y;

    while (1) 
    {
        scanf("%s", choice);
        if (strcmp(choice, "f") == 0) 
        {
            scanf("%d", &x);
            list_insert_front(&L, x);
        } else if (strcmp(choice, "t") == 0) 
        {
            scanf("%d", &x);
            list_insert_tail(&L, x);
        } else if (strcmp(choice, "a") == 0) 
        {
            scanf("%d %d", &x, &y);
            list_insert_after(&L, x, y);
        } else if (strcmp(choice, "b") == 0) 
        {
            scanf("%d %d", &x, &y);
            list_insert_before(&L, x, y);
        } else if (strcmp(choice, "d") == 0) 
        {
            scanf("%d", &x);
            int deleted = list_delete(&L, x);
            printf("%d\n", deleted);
        } else if (strcmp(choice, "i") == 0) 
        {
            int deletedInitial = list_delete_initial(&L);
            printf("%d\n", deletedInitial);
        } else if (strcmp(choice, "l") == 0) 
        {
            int deletedLast = list_delete_last(&L);
            printf("%d\n", deletedLast);
        } else if (strcmp(choice, "s") == 0) 
        {
            scanf("%d", &x);
            int result = list_search(L, x);
            printf("%d\n", result);
        } else if (strcmp(choice, "ds") == 0) 
        {
            list_display(L);
        } else if (strcmp(choice, "rn") == 0) 
        {
            list_reverse_negative(&L);
            list_display(L);
        } else if (strcmp(choice, "e") == 0) 
        {
            return 0;
        }
    }

    return 0;
}

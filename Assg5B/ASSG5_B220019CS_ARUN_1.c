#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    int data;
    struct node* next;
};

typedef struct node node;

node* create_node(int k)
{
    node* newNode = (node*)malloc(sizeof(node));
    newNode->data = k;
    newNode->next = NULL;
    return newNode;
}

void list_insert_tail(node** L, int k)
{
    node* newNode = create_node(k);
    if (*L == NULL)
    {
        *L = newNode;
    }
    else
    {
        node* current = *L;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = newNode;
    }
}

void list_insert_front(node** L, int k)
{
    node* newNode = create_node(k);
    newNode->next = *L;
    *L = newNode;
}

int list_pos(node** L, int k)
{
    int pos = 0;
    node* current = *L;
    while (current != NULL)
    {
        if (current->data == k)
        {
            return pos;
        }
        current = current->next;
        pos++;
    }
    return -1;
}

int list_length(node** L)
{
    int len = 0;
    node* current = *L;
    while (current != NULL)
    {
        len++;
        current = current->next;
    }
    return len;
}

int list_search(node** L, int k)
{
    node* current = *L;
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

void list_insert_before(node** L, int x, int y)
{
    int pos = list_pos(L, y);
    if (pos == 0 || pos == -1)
    {
        list_insert_front(L, x);
    }
    else
    {
        node* newnode = create_node(x);
        node* current = *L;
        node* prev = NULL;
        for (int i = 0; i < pos; i++)
        {
            prev = current;
            current = current->next;
        }
        newnode->next = current;
        if (prev != NULL)
        {
            prev->next = newnode;
        }
        else
        {
            *L = newnode;
        }
    }
}

void list_insert_after(node** L, int x, int y)
{
    int pos = list_pos(L, y);
    int len = list_length(L);
    if (pos == len - 1 || pos == -1)
    {
        list_insert_tail(L, x);
    }
    else
    {
        node* newnode = create_node(x);
        node* current = *L;
        node* prev = NULL;
        for (int i = 0; i <= pos; i++)
        {
            prev = current;
            current = current->next;
        }
        newnode->next = current;
        if (prev != NULL)
        {
            prev->next = newnode;
        }
        else
        {
            *L = newnode;
        }
    }
}

int list_delete_first(node** L)
{
    if (*L == NULL)
    {
        return -1;
    }
    node* currentNode = *L;
    *L = currentNode->next;
    int temp = currentNode->data;
    free(currentNode);
    return temp;
}

int list_delete_last(node** L)
{
    if (*L == NULL)
    {
        return -1;
    }
    node* currentNode = *L;
    node* prevNode = NULL;
    while (currentNode->next != NULL)
    {
        prevNode = currentNode;
        currentNode = currentNode->next;
    }
    int temp = currentNode->data;
    free(currentNode);
    if (prevNode != NULL)
    {
        prevNode->next = NULL;
    }
    else
    {
        *L = NULL;
    }
    return temp;
}

int list_delete(node** L, int k)
{
    int pos = list_pos(L, k);
    int len = list_length(L);
    if (pos == -1)
    {
        return -1;
    }
    else if (pos == 0)
    {
        return list_delete_first(L);
    }
    else if (pos == len - 1)
    {
        return list_delete_last(L);
    }
    else
    {
        node* currentNode = *L;
        node* prevNode = NULL;
        node* nextNode = currentNode->next;

        for (int i = 0; i < pos; i++)
        {
            prevNode = currentNode;
            currentNode = currentNode->next;
            nextNode = currentNode->next;
        }
        int deletedData = currentNode->data;
        free(currentNode);
        prevNode->next = nextNode;
        return deletedData;
    }
}

void list_reverse(node** L)
{
    node* currentNode = *L;
    node* prevNode = NULL;
    node* nextNode = *L;
    while (nextNode != NULL)
    {
        nextNode = nextNode->next;
        currentNode->next = prevNode;
        prevNode = currentNode;
        currentNode = nextNode;
    }
    *L = prevNode;
}

void list_reverse_even(node** L)
{
    node* even_head = NULL;
    node* even_tail = NULL;
    node* current = *L;
    int index = 1;

    while (current != NULL)
    {
        if (index % 2 == 0)
        {
            node* newNode = create_node(current->data);
            if (even_head == NULL)
            {
                even_head = newNode;
                even_tail = newNode;
            }
            else
            {
                newNode->next = even_head;
                even_head = newNode;
            }
        }
        current = current->next;
        index++;
    }

    current = *L;
    index = 1;
    node* even_current = even_head;

    while (current != NULL && even_current != NULL)
    {
        if (index % 2 == 0)
        {
            current->data = even_current->data;
            even_current = even_current->next;
        }
        current = current->next;
        index++;
    }

    while (even_head != NULL)
    {
        node* temp = even_head;
        even_head = even_head->next;
        free(temp);
    }
}

void list_display(node* L)
{
    node* current = L;
    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
}

int main()
{
    node* L = NULL;
    char choice[3]; 
    int x, y;

    while (1)
    {
        scanf(" %2s", choice); 
        if (strcmp(choice, "f") == 0)
        {
            scanf("%d", &x);
            list_insert_front(&L, x);
        }
        else if (strcmp(choice, "t") == 0)
        {
            scanf("%d", &x);
            list_insert_tail(&L, x);
        }
        else if (strcmp(choice, "a") == 0)
        {
            scanf("%d %d", &x, &y);
            list_insert_after(&L, x, y);
        }
        else if (strcmp(choice, "b") == 0)
        {
            scanf("%d %d", &x, &y);
            list_insert_before(&L, x, y);
        }
        else if (strcmp(choice, "d") == 0)
        {
            scanf("%d", &x);
            int deleted = list_delete(&L, x);
            printf("%d\n", deleted);
        }
        else if (strcmp(choice, "i") == 0)
        {
            int deleted = list_delete_first(&L);
            printf("%d\n", deleted);
        }
        else if (strcmp(choice, "l") == 0)
        {
            int deleted = list_delete_last(&L);
            printf("%d\n", deleted);
        }
        else if (strcmp(choice, "s") == 0)
        {
            scanf("%d", &x);
            int result = list_search(&L, x);
            printf("%d\n", result);
        }
        else if (strcmp(choice, "r") == 0)
        {
            list_reverse(&L);
            list_display(L);
            printf("\n");
        }
        else if (strcmp(choice, "ds") == 0)
        {
            list_display(L);
            printf("\n");
        }
        else if (strcmp(choice, "re") == 0)
        {
            list_reverse_even(&L);
            list_display(L);
            printf("\n");
        }
        else if (strcmp(choice, "e") == 0)
        {
            return 0; 
        }
    }

    return 0;
}

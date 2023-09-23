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
    newNode->data = k;
    newNode->next = NULL;
    return newNode;
}

void list_insert_tail(node** L, int k)
{
    node* newNode = create_node(k);
    node* current = *L;
    if (current->next == NULL)
    {
        // Fixed assignment to newNode
        *L = newNode;
    }
    else
    {
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
    *L = newNode;  // Fixed missing semicolon
}

int list_pos(node** L, int k)
{
    int pos = 0;
    node* current = *L;
    while (current != NULL)
    {
        if (current->data == k)  // Fixed comparison operator
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

int list_search(node** L, int k)  // Changed the function name and parameter
{
    node* current = *L;
    while (current != NULL)
    {
        if (current->data == k)  // Fixed comparison operator
        {
            return 1;
        }
        current = current->next;
    }
    return -1;
}

void list_insert_before(node** L, int x, int y)
{
    int pos = list_pos(L, y);  // Changed parameter
    if (pos == 0)  // Fixed comparison operator
    {
        list_insert_front(L, x);  // Changed parameter
    }
    
    node* newnode = create_node(x);
    node* current = *L;
    node* prev = NULL;
    for (int i = 0; i < pos; i++)
    {
        prev = current;
        current = current->next;
    }
    newnode->next = current;  // Fixed assignment
    if (prev != NULL)
    {
        prev->next = newnode;
    }
    else
    {
        *L = newnode;
    }
}

void list_insert_after(node** L, int x, int y)
{
    int pos = list_pos(L, y);  // Changed parameter
    int len = list_length(L);  // Changed parameter
    if (pos == len)  // Fixed comparison operator
    {
        list_insert_tail(L, x);  // Changed parameter
    }

    node* newnode = create_node(x);
    node* current = *L;
    node* prev = NULL;
    for (int i = 0; i <= pos; i++)
    {
        prev = current;
        current = current->next;
    }
    newnode->next = current;  // Fixed assignment
    if (prev != NULL)
    {
        prev->next = newnode;
    }
    else
    {
        *L = newnode;
    }
}
int list_delete_first(node** L)  // Changed parameter
{
    node* currentNode = *L;
    *L = currentNode->next;
    int temp = currentNode->data;
    free(currentNode);
    return temp;
}

int list_delete_last(node** L)  // Changed parameter
{
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
    int pos = list_pos(L, k);  // Changed parameter
    int len = list_length(L);  // Changed parameter
    if (pos == -1)  // Fixed comparison operator
    {
        return -1;
    }
    else if (pos == 0)  // Fixed comparison operator
    {
        return list_delete_first(L);  // Changed function name
    }
    else if (pos == len - 1)  // Fixed comparison operator
    {
        return list_delete_last(L);  // Changed function name
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
    while (current->next != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("%d", current->data);
}

int main()
{
    node* L = NULL;
    char choice[3]; // Increased size to accommodate "ds" input
    int key1, key2;

    while (1)
    {
        scanf(" %2s", choice); // Read up to 2 characters

        if (choice[0] == 'f')
        {
            scanf("%d", &key1);
            list_insert_front(&L, key1);
        }
        else if (choice[0] == 't')
        {
            scanf("%d", &key1);
            list_insert_tail(&L, key1);
        }
        else if (choice[0] == 'a')
        {
            scanf("%d %d", &key1, &key2);
            list_insert_after(&L, key1, key2);
        }
        else if (choice[0] == 'b')
        {
            scanf("%d %d", &key1, &key2);
            list_insert_before(&L, key1, key2);
        }
        else if (choice[0] == 'd')
        {
            scanf("%d", &key1);
            list_delete(&L, key1);
        }
        else if (choice[0] == 'i')
        {
            list_delete_first(&L);
        }
        else if (choice[0] == 'l')
        {
            list_delete_last(&L);
        }
        else if (choice[0] == 's')
        {
            scanf("%d", &key1);
            if (list_search(&L, key1) == 1)
                printf("1\n");
            else
                printf("-1\n");
        }
        else if (choice[0] == 'r')
        {
            list_reverse(&L);
            list_display(L);
            printf("\n");
        }
        else if (choice[0] == 'd' && choice[1] == 's')
        {
            list_display(L);
            printf("\n");
        }
        else if (choice[0] == 'r' && choice[1] == 'e')
        {
            list_reverse_even(&L);
            list_display(L);
            printf("\n");
        }
        else if (choice[0] == 'e')
        {
            return 0; // Exit the program
        }
    }

    return 0;
}
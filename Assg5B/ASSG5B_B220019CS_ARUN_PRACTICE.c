#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    int pid;
    int bn;
    int doctor;
    struct node* next;
};

typedef struct node node;

node* create_node(int x, int y)
{
    node* newNode = (node*)malloc(sizeof(node));
    newNode->pid = x;
    newNode->bn =y;
    if(y>=1 && y<=1000)
    {
        newNode->doctor=1;
    }
    if(y>=1001   && y<=10000)
    {
        newNode->doctor=2;
    }
    newNode->next = NULL;
    return newNode;
}

void add_patient(node** L, int pid,int bn)
{
    node* newNode = create_node(pid, bn);
    if (*L == NULL)
    {
        *L = newNode;
    }
    else
    {
        node* current = *L;
        node* prev = NULL;
        while (current->bn < bn)
        {
            prev = prev->next;
            current = current->next;
        }
        if(current->next=NULL)
        {
            current->next=newNode;
        }
        else
        {
            newNode->next=current;
            prev->next=newNode;
        }
    }
}

void next_token(node **L)
{
    node* current = *L;
    printf("%d",current->pid);
}

void call_token(node **L)
{
    node* current = *L;
    node* tempNode = *L;
    int temp = current->pid;
    *L=current->next;
    free (tempNode->next);
    printf("%d",temp);
}

void get_bn(node** L, int bn)
{
    node* current = *L;
    while (current != NULL)
    {
        if (current->bn == bn)
        {
            printf("%d",current->pid);
            return;
        }
        current = current->next;
    }
    printf("0");
}

void get_pid(node** L, int pid)
{
    node* current = *L;
    while (current != NULL)
    {
        if (current->pid == pid)
        {
            printf("%d",current->bn);
            return;
        }
        current = current->next;
    }
    printf("0");
}

void doctor_a(node** L)
{
    int doctorAFound = 0; 
    node* current = *L;
    
    while (current != NULL)
    {
        if (current->doctor == 1)
        {
            printf("%d ", current->pid);
            doctorAFound = 1; 
        }
        current = current->next;
    }
    
    if (!doctorAFound)
    {
        printf("0");
    }
}

void doctor_b(node** L)
{
    int doctorBFound = 0; 
    node* current = *L;
    
    while (current != NULL)
    {
        if (current->doctor == 2)
        {
            printf("%d ", current->pid);
            doctorBFound = 1; 
        }
        current = current->next;
    }
    
    if (!doctorBFound)
    {
        printf("0");
    }
}

void display(node* L)
{
    if (L == NULL)
    {
        printf("0\n");
        return;
    }

    node* current = L;

    while (current != NULL)
    {
        printf("%d %d\n", current->pid, current->bn);
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

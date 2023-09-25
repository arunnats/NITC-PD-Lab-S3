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

void add_patient(node** L, int pid, int bn)
{
    node* newNode = create_node(pid, bn);
    if (*L == NULL || bn < (*L)->bn)
    {
        newNode->next = *L;
        *L = newNode;
    }
    else
    {
        node* current = *L;
        node* prev = NULL;
        while (current != NULL && current->bn < bn)
        {
            prev = current;
            current = current->next;
        }
        if (current != NULL)
        {
            newNode->next = current;
            prev->next = newNode;
        }
        else
        {
            prev->next = newNode;
        }
    }
}


void next_token(node **L)
{
    if (*L != NULL)
    {
        node* current = *L;
        printf("%d ", current->pid);
    }
    else
    {
        printf("0 ");
    }
}


void call_token(node** L)
{
    if (*L != NULL)
    {
        node* current = *L;
        printf("%d ", current->pid);
        *L = current->next;
        free(current);
    }
    else
    {
        printf("0 ");
    }
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
    int found = 0;
    node* current = *L;
    while (current != NULL)
    {
        if (current->pid == bn)
        {
            printf("%d ", current->bn);
            found = 1;
            break;
        }
        current = current->next;
    }
    if (!found)
    {
        printf("0 ");
    }
}

void get_pid(node** L, int pid)
{
    int found = 0;
    node* current = *L;
    while (current != NULL)
    {
        if (current->bn == pid)
        {
            printf("%d ", current->pid);
            found = 1;
            break;
        }
        current = current->next;
    }
    if (!found)
    {
        printf("0 ");
    }
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
    int pid, bn;

    do
    {
        scanf("%s", choice); 
        
        if (strcmp(choice, "a") == 0)
        {
            scanf("%d %d", &pid, &bn);
            add_patient(&L, pid, bn);
        }
        else if (strcmp(choice, "c") == 0)
        {
            call_token(&L);
        }
        else if (strcmp(choice, "n") == 0)
        {
            next_token(&L);
        }
        else if (strcmp(choice, "bn") == 0)
        {
            scanf("%d", &pid);
            get_bn(&L, pid);
        }
        else if (strcmp(choice, "pid") == 0)
        {
            scanf("%d", &bn);
            get_pid(&L, bn);
        }
        else if (strcmp(choice, "dA") == 0)
        {
            doctor_a(&L);
        }
        else if (strcmp(choice, "dB") == 0)
        {
            doctor_b(&L);
        }
        else if (strcmp(choice, "e") == 0)
        {
            break; // Exit the loop
        }
        else if (strcmp(choice, "d") == 0)
        {
            display(L);
        }
        else
        {
            printf("Invalid choice\n");
        }

    } while (1);
}

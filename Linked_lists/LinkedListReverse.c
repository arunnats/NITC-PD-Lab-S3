#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void append(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* current = *head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
}

        
void reverse(struct Node** head)
{
    struct Node* currentNode = *head;
    struct Node* prevNode = NULL;
    struct Node* nextNode = *head;
    while (nextNode!= NULL) {
        nextNode=nextNode->next;
        currentNode->next=prevNode;
        prevNode=currentNode;
        currentNode=nextNode;
    }
    *head=prevNode;
    
}

void display(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    int n, data;
    struct Node* head = NULL;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &data);
        append(&head, data);
    }

    reverse(&head);    

    display(head);   

    return 0;
}
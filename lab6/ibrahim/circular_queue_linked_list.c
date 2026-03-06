#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};

void enqueue(struct Node **head, int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;

    if (*head == NULL)
    {
        *head = newNode;
        newNode->next = newNode;
        return;
    }
    newNode->next = (*head)->next;
    (*head)->next = newNode;
    *head = newNode;
    return;
}

void display(struct Node **head)
{
    struct Node *temp = (*head);
    if (*head == NULL)          
    {
        printf("Queue is empty\n");
        return;
    }
    do
    {
        temp = temp->next;
        printf("%d ", temp->data);
    } while (temp != *head);
    printf("\n");
    return;
}
void dequeue(struct Node **head)
{
    if (*head == NULL)          
    {
        printf("Queue is empty\n");
        return;
    }
    struct Node * temp;
    temp = (*head)->next;
    (*head)->next = (*head)->next->next;
    if (temp == *head)
    {
        *head = NULL;
        return;
    }
    free(temp);
    return;
}
int main()
{
    struct Node *head = NULL;
    int option, data;
    while (option != 4)
    {
        printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            printf("Enter data: ");
            scanf("%d", &data);
            enqueue(&head, data);
            break;
        case 2:
            dequeue(&head);
            break;
        case 3:
            display(&head);
            break;
        case 4:
            break;
        default:
            printf("Invalid option\n");
            break;
        }
    }
    return 0;
}

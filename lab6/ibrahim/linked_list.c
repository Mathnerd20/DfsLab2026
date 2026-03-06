#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};

void addbegin(struct Node **head, int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
    return;
}

void addend(struct Node **head, int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL)
    {
        *head = newNode;
        return;
    }

    struct Node *temp = *head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    return;
}

void addafter(struct Node **head, int data, int key)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;

    struct Node *temp = *head;
    while (temp != NULL && temp->data != key)
    {
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Key not found\n");
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

void display(struct Node **head)
{
    struct Node *temp = *head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
    return;
}
void delete(struct Node **head, int key)
{
    struct Node *temp = *head;
    struct Node *prev = NULL;

    if (temp != NULL && temp->data == key)
    {
        *head = temp->next;
        free(temp);
        return;
    }

    while (temp != NULL && temp->data != key)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Key not found\n");
        return;
    }

    prev->next = temp->next;
    printf("Deleted node with key %d\n", key);
    free(temp);
}
int main()
{
    struct Node *head = NULL;
    int option, data,pos;
    while (option != 6)
    {
        printf("1. Add at beginning\n2. Add at end\n3. Add after key\n4.delete\n5.display\n6.exit\n");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            printf("Enter data: ");
            scanf("%d", &data);
            addbegin(&head, data);
            break;
        case 2:
            printf("Enter data: ");
            scanf("%d", &data);
            addend(&head, data);
            break;
        case 3:
            int pos;
            printf("Enter data: ");
            scanf("%d", &data);
            printf("Enter key: ");
            scanf("%d", &pos);
            addafter(&head, data, pos);
            break;
        case 4:
            printf("Enter key to delete: ");
            scanf("%d", &data);
            delete(&head, data);
            break;
        case 5:
            display(&head);
            break;
        case 6:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid option\n");
        }
    }
    return 0;
}

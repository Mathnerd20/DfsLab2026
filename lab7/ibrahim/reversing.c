#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node *head = NULL;

void addend(int data)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
        return;
    }

    struct node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    return;
}

void display()
{
    struct node *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
    return;
}

int main(){
    int n,ele;
    printf("Enter the number of elements in the linked list: ");
    scanf("%d",&n);

    for(int i = 0;i < n;i++){
        printf("Enter the element number %d: ",i+1);
        scanf("%d",&ele);
        addend(ele);
    }
    printf("original linked list : ");
    display();

    struct node *prev = NULL,*curr = head,*next;
    while(curr  != NULL){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
    printf("reversed linked list : ");
    display();
    return 0;
}
#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

void addend(struct node **head, int data)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL)
    {
        *head = newNode;
        return;
    }

    struct node *temp = *head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    return;
}

int main(){
    struct node *head = NULL;
    int n,ele;
    printf("Enter the number of elements in the linked list: ");
    scanf("%d",&n);

    for(int i = 0;i < n;i++){
        printf("Enter the element number %d: ",i+1);
        scanf("%d",&ele);
        addend(&head,ele);
    }
    struct node *biggest = head,*temp = head->next;
    while(temp != NULL){
        if(temp->data > biggest->data){
            biggest = temp;
        }
        temp = temp->next;
    }
    printf("The higgest element is : %d\n",biggest->data);
    return 0;
}
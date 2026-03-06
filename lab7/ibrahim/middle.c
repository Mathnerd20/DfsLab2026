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

int main(){
    int n,ele;
    printf("Enter the number of elements in the linked list: ");
    scanf("%d",&n);

    for(int i = 0;i < n;i++){
        printf("Enter the element number %d: ",i+1);
        scanf("%d",&ele);
        addend(ele);
    }

    struct node *slow = head;
    struct node *fast = head;

    if(head != NULL){
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        printf("The middle elements is %d\n",slow->data);
    }
    else{
        printf("List is Empty");
    }
    return 0;
}
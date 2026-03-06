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

void display(struct node **head)
{
    struct node *temp = *head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
    return;
}

int main(){
    struct node *head1 = NULL;
    struct node *head2 = NULL;

    int n,ele = 0,check;
    printf("Enter the number of elements in the first sorted linked list: ");
    scanf("%d",&n);

    for(int i = 0;i < n;i++){
        check = ele;
        printf("Enter the element number %d: ",i+1);
        scanf("%d",&ele);
        if(ele < check){
            printf("the element is not in accesding order,reenter the element\n");
            i--;
            continue;
        }
        addend(&head1,ele);
    }
    ele = 0;

    printf("Enter the number of elements in the second sorted linked list: ");
    scanf("%d",&n);

    for(int i = 0;i < n;i++){
        check = ele;
        printf("Enter the element number %d: ",i+1);
        scanf("%d",&ele);
        if(ele < check){
            printf("the element is not in accesding order,reenter the element\n");
            i--;
            continue;
        }
        addend(&head2,ele);
    }

    printf("sorted list1 : ");
    display(&head1);
    printf("soeted list2 : ");
    display(&head2);

    struct node *sortedhead;
    if(head1->data < head2->data){
        sortedhead = head1;
        head1 = head1->next;
    }
    else{
        sortedhead = head2;
        head2 = head2->next;
    }
    struct node *tail = sortedhead;
    while(head1 != NULL && head2 != NULL){

        if(head1->data <= head2->data){
            tail->next = head1;
            head1 = head1->next;
        }
        else{
            tail->next = head2;
            head2 = head2->next;
        }
        tail = tail->next;
    }
    if(head1 != NULL){
        tail->next = head1;
    }
    else{
        tail->next = head2;
    }
    printf("merged sorted list : ");
    display(&sortedhead);
    return 0;
}
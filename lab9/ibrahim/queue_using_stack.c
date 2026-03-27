#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

void push(struct node **head,int data){
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = *head;
    *head = new_node;
}

int pop(struct node **head){
    if(*head == NULL){
        return -1;
    }
    else{
        struct node *temp = *head;
        *head = temp->next;
        int n = temp->data;
        free(temp);
        return n;
    }
}

void display(struct node **head){
    struct node *temp = *head;

    if(*head == NULL){
        printf("queue is empty\n");
        return;
    }

    while(temp != NULL){
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("\n");
    return;
}

int main(){
    struct node *head1 = NULL, *head2 = NULL;

    int option = -1;
    int n,m;
    while(option != 4){
        printf("1.)enqueue\n2.)dequeue\n3.)diplay\n4.)exit\n");
        printf("Enter the option: ");
        scanf("%d",&option);

        switch(option){
            case 1:
                printf("Enter the element you want to insert: ");
                scanf("%d",&n);
                m = pop(&head1);
                while(m != -1){
                    push(&head2,m);
                    m = pop(&head1);
                }

                push(&head1,n);

                m = pop(&head2);
                while(m != -1){
                    push(&head1,m);
                    m = pop(&head2);
                }
                break;
            case 2:
                n = pop(&head1);
                if(n == -1){
                    printf("queue is empty\n");
                }
                else{
                    printf("%d is deleted from the queue\n",n);
                }
                break;
            case 3:
                display(&head1);
                break;
            case 4:
                printf("Thank You\n");
                break;
            default:
                printf("Invalid option\n");
                break;
        }

    }

    return 0;
}
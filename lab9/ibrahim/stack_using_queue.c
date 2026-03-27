#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

void enqueue(struct node **rear,struct node **front,int data){
    
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = data;
    if(*rear == NULL && *front == NULL){
        *rear = new_node;
        *front = new_node;
        new_node->next = NULL;
    }
    else{
        new_node->next=*rear;
        *rear = new_node;
    }
    return;
}

int dequeue(struct node **rear,struct node **front){
    if(*front == NULL){
        return -1;
    }
    else if(*front == *rear){
        struct node *temp = *front;
        int n = temp->data;
        *front = NULL;
        *rear = NULL;
        free(temp);
        return n;
    }
    else{
        struct node *temp = *rear;
        while(temp->next != *front){
            temp = temp->next;
        }
        int n = temp->next->data;
        *front = temp;
        free(temp->next);
        temp->next = NULL;
        return n;
    }
}

void display(struct node **rear){
    if(*rear == NULL){
        printf("stack is empty\n");
        return;
    }

    struct node *temp = *rear;
    while(temp != NULL){
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("\n");
}


int main(){
    struct node *front1 = NULL,*front2 = NULL;
    struct node *rear1 = NULL,*rear2 = NULL;

    int option = -1;
    int n,m;
    while(option != 4){
        printf("1.)push\n2.)pop\n3.)display\n4.)exit\n");
        printf("Enter the option: ");
        scanf("%d",&option);

        switch(option){
            case 1:
                printf("Enter the element you want to insert in the stack: ");
                scanf("%d",&n);

                enqueue(&rear2,&front2,n);

                m = dequeue(&rear1,&front1);
                while(m != -1){
                    enqueue(&rear2,&front2,m);
                    m = dequeue(&rear1,&front1); 
                }

                m = dequeue(&rear2,&front2);
                while(m != -1){
                    enqueue(&rear1,&front1,m);
                    m = dequeue(&rear2,&front2); 
                }
                break;
            case 2:
                n = dequeue(&rear1,&front1);
                if(n == -1){
                    printf("stack is empty\n");
                }
                else{
                    printf("%d is removed from the stack\n",n);
                }
                break;
            case 3:
                display(&rear1);
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
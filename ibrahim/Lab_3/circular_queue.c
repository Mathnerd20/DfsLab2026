#include<stdio.h>
#include<stdlib.h>

#define MaxSize 100

struct queue
{
    int data[MaxSize];
    int front;
    int rear;
};

void enqueue(struct queue* q,int n){
    if((q->rear + 1)%MaxSize == q->front){
        printf("Queue is full!");
        return;
    }
    if(q->front == -1){
        q->rear = 0;
        q->front = 0;
    }
    else{
        q->rear = (q->rear+1)%MaxSize;
    }
    q->data[q->rear] = n;
    return;
}
int dequeue(struct queue* q){
    if(q->front == -1){
        return -1;
    }

    int n = q->data[q->front];
    
    if (q->front == q->rear)
    {
        q->front = -1;
        q->rear = -1;
    }
    else{
        q->front = (q->front+1)%MaxSize;
    }
    return n;
    
}
void display(struct queue* q){
    struct queue* temp;
    int rev = q->front;
    temp = q;
    int n;
    while(temp->front != -1){
        n = temp->data[temp->front];
        if(temp->front == temp->rear){
            temp->front = -1;
        }
        else{
            temp->front = (temp->front+1)%MaxSize;
        }
        printf("%d ",n);
    }
    q->front = rev;
}

int main(){
    struct queue qe;
    struct queue* q = &qe;
    q->front = -1;
    q->rear = -1;
    int option, n;
    while (option != 4)
    {
        printf("1.)enqueue\n2.)dequeue\n3.)display\n4.)exit\nenter the option : ");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            printf("Enter the element you want to enqueue : ");
            scanf("%d", &n);
            enqueue(q,n);
            break;
        case 2:
            n = dequeue(q);
            if (n == -1)
            {
                printf("The  queue is empty\n");
            }
            else
            {
                printf("%d is deleted from the queue\n",n);
            }
            break;
        case 3:
            display(q);
            printf("\n");
            break;
        case 4:
            printf("Thank you!");
            break;

        default:
            printf("option does not exits\n");
            break;
        }
    }
    return 0;
}

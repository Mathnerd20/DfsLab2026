#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
} *front = NULL, *rear = NULL;

void enqueue(int n)
{
    struct node *p;
    p = (struct node *)malloc(sizeof(struct node));
    p->data = n;
    p->next = NULL;
    if (rear == NULL || front == NULL)
    {
        front = p;
    }
    else
    {
        rear->next = p;
    }
    rear = p;
}

int dequeue()
{
    int n;
    if (front == NULL)
    {
        return -1;
    }
    else
    {
        n = front->data;
        front = front->next;
        return n;
    }
}
void display()
{
    struct node *p;
    p = front;
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    return;
}

int main()
{

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
            enqueue(n);
            break;
        case 2:
            n = dequeue();
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
            display();
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
#include<stdio.h>
#define MAX 7 
struct queue
{
    int a[MAX];
    int front;
    int count;
};

void enqueue(struct queue *q, int x);
void dequeue(struct queue *q);
void display(struct queue *q);

int main()
{
    struct queue q;
    q.front = 0;
    q.count = 0;
    int t = 9;
    while(t != -1)
    {
	scanf("%d", &t);
	switch(t)
	{
	    case 1:
		int w;
		printf("Enter element:");
		scanf("%d", &w);
	    	enqueue(&q, w);
		break;
	    case 2:
	    	dequeue(&q);
		break;
	    case 3:
	    	display(&q);
		break;
	}
    }
}

void enqueue(struct queue *q, int x)
{
    if(q->count == MAX)
    {
	printf("Queue Full");
	return;
    }
    q->a[(q->front + q->count) % MAX] = x;
    q->count++;
}
void dequeue(struct queue *q)
{
    if(q->count == 0)
    {
	printf("Queue Empty");
	return;
    }
    printf("%d\n", q->a[q->front]);
    q->front = (q->front + 1) % MAX;
    q->count--;
}
void display(struct queue *q)
{
    int i = 0;
    while(i < q->count)
    {
	printf("%d\n", q->a[(q->front + i) % MAX]);
	i++;
    }
}

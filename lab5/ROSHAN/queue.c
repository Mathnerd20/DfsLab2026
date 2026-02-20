#include<stdio.h>
#define Max 10

char queue[Max];
int front=0,rear=0;

void enqueue();
char dequeue();
void display();
int main()
{
	int s;
	do
	{
		printf("enter 1 for enqueue\nenter 2 for dequeue\nenter 3 for displaying\nenter 4 for quitting: ");
		scanf("%d",&s);
		switch(s)
		{
			case(1):
				enqueue();
				break;
			case(2):
				printf("%d\n",dequeue());
				break;
			case(3):
				display();
				break;
		};
	}while(s != 4);
	return 0;
}
void enqueue()
{
	if(rear==Max)
	{
		printf("queue is full!!!\n");
		return ;
	}
	int item;
	printf("enter the number to be enqueued: ");
	scanf("%d",&item);
	queue[rear]=item;
	rear = rear+1;
}
char dequeue()
{
	if(front==Max)
	{
		printf("queue is empty!!!\n");
		return '\0';
	}
	int x = queue[front];
	front = front+1;
	return x;
}
void display()
{
	if(front==Max)
	{
		printf("queue is empty!!!\n ");
		return;
	}
	for(int i=front;i<rear;i++)
	{
		printf("%d ",queue[i]);
	}
}

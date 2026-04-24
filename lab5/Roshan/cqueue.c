#include<stdio.h>
#define Max 10

char queue[Max];
int front=-1,rear=-1,count=0;

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
	if(count==Max)
	{
		printf("queue is full!!!\n");
		return ;
	}
	int item;
	printf("enter the number to be enqueued: ");
	scanf("%d",&item);
	rear=(rear+1)%Max;
	queue[rear]=item;
	count++;
}
char dequeue()
{
	if(count==0)
	{
		printf("queue is empty!!!\n");
		return '\0';
	}
	front = (front+1)%Max;
	int x = queue[front];
	count--;
	return x;
}
void display()
{
	if(count==0)
	{
		printf("queue is empty!!!\n ");
		return;
	}
	while(count != 0)
	{
		printf("%d ",dequeue());
	}
}

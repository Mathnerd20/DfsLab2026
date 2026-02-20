#include<stdio.h>
#include<stdlib.h>
struct node
{
    int info;
    struct node *back;
};

// typedef struct node struct node;
struct node *first = NULL;
struct node *top = NULL;
void enqueue();
void dequeue();
void display();
int main()
{
    int t = 10;
    printf("Choose the options as needed \n 1 for enqueue \n 2 for dequeue \n 3 for display \n 0 to quit \n");
    while(t != 0)
    {
	printf(" Enter option: ");
	scanf("%d", &t);
	switch(t)
	{
	    case 1:
	    	enqueue();
		break;
	    case 2:
	    	dequeue();
		break;
	    case 3:
	    	display();
		break;
	}
    }
}

void enqueue()
{
    struct node *tmp;
    tmp = (struct node *)malloc(sizeof(struct node));
    printf("Enter struct node to be enqueueed into the queue: ");
    int p;
    scanf("%d", &p);
    if(first == NULL) 
    {
	tmp->back = NULL;
	tmp->info = p;
	first = tmp;
	top = first;
	return;
    }
    top->back = tmp;
    tmp->back = NULL;
    //tmp->next = top;
    tmp->info = p;
    top = tmp;
}
void dequeue()
{
    struct node *tmp;
    if(top == NULL) 
    {
	printf("Stack Empty");
	return;
    }
    tmp = first;
    printf("%d\n", tmp->info);
    first = first->back;
    free(tmp);
}
void display()
{
    while(first != NULL)
    {
	dequeue();
    }
    //dequeue();
}

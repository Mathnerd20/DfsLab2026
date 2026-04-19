#include<stdio.h>
#include<stdlib.h>

struct NODE
{
    int info;
    struct NODE *up;
};
typedef struct NODE node;

void enqueue(node **, node **);
void dequeue(node **);
void display(node **);

int main()
{
    int t = 10;
    node *top = NULL;
    node *bottom = NULL;
    while(t != -1)
    {
	printf("Enter operation to be performed: \n 1 for enqueue \n 2 for dequeue \n 3 for display \n -1 to quit \n");
	printf("=======================\n");
	printf("Enter option: ");
	scanf("%d", &t);
	printf("=======================\n");

	switch(t)
	{
	    case 1:
		enqueue(&top, &bottom);	
		break;
	    case 2:
		dequeue(&bottom);	
		break;
	    case 3:
		display(&bottom);	
		break;
	}
    }
}

void enqueue(node **p, node **q)
{
    node *n;
    n = (node *)malloc(sizeof(node));
    if(*p == NULL)
    {
	*q = n;
    }
    else
    {
	(*p)->up = n;
    }
    n->up = NULL;
    printf("Enter value to be enqueued: ");
    scanf("%d", &n->info);
    *p = n;
    printf("\n");
    return;
}

void dequeue(node **p)
{
    node *n = *p;
    if(*p == NULL)
    {
	printf("Stack Empty");
    }
    *p = (*p)->up;
    printf("Dequeued value: %d\n", n->info);
    free(n);
    return;
}

void display(node **p)
{
    node *n = *p; 
    printf("First --> %d\n", n->info);
    while(n->up != NULL)
    {
	n = n->up;
	printf("\t  %d\n", n->info);
    }
    printf("Last -->  %d\n", n->info);
    printf("=======================\n");
    return;
}

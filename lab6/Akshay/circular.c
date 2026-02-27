#include<stdio.h>
#include<stdlib.h>
struct node
{
    int info;
    struct node *next;
};

// typedef struct node struct node;
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
    if(top == NULL) 
    {
	tmp->info = p;
	tmp->next = tmp;
	top = tmp;
	return;
    }
    tmp->next = top->next;
    top->next = tmp;
    //tmp->next = top;
    tmp->info = p;
}
void dequeue()
{
    struct node *tmp;
    if(top == NULL) 
    {
	printf("Stack Empty");
	return;
    }
    tmp = top->next;
    printf("%d\n", tmp->info);
    top->next = top->next->next;
    free(tmp);
}
void display()
{
    struct node *diss = top;
    do
    {
	diss = diss->next;
	printf("%d ", diss->info);
    }while(diss != top);
    //dequeue();
}

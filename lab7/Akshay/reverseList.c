#include<stdio.h>
#include<stdlib.h>
struct node
{
    int info;
    struct node *next;
};

// typedef struct node struct node;
struct node *top = NULL;

void push();
void pop();
void display();
void reverse();
int main()
{
    int t = 10;
    printf("Choose the options as needed \n 1 for push \n 2 for pop \n 3 for display \n 4 for reverse \n 0 to quit \n");
    while(t != 0)
    {
	printf(" Enter option: ");
	scanf("%d", &t);
	switch(t)
	{
	    case 1:
	    	push();
		break;
	    case 2:
	    	pop();
		break;
	    case 3:
	    	display();
		break;
	    case 4:
	    	reverse();
		break;
	}
    }
}

void push()
{
    struct node *tmp;
    tmp = (struct node *)malloc(sizeof(struct node));
    printf("Enter struct node to be pushed into the list: ");
    int p;
    scanf("%d", &p);
    /*if(top == NULL)
    {
	tmp->next = NULL;
    }*/
    tmp->next = top;
    tmp->info = p;
    top = tmp;
}
void pop()
{
    struct node *tmp;
    if(top == NULL)
    {
	printf("Stack Empty");
	return;
    }
    tmp = top;
    printf("%d\n", tmp->info);
    top = top->next;
    free(tmp);
}
void display()
{
    struct node *skipper = top;
    while(skipper != NULL)
    {
	printf("%d \n", skipper->info);
	skipper = skipper->next;
    }
}
void reverse()
{
    struct node *a = top;
    struct node *b = a->next;
    struct node *r = b->next;
    while(b != NULL)
    {
        b->next = a;
    	a = b;
    	b = r;
    	if(r != NULL)
    	    r = r->next;
    }
    top = a;
    return;
}

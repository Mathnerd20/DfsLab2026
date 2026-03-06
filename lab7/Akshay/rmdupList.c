#include<stdio.h>
#include<stdlib.h>
struct node
{
    int info;
    struct node *back;
};

// typedef struct node struct node;
struct node *top = NULL;
void push();
void pop();
void display();
void rmDup();
int main()
{
    int t = 10;
    printf("Choose the options as needed \n 1 for push \n 2 for pop \n 3 for display \n 4 for removing duplicates \n 0 to quit \n");
    printf("\n Enter a sorted list only!! \n");
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
	    	rmDup();
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
    tmp->back = top;
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
    top = top->back;
    free(tmp);
}
void display()
{
    struct node *John = top;
    while(John != NULL)
    {
	printf("%d \n", John->info);
	John = John->back;
    }
}
void rmDup()
{
    struct node *today = top;
    struct node *dup;
    while(today != NULL && today->back != NULL)
    {
	struct node *aft = today;
	while(aft->back != NULL)
	{
	    if(today->info == aft->back->info)
	    {
		dup = aft->back;
		aft->back = aft->back->back;
		printf("%d ", dup->info);
		free(dup);
	    }
	    else
	    {
		aft = aft->back;
	    }
	}
	today = today->back;
    }
}

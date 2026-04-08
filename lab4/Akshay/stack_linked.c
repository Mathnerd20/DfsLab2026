#include<stdio.h>
#include<stdlib.h>
struct node
{
    int info;
    struct node *next;
};

// typedef struct node struct node;
struct node *top = NULL; //Declaring pointer as global, not recommended practice
void push();
void pop();
void display();
int main()
{
    int t = 10;
    printf("Choose the options as needed \n 1 for push \n 2 for pop \n 3 for display \n 0 to quit \n");
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
	    default:
	    	continue;
	}
    }
}

void push()
{
    struct node *tmp;
    tmp = (struct node *)malloc(sizeof(struct node));
    printf("Enter struct node to be pushed into the stack: ");
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
    while(top != NULL)
    {
	pop();
    }
    pop();
}

#include<stdio.h>
#include<stdlib.h>
//In this I'll try to use double pointers
struct node
{
    int info;
    struct node *next;
};

// typedef struct node node;
void push(struct node **); //struct node ** indicates input as double pointer.
void pop(struct node **);
void display(struct node **);
int main()
{
    int t = 10;
    printf("Choose the options as needed \n 1 for push \n 2 for pop \n 3 for display \n 0 to quit \n");
    struct node *top = NULL;
    while(t != 0)
    {
	printf(" Enter option: ");
	scanf("%d", &t);
	switch(t)
	{
	    case 1:
		push(&top); //send address of pointer(&top), not pointer to pointer(**top). The address of pointer is the pointer to pointer top.
		break; 
//By putting struct node **top as argument, the compiler is getting confused and is thinking that we are trying to declare a pointer inside the function call
	    case 2:
		pop(&top);
		break;
	    case 3:
	    	display(&top);
		break;
	    default:
	    	continue;
		break;
	}
    }
}

void push(struct node **top)
{
    struct node *tmp;
    tmp = (struct node *)malloc(sizeof(struct node));
    printf("Enter struct node to be pushed into the stack: ");
    scanf("%d", &tmp->info);
    /*if(top == NULL) 
    {
	tmp->next = NULL;
    }*/
    tmp->next = *top;
    *top = tmp;
    return;
}

void pop(struct node **top)
{
    struct node *tmp;
    if(*top == NULL) 
    {
	printf("Stack Empty");
	return;
    }
    tmp = *top;
    printf("%d\n", tmp->info);
    *top = (*top)->next;
    free(tmp);
    return;
}

void display(struct node **top)
{
    struct node *tmp = *top;
    while(tmp != NULL)
    {
	printf("%d\n", tmp->info);
	tmp = tmp->next;
    }
    return;
}

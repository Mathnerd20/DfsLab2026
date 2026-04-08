#include<stdio.h>
#define MAX 100
struct STACK
{
    int top;
    int arr[MAX];
};
typedef struct STACK stack;
void push(stack *);
void pop(stack *);
void display(stack *);
int main()
{
    int t = 10;
    stack s;
    s.top = -1;
    printf("Choose the options as needed \n 1 for push \n 2 for pop \n 3 for display \n 0 to quit \n");
    while(t != 0)
    {
	printf(" Enter option: ");
	scanf("%d", &t);
	switch(t)
	{
	    case 1:
	    	push(&s);
		break;
	    case 2:
	    	pop(&s);
		break;
	    case 3:
	    	display(&s);
		break;
	    default:
	    	continue;
	}
    }
}

void push(stack *a)
{
    if(a->top == MAX-1)
    {
	printf("Stack full");
	return;
    }
    a->top++;
    scanf("%d", &a->arr[a->top]);
    return;
}
void pop(stack *a)
{
    if(a->top == -1)
    {
	printf("Stack empty");
	return;
    }
    printf("%d", a->arr[a->top]);
    a->top--;
    return;
}

void display(stack *a)
{
    int x = a->top;
    while(x != -1)
    {
	printf("%d\n", a->arr[x]);
	x--;
    }
    return;
}

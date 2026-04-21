#include"stackLinked.h"
#define MAX 100

void kop(struct node **top) //useless incorrect function
{
    while((*top)->next != NULL && (*top)->info != '(' )
    {
	printf("%c", pop(top));
    }
}

int main()
{
    printf("Enter expression: ");
    char s[MAX];
    scanf("%s", s);
    int i = 0;
    struct node *top = NULL;
    printf("Postfix is: ");
    push(&top, ' '); //without this, top is null and y = top->info fails giving seg fault
    while(s[i] != '\0')
    {
	if(s[i] >= '0' && s[i] <= '9')
	{
	    printf("%c", s[i]);
	    i++;
	    continue;
	}
	switch(s[i])
	{
	    case ')':
		while(top->info != '(')
		{
		    printf("%c", pop(&top));
		}
		char g = pop(&top); //captures the extra ) wihout printing it.
		break;
	    case '(':
		push(&top,'(');
		break;
	    case '/':
		char y = top->info;
		if(y == '*' || y == '/')
		{
		    //kop(&top);
		    printf("%c", pop(&top));
		    push(&top, '/');
		}
		else
		{
		    push(&top, '/');
		}
		break;
	    case '*':
		y = top->info;
		if(y == '*' || y == '/')
		{
		    //kop(&top);
		    printf("%c", pop(&top));
		    push(&top, '*');
		}
		else
		{
		    push(&top, '*');
		}
		break;
	    case '+':
		y = top->info;
		if(y == '*' || y == '/' || y == '+' || y == '-')
		{
		    //kop(&top);
		    printf("%c", pop(&top));
		    push(&top, '+');
		}
		else
		{
		    push(&top, '+');
		}
		break;
	    case '-':
		y = top->info;
		if(y == '*' || y == '/' || y == '+' || y == '-')
		{
		    //kop(&top);
		    printf("%c", pop(&top));
		    push(&top, '-');
		}
		else
		{
		    push(&top, '-');
		}
		break;
	}
	i++;
    }
    while(top != NULL)
    {
	printf("%c", pop(&top));
    }
}

#include "../../lab4/Akshay/stackLinked.h"
#define MAX 100
int main()
{
    char exp[MAX];
    scanf("%s", exp);
    struct node *top = NULL;
    push(&top, ' ');
    int i = 0;
    int result;
    while(exp[i] != '\0')
    {
	if(exp[i] >= '0' && exp[i] <='9')
	{
	    push(&top, exp[i]);
	}
	switch(exp[i])
	{
	    case '*':
	    	int x = pop(&top) - '0';
	    	int y = pop(&top) - '0';
		result = y * x + '0';
		push(&top, result);
		break;
	    case '/':
	    	x = pop(&top) - '0';
	    	y = pop(&top) - '0';
		result = y / x + '0';
		push(&top, result);
		break;
	    case '+':
	    	x = pop(&top) - '0';
	    	y = pop(&top) - '0';
		result = y + x + '0';
		push(&top, result);
		break;
	    case '-':
	    	x = pop(&top) - '0';
	    	y = pop(&top) - '0';
		result = y - x + '0';
		push(&top, result);
		break;
	}
	i++;
    }
    result = pop(&top) - '0';
    printf("%d", result);
}


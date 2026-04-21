#include "stackLinked.h"
#define MAX 100
int main()
{
    char s[MAX];
    scanf("%s", s);
    int yes = 1;
    int i = 0;
    struct node *top = NULL;
    push(&top, ' ');
    while(s[i] != '\0')
    {
	if(s[i] == '(' || s[i] == '[' || s[i] == '{') 
	{
	    push(&top, s[i]);
	    i++;
	    continue;
	}
	else if(s[i] == ')')
	{
	    if(top->info != '(')
	    {
		yes = 0;
		break;
	    }
	    pop(&top);
	}
	else if(s[i] == ']')
	{
	    if(top->info != '[')
	    {
		yes = 0;
		break;
	    }
	    pop(&top);
	}
	else if(s[i] == '}')
	{
	    if(top->info != '{')
	    {
		yes = 0;
		break;
	    }
	    pop(&top);
	}
	i++;
    }
    if(top->next != NULL)
    {
	yes = 0;
    }
    if(yes)
    {
	printf("No error");
    }
    else
    {
	printf("ERROR \n Brackets not matched");
    }
}


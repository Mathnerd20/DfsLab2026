#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct node
{
    char info;
    struct node *next;
};

// typedef struct node struct node;
struct node *top = NULL;
void push(char);
char pop();
void display();
int main()
{
    char s[100];
    scanf("%s", s);
    int k = strlen(s);
    for(int i = 0; i < k; i++)
    {
	push(s[i]);
    }
    int yes = 1;
    if(k%2 == 0)
    {
	int i = k/2;
	while( s[i] != '\0')
	{
	    if(s[i] != pop())
	    {
		yes = 0;
	    }
	    i++;
	}
    }
    else
    {
	int i = k/2 + 1;
	while( s[i] != '\0')
	{
	    if(s[i] != pop())
	    {
		yes = 0;
	    }
	    i++;
	}
    }
    if(yes)
    {
	printf("Palindrome");
    }
    else
    {
	printf("Not palindrome");
    }
}

void push(char c)
{
    struct node *tmp;
    tmp = (struct node *)malloc(sizeof(struct node));
    /*if(top == NULL) 
    {
	tmp->next = NULL;
    }*/
    tmp->next = top;
    tmp->info = c;
    top = tmp;
}
char pop()
{
    struct node *tmp;
    tmp = top;
    char p;
    p = tmp->info;
    top = top->next;
    free(tmp);
    return p;
}
void display()
{
    while(top != NULL)
    {
	pop();
    }
    pop();
}

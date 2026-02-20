#include<stdio.h>
#define Max 10

int stack[Max];
int top=-1;
void push(int);
int pop();
int ch_in(char);
int main()
{
	char postfix[Max];
	printf("enter the postfix string: ");
	scanf("%s",postfix);
	for(int i=0;postfix[i] != '\0';i++)
	{
		char x = postfix[i];
		if(x=='+' || x=='-' || x=='*' || x=='/')
		{
			int b = pop();
			int a = pop();
			int result;
			if(x=='+')
			{
				result= a+b;
				push(result);
			}
			else if(x=='-')
			{
				result=a-b;
				push(result);
			}
			else if(x=='*')
			{
				result=a*b;
				push(result);
			}
			else
			{
				result=a/b;
				push(result);
			}

		}
		else
		{
			int y = ch_in(x);
			push(y);
		}
	}
	printf("evaluaion is %d\n",pop());
	return 0;
}
void push(int item)
{
	if(top==Max-1)
	{
		printf("stack is full");
		return ;
	}
	top++;
	stack[top]=item;
}
int pop()
{
	if(top==-1)
	{
		printf("stack is empty");
	}
	else
	return stack[top--];
}
int ch_in(char c)
{
	int n = c-'0';
	return n;
}

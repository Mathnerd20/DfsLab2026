#include<stdio.h>
#define MAX 200
struct NODE
{
    char A[MAX];
    int top;
};
typedef struct NODE node;

void push(node *s, char x)
{
    if(s->top == MAX-1)
    {
	printf("Stack is FULL");
	return;
    }
    s->top++;
    s->A[s->top] = x;
}

char pop(node *s)
{
    if(s->top == -1)
    {
	return -1;
    }
    char x = s->A[s->top];
    s->top--;
    return x;
}


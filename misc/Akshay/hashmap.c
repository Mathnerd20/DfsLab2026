#include<stdio.h>
#include<stdlib.h>
struct NODE
{
    int info;
    struct NODE *next;
};
typedef struct NODE node;

int getprime(int n);
node **getlist(int n);
void add(node **p, int k);
int main()
{
    printf("Enter number of elements: ");
    int n;
    scanf("%d", &n);
    node **a;
    a = getlist(5);
    for(int i = 0; i < n; i++)
    {
	int k;
	scanf("%d", &k);
	switch(k % 10)
	{
	    case 0:
	    	add(&a[0], k);
		break;
	    case 1:
	    	add(&a[1], k);
		break;
	    case 2:
	    	add(&a[2], k);
		break;
	    case 3:
	    	add(&a[3], k);
		break;
	    case 4:
	    	add(&a[4], k);
		break;
	}
    }
}

node **getlist(int n)
{
    node **a;
    a = malloc(n * sizeof(node *));
    for(int i = 0; i < n; i++)
    {
	a[i] = NULL;
    }
    return a;
}
int getprime(int n)
{
    int k = 0;
    int m = n;
    while(m > 0)
    {
	m = m/2;
	k++;
    }
    int two;
    return 1;
}
void add(node **p, int k)
{
    node *new;
    new = (node *)malloc(sizeof(node));
    if(*p == NULL)
    {
	*p = new;
    }
    else
    {
	node *tmp = *p;
	while(tmp->next != NULL)
	{
	    tmp = tmp->next;
	}
	tmp->next = new;
    }
    new->next = NULL;
    new->info = k;
    return;
}

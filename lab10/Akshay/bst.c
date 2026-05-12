#include<stdio.h>
#include<stdlib.h>
struct bst
{
    int info;
    struct bst *right;
    struct bst *left;
};
typedef struct bst node;

void add(node *p, int k);
void delete(node *p, int a);
void display(node *p);
node *getnode();

int main()
{
    node *top == NULL;
    int t = 9;
    while(t != -1)
    {
	scanf("%d", &t);
	switch(t)
	{
	    case 1:
		int k;
		printf("Enter value to be added");
		scanf("%d", &k);
	    	add(top, k);
		break;
	    case 2:
	    	int k
		printf("Enter element to be deleted: ");
		scanf("%d", &k);
	    	delete(top, k);
		break;
	    case 3:
	    	display(top);
		break;
	}
    }
}

void add(node *p, int k)
{
    if(p == NULL)
    {
	p = getnode();
	p->info = k;
	p->right = NULL;
	p->left = NULL;
    }
    else if(p->info < k)
    {
	p->right = add(p->right,k);
    }
    else
    {
	p->left = add(p->left, k); 
    }
    return p;

}
node *getnode()
{
    node *new;
    new = (node *)malloc(sizeof(node*));
    return new;
}
void delete(node *top, a)
{
    if(p == NULL)
    {
	return p;
    }
    else if(
}

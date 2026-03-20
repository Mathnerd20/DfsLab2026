#include<stdio.h>
#include<stdlib.h>

struct node
{
int info;
struct node *right;
struct node *left;
};
// a,b,c,d
// 1,2,3,4
// a is first, d is last.
// typedef struct node struct node;

struct node *first = NULL;
struct node *last = NULL;
void addfirst();
void addlast();
void addI(int i);
void rmfirst();
void rmlast();
void rmI(int i);
void display();

int main()
{
    int t = 10;
    printf("Choose the options as needed: \n 1 for adding \n 2 to remove \n 3 to display \n 0 to quit \n");
    while(t != 0)
    {
	printf("--------------------------------------- \n");
	int k = 10;
	int i = 10;
	printf(" Enter option: ");
	scanf("%d", &t);
	if(t > 3 || t < 0)
	{
	    printf("Invalid Input");
	    continue;
	}
	switch(t)
	{
	    case 1:
		printf("--------------------------------------- \n Choose option: \n 1 for adding at first \n 2 for adding at last \n 3 for adding after ith position \n");
		printf(" Enter option: ");
		scanf("%d", &k);
		if(k > 3)
		{
		    printf("Invalid Input");
		    continue;
		}
		switch(k)
		{
		    case 1:
			addfirst();
			break;
		    case 2:
			addlast();
			break;
		    case 3:
			printf("Enter i: ");
			scanf("%d", &i);
			addI(i);
			break;
		}
		break;
	    case 2:
		printf("--------------------------------------- \n Choose option: \n 1 for deleting first \n 2 for deleting last \n 3 for deleting ith position \n");
		printf(" Enter option: ");
		scanf("%d", &k);
		if(k > 3)
		{
		    printf("Invalid Input");
		    continue;
		}
		switch(k)
		{
		    case 1:
			rmfirst();
			break;
		    case 2:
			rmlast();
			break;
		    case 3:
			printf("Enter i: ");
			scanf("%d", &i);
			rmI(i);
			break;
		}
		break;
	    case 3:
		display();
		break;
	}
    }
}

void addfirst()
{
    struct node *tmp;
    tmp = (struct node *)malloc(sizeof(struct node));
    printf("Enter info to be pushed to the first of list: ");
    int p;
    scanf("%d", &p);
    if(first == NULL) 
    {
	//tmp->right = NULL;
	//tmp->left = NULL;
	last = tmp;
    }
    else
    {
	first->left = tmp;
    }
    tmp->right = first;
    tmp->info = p;
    tmp->left = NULL;
    first = tmp;
}

void addlast()
{
    struct node *tmp;
    tmp = (struct node *)malloc(sizeof(struct node));
    printf("Enter info to be pushed to the last of list: ");
    int p;
    scanf("%d", &p);
    //there might be a error here.
    if(first == NULL) 
    {
	// tmp->next = NULL;
	first = tmp;
    }
    else
    {
	last->right = tmp;
    }
    tmp->left = last;
    tmp->right = NULL;
    tmp->info = p;
    last = tmp;
}

void addI(int i)
{
    struct node *tmp;
    tmp = (struct node *)malloc(sizeof(struct node));
    printf("Enter info to be pushed into the list after ith position: ");
    int p;
    scanf("%d", &p);
    struct node *skipper = first;
    for(int j = 1; j < i; j++)
    {
	skipper = skipper->right;
    }
    tmp->right = skipper->right;
    skipper->right = tmp;
    tmp->right->left = tmp;
    tmp->left = skipper;
    tmp->info = p;
}

void rmfirst()
{
    struct node *tmp;
    if(first == NULL) 
    {
	printf("List Empty");
	return;
    }
    tmp = first;
    printf("%d\n", tmp->info);
    if(first->right != NULL)
    {
	first = first->right;
	first->left = NULL;
    }
    else
    {
	first = NULL;
	last = NULL;
    }
    free(tmp);
}

void rmlast()
{
    struct node *tmp;
    if(last == NULL) 
    {
	printf("List Empty");
	return;
    }
    tmp = last;
    printf("%d\n", tmp->info);
    if(last->left != NULL)
    {
	last = last->left;
	last->right = NULL;
    }
    else
    {
	last = NULL;
	first = NULL;
    }
    free(tmp);
}

void rmI(int i)
{
    struct node *tmp;
    if(first == NULL || last == NULL) 
    {
	printf("List Empty");
	return;
    }
    /*if(i == 1)
    {
	rmlast();
    }*/
    struct node *skipper = first;
    //struct node *lmao = first;
    for(int j = 1; j < i; j++)
    {
	//lmao = skipper;
	skipper = skipper->right;
    }
    tmp = skipper;
    printf("%d\n", tmp->info);
    //first = first->next;
    skipper->right->left = skipper->left;
    skipper->left->right = skipper->right;
    free(tmp);
}

void display()
{
    struct node *lol = first;
    int i = 0;
    printf("Elements are: \n");
    while(lol != NULL)
    {
	i++;
	printf("%d (element number %d) \n", lol->info, i);
	lol = lol->right;
    }
}

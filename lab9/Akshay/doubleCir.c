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

struct node *rear = NULL;
void addfirst();
void addlast();
void addI(int i);
void rmfirst();
void rmlast();
void rmI(int i);
void displaybf(int i);
void display();

int main()
{
    int t = 10;
    printf("Choose the options as needed: \n 1 for adding \n 2 to remove \n 3 to display \n 4 to display after i \n 0 to quit \n");
    while(t != 0)
    {
	printf("--------------------------------------- \n");
	int k = 10;
	int i = 10;
	printf(" Enter option: ");
	scanf("%d", &t);
	if(t > 4 || t < 0)
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
	    /*
	    case 4:
	    	printf("Enter i: ");
		scanf("%d", &i);
	    	displaybf(i);
		break;
		*/
	}
    }
}

void addfirst()
{
    struct node *tmp;
    tmp = (struct node *)malloc(sizeof(struct node));
    printf("Enter info to be pushed to the first of list: ");
    scanf("%d", &tmp->info);
    if(rear == NULL) 
    {
	rear = tmp;
	tmp->left = rear;
	tmp->right = rear;
	return;
    }
    tmp->right = rear->right;
    rear->right->left = tmp;
    tmp->left = rear;
    rear->right = tmp;
}

void addlast()
{
    struct node *tmp;
    tmp = (struct node *)malloc(sizeof(struct node));
    printf("Enter info to be pushed to the last of list: ");
    scanf("%d", &tmp->info);
    //there might be a error here.
    if(rear == NULL) 
    {
	// tmp->next = NULL;
	rear = tmp;
	tmp->left = rear;
	tmp->right = rear;
	return;
    }
    tmp->left = rear;
    rear->right->left = tmp;
    tmp->right = rear->right;
    rear->right = tmp;
    rear = tmp;
}

void addI(int i)
{
    struct node *tmp;
    tmp = (struct node *)malloc(sizeof(struct node));
    printf("Enter info to be pushed into the list after ith position: ");
    scanf("%d", &tmp->info);
    struct node *skipper = rear;
    for(int j = 1; j <= i; j++)
    {
	skipper = skipper->right;
    }
    tmp->right = skipper->right;
    skipper->right = tmp;
    tmp->right->left = tmp;
    tmp->left = skipper;
}

void rmfirst()
{
    struct node *tmp;
    if(rear == NULL) 
    {
	printf("List is Empty");
	return;
    }
    tmp = rear->right;
    printf("%d\n", tmp->info);
    if(tmp == rear)
    {
	rear = NULL;
	return;
    }
    rear->right = tmp->right;
    tmp->right->left = rear;
    free(tmp);
}

void rmlast()
{
    struct node *tmp;
    if(rear == NULL) 
    {
	printf("List Empty");
	return;
    }
    tmp = rear;
    printf("%d\n", tmp->info);
    if(rear->left != rear)
    {
	rear->left->right = rear->right;
	rear = rear->left;
	rear->right->left = rear;
    }
    else
    {
	rear = NULL;
    }
    free(tmp);
}

void rmI(int i)
{
    struct node *tmp;
    if(rear == NULL) 
    {
	printf("List Empty");
	return;
    }
    struct node *skipper = rear;
    for(int j = 1; j <= i; j++)
    {
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
    struct node *lol = rear->right;
    int i = 0;
    printf("Elements are: \n");
    do
    {
	i++;
	printf("%d (element number %d) \n", lol->info, i);
	lol = lol->right;
    }while(lol != rear->right);
}

/*
void displaybf(int i)
{
    struct node *hehe = first;
    for(int j = 1; j < i; j++)
    {
	hehe = hehe->right;
    }
    while(hehe != NULL)
    {
	printf("%d \n",hehe->info);
	hehe = hehe->left;
    }
}
*/

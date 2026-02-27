#include<stdio.h>
#include<stdlib.h>
struct node
{
    int info;
    struct node *next;
};
// a,b,c,d
// 4,3,2,1
// a is last, last->next = NULL; d is first;
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
    printf("Choose the options as needed \n 1 for adding \n 2 to remove \n 3 to display \n 0 to quit \n");
    while(t != 0)
    {
	int k = 10;
	int i = 10;
	printf(" Enter option: ");
	scanf("%d", &t);
	switch(t)
	{
	    case 1:
	    	printf("Press 1 for adding at first \n 2 for adding at last \n 3 for adding after ith position \n");
		scanf("%d", &k);
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
	    	printf("Press 1 for deleting at first \n 2 for deleting at last \n 3 for deleting after ith position \n");
		scanf("%d", &k);
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
	// tmp->next = NULL;
	last = tmp;
    }
    tmp->next = first;
    tmp->info = p;
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
	last->next = tmp;
    }
    tmp->next = NULL;
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
	skipper = skipper->next;
    }
    tmp->next = skipper->next;
    tmp->info = p;
    skipper->next = tmp;
}
void rmfirst()
{
    struct node *tmp;
    if(first == NULL) 
    {
	printf("Stack Empty");
	return;
    }
    tmp = first;
    printf("%d\n", tmp->info);
    first = first->next;
    free(tmp);
}
void rmlast()
{
    struct node *tmp;
    if(first == NULL) 
    {
	printf("Stack Empty");
	return;
    }
    tmp = last;
    printf("%d\n", tmp->info);
    struct node *skipper = first;
    while(skipper->next->next != NULL)
    {
	skipper = skipper->next;
    }
    skipper->next = NULL;
    last = skipper;
    //first = first->next;
    free(tmp);
}
void rmI(int i)
{
    struct node *tmp;
    if(first == NULL) 
    {
	printf("Stack Empty");
	return;
    }
    /*if(i == 1)
    {
	rmlast();
    }*/
    struct node *skipper = first;
    struct node *lmao = first;
    for(int j = 1; j <= i; j++)
    {
	lmao = skipper;
	skipper = skipper->next;
    }
    tmp = skipper;
    printf("%d\n", tmp->info);
    //first = first->next;
    lmao->next = skipper->next;
    free(tmp);
}
void display()
{
    struct node *lol = first;
    int i = 0;
    while(lol->next != NULL)
    {
	i++;
	printf("%d (element number %d) \n", lol->info, i);
	lol = lol->next;
    }
    printf("%d", lol->info);
}

#include<stdio.h>
#include<stdlib.h>
struct node
{
    char info;
    struct node *next;
};
void push(struct node **top, char c)
{
    struct node *tmp;
    tmp = (struct node *)malloc(sizeof(struct node));
    tmp->info = c;
    tmp->next = *top;
    *top = tmp;
    return;
}

char pop(struct node **top)
{
    struct node *tmp;
    tmp = *top;
    char x = tmp->info;
    *top = (*top)->next;
    free(tmp);
    return x;
}


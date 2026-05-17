#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node
{
    char word[100];
    int freq;
    struct node *next;
};

static void push(struct node **top, char c[])
{
    struct node *tmp;
    tmp = (struct node *)malloc(sizeof(struct node));
    strcpy(tmp->word, c);
    tmp->next = *top;
    *top = tmp;
    return;
}

static char pop(struct node **top)
{
    struct node *tmp;
    tmp = *top;
    char x[100];
    strcpy((*top)->word, x);
    *top = (*top)->next;
    free(tmp);
    return x[99];
}


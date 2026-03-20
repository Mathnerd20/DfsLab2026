# include <stdio.h>
# include <stdlib.h>

struct NODE
{
    int item;
    struct NODE *prev;
    struct NODE *next;
};
typedef struct NODE nd;

nd *head = NULL;

void first (int t)
{
    nd *tmp;
    tmp = (nd*)malloc(sizeof(nd));

    if (head == NULL)
    {
        tmp->prev = head;
        tmp->next = head;
        tmp->item = t;
        head = tmp;
    }
    
    else
    {
        tmp->prev = NULL;
        tmp->next = head;
        head->prev = tmp;
        tmp->item = t;
        head = tmp;
    }
}

void middle (int t , int key)
{
    nd *tmp ; tmp = head;
    while (tmp->item != key) tmp = tmp->next;

    nd *add;
    add = (nd*)malloc(sizeof(nd));

    add->item = t;
    add->prev = tmp;
    add->next = tmp->next;
    tmp->next->prev = add;
    tmp->next = add;
}

void last (int t)
{
    nd *tmp ; tmp = head;
    while (tmp->next != NULL) tmp = tmp->next;

    nd *add;
    add = (nd*)malloc(sizeof(nd));

    add->next = NULL;
    add->prev = tmp;
    tmp->next = add;
    add->item = t;
}

void delete_first ()
{
    nd *tmp;
    tmp = head;

    printf("The deleted item is : %d\n", tmp->item);
    tmp->next->prev = NULL;
    head = head->next;
    free(tmp);
}

void delete_middle (int key)
{
    nd *tmp;
    tmp = head;

    while (tmp->item != key) tmp = tmp->next;

    tmp->next->prev = tmp->prev;
    tmp->prev->next = tmp->next;
    
    free(tmp);
}

void delete_last ()
{
    nd *tmp;
    tmp = head;

    while (tmp->next != NULL) tmp = tmp->next;

    tmp->prev->next = NULL;
    printf("Deleted item is %d\n", tmp->item);
    free(tmp);
}

void display ()
{
    nd *tmp;
    tmp = head;

    while (tmp != NULL)
    {
        printf("%d ", tmp->item);
        tmp = tmp->next;
    }
    printf('\n');
}

int main ()
{
    int n;

    do
    {
        printf("Enter 1 to add item in front\n2 to add at particular location\n3 to add item at last\n4 to delete 1st node\n5 to delete middle node\n6 to delete end node\n7 to display (0 to exit then programm) : ");
        scanf("%d", &n);

        switch(n)
        {
            case 1:
                int t;
                printf("Enter the item u want to add : ");
                scanf("%d", &t);

                first (t);
                break;

            case 2:
                int keya;
                printf("Enter the key of the node after which u want to add node : ");
                scanf("%d", &keya);

                int a;
                printf("Enter the item u want to add : ");
                scanf("%d", &a);

                middle (a , keya);
                break;
            
            case 3:
                int b;
                printf("Enter the item u want to add : ");
                scanf("%d", &b);

                last (b);
                break;

            case 4:
                delete_first ();
                break;

            case 5:
                int keyd;
                printf("Please enter the item of the node u want to delete : ");
                scanf("%d", &keyd);

                delete_middle (keyd);
                break;

            case 6:
                delete_last ();
                break;

            case 7:
                display ();
                break;
        }
    }while (n != 0);
}

